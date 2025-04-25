#include "pump_control.h"
void
EventGeneralFaultDebounceCallBack (void)
{
  /*
   * If PO    goes hi, de-bounce for 0.5 sec if still hi then fault 4 state
   */
   
    state = timer_events[EventGeneralFaultDebounce].next_state;
    fault_flags.generalFaultBit = 1;
    if (shutdownState == state) {

        clear_callback_for_shutdown();
    }
     
}

