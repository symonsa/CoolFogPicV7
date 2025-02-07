#include "pump_control.h"

void
EventLowWaterPressureCallBack(void) {
    /*
     * flag_bit indicates if we are to go to fault state or not
     * not if we are in standby
     * Fault 2 state:=    LWP fault. Pulse fault o/p hi, 2 x pulse then off for 1 sec - repeat
     *    Pump shutdown
     *    Check LWP & reflect at WP-OK
     *    Reset @ pwr up only
     *
     *
     * event data flag sets the next state
     */
    WATER_PRESSURE_OK_SET(!LOW_WATER_PRESSURE_ACTIVE);

    if (timer_events[EventLowWaterPressure].flag_bit) {

        fault_flags.lwp_fault = true;

    }
    state = timer_events[EventLowWaterPressure].next_state;
	if (shutdownState == state) {

        clear_callback_for_shutdown();
    }

}

void
EventLowWaterPressureDebounceCallBack(void) {
    /*
     * flag_bit indicates if we are to go to fault state or not
     * not if we are in standby
     * Fault 2 state:=    LWP fault. Pulse fault o/p hi, 2 x pulse then off for 1 sec - repeat
     *    Pump shutdown
     *    Check LWP & reflect at WP-OK
     *    Reset @ pwr up only
     *
     *
     * event data flag sets the next state
     */
    WATER_PRESSURE_OK_SET(!LOW_WATER_PRESSURE_ACTIVE);
    



}
