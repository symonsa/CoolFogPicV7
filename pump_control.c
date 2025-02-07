/************18f14550*/


// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
// was #pragma config FOSC = XT_XT     // Oscillator Selection bits (XT oscillator (XT))
#pragma config FOSC = INTOSCIO_EC// Oscillator Selection bits (Internal oscillator, port function on RA6, EC used by USB (INTIO))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 1         // Brown-out Reset Voltage bits (Setting 2 4.33V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
//#pragma config ICPRT = ON       // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT enabled)

#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>




#include "pump_control.h"
#include "serial_buffer.h"
#include <stdio.h>

char state = standbyState;
unsigned int zones = 0;

char *PumpStateMappings[] = {
    "standbyState\n\r",
    "shutdownState\n\r",
    "startpumpInitialState\n\r",
    "startpumpWaitState\n\r",
    "startpumpSecondLWPCheckState\n\r",
    "startmainState\n\r",
    "pumprunState\n\r"
};

void printPumpState(void) {
    return;
    printf(PumpStateMappings[state]);
}

void printFaultState(void) {
    return;
    if (fault_flags . boostPumpBit) {
        printf("boostPumpBit\n\r");
    }
    if (fault_flags . lwl_fault) {
        printf("lwl_fault\n\r");
    }
    if (fault_flags . lwp_fault) {
        printf("lwp_fault\n\r");
    }
    if (fault_flags . lfp_fault) {
        printf("lfp_fault\n\r");
    }
    if (fault_flags . po_fault) {
        printf("po_fault\n\r");
    }
    if (fault_flags . wpOkBit) {
        printf("wpOkBit\n\r");
    }
    if (fault_flags . mainPumpBit) {
        printf("mainPumpBit\n\r");
    }
    if (fault_flags . boostPumpBit) {
        printf("boostPumpBit\n\r");
    }
    if (fault_flags . pumpOverloadBit) {
        printf("pumpOverloadBit\n\r");
    }
    if (fault_flags . dumpSolenoidBit) {
        printf("dumpSolenoidBit\n\r");
    }

}

void
init(void) {




    T0CS = 0;
    // Set digital pins
    ADCON1 = 0x7f;
    //  PCFG6 = 1;
    //  PCFG5 = 1;
    //  PCFG4 = 1;
    PCFG3 = 1;
    //  PCFG2 = 1;
    //  PCFG1 = 1;
    //  PCFG0 = 1;
    RBPU = 0;
    // new
    /*
     IRCF2:IRCF0: Internal Oscillator Frequency Select bits
111 = 8 MHz (INTOSC drives clock directly)
110 = 4 MHz
101 = 2 MHz
100 = 1 MHz(3)
011 = 500 kHz
010 = 250 kHz
001 = 125 kHz
000 = 31 kHz (from either INTOSC/256 or INTRC directly)(2)
     */
IRCF2 = 1;
IRCF1 = 1;
IRCF0 = 1;


    PORTA = 0;
    PORTB = 0;
    TRISA = 0;
    TRISB = 0;

    
    INIT_OUTPUT_PINS;
    INIT_INPUT_PINS;
    // memset(&fault_flags,0,sizeof(fault_flags));
#define FAULT_INIT_VALUE 0
    fault_flags.boostPumpBit = 0;
    fault_flags.lwl_fault = FAULT_INIT_VALUE; //fault state 1
    fault_flags.lwp_fault = FAULT_INIT_VALUE; //fault state 2
    fault_flags.lfp_fault = FAULT_INIT_VALUE; // fault state 3
    fault_flags.po_fault = FAULT_INIT_VALUE; // fault state 4

    fault_flags.wpOkBit = 0;
    fault_flags.mainPumpBit = 0;
    fault_flags.boostPumpBit = 0;
    fault_flags.pumpOverloadBit = 0;
    fault_flags.dumpSolenoidBit = 0;



    GIE = 1;
    state = standbyState;
    zones = 0;
    inIdleDumpHour = 0;




    ser_int();

}

void
resetPump(void) {
    init();
    init_event_timer();
}

/**
 * 2019-01-19 AS
 * The interface box does not send through the master reset, so we are changing 
 * the logic
 * Now we look - if the run signal is low, and we one of the errors is on
 * then we reset
 */
void checkIfShoudReset(void) {

    if (!RUN_SIGNAL_ACTIVE
            && (fault_flags.lwl_fault
            || fault_flags.lwp_fault
            || fault_flags.lfp_fault
            || fault_flags.po_fault)
            ) {
        //printf("resetting pump \r\n");
        resetPump();
    }
}

/*
void debugIfShouldReset(void) {
    if (!RUN_SIGNAL_ACTIVE) {
        printf("run signal false");
    } else {
        printf("run signal true");
    }
    if ((fault_flags.lwl_fault
            || fault_flags.lwp_fault
            || fault_flags.lfp_fault
            || fault_flags.po_fault)
            ) {
        printf("fault true");
    } else {
        printf("fault false");
    }
}*/

void toggleLeds(void) {
    LEDPORT++;
}
void mainserial(void);

void
main(void) {
    char *message;
    char sendGetMessageBuffer[MAX_MESSAGE] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};
    init();
    init_event_timer();
    ser_int();
    printf("waitingxxxx \n\r");
//        while (1) {
//            serial_process_loop();
//            toggleLeds();
//            //printf("z");
//            if (has_data(&inbound)) {
//                char c = pop(&inbound);
//                //puts("got message '");
//                push(&outbound,c );
//                //putch('\'');
//                
//            }
//             process_event_timer();
//            //__delay_ms(1000);
//    
//        }

    unsigned int msg_counter = 0;
    while (1) {
        toggleLeds();
        //printf("z");
        process_event_timer();
#if 1
        if ((message = receiveMessage())) { /* AS 2023-06-20 note: place parentheses around the assignment to silence this warning*/
            //printf("received message %s \r\n",message);
            process_message(message);
        }
#endif
        serial_process_loop();
#if 1
        msg_counter++;
        if (msg_counter >= (1 << 10)) {
            printPumpState();
            printFaultState();
            process_get_status_message(sendGetMessageBuffer);
            //debugIfShouldReset();
            msg_counter = 0;
        }
#endif   

#if 1
        checkIfShoudReset();
        monitor_water_pressure();
        if (!PO_SIGNAL_ACTIVE) {
            clear_callback(EventPODebounce);
        }
        switch (state) {
            case standbyState:
                standby();
                break;
            case shutdownState:
                shutdown();
                break;
            case startpumpInitialState:
                start_pump();
                break;
            case startpumpWaitState:
                start_pump();
                break;
            case startpumpSecondLWPCheckState:
                start_pump();
                break;
            case startmainState:
                start_main();
                break;
            case pumprunState:
                pump_run();
                break;
        }

        if (state == standbyState) {
            if (!timer_events[EventIdleTimeout].active) {
                timer_events[EventIdleTimeout].flag_bit = 0;
                timer_events[EventIdleTimeout].flag_data = 0;
                enable_callback(EventIdleTimeout, IDLE_TIMEOUT);
            }

        } else {
            clear_callback(EventIdleTimeout);
        }

#endif

    }

}
