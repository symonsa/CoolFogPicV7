#include "pump_control.h"

void
shutdown (void)
{
  /*
   * shutdown:  when  RUN goes hi (pump off)  or faults call for shutdown, then
   *    1/ set main & booster pump o/p lo (off)
   *    2/ 1 second delay
   *    3/ set dump solenoid o/p [RB3] hi for time set by the hex switch on i/p RB4-7
   *    4/ set dump sol o/p lo
   *    5/ now back in standby mode.
   */
  MAIN_PUMP_SET (0);
  BOOST_PUMP_SET (0);
  DUMP_SOLENOID_SET (1);



  enable_callback (EventDumpSolenoid, DUMP_SOLENOID_ON_TIME);


}

