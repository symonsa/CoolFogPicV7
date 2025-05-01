#include "pump_control.h"
void
standby (void)
{
  // Standby:   
//  WP & WL & RUN are monitored, 
//		 if  WP i/p is lo [ok]	-	 then WP o/p is set hi (on)  
//		 if  WP i/p is hi [not ok]-	 then WP o/p is set lo (off)
// if WL i/p is lo - no action. 
//		 if WL i/p is hi –Fault 1 state
//                      ALL other o/p’s are lo.  
//




    
  



  //   if LWL is OK [lo] no action. 
  //   2/If LWL goes hi then Fault 1 state see below for fault states, 
  if (!LOW_WATER_LEVEL_ACTIVE) {
    // LWL is ok
    // reset states and callback
    clear_callback (EventLowWaterLevel);
    fault_flags.lwl_fault = 0;
  }
  else {
    fault_flags.lwl_fault = 1;
    enable_callback (EventLowWaterLevel, LWL_FINAL_WAIT);

  }

  //   ALL other o/p's are lo.  This is normal standby status.
  MAIN_PUMP_SET (0);

  BOOST_PUMP_SET (0);
  if (!inIdleDumpHour){
     DUMP_SOLENOID_SET (0);
  }  

  //   If RUN is non-active [hi] no action 

  //   3/If RUN goes lo then start pump.
  //		3/If RUN goes lo then start pump sequence as follows. 
  if (RUN_SIGNAL_ACTIVE && !FAULT_EXISTS) {
    disableZonesDueToFault = false;
    state = startpumpInitialState;
    inIdleDumpHour = 0;
     DUMP_SOLENOID_SET (0);

  }


}
