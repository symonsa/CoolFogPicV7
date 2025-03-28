#include "pump_control.h"
void
EventBoostPumpPODebounceCallBack (void)
{
  /*
   * If PO    goes hi, de-bounce for 0.5 sec if still hi then fault 4 state
   */
   
    state = timer_events[EventBoostPumpPODebounce].next_state;
    fault_flags.boost_pump_fault = 1;
    if (shutdownState == state) {

        clear_callback_for_shutdown();
    }
     
}

