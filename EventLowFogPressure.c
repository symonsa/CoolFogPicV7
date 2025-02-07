#include "pump_control.h"
//#include <string.h>
void
EventLowFogPressureCallBack(void) {
    /*
     * Fault 3 state: =  LFP fault. Pulse fault o/p hi, 3 x pulse then off for 1 sec - repeat 
     *   Pump shutdown
     *   Reset @ pwr up only
     *
     * 
     * event data flag sets the time in seconds 
     * if we need to de bounce again
     */

    if (timer_events[EventLowFogPressure].flag_data) {
    enable_callback (EventLowFogPressure, timer_events[EventLowFogPressure].flag_data);
        timer_events[EventLowFogPressure].flag_data = 0;
        timer_events[EventLowFogPressure].flag_bit = true;
  }
  else {
        fault_flags.lfp_fault = true;
        state = shutdownState;
        clear_callback_for_shutdown();
    }

}

