#ifndef PUMP_CONTROL_H
#define PUMP_CONTROL_H

#include <xc.h>
//#include <string.h>
//#include <stdlib.h>
#include <limits.h>










#define INPUT_ZONES_PORT PORTA
#define INPUT_ZONES_PORT_TRIS TRISA

#define OUTPUT_ZONES_PORT PORTB
#define OUTPUT_ZONES_PORT_TRIS TRISB 

#ifdef _PIC18F4550_H_
#define LOW_WATER_PRESSURE_BIT PORTCbits.RC1	// active hi

#define LOW_WATER_LEVEL_BIT PORTCbits.RC2	// active hi
#define LOW_FOG_PRESSURE_BIT PORTCbits.RC0	// active hi !!!!changed
#define PUMP_OVERLOAD_BIT PORTDbits.RD1	
#define BOOST_PUMP_OVERLOAD_BIT PORTDbits.RD0	
	
	
#define WATER_PRESSURE_OK_BIT PORTDbits.RD7	
#define MAIN_PUMP_BIT PORTEbits.RE0	
#define DUMP_SOLENOID_BIT PORTEbits.RE2	
#define FAULT_OUTPUT_BIT PORTEbits.RE3	
#define BOOST_PUMP_BIT PORTEbits.RE1	
#define ANY_FAULT_OUT_BIT PORTDbits.RD4	
#define TRANSMIT_CONTROL_BIT PORTCbits.RC5	

#define MAIN_PUMP_BIT2 PORTDbits.RD3	
#define BOOST_PUMP_BIT2 PORTDbits.RD2	

	


#define TRIS_LOW_WATER_PRESSURE_BIT TRISCbits.TRISC1

#define TRIS_LOW_WATER_LEVEL_BIT TRISCbits.TRISC2
#define TRIS_LOW_FOG_PRESSURE_BIT TRISCbits.TRISC0
#define TRIS_PUMP_OVERLOAD_BIT TRISDbits.TRISD1
#define TRIS_BOOST_PUMP_OVERLOAD_BIT TRISDbits.TRISD0

#define TRIS_WATER_PRESSURE_OK_BIT TRISDbits.TRISD7
#define TRIS_MAIN_PUMP_BIT TRISEbits.TRISE0
#define TRIS_DUMP_SOLENOID_BIT TRISEbits.TRISE2
#define TRIS_FAULT_OUTPUT_BIT TRISEbits.TRISE3
#define TRIS_BOOST_PUMP_BIT TRISEbits.TRISE1
#define TRIS_ANY_FAULT_OUT_BIT TRISDbits.TRISD4
#define TRIS_TRANSMIT_CONTROL_BIT TRISCbits.TRISC5

#define TRIS_MAIN_PUMP_BIT2 TRISDbits.TRISD3
#define TRIS_BOOST_PUMP_BIT2 TRISDbits.TRISD2

#else

#define LOW_WATER_PRESSURE_BIT PORTCbits.RC1
#define RUN_SIGNAL_BIT PORTbits.
#define LOW_WATER_LEVEL_BIT PORTCbits.RC2
#define LOW_FOG_PRESSURE_BIT PORTCbits.RC0
#define PUMP_OVERLOAD_BIT PORTDbits.RD1
#define BOOST_PUMP_OVERLOAD_BIT PORTDbits.RD0


#define WATER_PRESSURE_OK_BIT PORTDbits.RD7
#define MAIN_PUMP_BIT PORTEbits.RE0
#define DUMP_SOLENOID_BIT PORTEbits.RE2
#define FAULT_OUTPUT_BIT PORTDbits.RD5
#define BOOST_PUMP_BIT PORTEbits.RE1
#define ANY_FAULT_OUT_BIT PORTDbits.RD4
#define TRANSMIT_CONTROL_BIT PORTCbits.RC5

#define MAIN_PUMP_BIT2 PORTDbits.RD3
#define BOOST_PUMP_BIT2 PORTDbits.RD2


#define TRIS_LOW_WATER_PRESSURE_BIT TRISCbits.TRISC1

#define TRIS_LOW_WATER_LEVEL_BIT TRISCbits.TRISC2
#define TRIS_LOW_FOG_PRESSURE_BIT TRISCbits.TRISC0
#define TRIS_PUMP_OVERLOAD_BIT TRISDbits.TRISD1
#define TRIS_BOOST_PUMP_OVERLOAD_BIT TRISDbits.TRISD0

