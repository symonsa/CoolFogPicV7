#include "pump_control.h"
void
start_pump ()
{
  // if run is on (lo)

  //1/ check LWL. if hi = Fault 1 state &  wait : but if lo(OK) then
  if (LOW_WATER_LEVEL_ACTIVE) {
    fault_flags.lwl_fault = true;
    enable_callback (EventLowWaterLevel, LWL_FINAL_WAIT);
    return;
  }


  // set boost pump on 
  if (state != startpumpWaitState) {
    BOOST_PUMP_SET (1);
  }

  if (!RUN_SIGNAL_ACTIVE) {

    //3/ check RUN if hi[off] then shutdown, 
    state = shutdownState;
     clear_callback_for_shutdown();
    return;
  }
  else {

    /*
     * if lo[run] then  (startpumpInitialState)
     * 4 check LWP if hi [go back to 3/, if LWP remains hi [not OK] for 30 secs 
     * 5          Turn boost pump OFF
     * 6          Then wait 30sec - (startpumpWaitState)
     *              Checking LWP and LWL & LWL fault state if error,
     *              but will not activate LWP fault state 2 @ this time.
     * 7          set boost pump ON (startpumpSecondLWPCheckState)
     * 8          check RUN if hi[off] then shutdown if lo[run] then  
     * 9          check LWP if hi [go back to 8/; if LWP remains hi [not OK] for 30 secs then fault 2 state.
     */

    if (!fault_flags.wpOkBit) {
      if (state == startpumpInitialState) {
	/*
	 * in initial state. Wait 30 seconds then need to go to wait state
	 */
	timer_events[EventLowWaterPressure].flag_bit = false;
	timer_events[EventLowWaterPressure].next_state = startpumpWaitState;
	enable_callback (EventLowWaterPressure, LWP_WAIT_TIME);

	return;
      }
      if (state == startpumpWaitState) {
	/*
	 * set boost off, wait for 30 sec, then go to second check state
	 */
	BOOST_PUMP_SET (0);

	timer_events[EventLowWaterPressure].flag_bit = false;
	timer_events[EventLowWaterPressure].next_state = startpumpSecondLWPCheckState;
	enable_callback (EventLowWaterPressure, LWP_WAIT_TIME);

	return;
      }
      if (state == startpumpSecondLWPCheckState) {
	/*
	 * set boost on, wait for 30 sec, then go to shutdown
	 */
	BOOST_PUMP_SET (1);

	timer_events[EventLowWaterPressure].flag_bit = true;
	timer_events[EventLowWaterPressure].next_state = shutdownState;
	enable_callback (EventLowWaterPressure, LWP_WAIT_TIME);

	return;
      }

    }
    else {
      clear_callback (EventLowWaterPressure);
    }

    //BUT if LWP is lo[OK] then Start-Main
    state = startmainState;

  }

}

