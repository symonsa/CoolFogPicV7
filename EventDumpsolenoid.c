#include "pump_control.h"
dump_mode_e dump_mode = normal;
 unsigned char dumpZones=0;

void
EventDumpSolenoidCallBack(void) {
    DUMP_SOLENOID_SET(0);

    state = standbyState;
}

void EventDumpZone1ForZone0CallBack(void) {
    EventDumpZone1ForZone0_CLEAR;
}

void EventDumpZone3ForZone2CallBack(void) {
    EventDumpZone3ForZone2_CLEAR;
}

void EventDumpZone5ForZone4CallBack(void) {
    EventDumpZone5ForZone4_CLEAR;
}

void EventDumpZone7ForZone6CallBack(void) {
    EventDumpZone7ForZone6_CLEAR;
}

/**
 * go through the modes
 * If the previous zone position was on, and now off, then 
 * set the dump as per mode
 * 
 * Go through the modes in reverse order as 3 is a subset of 4 etc
 * @param previousZones
 * @param currentZones
 */
void
determineIfTurnOnDump(unsigned char previousZones, unsigned char currentZones) {
#define BIT_MASK(n) ( 1<< (n))
#define BIT_N_CHANGED_OFF(n) ( (previousZones & BIT_MASK(n)) &&  (!((currentZones) & BIT_MASK(n)) ))

    if (previousZones ==currentZones ){
        // nothing has changed
        return;
    }

    switch (dump_mode) {
        case fourZonesFourDump /*zone 7 for zone 6*/:
            if (BIT_N_CHANGED_OFF(6)) {
                EventDumpZone7ForZone6_SET;
                enable_callback(EventDumpZone7ForZone6, DUMP_SOLENOID_ON_TIME);
            }
        case threeZonesThreeDump /* zone 5 for zone 4*/:
            if (BIT_N_CHANGED_OFF(4)) {
                EventDumpZone5ForZone4_SET;
                enable_callback(EventDumpZone5ForZone4, DUMP_SOLENOID_ON_TIME);
            }

        case twoZonesTwoDump /*zone 3 for zone 2*/:
            if (BIT_N_CHANGED_OFF(2)) {
                EventDumpZone3ForZone2_SET;
                enable_callback(EventDumpZone3ForZone2, DUMP_SOLENOID_ON_TIME);

            }
        case oneZoneOneDump /*zone 1 dump, zone 0 on */:
            if (BIT_N_CHANGED_OFF(0)) {
                EventDumpZone1ForZone0_SET;
                enable_callback(EventDumpZone1ForZone0, DUMP_SOLENOID_ON_TIME);
            }
        case normal /* 8 zones */:




            break;
    }




}
