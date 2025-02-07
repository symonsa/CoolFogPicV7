#ifndef PUMP_CONTROL_H
#define PUMP_CONTROL_H

#include <xc.h>
//#include <string.h>
//#include <stdlib.h>
#include <limits.h>




#define LEDPORT PORTD





#define LOW_WATER_PRESSURE_BIT PORTBbits.RB2	// active hi
#define RUN_SIGNAL_BIT PORTBbits.RB3	// active lo
#define LOW_WATER_LEVEL_BIT PORTAbits.RA4	// active hi
#define LOW_FOG_PRESSURE_BIT PORTAbits.RA5	// active hi !!!!changed
#define PUMP_OVERLOAD_BIT PORTBbits.RB4	

#define WATER_PRESSURE_OK_BIT PORTAbits.RA0	
#define MAIN_PUMP_BIT PORTAbits.RA1	
#define DUMP_SOLENOID_BIT PORTAbits.RA2	
#define FAULT_OUTPUT_BIT PORTAbits.RA3	
#define BOOST_PUMP_BIT PORTBbits.RB5	

#define TRANSMIT_CONTROL_BIT PORTBbits.RB0	



#define TRIS_LOW_WATER_PRESSURE_BIT TRISBbits.RB2
#define TRIS_RUN_SIGNAL_BIT TRISBbits.RB3
#define TRIS_LOW_WATER_LEVEL_BIT TRISAbits.RA4
#define TRIS_LOW_FOG_PRESSURE_BIT TRISAbits.RA5
#define TRIS_PUMP_OVERLOAD_BIT TRISBbits.RB4

#define TRIS_WATER_PRESSURE_OK_BIT TRISAbits.RA0
#define TRIS_MAIN_PUMP_BIT TRISAbits.RA1
#define TRIS_DUMP_SOLENOID_BIT TRISAbits.RA2
#define TRIS_FAULT_OUTPUT_BIT TRISAbits.RA3
#define TRIS_BOOST_PUMP_BIT TRISBbits.RB5

#define TRIS_TRANSMIT_CONTROL_BIT TRISBbits.RB0






#define LOW_WATER_LEVEL_ACTIVE ( LOW_WATER_LEVEL_BIT)
#define LOW_WATER_PRESSURE_ACTIVE (  LOW_WATER_PRESSURE_BIT)
#define RUN_SIGNAL_ACTIVE ( (!RUN_SIGNAL_BIT) || (zones != 0) )
#define LOW_FOG_PRESSURE_ACTIVE ( LOW_FOG_PRESSURE_BIT)
#define PO_SIGNAL_ACTIVE ( !PUMP_OVERLOAD_BIT)

#define TRIS_INPUT 1
#define TRIS_OUTPUT 0


// port directions: 1=input, 0=output

#define INIT_INPUT_PINS  \
 TRIS_LOW_WATER_PRESSURE_BIT = TRIS_INPUT; \
 TRIS_RUN_SIGNAL_BIT = TRIS_INPUT; \
 TRIS_LOW_WATER_LEVEL_BIT = TRIS_INPUT; \
 TRIS_LOW_FOG_PRESSURE_BIT = TRIS_INPUT; \
 TRIS_PUMP_OVERLOAD_BIT = TRIS_INPUT; 
 

#define INIT_OUTPUT_PINS  FAULT_OUTPUT_SET(0);\
                            WATER_PRESSURE_OK_SET(0);\
                            MAIN_PUMP_SET(0);\
                             BOOST_PUMP_SET(0);\
                           DUMP_SOLENOID_SET(0);\
                            TRANSMIT_CONTROL_SET(0);\
                            TRISD = 0; LEDPORT = 0x00;\
 TRIS_WATER_PRESSURE_OK_BIT = TRIS_OUTPUT; \
 TRIS_MAIN_PUMP_BIT = TRIS_OUTPUT; \
 TRIS_DUMP_SOLENOID_BIT = TRIS_OUTPUT; \
 TRIS_FAULT_OUTPUT_BIT = TRIS_OUTPUT; \
 TRIS_BOOST_PUMP_BIT = TRIS_OUTPUT; \
 TRIS_TRANSMIT_CONTROL_BIT = TRIS_OUTPUT; 
 






/* outputs */


#define FAULT_OUTPUT_SET(x) { FAULT_OUTPUT_BIT = (x);}
#define WATER_PRESSURE_OK_SET(x) {  WATER_PRESSURE_OK_BIT = (x); fault_flags.wpOkBit = (x);}
#define MAIN_PUMP_SET(x) {  MAIN_PUMP_BIT = (x); fault_flags.mainPumpBit = (x);}
#define BOOST_PUMP_SET(x) {  BOOST_PUMP_BIT = (x); fault_flags.boostPumpBit = (x);}
#define DUMP_SOLENOID_SET(x) {  DUMP_SOLENOID_BIT = (x); fault_flags.dumpSolenoidBit = (x);}
#define TRANSMIT_CONTROL_SET(x) {  TRANSMIT_CONTROL_BIT = (x);}
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
        unsigned pumpOverloadBit : 1;
        unsigned dumpSolenoidBit : 1;


    };
    unsigned int value;
} fault_flags_t;

extern fault_flags_t fault_flags;

extern unsigned int zones;

void shutdown(void);
#define _XTAL_FREQ 8000000
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
