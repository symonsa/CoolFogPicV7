//#include <pic.h>
#include <xc.h>
#include "pump_control.h"
#include "serial_buffer.h"
#include <stdio.h>

#ifdef _PIC18F4550_H_
#define USE_SER_INTERUPT 1
#else
#define USE_SER_INTERUPT 0
#endif
#define bigdelay //__delay_ms(2000);
void ser_int(void);
void tx(char);
unsigned char rx(void);
void txstr(char* str);

void testleds(void) {


    PORTD = 0xff;
    //__delay_ms(2000);
//    RD0 = ~RCIF;
//    RD1 = ~TXIF;
//    RD2 = ~TRMT;
//    RD3 = ~OERR;
    //    RD4 = 0;

}

void mainserial3(void) {

    ser_int();


    for (int j = 0; j < 1000; j++) {
        for (int i = 0; i < 10; i++) {

            tx('0' + i);
        }
        txstr("abcdefghijklmnopqrstuvwxyz\n\r");
    }
    while (1) {
        tx(rx());
    }
}



/**
 * Load the new char to be transmitted into THR.
Wait till the char is transmitted. TXIF will be set when the TXREG is empty.
Clear the TXIF for the next cycle.
 */
void ser_int(void) {
    RCSTA = 0X90;
    TRISC6 = 0; //Output (TX)
    TRISC7 = 1; //Input (RX)
    TXSTA = 0x24; //BRGH=1, TXEN = 1, Asynchronous Mode, 8-bit mode
    SYNC = 0;
    SPEN = 1;
    TX9 = 0;

    RCSTA = 0b10010000; //Serial Port enabled,8-bit reception
#ifdef _PIC18F4550_H_
    SPBRG = 207; //9600 baudrate for 4Mhz is 25, 8Mhz 51, 207 for 2400 baud
#else
     SPBRG = 103; //2400 baud 16f877a
#endif

    CREN = 1;
    TXIE = USE_SER_INTERUPT;
    RCIE = USE_SER_INTERUPT;
    GIE = 1;
    PEIE = 1;
}

/**
 * Load the new char to be transmitted into THR.
Wait till the char is transmitted. TXIF will be set when the TXREG is empty.
Clear the TXIF for the next cycle.
 * @param a
 */
void tx(char a) {


    while (!TRMT) {

    };
    TXREG = a;


}

/**
 * Wait till the Data is received. RCIF will be set once the data is received in the RCREG register.
Clear the receiver flag(RCIF) for the next cycle.
Copy/Read the received data from the RCREG register.
 * @return 
 */
unsigned char rx(void) {

    while (!RCIF);

    return RCREG;
}

void txstr(char *s) {
    while (*s) {
        tx(*s++);
    }
}

void serial_process_loop(void) {

    if (TRMT && has_data(&outbound)) {
#if USE_SER_INTERUPT
        TXIE = USE_SER_INTERUPT;
#else

        TXREG = pop(&outbound);
#endif

    }

#if !USE_SER_INTERUPT
    if (RCIF) {
        if (OERR|| FERR) {
            CREN = 0;
            CREN = 1;
            puts("serial overflow");
        }
        unsigned char a = RCREG;
        if (not_full(&inbound)) {
            push(&inbound, a);
        }
    }

#endif

}


void usart_interrupt(void) {

    if (TXIE && TXIF) {
        TXIE = 0;
        if (/*TRMT &&*/ has_data(&outbound)) {
            TXREG = pop(&outbound);
            TXIE = 1;
        }
    }
    if (RCIE && RCIF) {
        if (OERR) {
            CREN = 0;
            CREN = 1;
             puts("serial overflow");
        }
        unsigned char a = RCREG;
        if (not_full(&inbound)) {
            push(&inbound, a);
        }
    }



}
#ifdef USE_SER_INTERUPT_LOCAL
///*
// Overrun bit OERR has to be cleared in software.
//This is done by resetting the receive logic (CREN
//is cleared and then set). If bit OERR is set, transfers
//from the RSR register to the RCREG
// */

void __interrupt() usart(void) {

    if (TXIE && TXIF) {
        TXIE = 0;
        if (/*TRMT &&*/ has_data(&outbound)) {
            TXREG = pop(&outbound);
            TXIE = 1;
        }
    }
    if (RCIE && RCIF) {
        if (OERR) {
            CREN = 0;
            CREN = 1;
        }
        unsigned char a = RCREG;
        if (not_full(&inbound)) {
            push(&inbound, a);
        }
    }



}
#endif


char
getch_timeout (void)
{
  if (OERR) {
    CREN = 0;
    CREN = 1;
  }

  CREN = 1;
  if (!RCIF) {
    return 0;
  }

  return (RCREG);
}
void putch(char c) {
    push(&outbound, c);

}
int puts(const  char *str){
    for ( const char * c = str; *c != 0; c++){
        putch(*c);
    }
    return 0;
}


char *
receiveMessage (void)
{
  static char message[MAX_MESSAGE];
  char c;
  static int len = 0;

  if (!has_data(&inbound)) {
      return 0;
  }

  c = pop(&inbound);
  //c = getch_timeout ();
  if (0 == c) {
    // nothing yet
    return NULL;
  }
  //putch(c);
  if ((0 == len) && (c != frameStart)) {
    // not a start of a message
    return NULL;
  }
  // received a valid character - so add
  message[len] = c;
  //printf("%c",c);
  len++;
  if (len >= MAX_MESSAGE) {
    // not valid
    len = 0;
    return NULL;
  }
  if (frameEnd == c) {
    message[len] = 0;
    //printf("Message%s %d\r\n",message,len);
    len = 0;

    return message;
  }

  return NULL;

}

/*
* output_message 
* outputs the message to the serial stream, handling the handshakes
*/
void
output_message (char *message)
{
  if (NULL == message) {
    return;
  }
 // TRANSMIT_CONTROL_SET (1);
  for (int i = 0; (i < MAX_MESSAGE) && (0 != message[i]); i++) {
    putch (message[i]);
  }
//  while (!TRMT) {
//    ;
//  }
//  TRANSMIT_CONTROL_SET (0);


}

void
sendChars(void){
	// still sending
	if (!TRMT || outbound.length){
		TRANSMIT_CONTROL_SET (1);
	}else{
		TRANSMIT_CONTROL_SET (0);
	}	
	if (!outbound.length){
		//nothing there
		return;
	}
	// Still in process of sending
	if (!TRMT){
		return;
	}
	/*
	 *  if we got here we have something to send,
	 *  but are not currently sending	
	 */
	 TXEN = 1;
	 TXREG = pop(&outbound);
			
}	
SerialBuffer_t inbound = {0};
SerialBuffer_t outbound = {0};
