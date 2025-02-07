#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=EventDumpsolenoid.c EventFaultStateLed.c EventIdleTimeout.c EventLowFogPressure.c EventLowWaterLevel.c EventLowWaterPressure.c EventPODebounce.c EventRunSignalDebounce.c MonitorWaterPressure.c pump_control.c pump_run.c serial.c serial_buffer.c serial_message.c shutdown_state.c standby_state.c start_main.c start_pump_state.c timer_event.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/EventDumpsolenoid.p1 ${OBJECTDIR}/EventFaultStateLed.p1 ${OBJECTDIR}/EventIdleTimeout.p1 ${OBJECTDIR}/EventLowFogPressure.p1 ${OBJECTDIR}/EventLowWaterLevel.p1 ${OBJECTDIR}/EventLowWaterPressure.p1 ${OBJECTDIR}/EventPODebounce.p1 ${OBJECTDIR}/EventRunSignalDebounce.p1 ${OBJECTDIR}/MonitorWaterPressure.p1 ${OBJECTDIR}/pump_control.p1 ${OBJECTDIR}/pump_run.p1 ${OBJECTDIR}/serial.p1 ${OBJECTDIR}/serial_buffer.p1 ${OBJECTDIR}/serial_message.p1 ${OBJECTDIR}/shutdown_state.p1 ${OBJECTDIR}/standby_state.p1 ${OBJECTDIR}/start_main.p1 ${OBJECTDIR}/start_pump_state.p1 ${OBJECTDIR}/timer_event.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/EventDumpsolenoid.p1.d ${OBJECTDIR}/EventFaultStateLed.p1.d ${OBJECTDIR}/EventIdleTimeout.p1.d ${OBJECTDIR}/EventLowFogPressure.p1.d ${OBJECTDIR}/EventLowWaterLevel.p1.d ${OBJECTDIR}/EventLowWaterPressure.p1.d ${OBJECTDIR}/EventPODebounce.p1.d ${OBJECTDIR}/EventRunSignalDebounce.p1.d ${OBJECTDIR}/MonitorWaterPressure.p1.d ${OBJECTDIR}/pump_control.p1.d ${OBJECTDIR}/pump_run.p1.d ${OBJECTDIR}/serial.p1.d ${OBJECTDIR}/serial_buffer.p1.d ${OBJECTDIR}/serial_message.p1.d ${OBJECTDIR}/shutdown_state.p1.d ${OBJECTDIR}/standby_state.p1.d ${OBJECTDIR}/start_main.p1.d ${OBJECTDIR}/start_pump_state.p1.d ${OBJECTDIR}/timer_event.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/EventDumpsolenoid.p1 ${OBJECTDIR}/EventFaultStateLed.p1 ${OBJECTDIR}/EventIdleTimeout.p1 ${OBJECTDIR}/EventLowFogPressure.p1 ${OBJECTDIR}/EventLowWaterLevel.p1 ${OBJECTDIR}/EventLowWaterPressure.p1 ${OBJECTDIR}/EventPODebounce.p1 ${OBJECTDIR}/EventRunSignalDebounce.p1 ${OBJECTDIR}/MonitorWaterPressure.p1 ${OBJECTDIR}/pump_control.p1 ${OBJECTDIR}/pump_run.p1 ${OBJECTDIR}/serial.p1 ${OBJECTDIR}/serial_buffer.p1 ${OBJECTDIR}/serial_message.p1 ${OBJECTDIR}/shutdown_state.p1 ${OBJECTDIR}/standby_state.p1 ${OBJECTDIR}/start_main.p1 ${OBJECTDIR}/start_pump_state.p1 ${OBJECTDIR}/timer_event.p1

