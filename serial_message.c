
#include "pump_control.h"

#define ADDRESS_POS 1
#define MSG_TYPE_POS 2
#define NEW_ADDRESS_POS 3
#define ZONE1POS 3
#define ZONE2POS 4
#define DUMP_MODE_POS 5
#define DUMP_TIME_POS 6
#define STATUS1_POS 7
#define STATUS2_POS 8
#define STATUS3_POS 9
#define CHECKSUM_POS 10
#define END_MESSAGE_POS 11
#define SECOND_END_MESSAGE_POS 12
#define NUL_POS 13
#define ERROR_STATS_MSG_TYPE 'e'
#define ERROR_POS_HI 3
#define ERROR_POS_LO 4
#define SENT_POS_HI 5
#define SENT_POS_LO 6
#define RECV_POS_HI 7
#define RECV_POS_LO 8
#define PADDING_POS 9
static char outputMessage[MAX_MESSAGE];
//char address = '0';
__EEPROM_DATA('0', '1', 0, 0, 0, 0, 0, 0);

unsigned char numSerialErrors = 0;
unsigned char numSerialReceived = 0;
unsigned char numSerialSent = 0;

unsigned char xtochar(char x) {
    if ((x >= '0')
            && (x <= '9')) {
        return (x - '0');
    } else if ((x >= 'a')
            && (x <= 'f')) {
        return (x) - 'a' + 10;
    } else if ((x >= 'A')
            && (x <= 'F')) {
        return (x) - 'F' + 10;
    }
    return 0;
}

char chartox(unsigned char c) {
    if (c > 9) {
        return 'a' + (c - 10);
    } else {
        return '0' + c;

    }
}

void setBaseMessage(char messageType, char msgAddress) {
    outputMessage[0] = frameStart;

    outputMessage[ADDRESS_POS] = msgAddress;
    outputMessage[MSG_TYPE_POS] = messageType;
    outputMessage[ZONE1POS] = chartox(combinedZones >> 4);
    outputMessage[ZONE2POS] = chartox((combinedZones & 15));

    outputMessage[DUMP_MODE_POS] = chartox(dump_mode);
    outputMessage[DUMP_TIME_POS] = chartox(dump_time);
    // now set the status

    char v = (fault_flags.value >> 8) &0xf;
    outputMessage[STATUS1_POS] = chartox(v);

    v = (fault_flags.value >> 4) &0xf;
    outputMessage[STATUS2_POS] = chartox(v);

    v = (fault_flags.value) &0xf;
    outputMessage[STATUS3_POS] = chartox(v);
    outputMessage[CHECKSUM_POS] = chartox(calculateChecksum(outputMessage));
    outputMessage[END_MESSAGE_POS] = frameEnd;
    outputMessage[SECOND_END_MESSAGE_POS] = frameEnd; // a bit of a hack because the transmit control is going low too early
    outputMessage[NUL_POS] = 0;
}

void process_set_zones_message(char * inmessage) {
    commsZones = (xtochar(inmessage[ZONE1POS]) << 4) + xtochar(inmessage[ZONE2POS]);
    dump_mode = xtochar(inmessage[DUMP_MODE_POS]);
    dump_time = xtochar(inmessage[DUMP_TIME_POS]);

    combineZones();
    setBaseMessage('s', inmessage[ADDRESS_POS]);


    output_message(outputMessage);


}

void process_get_status_message(char * inmessage) {
    //    printf("In process get status\r\n");
    combineZones();
    setBaseMessage('g', inmessage[ADDRESS_POS]);

    //    for (int i = 0; i < MAX_MESSAGE; i ++){
    //	    printf("msg %c %c\r\n",outputMessage[i],outputMessage[i]+'0' );
    //	} 
    output_message(outputMessage);

}

void process_error_stats_message(char msgAddress) {
    outputMessage[0] = frameStart;

    outputMessage[ADDRESS_POS] = msgAddress;
    outputMessage[MSG_TYPE_POS] = ERROR_STATS_MSG_TYPE;

    outputMessage[ERROR_POS_HI] = chartox(numSerialErrors >> 4);
    outputMessage[ERROR_POS_LO] = chartox((numSerialErrors & 15));

    outputMessage[SENT_POS_HI] = chartox(numSerialSent >> 4);
    outputMessage[SENT_POS_LO] = chartox((numSerialSent & 15));

    outputMessage[RECV_POS_HI] = chartox(numSerialReceived >> 4);
    outputMessage[RECV_POS_LO] = chartox((numSerialReceived & 15));
    outputMessage[PADDING_POS] = '0';
    outputMessage[CHECKSUM_POS] = chartox(calculateChecksum(outputMessage));

    outputMessage[END_MESSAGE_POS] = frameEnd;
    outputMessage[SECOND_END_MESSAGE_POS] = frameEnd; // a bit of a hack because the transmit control is going low too early
    outputMessage[NUL_POS] = 0;
    output_message(outputMessage);

}

void process_set_address_message(char * inmessage) {
    unsigned char new_address = inmessage[NEW_ADDRESS_POS];
    /* AS 2023-06-20 The Write_b_eep routine is no longer supported. Please use the MPLAB X MCC. eeprom_write(0, new_address);*/

    setBaseMessage('a', inmessage[ADDRESS_POS]);
    output_message(outputMessage);

}

void process_reset_pump(char * inmessage) {
    resetPump();
    setBaseMessage('m', inmessage[ADDRESS_POS]);
    output_message(outputMessage);
}

void
process_message(char *inmessage) {

    char msgType;
    unsigned char address = 0; //eeprom_read(0);



    //printf("m %c a %c\r\n",inmessage[ADDRESS_POS],address +'0');
    if (inmessage[ADDRESS_POS] == '0' || inmessage[ADDRESS_POS] == address) {
        unsigned char checkSumCalculated = calculateChecksum(inmessage);
        unsigned char checkSumActual = xtochar(inmessage[CHECKSUM_POS]);
        if (checkSumCalculated != checkSumActual) {
            numSerialErrors++;
            return;
        }
        numSerialReceived++;

        msgType = inmessage[MSG_TYPE_POS];

        switch (msgType) {
            case 'S':
            case 's':
                process_set_zones_message(inmessage);
                break;

            case 'G':
            case 'g':
                process_get_status_message(inmessage);
                break;

            case 'A':
            case 'a':
                process_set_address_message(inmessage);
                break;

                /**
                 * master reset of pump
                 * Using M to get a mid point between G and S so that if there
                 * is a bit error, we should not hit this one
                 * @param inmessage
                 */

            case 'M':
            case 'm':
                process_reset_pump(inmessage);
                break;
            case 'E':
            case 'e':
                process_error_stats_message(inmessage[ADDRESS_POS]);
                break;

            default:
                numSerialErrors++;

        }


    }
}

// Function to calculate the 4-bit checksum of a string

unsigned char calculateChecksum(const char* str) {
    int sum = 0;


    // Iterate through each character in the string
    for (unsigned char i = ADDRESS_POS; i < CHECKSUM_POS; i++) {
        sum += (unsigned char) str[i]; // Add the ASCII value of the character to the sum
    }

    // Fold the sum to 4 bits
    while (sum > 0xF) { // 0xF is 1111 in binary, the maximum value of a 4-bit number
        sum = (sum & 0xF) + (sum >> 4);
    }

    return (unsigned char) (sum & 0xF); // the sum, masked to 4 bits
}






