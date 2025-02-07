#include "pump_control.h"

char inIdleDumpHour = 0;
void
EventIdleTimeoutCallBack (void)
{
  if (!timer_events[EventIdleTimeout].flag_bit) {
    /* 
     * we have been idle for an hour, so turn on dump
     */
    DUMP_SOLENOID_SET (1);
    inIdleDumpHour = 1;

    /* 
     * now let this run for an hour
     */
    timer_events[EventIdleTimeout].flag_bit = 1;
    timer_events[EventIdleTimeout].flag_data = 0;
    enable_callback (EventIdleTimeout, IDLE_TIMEOUT);

  }
  else {
    /*
     * close the solenoid
     */
    DUMP_SOLENOID_SET (0);
    inIdleDumpHour = 0;
    // keep the timer running as it will be reset in standby
    // but ensure we don't turn on again
    timer_events[EventIdleTimeout].flag_bit = 1;
    timer_events[EventIdleTimeout].flag_data = 0;
    enable_callback (EventIdleTimeout, IDLE_TIMEOUT);

  }
}

