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
FINAL_IMAGE=${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ece118_base/AD.c ece118_base/BOARD.c ece118_base/ES_CheckEvents.c ece118_base/ES_Framework.c ece118_base/ES_KeyboardInput.c ece118_base/ES_LookupTables.c ece118_base/ES_PostList.c ece118_base/ES_Queue.c ece118_base/ES_TattleTale.c ece118_base/ES_TimerService.c ece118_base/ES_Timers.c ece118_base/IO_Ports.c ece118_base/LED.c ece118_base/RC_Servo.c ece118_base/pwm.c ece118_base/serial.c ece118_base/timers.c ece118_template/PingEventChecker.c PingSensor.c ece118_base/ColorSensor.c ece118_base/ColorEventChecker.c ece118_base/PingService.c ece118_base/ColorService.c ece118_base/IRSensor.c ece118_base/IREventChecker.c ece118_base/IRService.c ece118_base/Actuators.c ece118_base/SortSubHSM.c ece118_template/TemplateES_Main.c ece118_base/RedFlowSubHSM.c ece118_base/BlueFlowSubHSM.c ece118_base/CenterSubHSM.c ece118_template/TemplateHSM.c ece118_base/LeftSubHSM.c ece118_template/RightSubHSM.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ece118_base/AD.o ${OBJECTDIR}/ece118_base/BOARD.o ${OBJECTDIR}/ece118_base/ES_CheckEvents.o ${OBJECTDIR}/ece118_base/ES_Framework.o ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o ${OBJECTDIR}/ece118_base/ES_LookupTables.o ${OBJECTDIR}/ece118_base/ES_PostList.o ${OBJECTDIR}/ece118_base/ES_Queue.o ${OBJECTDIR}/ece118_base/ES_TattleTale.o ${OBJECTDIR}/ece118_base/ES_TimerService.o ${OBJECTDIR}/ece118_base/ES_Timers.o ${OBJECTDIR}/ece118_base/IO_Ports.o ${OBJECTDIR}/ece118_base/LED.o ${OBJECTDIR}/ece118_base/RC_Servo.o ${OBJECTDIR}/ece118_base/pwm.o ${OBJECTDIR}/ece118_base/serial.o ${OBJECTDIR}/ece118_base/timers.o ${OBJECTDIR}/ece118_template/PingEventChecker.o ${OBJECTDIR}/PingSensor.o ${OBJECTDIR}/ece118_base/ColorSensor.o ${OBJECTDIR}/ece118_base/ColorEventChecker.o ${OBJECTDIR}/ece118_base/PingService.o ${OBJECTDIR}/ece118_base/ColorService.o ${OBJECTDIR}/ece118_base/IRSensor.o ${OBJECTDIR}/ece118_base/IREventChecker.o ${OBJECTDIR}/ece118_base/IRService.o ${OBJECTDIR}/ece118_base/Actuators.o ${OBJECTDIR}/ece118_base/SortSubHSM.o ${OBJECTDIR}/ece118_template/TemplateES_Main.o ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o ${OBJECTDIR}/ece118_base/CenterSubHSM.o ${OBJECTDIR}/ece118_template/TemplateHSM.o ${OBJECTDIR}/ece118_base/LeftSubHSM.o ${OBJECTDIR}/ece118_template/RightSubHSM.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ece118_base/AD.o.d ${OBJECTDIR}/ece118_base/BOARD.o.d ${OBJECTDIR}/ece118_base/ES_CheckEvents.o.d ${OBJECTDIR}/ece118_base/ES_Framework.o.d ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o.d ${OBJECTDIR}/ece118_base/ES_LookupTables.o.d ${OBJECTDIR}/ece118_base/ES_PostList.o.d ${OBJECTDIR}/ece118_base/ES_Queue.o.d ${OBJECTDIR}/ece118_base/ES_TattleTale.o.d ${OBJECTDIR}/ece118_base/ES_TimerService.o.d ${OBJECTDIR}/ece118_base/ES_Timers.o.d ${OBJECTDIR}/ece118_base/IO_Ports.o.d ${OBJECTDIR}/ece118_base/LED.o.d ${OBJECTDIR}/ece118_base/RC_Servo.o.d ${OBJECTDIR}/ece118_base/pwm.o.d ${OBJECTDIR}/ece118_base/serial.o.d ${OBJECTDIR}/ece118_base/timers.o.d ${OBJECTDIR}/ece118_template/PingEventChecker.o.d ${OBJECTDIR}/PingSensor.o.d ${OBJECTDIR}/ece118_base/ColorSensor.o.d ${OBJECTDIR}/ece118_base/ColorEventChecker.o.d ${OBJECTDIR}/ece118_base/PingService.o.d ${OBJECTDIR}/ece118_base/ColorService.o.d ${OBJECTDIR}/ece118_base/IRSensor.o.d ${OBJECTDIR}/ece118_base/IREventChecker.o.d ${OBJECTDIR}/ece118_base/IRService.o.d ${OBJECTDIR}/ece118_base/Actuators.o.d ${OBJECTDIR}/ece118_base/SortSubHSM.o.d ${OBJECTDIR}/ece118_template/TemplateES_Main.o.d ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o.d ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o.d ${OBJECTDIR}/ece118_base/CenterSubHSM.o.d ${OBJECTDIR}/ece118_template/TemplateHSM.o.d ${OBJECTDIR}/ece118_base/LeftSubHSM.o.d ${OBJECTDIR}/ece118_template/RightSubHSM.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ece118_base/AD.o ${OBJECTDIR}/ece118_base/BOARD.o ${OBJECTDIR}/ece118_base/ES_CheckEvents.o ${OBJECTDIR}/ece118_base/ES_Framework.o ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o ${OBJECTDIR}/ece118_base/ES_LookupTables.o ${OBJECTDIR}/ece118_base/ES_PostList.o ${OBJECTDIR}/ece118_base/ES_Queue.o ${OBJECTDIR}/ece118_base/ES_TattleTale.o ${OBJECTDIR}/ece118_base/ES_TimerService.o ${OBJECTDIR}/ece118_base/ES_Timers.o ${OBJECTDIR}/ece118_base/IO_Ports.o ${OBJECTDIR}/ece118_base/LED.o ${OBJECTDIR}/ece118_base/RC_Servo.o ${OBJECTDIR}/ece118_base/pwm.o ${OBJECTDIR}/ece118_base/serial.o ${OBJECTDIR}/ece118_base/timers.o ${OBJECTDIR}/ece118_template/PingEventChecker.o ${OBJECTDIR}/PingSensor.o ${OBJECTDIR}/ece118_base/ColorSensor.o ${OBJECTDIR}/ece118_base/ColorEventChecker.o ${OBJECTDIR}/ece118_base/PingService.o ${OBJECTDIR}/ece118_base/ColorService.o ${OBJECTDIR}/ece118_base/IRSensor.o ${OBJECTDIR}/ece118_base/IREventChecker.o ${OBJECTDIR}/ece118_base/IRService.o ${OBJECTDIR}/ece118_base/Actuators.o ${OBJECTDIR}/ece118_base/SortSubHSM.o ${OBJECTDIR}/ece118_template/TemplateES_Main.o ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o ${OBJECTDIR}/ece118_base/CenterSubHSM.o ${OBJECTDIR}/ece118_template/TemplateHSM.o ${OBJECTDIR}/ece118_base/LeftSubHSM.o ${OBJECTDIR}/ece118_template/RightSubHSM.o

# Source Files
SOURCEFILES=ece118_base/AD.c ece118_base/BOARD.c ece118_base/ES_CheckEvents.c ece118_base/ES_Framework.c ece118_base/ES_KeyboardInput.c ece118_base/ES_LookupTables.c ece118_base/ES_PostList.c ece118_base/ES_Queue.c ece118_base/ES_TattleTale.c ece118_base/ES_TimerService.c ece118_base/ES_Timers.c ece118_base/IO_Ports.c ece118_base/LED.c ece118_base/RC_Servo.c ece118_base/pwm.c ece118_base/serial.c ece118_base/timers.c ece118_template/PingEventChecker.c PingSensor.c ece118_base/ColorSensor.c ece118_base/ColorEventChecker.c ece118_base/PingService.c ece118_base/ColorService.c ece118_base/IRSensor.c ece118_base/IREventChecker.c ece118_base/IRService.c ece118_base/Actuators.c ece118_base/SortSubHSM.c ece118_template/TemplateES_Main.c ece118_base/RedFlowSubHSM.c ece118_base/BlueFlowSubHSM.c ece118_base/CenterSubHSM.c ece118_template/TemplateHSM.c ece118_base/LeftSubHSM.c ece118_template/RightSubHSM.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ece118_base/AD.o: ece118_base/AD.c  .generated_files/flags/default/60ea93666c4fadca4b1a8bc2853f41cf9ce2499c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/AD.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/AD.o.d" -o ${OBJECTDIR}/ece118_base/AD.o ece118_base/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/BOARD.o: ece118_base/BOARD.c  .generated_files/flags/default/6f99cc4bca2d96f5b5b658aa839ea0c298eabbfa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/BOARD.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/BOARD.o.d" -o ${OBJECTDIR}/ece118_base/BOARD.o ece118_base/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_CheckEvents.o: ece118_base/ES_CheckEvents.c  .generated_files/flags/default/11fb706643dea3670e25e34fc208798730496936 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ece118_base/ES_CheckEvents.o ece118_base/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_Framework.o: ece118_base/ES_Framework.c  .generated_files/flags/default/84e6140c421e824a2c9bb068a7310d76cdf417ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_Framework.o.d" -o ${OBJECTDIR}/ece118_base/ES_Framework.o ece118_base/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_KeyboardInput.o: ece118_base/ES_KeyboardInput.c  .generated_files/flags/default/35e1697f9d494b2cb420ca6888c89d53eacff94a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o ece118_base/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_LookupTables.o: ece118_base/ES_LookupTables.c  .generated_files/flags/default/2c06637ffc409d471787c4750cdfe3ec8a1fa1d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_LookupTables.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_LookupTables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_LookupTables.o.d" -o ${OBJECTDIR}/ece118_base/ES_LookupTables.o ece118_base/ES_LookupTables.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_PostList.o: ece118_base/ES_PostList.c  .generated_files/flags/default/a11be1dcd0717ac3f2a7bb5f7e481f441aafe647 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_PostList.o.d" -o ${OBJECTDIR}/ece118_base/ES_PostList.o ece118_base/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_Queue.o: ece118_base/ES_Queue.c  .generated_files/flags/default/4641f141bd15cc71e7eb1ddddc39f0ed9e6f401 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_Queue.o.d" -o ${OBJECTDIR}/ece118_base/ES_Queue.o ece118_base/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_TattleTale.o: ece118_base/ES_TattleTale.c  .generated_files/flags/default/cb98046b0c1d81155cdea85e83351d83bc36da49 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_TattleTale.o.d" -o ${OBJECTDIR}/ece118_base/ES_TattleTale.o ece118_base/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_TimerService.o: ece118_base/ES_TimerService.c  .generated_files/flags/default/cb6a15b9d89ccacf0843b92e939b834df664b07e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TimerService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TimerService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_TimerService.o.d" -o ${OBJECTDIR}/ece118_base/ES_TimerService.o ece118_base/ES_TimerService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_Timers.o: ece118_base/ES_Timers.c  .generated_files/flags/default/c930195e7327ee272ed9157ef5e4860293fa8f3e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_Timers.o.d" -o ${OBJECTDIR}/ece118_base/ES_Timers.o ece118_base/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IO_Ports.o: ece118_base/IO_Ports.c  .generated_files/flags/default/da31f136aac01e9521d4173c6111f38881b65d00 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IO_Ports.o.d" -o ${OBJECTDIR}/ece118_base/IO_Ports.o ece118_base/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/LED.o: ece118_base/LED.c  .generated_files/flags/default/792ee0606d7df07ee3fa34c71519e31e49d7d080 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/LED.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/LED.o.d" -o ${OBJECTDIR}/ece118_base/LED.o ece118_base/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/RC_Servo.o: ece118_base/RC_Servo.c  .generated_files/flags/default/5ed60c5c50036438c9fedb28e24d2685a5b59759 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/RC_Servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/RC_Servo.o.d" -o ${OBJECTDIR}/ece118_base/RC_Servo.o ece118_base/RC_Servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/pwm.o: ece118_base/pwm.c  .generated_files/flags/default/76384eb4a326de1f70fa1fa1d1e3998a7153fcdb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/pwm.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/pwm.o.d" -o ${OBJECTDIR}/ece118_base/pwm.o ece118_base/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/serial.o: ece118_base/serial.c  .generated_files/flags/default/10dc8f30c0df5008953c9bb7401236b5c6fcc5f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/serial.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/serial.o.d" -o ${OBJECTDIR}/ece118_base/serial.o ece118_base/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/timers.o: ece118_base/timers.c  .generated_files/flags/default/a30357c62429648f535c390e0def60dbf7f2731 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/timers.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/timers.o.d" -o ${OBJECTDIR}/ece118_base/timers.o ece118_base/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/PingEventChecker.o: ece118_template/PingEventChecker.c  .generated_files/flags/default/22bfd8a9771bbd74b52ce5883812eafd2529cdbc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/PingEventChecker.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/PingEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/PingEventChecker.o.d" -o ${OBJECTDIR}/ece118_template/PingEventChecker.o ece118_template/PingEventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PingSensor.o: PingSensor.c  .generated_files/flags/default/ed300a4a2faaa5e6938a84660e12d7ecd7b74ffc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PingSensor.o.d 
	@${RM} ${OBJECTDIR}/PingSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/PingSensor.o.d" -o ${OBJECTDIR}/PingSensor.o PingSensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ColorSensor.o: ece118_base/ColorSensor.c  .generated_files/flags/default/f630b3da0f12abe48b0e68e2a002d5ff51f6e6da .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ColorSensor.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ColorSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ColorSensor.o.d" -o ${OBJECTDIR}/ece118_base/ColorSensor.o ece118_base/ColorSensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ColorEventChecker.o: ece118_base/ColorEventChecker.c  .generated_files/flags/default/838ee57589b9c5c4140091b72cb090a6375693cd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ColorEventChecker.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ColorEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ColorEventChecker.o.d" -o ${OBJECTDIR}/ece118_base/ColorEventChecker.o ece118_base/ColorEventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/PingService.o: ece118_base/PingService.c  .generated_files/flags/default/f39f38b340cc8cf3db05cd8bba806fb77896d1da .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/PingService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/PingService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/PingService.o.d" -o ${OBJECTDIR}/ece118_base/PingService.o ece118_base/PingService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ColorService.o: ece118_base/ColorService.c  .generated_files/flags/default/13bb1615ff0115c13c1b9c408a623f03cae34721 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ColorService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ColorService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ColorService.o.d" -o ${OBJECTDIR}/ece118_base/ColorService.o ece118_base/ColorService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IRSensor.o: ece118_base/IRSensor.c  .generated_files/flags/default/f8f54fa007adcfa9435c49dafe3b63b689ae90af .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IRSensor.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IRSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IRSensor.o.d" -o ${OBJECTDIR}/ece118_base/IRSensor.o ece118_base/IRSensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IREventChecker.o: ece118_base/IREventChecker.c  .generated_files/flags/default/5bfd097fc8552662ff3344dd8789963379274d6b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IREventChecker.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IREventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IREventChecker.o.d" -o ${OBJECTDIR}/ece118_base/IREventChecker.o ece118_base/IREventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IRService.o: ece118_base/IRService.c  .generated_files/flags/default/79fb4b43b93a3b33e9951c7a23f498c8e3de6809 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IRService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IRService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IRService.o.d" -o ${OBJECTDIR}/ece118_base/IRService.o ece118_base/IRService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/Actuators.o: ece118_base/Actuators.c  .generated_files/flags/default/abd03f7e3c521a1876f489775efb5116968388b5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/Actuators.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/Actuators.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/Actuators.o.d" -o ${OBJECTDIR}/ece118_base/Actuators.o ece118_base/Actuators.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/SortSubHSM.o: ece118_base/SortSubHSM.c  .generated_files/flags/default/9365a2ab7b25cea80d0aab640c504664d7fc11ae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/SortSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/SortSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/SortSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/SortSubHSM.o ece118_base/SortSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/TemplateES_Main.o: ece118_template/TemplateES_Main.c  .generated_files/flags/default/945390f94d783f81eb2062c45a074e4ca245c6cb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateES_Main.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/TemplateES_Main.o.d" -o ${OBJECTDIR}/ece118_template/TemplateES_Main.o ece118_template/TemplateES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/RedFlowSubHSM.o: ece118_base/RedFlowSubHSM.c  .generated_files/flags/default/39c9126b743d225662c0715addd2a6818bdc7698 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/RedFlowSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o ece118_base/RedFlowSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o: ece118_base/BlueFlowSubHSM.c  .generated_files/flags/default/d0629b614bbb0a467b45966e6cf176dabc5d7819 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o ece118_base/BlueFlowSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/CenterSubHSM.o: ece118_base/CenterSubHSM.c  .generated_files/flags/default/e99ddce120dd90fc2d04efd5d8b19ddea4daeab3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/CenterSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/CenterSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/CenterSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/CenterSubHSM.o ece118_base/CenterSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/TemplateHSM.o: ece118_template/TemplateHSM.c  .generated_files/flags/default/61376dbd499c711a69bdb2b563efbc9d87f11ba6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/TemplateHSM.o.d" -o ${OBJECTDIR}/ece118_template/TemplateHSM.o ece118_template/TemplateHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/LeftSubHSM.o: ece118_base/LeftSubHSM.c  .generated_files/flags/default/1a3bde6f33471d99f926fb02c49ceb78adb89a8c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/LeftSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/LeftSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/LeftSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/LeftSubHSM.o ece118_base/LeftSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/RightSubHSM.o: ece118_template/RightSubHSM.c  .generated_files/flags/default/ccd53828b4d6c709ce3c1027212ad783664c1032 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/RightSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/RightSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/RightSubHSM.o.d" -o ${OBJECTDIR}/ece118_template/RightSubHSM.o ece118_template/RightSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/ece118_base/AD.o: ece118_base/AD.c  .generated_files/flags/default/9b104c9ed4fa2fb6b8f04302086850034eaf5dd3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/AD.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/AD.o.d" -o ${OBJECTDIR}/ece118_base/AD.o ece118_base/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/BOARD.o: ece118_base/BOARD.c  .generated_files/flags/default/4cf303332e1f570625e3e0c4ceaa126aee8d748c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/BOARD.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/BOARD.o.d" -o ${OBJECTDIR}/ece118_base/BOARD.o ece118_base/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_CheckEvents.o: ece118_base/ES_CheckEvents.c  .generated_files/flags/default/1a013d427372e217acf2153377c66e1eb681bf48 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ece118_base/ES_CheckEvents.o ece118_base/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_Framework.o: ece118_base/ES_Framework.c  .generated_files/flags/default/fbb76f99bb604d4916a4eb09804a2928d708d105 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_Framework.o.d" -o ${OBJECTDIR}/ece118_base/ES_Framework.o ece118_base/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_KeyboardInput.o: ece118_base/ES_KeyboardInput.c  .generated_files/flags/default/aa7aae8a042fa99c65fecd44640b06fbd0233911 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ece118_base/ES_KeyboardInput.o ece118_base/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_LookupTables.o: ece118_base/ES_LookupTables.c  .generated_files/flags/default/2a3a363bda2b592e3632c6c2fef3a6c209145ee0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_LookupTables.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_LookupTables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_LookupTables.o.d" -o ${OBJECTDIR}/ece118_base/ES_LookupTables.o ece118_base/ES_LookupTables.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_PostList.o: ece118_base/ES_PostList.c  .generated_files/flags/default/e7954279840269053165706ffbcfb90c16342ad7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_PostList.o.d" -o ${OBJECTDIR}/ece118_base/ES_PostList.o ece118_base/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_Queue.o: ece118_base/ES_Queue.c  .generated_files/flags/default/25160b6737c6fccde667ac56432765993924320a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_Queue.o.d" -o ${OBJECTDIR}/ece118_base/ES_Queue.o ece118_base/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_TattleTale.o: ece118_base/ES_TattleTale.c  .generated_files/flags/default/4b699be5855437406b0f22e5db5d921932ef9dc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_TattleTale.o.d" -o ${OBJECTDIR}/ece118_base/ES_TattleTale.o ece118_base/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_TimerService.o: ece118_base/ES_TimerService.c  .generated_files/flags/default/533a2d4a1fa2d741bcda63e3d652fb5be0e12c6d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TimerService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_TimerService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_TimerService.o.d" -o ${OBJECTDIR}/ece118_base/ES_TimerService.o ece118_base/ES_TimerService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ES_Timers.o: ece118_base/ES_Timers.c  .generated_files/flags/default/cb5f0bd89dabfaf6d2d2d04a3bbe659df887b723 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ES_Timers.o.d" -o ${OBJECTDIR}/ece118_base/ES_Timers.o ece118_base/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IO_Ports.o: ece118_base/IO_Ports.c  .generated_files/flags/default/df965e8fdab393b2f626d0812140ed753734ac51 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IO_Ports.o.d" -o ${OBJECTDIR}/ece118_base/IO_Ports.o ece118_base/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/LED.o: ece118_base/LED.c  .generated_files/flags/default/da01a8cdac62501d25a01c3102e3f862d62a1534 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/LED.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/LED.o.d" -o ${OBJECTDIR}/ece118_base/LED.o ece118_base/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/RC_Servo.o: ece118_base/RC_Servo.c  .generated_files/flags/default/f1d81323aa5d427bee1b54a845ad0120cbc2a4f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/RC_Servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/RC_Servo.o.d" -o ${OBJECTDIR}/ece118_base/RC_Servo.o ece118_base/RC_Servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/pwm.o: ece118_base/pwm.c  .generated_files/flags/default/5405a9552acefc9ad1e5822cf4b9e5a034bb14ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/pwm.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/pwm.o.d" -o ${OBJECTDIR}/ece118_base/pwm.o ece118_base/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/serial.o: ece118_base/serial.c  .generated_files/flags/default/5c85735ffd5a4e5a17b7efaab552061be248fdb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/serial.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/serial.o.d" -o ${OBJECTDIR}/ece118_base/serial.o ece118_base/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/timers.o: ece118_base/timers.c  .generated_files/flags/default/411a97f09e4947e36bf4f06ea54ad568a8c40c5a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/timers.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/timers.o.d" -o ${OBJECTDIR}/ece118_base/timers.o ece118_base/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/PingEventChecker.o: ece118_template/PingEventChecker.c  .generated_files/flags/default/4dd64dc18927c23aaeb2fab06b4d3da37184d819 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/PingEventChecker.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/PingEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/PingEventChecker.o.d" -o ${OBJECTDIR}/ece118_template/PingEventChecker.o ece118_template/PingEventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PingSensor.o: PingSensor.c  .generated_files/flags/default/6fe40cb2df51d957f89527d2ce07904dfe228dd2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PingSensor.o.d 
	@${RM} ${OBJECTDIR}/PingSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/PingSensor.o.d" -o ${OBJECTDIR}/PingSensor.o PingSensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ColorSensor.o: ece118_base/ColorSensor.c  .generated_files/flags/default/e80dd7edf61f4e23f94bea79e2fa38ca9b2b5854 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ColorSensor.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ColorSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ColorSensor.o.d" -o ${OBJECTDIR}/ece118_base/ColorSensor.o ece118_base/ColorSensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ColorEventChecker.o: ece118_base/ColorEventChecker.c  .generated_files/flags/default/7a076dcab57f48b02f656668766e4344ed6fa19 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ColorEventChecker.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ColorEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ColorEventChecker.o.d" -o ${OBJECTDIR}/ece118_base/ColorEventChecker.o ece118_base/ColorEventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/PingService.o: ece118_base/PingService.c  .generated_files/flags/default/47949c50ecbc188d66c58e6a27927bdc9ebc822 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/PingService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/PingService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/PingService.o.d" -o ${OBJECTDIR}/ece118_base/PingService.o ece118_base/PingService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/ColorService.o: ece118_base/ColorService.c  .generated_files/flags/default/684720f8ce275be3e49d41e0833942f4a971335f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/ColorService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/ColorService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/ColorService.o.d" -o ${OBJECTDIR}/ece118_base/ColorService.o ece118_base/ColorService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IRSensor.o: ece118_base/IRSensor.c  .generated_files/flags/default/aba90d3e447b073663c96e2235a418ce8585ac58 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IRSensor.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IRSensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IRSensor.o.d" -o ${OBJECTDIR}/ece118_base/IRSensor.o ece118_base/IRSensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IREventChecker.o: ece118_base/IREventChecker.c  .generated_files/flags/default/7277e3e9c6adb34b8eb03d5dc663e3a7b4782dbc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IREventChecker.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IREventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IREventChecker.o.d" -o ${OBJECTDIR}/ece118_base/IREventChecker.o ece118_base/IREventChecker.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/IRService.o: ece118_base/IRService.c  .generated_files/flags/default/7a6dcbb5d1f99f4030f401b7c7a1bd60612b0ae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/IRService.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/IRService.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/IRService.o.d" -o ${OBJECTDIR}/ece118_base/IRService.o ece118_base/IRService.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/Actuators.o: ece118_base/Actuators.c  .generated_files/flags/default/33c232220dda0fb75d2644e97fec8fb01737e2ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/Actuators.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/Actuators.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/Actuators.o.d" -o ${OBJECTDIR}/ece118_base/Actuators.o ece118_base/Actuators.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/SortSubHSM.o: ece118_base/SortSubHSM.c  .generated_files/flags/default/b0062c05a768be30cc19436d4c51532a37273dc6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/SortSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/SortSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/SortSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/SortSubHSM.o ece118_base/SortSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/TemplateES_Main.o: ece118_template/TemplateES_Main.c  .generated_files/flags/default/9c4debf32100d35017047eab52b8c7e14613241f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateES_Main.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/TemplateES_Main.o.d" -o ${OBJECTDIR}/ece118_template/TemplateES_Main.o ece118_template/TemplateES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/RedFlowSubHSM.o: ece118_base/RedFlowSubHSM.c  .generated_files/flags/default/13eb6871135836bd08e5ab160e6641e51d1b452f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/RedFlowSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/RedFlowSubHSM.o ece118_base/RedFlowSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o: ece118_base/BlueFlowSubHSM.c  .generated_files/flags/default/b54cec7335f1eb627eafb575c78bbc50e1d64032 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/BlueFlowSubHSM.o ece118_base/BlueFlowSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/CenterSubHSM.o: ece118_base/CenterSubHSM.c  .generated_files/flags/default/f7e1d2e5510dedeb0f64ca71de8d422aba65c4ba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/CenterSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/CenterSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/CenterSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/CenterSubHSM.o ece118_base/CenterSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/TemplateHSM.o: ece118_template/TemplateHSM.c  .generated_files/flags/default/670c59b208e147809fff5006a7a7b179f499e8a2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/TemplateHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/TemplateHSM.o.d" -o ${OBJECTDIR}/ece118_template/TemplateHSM.o ece118_template/TemplateHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_base/LeftSubHSM.o: ece118_base/LeftSubHSM.c  .generated_files/flags/default/5c07b4f04ef5a909dd54942fc2689bc6d65a3ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_base" 
	@${RM} ${OBJECTDIR}/ece118_base/LeftSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_base/LeftSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_base/LeftSubHSM.o.d" -o ${OBJECTDIR}/ece118_base/LeftSubHSM.o ece118_base/LeftSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/ece118_template/RightSubHSM.o: ece118_template/RightSubHSM.c  .generated_files/flags/default/2563bda7d6535f4033b48aed6d84e6f2eef29611 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ece118_template" 
	@${RM} ${OBJECTDIR}/ece118_template/RightSubHSM.o.d 
	@${RM} ${OBJECTDIR}/ece118_template/RightSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -I"." -I"ece118_template" -I"ece118_base" -MP -MMD -MF "${OBJECTDIR}/ece118_template/RightSubHSM.o.d" -o ${OBJECTDIR}/ece118_template/RightSubHSM.o ece118_template/RightSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Wall_E.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
