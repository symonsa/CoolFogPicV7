#include "pump_control.h"

void 
monitor_water_pressure(void){
    //1/ The WP o/p should always be the inverse of the WP i/p
 //2/ If WP i/p changes state - de-bounce for 2 -3 secs before setting WP o/p 

  if (LOW_WATER_PRESSURE_ACTIVE == fault_flags.wpOkBit){
      /*
      * As LWP and WP are inverse, if they are the same then enable the debounce callback
      */
       timer_events[EventLowWaterPressureDebounce].flag_bit = 0;
    //timer_events[EventLowWaterPressureDebounce].next_state = standbyState;
    enable_callback (EventLowWaterPressureDebounce, DEBOUNCE_TIME);
  }  else{
    // still the same, clear the callback
    clear_callback(EventLowWaterPressureDebounce);
  }  
    
}

    