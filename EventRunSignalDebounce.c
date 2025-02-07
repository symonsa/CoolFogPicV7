#include "pump_control.h"

void
EventRunSignalDebounceCallBack(void) {
    /*
     * if RUN goes hi  de-bounce for 0.5 sec if still hi then go to shutdown
     */

    state = timer_events[EventRunSignalDebounce].next_state;
    if (shutdownState == state) {

        clear_callback_for_shutdown();
    }

}
