#include "pump_control.h"

void
start_main(void) {
    /* 
     * 10 / set main pump o/p [RB1] hi
     * 11/ with main pump on, monitor LWL & LWP but wait 30sec before checking LFP
     * De-bounce for 3 sec if still LO [not OK] then, fault 3 state. 
     * See below for fault states  
     * BUT if LFP = HI [OK] then run pump~ .  
     */
    BOOST_PUMP_SET(1);
    MAIN_PUMP_SET(1);
    monitor_pump_run();

    if (!LOW_FOG_PRESSURE_ACTIVE) {
        clear_callback(EventLowFogPressure);
        state = pumprunState;
    } else {
        if (!timer_events[EventLowFogPressure].active) {
            timer_events[EventLowFogPressure].flag_bit = false;
            timer_events[EventLowFogPressure].flag_data = DEBOUNCE_TIME;
            enable_callback(EventLowFogPressure, LFP_WAIT_TIME);
        }
    }

}

