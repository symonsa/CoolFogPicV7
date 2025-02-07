#include "pump_control.h"
void
EventDumpSolenoidCallBack (void)
{
  DUMP_SOLENOID_SET (0);

  state = standbyState;
}
