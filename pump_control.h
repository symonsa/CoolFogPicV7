#ifndef PUMP_CONTROL_H
#define PUMP_CONTROL_H

#include <xc.h>
//#include <string.h>
//#include <stdlib.h>
#include <limits.h>










#define INPUT_ZONES_PORT PORTB
#define INPUT_ZONES_PORT_TRIS TRISB

#define OUTPUT_ZONES_PORT PORTA
#define OUTPUT_ZONES_PORT_BITS PORTAbits
#define OUTPUT_ZONES_PORT_TRIS TRISA


#define LOW_WATER_PRESSURE_BIT PORTCbits.RC1
#define RUN_SIGNAL_BIT PORTbits.
#define LOW_WATER_LEVEL_BIT PORTCbits.RC2
#define LOW_FOG_PRESSURE_BIT PORTCbits.RC0
#define PUMP_OVERLOAD_BIT PORTDbits.RD1
#define BOOST_PUMP_OVERLOAD_BIT PORTDbits.RD0
//After further testing, we will need to add a new fault code ?Output Fault? Light 3Sec on, 1Sec off. When shorted (simulating a coil failure) heat skyrockets.
#define GENERAL_FAULT_BIT PORTDbits.RD6


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
#define TRIS_GENERAL_FAULT_BIT TRISDbits.TRISD6

#define TRIS_WATER_PRESSURE_OK_BIT TRISDbits.TRISD7
#define TRIS_MAIN_PUMP_BIT TRISEbits.TRISE0
#define TRIS_DUMP_SOLENOID_BIT TRISEbits.TRISE2
#define TRIS_FAULT_OUTPUT_BIT TRISDbits.TRISD5
#define TRIS_BOOST_PUMP_BIT TRISEbits.TRISE1
#define TRIS_ANY_FAULT_OUT_BIT TRISDbits.TRISD4
#if defined _18F4550
#define TRIS_TRANSMIT_CONTROL_BIT TRISDbits.TRISD4 // hack
#else
#define TRIS_TRANSMIT_CONTROL_BIT TRISCbits.TRISC5
#endif

#define TRIS_MAIN_PUMP_BIT2 TRISDbits.TRISD3
#define TRIS_BOOST_PUMP_BIT2 TRISDbits.TRISD2




#define LOW_WATER_LEVEL_ACTIVE ( LOW_WATER_LEVEL_BIT)
#define LOW_WATER_PRESSURE_ACTIVE (  LOW_WATER_PRESSURE_BIT)
#define RUN_SIGNAL_ACTIVE (  (shouldRun != 0) )
#define LOW_FOG_PRESSURE_ACTIVE ( LOW_FOG_PRESSURE_BIT)
#define PO_SIGNAL_ACTIVE ( !(PUMP_OVERLOAD_BIT) )
#define BOOST_PUMP_PO_SIGNAL_ACTIVE (!(BOOST_PUMP_OVERLOAD_BIT))
#define GENERAL_FAULT_SIGNAL_ACTIVE (!(GENERAL_FAULT_BIT))

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
 TRIS_GENERAL_FAULT_BIT = TRIS_INPUT; \
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





extern char inIdleDumpHour;

typedef enum dump_mode_e {
    normal, /* 8 zones */
    oneZoneOneDump, /*zone 1 dump, zone 0 on */
    twoZonesTwoDump, /*zone 3 for zone 2*/
    threeZonesThreeDump, /* zone 5 for zone 4*/
    fourZonesFourDump /*zone 7 for zone 6*/
} dump_mode_e;
extern dump_mode_e dump_mode;

extern unsigned char dumpZones;
#define ZONE7_BITMASK (0b10000000)
#define ZONE6_BITMASK (0b01000000)
#define ZONE5_BITMASK (0b00100000)
#define ZONE4_BITMASK (0b00010000)
#define ZONE3_BITMASK (0b00001000)
#define ZONE2_BITMASK (0b00000100)
#define ZONE1_BITMASK (0b00000010)
#define ZONE0_BITMASK (0b00000001)

#define EventDumpZone1ForZone0_SET dumpZones|=ZONE1_BITMASK
#define EventDumpZone1ForZone0_CLEAR dumpZones &= (~ZONE1_BITMASK)

#define EventDumpZone3ForZone2_SET dumpZones|=ZONE3_BITMASK
#define EventDumpZone3ForZone2_CLEAR dumpZones &= (~ZONE3_BITMASK)

#define EventDumpZone5ForZone4_SET dumpZones|=ZONE5_BITMASK
#define EventDumpZone5ForZone4_CLEAR dumpZones &= (~ZONE5_BITMASK)

#define EventDumpZone7ForZone6_SET dumpZones|=ZONE7_BITMASK
#define EventDumpZone7ForZone6_CLEAR dumpZones &= (~ZONE7_BITMASK)

typedef enum pump_state_e {
    standbyState,
    shutdownState,
    startpumpInitialState,
    startpumpWaitState,
    startpumpSecondLWPCheckState,
    startmainState,
    pumprunState
} pump_state_e;
extern pump_state_e state;

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
    EventBoostPumpPODebounce,
    EventGeneralFaultDebounce,
    EventDumpZone1ForZone0,
    EventDumpZone3ForZone2,
    EventDumpZone5ForZone4,
    EventDumpZone7ForZone6,

    EventTotalNumber
} timer_event_pos;

typedef struct timer_event {
    int time_left;
    //int data;
    //char * name;
     unsigned flag_data;
    unsigned char active ;
    unsigned char flag_bit ;
    unsigned char next_state ;
   

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
        unsigned boost_pump_fault : 1;

        unsigned dumpSolenoidBit : 1;
        unsigned overrideBit : 1;
        unsigned generalFaultBit:1;


    };
    unsigned int value;
} fault_flags_t;

extern fault_flags_t fault_flags;

#define FAULT_EXISTS ( fault_flags.lwl_fault || fault_flags.lwp_fault || fault_flags.lfp_fault || fault_flags.po_fault || fault_flags.boost_pump_fault ||fault_flags.generalFaultBit )

extern unsigned char combinedZones; // the or of below
extern unsigned char commsZones; // coming in from comms
extern unsigned char shouldRun;// mask the combined zones and dump mode to determine if the pump should be on
#define manualZones INPUT_ZONES_PORT // additional from manual switches 
#define outputZones OUTPUT_ZONES_PORT // output the combined zones

void combineZones(void);
void shutdown(void);
#ifdef _PIC18F4550_H_
#define _XTAL_FREQ 8000000
#elif defined _18F4523
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

#define MAX_MESSAGE 13 // additional buffer if we need to dup the ending
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
void EventBoostPumpPODebounceCallBack(void);
void EventGeneralFaultDebounceCallBack(void);

void EventDumpZone1ForZone0CallBack(void);
void EventDumpZone3ForZone2CallBack(void);
void EventDumpZone5ForZone4CallBack(void);
void EventDumpZone7ForZone6CallBack(void);
void determineIfTurnOnDump(unsigned char previousZones, unsigned char currentZones);
void determinIfPumpShouldRun(void);

void monitor_water_pressure(void);
void monitor_pump_run(void);


void clear_callback_for_shutdown(void);

void process_get_status_message(char * inmessage);

#endif
