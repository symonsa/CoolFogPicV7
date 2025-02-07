#include "pump_control.h"

void
EventLowWaterLevelCallBack(void) {
    /*
     * Fault 1 state;=    LWL fault. Pulse fault o/p hi, 1 x pulse then off for 1 sec - repeat
     *    If on for 30 sec, then pump shutdown
     *    Reset as soon as LWL is lo (OK)
     */
    if (!fault_flags.lwl_fault) {
        /*
         * was not in fault state. Set fault state, then wait for 30 seconds
         */
        fault_flags.lwl_fault = true;
        enable_callback(EventLowWaterLevel, LWL_FINAL_WAIT);
    } else {
        /*
         * still in fault state after timeout, so shutdown
         */
        if (state != standbyState) {
            state = shutdownState;

            clear_callback_for_shutdown();
        }
    }
}


