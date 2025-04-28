#include "pump_control.h"
dump_mode_e dump_mode = normal;
dump_time_e dump_time = twoSeconds;
unsigned char dumpZones = 0;
unsigned char shouldRun = 0;

void enableDumpWaitCallback(timer_event_pos evnt){
    timer_events[evnt].flag_bit = 0; 
    enable_callback(evnt, DUMP_SOLENOID_WAIT_TIME);
}
void enableDumpOnCallback(timer_event_pos evnt){
    timer_events[evnt].flag_bit = 1; 
    enable_callback(evnt, getDumpOnTime());
}


void
EventDumpSolenoidCallBack(void) {
    timer_event_pos evnt = EventDumpSolenoid;
    if (timer_events[evnt].flag_bit) {
        DUMP_SOLENOID_SET(0);
        state = standbyState;
    } else {
        DUMP_SOLENOID_SET(1);
        enableDumpOnCallback(evnt);
     
    }

}

void EventDumpZone1ForZone0CallBack(void) {
    timer_event_pos evnt = EventDumpZone1ForZone0;
    if (timer_events[evnt].flag_bit) {
        EventDumpZone1ForZone0_CLEAR;
    } else {
        EventDumpZone1ForZone0_SET;
        enableDumpOnCallback(evnt);
    }
}

void EventDumpZone3ForZone2CallBack(void) {
    timer_event_pos evnt = EventDumpZone3ForZone2;
    if (timer_events[evnt].flag_bit) {
        EventDumpZone3ForZone2_CLEAR;
    } else {
        EventDumpZone3ForZone2_SET;
        enableDumpOnCallback(evnt);
    }

}

void EventDumpZone5ForZone4CallBack(void) {
    timer_event_pos evnt = EventDumpZone5ForZone4;
    if (timer_events[evnt].flag_bit) {
        EventDumpZone5ForZone4_CLEAR;
    } else {
        EventDumpZone5ForZone4_SET;
        enableDumpOnCallback(evnt);
    }

}

void EventDumpZone7ForZone6CallBack(void) {
    timer_event_pos evnt = EventDumpZone7ForZone6;
    if (timer_events[evnt].flag_bit) {
        EventDumpZone7ForZone6_CLEAR;
    } else {
        EventDumpZone7ForZone6_SET;
        enableDumpOnCallback(evnt);
    }

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

    determinIfPumpShouldRun();
    if (previousZones == currentZones) {
        // nothing has changed
        return;
    }

    switch (dump_mode) {
        case fourZonesFourDump /*zone 7 for zone 6*/:
            if (BIT_N_CHANGED_OFF(6)) {
                enableDumpWaitCallback(EventDumpZone7ForZone6);
            }
        case threeZonesThreeDump /* zone 5 for zone 4*/:
            if (BIT_N_CHANGED_OFF(4)) {
                enableDumpWaitCallback(EventDumpZone5ForZone4);
            }

        case twoZonesTwoDump /*zone 3 for zone 2*/:
            if (BIT_N_CHANGED_OFF(2)) {
                enableDumpWaitCallback(EventDumpZone3ForZone2);
            }
        case oneZoneOneDump /*zone 1 dump, zone 0 on */:
            if (BIT_N_CHANGED_OFF(0)) {
                enableDumpWaitCallback(EventDumpZone1ForZone0);
            }
        case normal /* 8 zones */:




            break;
    }




}
#define BITMASK_4ZONE_DUMP (0b01111111)
#define BITMASK_3ZONE_DUMP (0b11011111)
#define BITMASK_2ZONE_DUMP (0b11110111)
#define BITMASK_1ZONE_DUMP (0b11111101)

void
determinIfPumpShouldRun(void) {
    unsigned char maskedZones = combinedZones;

    // use fall through
    switch (dump_mode) {
        case fourZonesFourDump /*zone 7 for zone 6*/:
            maskedZones &= BITMASK_4ZONE_DUMP;

        case threeZonesThreeDump /* zone 5 for zone 4*/:
            maskedZones &= BITMASK_3ZONE_DUMP;

        case twoZonesTwoDump /*zone 3 for zone 2*/:
            maskedZones &= BITMASK_3ZONE_DUMP;

        case oneZoneOneDump /*zone 1 dump, zone 0 on */:
            maskedZones &= BITMASK_2ZONE_DUMP;

        case normal /* 8 zones */:
            // nothing
            break;
    }
    shouldRun = maskedZones;

}

unsigned int getDumpOnTime(void) {
    switch (dump_time) {
        case twoSeconds:
            return TWO_SECONDS;
        case fiveSeconds:
            return FIVE_SECONDS;
        case tenSeconds:
            return TEN_SECONDS;
        case twentySeconds:
            return TWENTY_SECONDS;
    }
    return TWO_SECONDS;
}
