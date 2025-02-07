
#include "pump_control.h"
void
pump_run (void)
{
  /*
   * pump run:  unit is now in normal active operation.  LFP, LWL, LWP, RUN i/p are monitored.
   *     If LFP goes LO, de-bounce for 3sec if still LO then fault 3 state. - AS 2018-01-29 changed to 15 seconds
   *     If LWL goes hi, de-bounce for 3sec if still hi then Fault 1 state    
   *     If LWP goes hi, de-bounce for 3sec if still hi then fault 2 state.  
   *     need to also monitor run signal
   *     If PO    goes hi, de-bounce for 0.5 sec if still hi then fault 4 state
   *     if RUN goes hi  de-bounce for 0.5 sec if still hi then go to shutdown
   */
   monitor_pump_run();
  
 if (!LOW_FOG_PRESSURE_ACTIVE) {
      clear_callback (EventLowFogPressure);
  } else {    
    if (!timer_events[EventLowFogPressure].active) {
      timer_events[EventLowFogPressure].flag_bit = true;
      timer_events[EventLowFogPressure].flag_data = LFP_DEBOUNCE_TIME; 
      enable_callback (EventLowFogPressure, LFP_DEBOUNCE_TIME);
    }
    
  }

}


/**
* Monitor inputs for both pump run and start main
* these do not monitor the fog inputs as the fog needs to be
* delayed by 30 seconds
*/

void 
monitor_pump_run(void){
    
    
    if (RUN_SIGNAL_ACTIVE) {
      clear_callback (EventRunSignalDebounce);
      
  } else {    
      // if RUN goes hi  de-bounce for 0.5 sec if still hi then go to shutdown
       if (!timer_events[EventRunSignalDebounce].active) {
      timer_events[EventRunSignalDebounce].flag_bit = false;
      timer_events[EventRunSignalDebounce].next_state = shutdownState;
      enable_callback (EventRunSignalDebounce, RUN_SIGNAL_DEBOUNCE_TIME);
    }
    
  }
  
  // If PO    goes hi, de-bounce for 0.5 sec if still hi then fault 4 state
  if (PO_SIGNAL_ACTIVE) {
      // if PO goes hi  de-bounce for 0.5 sec if still hi then go to shutdown
       if (!timer_events[EventPODebounce].active) {
      timer_events[EventPODebounce].flag_bit = false;
      timer_events[EventPODebounce].next_state = shutdownState;
      enable_callback (EventPODebounce, PO_SIGNAL_DEBOUNCE_TIME);
    }
    
  }
  
 

  if (!LOW_WATER_LEVEL_ACTIVE) {
       clear_callback (EventLowWaterLevel);
      fault_flags.lwl_fault = false;
  } else {    
    if (!timer_events[EventLowWaterLevel].active) {
      timer_events[EventLowWaterLevel].flag_bit = true;
      timer_events[EventLowWaterLevel].flag_data = 0;
      enable_callback (EventLowWaterLevel, DEBOUNCE_TIME);
    
    }
  }
  
  if (fault_flags.wpOkBit) {
      clear_callback (EventLowWaterPressure);
  }else {
    if (!timer_events[EventLowWaterPressure].active) {
      timer_events[EventLowWaterPressure].flag_bit = true;
      timer_events[EventLowWaterPressure].next_state = shutdownState;
      enable_callback (EventLowWaterPressure, DEBOUNCE_TIME);
    }
  } 
  
    
}    