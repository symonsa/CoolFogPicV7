//#include <stdio.h>
#include "pump_control.h"
#include <string.h>


TIMER_VOLATILE_TYPE timer_event timer_events[EventTotalNumber];
TIMER_VOLATILE_TYPE unsigned char timer_count = 0;
fault_flags_t fault_flags;


#ifdef UNIT_TEST
unit_test_inputs_t unit_test_types = {0, 0, 1, 0, 0};
#endif

void
enable_callback(char callback, int time_delay) {
    if (!timer_events[callback].active) {
        timer_events[callback].time_left = time_delay;
        timer_events[callback].active = true;
    }

}

void
clear_callback(char callback) {
    timer_events[callback].active = false;
}

void
clear_callback_for_shutdown(void) {
    clear_callback(EventLowWaterLevel);
    clear_callback(EventLowWaterPressure);
    clear_callback(EventLowWaterPressureDebounce);
    clear_callback(EventLowFogPressure);
    clear_callback(EventDumpSolenoid);
    clear_callback(EventPODebounce);
    clear_callback(EventRunSignalDebounce);
}

void
init_event_timer(void) {
     memset((void*)&timer_events[0],0,sizeof(timer_events));
#define SET_UP_CALLBACK(cb,n) timer_events[cb].callback = cb##CallBack; timer_events[cb].active=false; // timer_events[cb].name = n;

    SET_UP_CALLBACK(EventLowWaterLevel, "EventLowWaterLevelCallBack");

    SET_UP_CALLBACK(EventLowWaterPressure, "EventLowWaterPressureCallBack");
    SET_UP_CALLBACK(EventLowWaterPressureDebounce, "EventLowWaterPressureCallBack");

    SET_UP_CALLBACK(EventLowFogPressure, "EventLowFogPressureCallBack");
    SET_UP_CALLBACK(EventFaultStateLED, "EventFaultStateLEDCallBack");
    enable_callback(EventFaultStateLED, 1);
    SET_UP_CALLBACK(EventIdleTimeout, "EventIdleTimeoutCallBack");
    SET_UP_CALLBACK(EventDumpSolenoid, "EventDumpSolenoidCallBack");
    SET_UP_CALLBACK(EventPODebounce, "EventPODebounceCallBack");
    SET_UP_CALLBACK(EventBoostPumpPODebounce, "EventBoostPumpPODebounceCallBack")
    SET_UP_CALLBACK(EventRunSignalDebounce, "EventRunSignalDebounceCallBack");
    SET_UP_CALLBACK(EventDumpZone1ForZone0, "EventDumpZone1ForZone0CallBack")
    SET_UP_CALLBACK(EventDumpZone3ForZone2, "EventDumpZone3ForZone2CallBack")
    SET_UP_CALLBACK(EventDumpZone5ForZone4, "EventDumpZone5ForZone4CallBack")
    SET_UP_CALLBACK(EventDumpZone7ForZone6, "EventDumpZone7ForZone6CallBack")

    TMR0IE = 1;

}

#if 1

void __interrupt()
event_timer_isr(void) {
    if ((TMR0IE) && (TMR0IF)) {
        timer_count++;

        TMR0IF = 0;
    }
    usart_interrupt();
}
#endif

/**
 * process_event_timer 
 * If the timer counter has been set by the interrupt routine
 * process each active event
 * repeat until the timer counter is <=0. This is incase we have 
 * been delayed and the interrupt has occured again
 */
void
process_event_timer(void) {
    TMR0IE = 0;
    while (timer_count > 0) {

        timer_count--;


        for (signed char i = 0; i < EventTotalNumber; i++) {
            if (timer_events[i].active) {
                timer_events[i].time_left--;
                // Check if it is time to execute
                if (timer_events[i].time_left == 0) {
                    timer_events[i].active = false;
                    if (timer_events[i].callback) {

                        (*timer_events[i].callback) ();

    }
                }
            }
        }
    }
    TMR0IE = 1;
}