#define TRIS_WATER_PRESSURE_OK_BIT TRISDbits.TRISD7
#define TRIS_MAIN_PUMP_BIT TRISEbits.TRISE0
#define TRIS_DUMP_SOLENOID_BIT TRISEbits.TRISE2
#define TRIS_FAULT_OUTPUT_BIT TRISDbits.TRISD5
#define TRIS_BOOST_PUMP_BIT TRISEbits.TRISE1
#define TRIS_ANY_FAULT_OUT_BIT TRISDbits.TRISD4
#define TRIS_TRANSMIT_CONTROL_BIT TRISCbits.TRISC5

#define TRIS_MAIN_PUMP_BIT2 TRISDbits.TRISD3
#define TRIS_BOOST_PUMP_BIT2 TRISDbits.TRISD2

#endif



#define LOW_WATER_LEVEL_ACTIVE ( LOW_WATER_LEVEL_BIT)
#define LOW_WATER_PRESSURE_ACTIVE (  LOW_WATER_PRESSURE_BIT)
#define RUN_SIGNAL_ACTIVE (  (combinedZones != 0) )
#define LOW_FOG_PRESSURE_ACTIVE ( LOW_FOG_PRESSURE_BIT)
#define PO_SIGNAL_ACTIVE ( (!PUMP_OVERLOAD_BIT) || ( !BOOST_PUMP_OVERLOAD_BIT) )

#define TRIS_INPUT 1
#define TRIS_OUTPUT 0
#define TRIS_INPUT_FULL_PORT 0xff
#define TRIS_OUTPUT_FULL_PORT 0


// port directions: 1=input, 0=output

#define INIT_INPUT_PINS  \
   TRIS_LOW_WATER_PRESSURE_BIT = TRIS_INPUT; \
 TRIS_LOW_WATER_LEVEL_BIT = TRIS_INPUT; \
 TRIS_LOW_FOG_PRESSURE_BIT = TRIS_INPUT; \
 TRIS_PUMP_OVERLOAD_BIT = TRIS_INPUT; \
 TRIS_BOOST_PUMP_OVERLOAD_BIT = TRIS_INPUT; \
 INPUT_ZONES_PORT_TRIS = TRIS_INPUT_FULL_PORT

 
#define INIT_OUTPUT_PINS  FAULT_OUTPUT_SET(0);\
                            WATER_PRESSURE_OK_SET(0);\
                            MAIN_PUMP_SET(0);\
                             BOOST_PUMP_SET(0);\
                           DUMP_SOLENOID_SET(0);\
                            TRANSMIT_CONTROL_SET(0);\
                            ANY_FAULT_SET(0);\
                            OUTPUT_ZONES_PORT_TRIS = TRIS_OUTPUT_FULL_PORT; OUTPUT_ZONES_PORT = 0x00;\
   TRIS_WATER_PRESSURE_OK_BIT = TRIS_OUTPUT; \
 TRIS_MAIN_PUMP_BIT = TRIS_OUTPUT; \
 TRIS_DUMP_SOLENOID_BIT = TRIS_OUTPUT; \
 TRIS_FAULT_OUTPUT_BIT = TRIS_OUTPUT; \
 TRIS_BOOST_PUMP_BIT = TRIS_OUTPUT; \
 TRIS_ANY_FAULT_OUT_BIT = TRIS_OUTPUT; \
 TRIS_TRANSMIT_CONTROL_BIT = TRIS_OUTPUT; \
 TRIS_MAIN_PUMP_BIT2 = TRIS_OUTPUT; \
 TRIS_BOOST_PUMP_BIT2 = TRIS_OUTPUT; 


 





/* outputs */


#define FAULT_OUTPUT_SET(x) { FAULT_OUTPUT_BIT = (x);}
#define WATER_PRESSURE_OK_SET(x) {  WATER_PRESSURE_OK_BIT = (x); fault_flags.wpOkBit = (x);}
#define MAIN_PUMP_SET(x) {  MAIN_PUMP_BIT = (x); MAIN_PUMP_BIT2 = (x); fault_flags.mainPumpBit = (x);}
#define BOOST_PUMP_SET(x) {  BOOST_PUMP_BIT = (x); BOOST_PUMP_BIT2 = (x); fault_flags.boostPumpBit = (x);}
#define DUMP_SOLENOID_SET(x) {  DUMP_SOLENOID_BIT = (x); fault_flags.dumpSolenoidBit = (x);}
#define TRANSMIT_CONTROL_SET(x) {  TRANSMIT_CONTROL_BIT = (x);}
#define ANY_FAULT_SET(x) { ANY_FAULT_OUT_BIT = (x);}
// port directions: 1=input, 0=output




extern char state;
extern char inIdleDumpHour;

typedef enum pump_state_e {
    standbyState,
    shutdownState,
    startpumpInitialState,
    startpumpWaitState,
    startpumpSecondLWPCheckState,
    startmainState,
    pumprunState
} pump_state_e;

