#include "pump_control.h"

void
EventFaultStateLEDCallBack(void) {


    /*
     * need to pulse the LEDs. The number of pulses is set by the 
     * fault state.
     * The flag_data will hold low bits number of flashes left
     * the flag_bit bit will hold LED state (on/off)
     */
    if (!(FAULT_EXISTS)) {
        /* no faults - turn LED off */
        FAULT_OUTPUT_SET(0);
        timer_events[EventFaultStateLED].flag_bit = 0;
        timer_events[EventFaultStateLED].flag_data = 0;
        enable_callback(EventFaultStateLED, LED_SHORT_TIME);
    } else {
        /* if LED on, turn off.
         * if off turn on
         * add to the timer again with the short delay or long delay 
         * depending on the number of flashes
         */
        if (timer_events[EventFaultStateLED].flag_bit) {
            /* led was on - turn off */
            FAULT_OUTPUT_SET(0);
            timer_events[EventFaultStateLED].flag_bit = 0;
            /* need to decrement the count if > 0 */
            if (timer_events[EventFaultStateLED].flag_data) {

                enable_callback(EventFaultStateLED, LED_SHORT_TIME);
            } else {
                /*
                 * long delay between pulses 
                 * and reset number of pulses
                 */
                timer_events[EventFaultStateLED].flag_data =
                        fault_flags.generalFaultBit ? 6 :
                         fault_flags.boost_pump_fault ? 5 :
                        fault_flags.po_fault ? 4 :
                        fault_flags.lfp_fault ? 3 :
                        fault_flags.lwp_fault ? 2 :
                        fault_flags.lwl_fault ? 1 :
                        0;

                enable_callback(EventFaultStateLED, LED_LONG_TIME);
            }
        } else {
            /* led was off, turn on */
            FAULT_OUTPUT_SET(1);
            timer_events[EventFaultStateLED].flag_bit = 1;
            if (timer_events[EventFaultStateLED].flag_data) {
                timer_events[EventFaultStateLED].flag_data--;
            }
            enable_callback(EventFaultStateLED, LED_SHORT_TIME);
        }
    }

}