# Source Files
SOURCEFILES=EventDumpsolenoid.c EventFaultStateLed.c EventIdleTimeout.c EventLowFogPressure.c EventLowWaterLevel.c EventLowWaterPressure.c EventPODebounce.c EventRunSignalDebounce.c MonitorWaterPressure.c pump_control.c pump_run.c serial.c serial_buffer.c serial_message.c shutdown_state.c standby_state.c start_main.c start_pump_state.c timer_event.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4550
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/EventDumpsolenoid.p1: EventDumpsolenoid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventDumpsolenoid.p1.d 
	@${RM} ${OBJECTDIR}/EventDumpsolenoid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventDumpsolenoid.p1 EventDumpsolenoid.c 
	@-${MV} ${OBJECTDIR}/EventDumpsolenoid.d ${OBJECTDIR}/EventDumpsolenoid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventDumpsolenoid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventFaultStateLed.p1: EventFaultStateLed.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventFaultStateLed.p1.d 
	@${RM} ${OBJECTDIR}/EventFaultStateLed.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventFaultStateLed.p1 EventFaultStateLed.c 
	@-${MV} ${OBJECTDIR}/EventFaultStateLed.d ${OBJECTDIR}/EventFaultStateLed.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventFaultStateLed.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventIdleTimeout.p1: EventIdleTimeout.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventIdleTimeout.p1.d 
	@${RM} ${OBJECTDIR}/EventIdleTimeout.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventIdleTimeout.p1 EventIdleTimeout.c 
	@-${MV} ${OBJECTDIR}/EventIdleTimeout.d ${OBJECTDIR}/EventIdleTimeout.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventIdleTimeout.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventLowFogPressure.p1: EventLowFogPressure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventLowFogPressure.p1.d 
	@${RM} ${OBJECTDIR}/EventLowFogPressure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventLowFogPressure.p1 EventLowFogPressure.c 
	@-${MV} ${OBJECTDIR}/EventLowFogPressure.d ${OBJECTDIR}/EventLowFogPressure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventLowFogPressure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventLowWaterLevel.p1: EventLowWaterLevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventLowWaterLevel.p1.d 
	@${RM} ${OBJECTDIR}/EventLowWaterLevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventLowWaterLevel.p1 EventLowWaterLevel.c 
	@-${MV} ${OBJECTDIR}/EventLowWaterLevel.d ${OBJECTDIR}/EventLowWaterLevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventLowWaterLevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventLowWaterPressure.p1: EventLowWaterPressure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventLowWaterPressure.p1.d 
	@${RM} ${OBJECTDIR}/EventLowWaterPressure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventLowWaterPressure.p1 EventLowWaterPressure.c 
	@-${MV} ${OBJECTDIR}/EventLowWaterPressure.d ${OBJECTDIR}/EventLowWaterPressure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventLowWaterPressure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventPODebounce.p1: EventPODebounce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventPODebounce.p1.d 
	@${RM} ${OBJECTDIR}/EventPODebounce.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventPODebounce.p1 EventPODebounce.c 
	@-${MV} ${OBJECTDIR}/EventPODebounce.d ${OBJECTDIR}/EventPODebounce.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventPODebounce.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventRunSignalDebounce.p1: EventRunSignalDebounce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventRunSignalDebounce.p1.d 
	@${RM} ${OBJECTDIR}/EventRunSignalDebounce.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventRunSignalDebounce.p1 EventRunSignalDebounce.c 
	@-${MV} ${OBJECTDIR}/EventRunSignalDebounce.d ${OBJECTDIR}/EventRunSignalDebounce.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventRunSignalDebounce.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MonitorWaterPressure.p1: MonitorWaterPressure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MonitorWaterPressure.p1.d 
	@${RM} ${OBJECTDIR}/MonitorWaterPressure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MonitorWaterPressure.p1 MonitorWaterPressure.c 
	@-${MV} ${OBJECTDIR}/MonitorWaterPressure.d ${OBJECTDIR}/MonitorWaterPressure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MonitorWaterPressure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/pump_control.p1: pump_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pump_control.p1.d 
	@${RM} ${OBJECTDIR}/pump_control.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/pump_control.p1 pump_control.c 
	@-${MV} ${OBJECTDIR}/pump_control.d ${OBJECTDIR}/pump_control.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/pump_control.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/pump_run.p1: pump_run.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pump_run.p1.d 
	@${RM} ${OBJECTDIR}/pump_run.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/pump_run.p1 pump_run.c 
	@-${MV} ${OBJECTDIR}/pump_run.d ${OBJECTDIR}/pump_run.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/pump_run.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/serial.p1: serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial.p1.d 
	@${RM} ${OBJECTDIR}/serial.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/serial.p1 serial.c 
	@-${MV} ${OBJECTDIR}/serial.d ${OBJECTDIR}/serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/serial_buffer.p1: serial_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial_buffer.p1.d 
	@${RM} ${OBJECTDIR}/serial_buffer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/serial_buffer.p1 serial_buffer.c 
	@-${MV} ${OBJECTDIR}/serial_buffer.d ${OBJECTDIR}/serial_buffer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/serial_buffer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/serial_message.p1: serial_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial_message.p1.d 
	@${RM} ${OBJECTDIR}/serial_message.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/serial_message.p1 serial_message.c 
	@-${MV} ${OBJECTDIR}/serial_message.d ${OBJECTDIR}/serial_message.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/serial_message.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/shutdown_state.p1: shutdown_state.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/shutdown_state.p1.d 
	@${RM} ${OBJECTDIR}/shutdown_state.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/shutdown_state.p1 shutdown_state.c 
	@-${MV} ${OBJECTDIR}/shutdown_state.d ${OBJECTDIR}/shutdown_state.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/shutdown_state.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/standby_state.p1: standby_state.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/standby_state.p1.d 
	@${RM} ${OBJECTDIR}/standby_state.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/standby_state.p1 standby_state.c 
	@-${MV} ${OBJECTDIR}/standby_state.d ${OBJECTDIR}/standby_state.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/standby_state.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/start_main.p1: start_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/start_main.p1.d 
	@${RM} ${OBJECTDIR}/start_main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/start_main.p1 start_main.c 
	@-${MV} ${OBJECTDIR}/start_main.d ${OBJECTDIR}/start_main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/start_main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/start_pump_state.p1: start_pump_state.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/start_pump_state.p1.d 
	@${RM} ${OBJECTDIR}/start_pump_state.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/start_pump_state.p1 start_pump_state.c 
	@-${MV} ${OBJECTDIR}/start_pump_state.d ${OBJECTDIR}/start_pump_state.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/start_pump_state.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/timer_event.p1: timer_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_event.p1.d 
	@${RM} ${OBJECTDIR}/timer_event.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/timer_event.p1 timer_event.c 
	@-${MV} ${OBJECTDIR}/timer_event.d ${OBJECTDIR}/timer_event.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/timer_event.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/EventDumpsolenoid.p1: EventDumpsolenoid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventDumpsolenoid.p1.d 
	@${RM} ${OBJECTDIR}/EventDumpsolenoid.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventDumpsolenoid.p1 EventDumpsolenoid.c 
	@-${MV} ${OBJECTDIR}/EventDumpsolenoid.d ${OBJECTDIR}/EventDumpsolenoid.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventDumpsolenoid.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventFaultStateLed.p1: EventFaultStateLed.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventFaultStateLed.p1.d 
	@${RM} ${OBJECTDIR}/EventFaultStateLed.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventFaultStateLed.p1 EventFaultStateLed.c 
	@-${MV} ${OBJECTDIR}/EventFaultStateLed.d ${OBJECTDIR}/EventFaultStateLed.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventFaultStateLed.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventIdleTimeout.p1: EventIdleTimeout.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventIdleTimeout.p1.d 
	@${RM} ${OBJECTDIR}/EventIdleTimeout.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventIdleTimeout.p1 EventIdleTimeout.c 
	@-${MV} ${OBJECTDIR}/EventIdleTimeout.d ${OBJECTDIR}/EventIdleTimeout.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventIdleTimeout.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventLowFogPressure.p1: EventLowFogPressure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventLowFogPressure.p1.d 
	@${RM} ${OBJECTDIR}/EventLowFogPressure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventLowFogPressure.p1 EventLowFogPressure.c 
	@-${MV} ${OBJECTDIR}/EventLowFogPressure.d ${OBJECTDIR}/EventLowFogPressure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventLowFogPressure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventLowWaterLevel.p1: EventLowWaterLevel.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventLowWaterLevel.p1.d 
	@${RM} ${OBJECTDIR}/EventLowWaterLevel.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventLowWaterLevel.p1 EventLowWaterLevel.c 
	@-${MV} ${OBJECTDIR}/EventLowWaterLevel.d ${OBJECTDIR}/EventLowWaterLevel.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventLowWaterLevel.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventLowWaterPressure.p1: EventLowWaterPressure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventLowWaterPressure.p1.d 
	@${RM} ${OBJECTDIR}/EventLowWaterPressure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventLowWaterPressure.p1 EventLowWaterPressure.c 
	@-${MV} ${OBJECTDIR}/EventLowWaterPressure.d ${OBJECTDIR}/EventLowWaterPressure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventLowWaterPressure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventPODebounce.p1: EventPODebounce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventPODebounce.p1.d 
	@${RM} ${OBJECTDIR}/EventPODebounce.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventPODebounce.p1 EventPODebounce.c 
	@-${MV} ${OBJECTDIR}/EventPODebounce.d ${OBJECTDIR}/EventPODebounce.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventPODebounce.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EventRunSignalDebounce.p1: EventRunSignalDebounce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EventRunSignalDebounce.p1.d 
	@${RM} ${OBJECTDIR}/EventRunSignalDebounce.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/EventRunSignalDebounce.p1 EventRunSignalDebounce.c 
	@-${MV} ${OBJECTDIR}/EventRunSignalDebounce.d ${OBJECTDIR}/EventRunSignalDebounce.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EventRunSignalDebounce.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MonitorWaterPressure.p1: MonitorWaterPressure.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MonitorWaterPressure.p1.d 
	@${RM} ${OBJECTDIR}/MonitorWaterPressure.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MonitorWaterPressure.p1 MonitorWaterPressure.c 
	@-${MV} ${OBJECTDIR}/MonitorWaterPressure.d ${OBJECTDIR}/MonitorWaterPressure.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MonitorWaterPressure.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/pump_control.p1: pump_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pump_control.p1.d 
	@${RM} ${OBJECTDIR}/pump_control.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/pump_control.p1 pump_control.c 
	@-${MV} ${OBJECTDIR}/pump_control.d ${OBJECTDIR}/pump_control.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/pump_control.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/pump_run.p1: pump_run.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pump_run.p1.d 
	@${RM} ${OBJECTDIR}/pump_run.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/pump_run.p1 pump_run.c 
	@-${MV} ${OBJECTDIR}/pump_run.d ${OBJECTDIR}/pump_run.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/pump_run.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/serial.p1: serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial.p1.d 
	@${RM} ${OBJECTDIR}/serial.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/serial.p1 serial.c 
	@-${MV} ${OBJECTDIR}/serial.d ${OBJECTDIR}/serial.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/serial.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/serial_buffer.p1: serial_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial_buffer.p1.d 
	@${RM} ${OBJECTDIR}/serial_buffer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/serial_buffer.p1 serial_buffer.c 
	@-${MV} ${OBJECTDIR}/serial_buffer.d ${OBJECTDIR}/serial_buffer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/serial_buffer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/serial_message.p1: serial_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/serial_message.p1.d 
	@${RM} ${OBJECTDIR}/serial_message.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/serial_message.p1 serial_message.c 
	@-${MV} ${OBJECTDIR}/serial_message.d ${OBJECTDIR}/serial_message.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/serial_message.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/shutdown_state.p1: shutdown_state.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/shutdown_state.p1.d 
	@${RM} ${OBJECTDIR}/shutdown_state.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/shutdown_state.p1 shutdown_state.c 
	@-${MV} ${OBJECTDIR}/shutdown_state.d ${OBJECTDIR}/shutdown_state.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/shutdown_state.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/standby_state.p1: standby_state.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/standby_state.p1.d 
	@${RM} ${OBJECTDIR}/standby_state.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/standby_state.p1 standby_state.c 
	@-${MV} ${OBJECTDIR}/standby_state.d ${OBJECTDIR}/standby_state.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/standby_state.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/start_main.p1: start_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/start_main.p1.d 
	@${RM} ${OBJECTDIR}/start_main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/start_main.p1 start_main.c 
	@-${MV} ${OBJECTDIR}/start_main.d ${OBJECTDIR}/start_main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/start_main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/start_pump_state.p1: start_pump_state.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/start_pump_state.p1.d 
	@${RM} ${OBJECTDIR}/start_pump_state.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/start_pump_state.p1 start_pump_state.c 
	@-${MV} ${OBJECTDIR}/start_pump_state.d ${OBJECTDIR}/start_pump_state.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/start_pump_state.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/timer_event.p1: timer_event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_event.p1.d 
	@${RM} ${OBJECTDIR}/timer_event.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/timer_event.p1 timer_event.c 
	@-${MV} ${OBJECTDIR}/timer_event.d ${OBJECTDIR}/timer_event.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/timer_event.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     --rom=default,-7dc0-7fff --ram=default,-3f4-3ff,-fdb-fdf,-fe3-fe7,-feb-fef,-fd4-fd4,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/aecv7.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