typedef enum timer_event_pos {
    EventLowWaterLevel = 0,
    EventLowWaterPressure,
    EventLowWaterPressureDebounce,
    EventLowFogPressure,
    EventFaultStateLED,
    EventIdleTimeout,
    EventDumpSolenoid,
    EventRunSignalDebounce,
    EventPODebounce,
    EventTotalNumber
} timer_event_pos;

typedef struct timer_event {
    int time_left;
    //int data;
    //char * name;
    unsigned active : 1;
    unsigned flag_bit : 1;
    unsigned char next_state;
    unsigned flag_data;


    void (*callback) (void);


} timer_event;


#define TIMER_VOLATILE_TYPE volatile
extern TIMER_VOLATILE_TYPE timer_event timer_events[EventTotalNumber];
extern TIMER_VOLATILE_TYPE unsigned char timer_count;

void init_event_timer(void);

#define false 0
#define true 1

void process_event_timer(void);
void enable_callback(char callback, int time_delay);
void clear_callback(char callback);

typedef union {

    struct {
        unsigned lwl_fault : 1; //fault state 1
        unsigned lwp_fault : 1; //fault state 2
        unsigned lfp_fault : 1; // fault state 3
        unsigned po_fault : 1; // fault state 4

        unsigned wpOkBit : 1;
        unsigned mainPumpBit : 1;
        unsigned boostPumpBit : 1;
        unsigned UNUSED_pumpOverloadBit : 1;
        unsigned dumpSolenoidBit : 1;


    };
    unsigned int value;
} fault_flags_t;

extern fault_flags_t fault_flags;

#define FAULT_EXISTS ( fault_flags.lwl_fault || fault_flags.lwp_fault || fault_flags.lfp_fault || fault_flags.po_fault)

extern unsigned char combinedZones; // the or of below
extern unsigned char commsZones; // coming in from comms
#define manualZones INPUT_ZONES_PORT // additional from manual switches 
#define outputZones OUTPUT_ZONES_PORT // output the combined zones

void combineZones(void);
void shutdown(void);
#ifdef _PIC18F4550_H_
#define _XTAL_FREQ 8000000
#else
#define _XTAL_FREQ 4000000
#endif
#define TIME_PULSE_PER_SEC (_XTAL_FREQ/256/4/256)

#define LWL_FINAL_WAIT (30*TIME_PULSE_PER_SEC)
#define LWP_WAIT_TIME (30*TIME_PULSE_PER_SEC)
#define LFP_WAIT_TIME (30*TIME_PULSE_PER_SEC)
#define LFP_DEBOUNCE_TIME (15*TIME_PULSE_PER_SEC)
#define LED_SHORT_TIME (TIME_PULSE_PER_SEC/4)
#define LED_LONG_TIME (TIME_PULSE_PER_SEC*1)
#define DEBOUNCE_TIME (3*TIME_PULSE_PER_SEC)
//#define IDLE_TIMEOUT (60*60*TIME_PULSE_PER_SEC)
#define IDLE_TIMEOUT (SHRT_MAX)

#define RUN_SIGNAL_DEBOUNCE_TIME (TIME_PULSE_PER_SEC/2)
#define PO_SIGNAL_DEBOUNCE_TIME (TIME_PULSE_PER_SEC/2)

#define DUMP_SOLENOID_ON_TIME (2*TIME_PULSE_PER_SEC)


#define bitset(var, bitno) ((var) |= 1UL << (bitno))
#define bitclr(var, bitno) ((var) &= ~(1UL << (bitno)))

#define MAX_MESSAGE 10
#define frameStart '{'
#define frameEnd '}'

char *receiveMessage(void);
void putch(char c);
int puts(const char * str);
void usart_interrupt(void);
char getch_timeout(void);
char getch(void);
void process_message(char *message);
void output_message(char *message);

void shutdown(void);
void start_main(void);
void pump_run(void);
void standby(void);
void start_pump(void);
void resetPump(void);

void EventLowWaterLevelCallBack(void);
void EventLowWaterPressureCallBack(void);
void EventLowWaterPressureDebounceCallBack(void);
void EventLowFogPressureCallBack(void);
void EventFaultStateLEDCallBack(void);
void EventDumpSolenoidCallBack(void);
void EventIdleTimeoutCallBack(void);
void EventRunSignalDebounceCallBack(void);
void EventPODebounceCallBack(void);

void monitor_water_pressure(void);
void monitor_pump_run(void);


void clear_callback_for_shutdown(void);

void process_get_status_message(char * inmessage);

#endif
