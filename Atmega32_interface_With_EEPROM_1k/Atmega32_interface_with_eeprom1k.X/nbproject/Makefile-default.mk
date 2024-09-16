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
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../../../5/app5.X/MY_SPI.c ../../../1/app1.X/DIO.c main.c EEPROM_1k.c ../../../1/app1.X/MY_LCD4.c ../../../1/app1.X/int_to_arr.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/598284295/MY_SPI.o ${OBJECTDIR}/_ext/2077993593/DIO.o ${OBJECTDIR}/main.o ${OBJECTDIR}/EEPROM_1k.o ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o ${OBJECTDIR}/_ext/2077993593/int_to_arr.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/598284295/MY_SPI.o.d ${OBJECTDIR}/_ext/2077993593/DIO.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/EEPROM_1k.o.d ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d ${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/598284295/MY_SPI.o ${OBJECTDIR}/_ext/2077993593/DIO.o ${OBJECTDIR}/main.o ${OBJECTDIR}/EEPROM_1k.o ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o ${OBJECTDIR}/_ext/2077993593/int_to_arr.o

# Source Files
SOURCEFILES=../../../5/app5.X/MY_SPI.c ../../../1/app1.X/DIO.c main.c EEPROM_1k.c ../../../1/app1.X/MY_LCD4.c ../../../1/app1.X/int_to_arr.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/598284295/MY_SPI.o: ../../../5/app5.X/MY_SPI.c  .generated_files/flags/default/1cbab36d8dbbc8fc40acab96be2ca671c4ae7c7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/598284295" 
	@${RM} ${OBJECTDIR}/_ext/598284295/MY_SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/598284295/MY_SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/598284295/MY_SPI.o.d" -MT "${OBJECTDIR}/_ext/598284295/MY_SPI.o.d" -MT ${OBJECTDIR}/_ext/598284295/MY_SPI.o -o ${OBJECTDIR}/_ext/598284295/MY_SPI.o ../../../5/app5.X/MY_SPI.c 
	
${OBJECTDIR}/_ext/2077993593/DIO.o: ../../../1/app1.X/DIO.c  .generated_files/flags/default/cc646fb47f81f1013036d70238e1ff6a4cad47cd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2077993593" 
	@${RM} ${OBJECTDIR}/_ext/2077993593/DIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/2077993593/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/2077993593/DIO.o.d" -MT "${OBJECTDIR}/_ext/2077993593/DIO.o.d" -MT ${OBJECTDIR}/_ext/2077993593/DIO.o -o ${OBJECTDIR}/_ext/2077993593/DIO.o ../../../1/app1.X/DIO.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/25aeafea069c428bbbcef1a92b1bf1897c6e3e1d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/EEPROM_1k.o: EEPROM_1k.c  .generated_files/flags/default/52b4e9a4fc7c8a5325322bc2cc27a89917da01b1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_1k.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_1k.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/EEPROM_1k.o.d" -MT "${OBJECTDIR}/EEPROM_1k.o.d" -MT ${OBJECTDIR}/EEPROM_1k.o -o ${OBJECTDIR}/EEPROM_1k.o EEPROM_1k.c 
	
${OBJECTDIR}/_ext/2077993593/MY_LCD4.o: ../../../1/app1.X/MY_LCD4.c  .generated_files/flags/default/139d90af9bf755bd035e0fd46dc5640735ef64ea .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2077993593" 
	@${RM} ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d 
	@${RM} ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d" -MT "${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d" -MT ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o -o ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o ../../../1/app1.X/MY_LCD4.c 
	
${OBJECTDIR}/_ext/2077993593/int_to_arr.o: ../../../1/app1.X/int_to_arr.c  .generated_files/flags/default/41927c4944a85814feddedb20ee67d6456debb7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2077993593" 
	@${RM} ${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d 
	@${RM} ${OBJECTDIR}/_ext/2077993593/int_to_arr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d" -MT "${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d" -MT ${OBJECTDIR}/_ext/2077993593/int_to_arr.o -o ${OBJECTDIR}/_ext/2077993593/int_to_arr.o ../../../1/app1.X/int_to_arr.c 
	
else
${OBJECTDIR}/_ext/598284295/MY_SPI.o: ../../../5/app5.X/MY_SPI.c  .generated_files/flags/default/7d41e86df0f0314ca6a3e0bb51a409dc9bb51eb7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/598284295" 
	@${RM} ${OBJECTDIR}/_ext/598284295/MY_SPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/598284295/MY_SPI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/598284295/MY_SPI.o.d" -MT "${OBJECTDIR}/_ext/598284295/MY_SPI.o.d" -MT ${OBJECTDIR}/_ext/598284295/MY_SPI.o -o ${OBJECTDIR}/_ext/598284295/MY_SPI.o ../../../5/app5.X/MY_SPI.c 
	
${OBJECTDIR}/_ext/2077993593/DIO.o: ../../../1/app1.X/DIO.c  .generated_files/flags/default/10fd5104699f0ffba9fba2b73f48c10454ff3aee .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2077993593" 
	@${RM} ${OBJECTDIR}/_ext/2077993593/DIO.o.d 
	@${RM} ${OBJECTDIR}/_ext/2077993593/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/2077993593/DIO.o.d" -MT "${OBJECTDIR}/_ext/2077993593/DIO.o.d" -MT ${OBJECTDIR}/_ext/2077993593/DIO.o -o ${OBJECTDIR}/_ext/2077993593/DIO.o ../../../1/app1.X/DIO.c 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/1b9ccec6c1e16c4eb810d1e9287d41f8469d728e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/EEPROM_1k.o: EEPROM_1k.c  .generated_files/flags/default/73fc5223245175fe1d2e7e8b50fb0f067c5bb4c0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EEPROM_1k.o.d 
	@${RM} ${OBJECTDIR}/EEPROM_1k.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/EEPROM_1k.o.d" -MT "${OBJECTDIR}/EEPROM_1k.o.d" -MT ${OBJECTDIR}/EEPROM_1k.o -o ${OBJECTDIR}/EEPROM_1k.o EEPROM_1k.c 
	
${OBJECTDIR}/_ext/2077993593/MY_LCD4.o: ../../../1/app1.X/MY_LCD4.c  .generated_files/flags/default/32eafc0e1030b0a128818a46feff9c542fc1da7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2077993593" 
	@${RM} ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d 
	@${RM} ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d" -MT "${OBJECTDIR}/_ext/2077993593/MY_LCD4.o.d" -MT ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o -o ${OBJECTDIR}/_ext/2077993593/MY_LCD4.o ../../../1/app1.X/MY_LCD4.c 
	
${OBJECTDIR}/_ext/2077993593/int_to_arr.o: ../../../1/app1.X/int_to_arr.c  .generated_files/flags/default/6214f2e9a6e9fb5666a3f12bbead6db430dc3de3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2077993593" 
	@${RM} ${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d 
	@${RM} ${OBJECTDIR}/_ext/2077993593/int_to_arr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3 -mno-const-data-in-progmem     -MD -MP -MF "${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d" -MT "${OBJECTDIR}/_ext/2077993593/int_to_arr.o.d" -MT ${OBJECTDIR}/_ext/2077993593/int_to_arr.o -o ${OBJECTDIR}/_ext/2077993593/int_to_arr.o ../../../1/app1.X/int_to_arr.c 
	
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
${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"   -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} ${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3 -mno-const-data-in-progmem     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o ${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}/avr-objcopy -O ihex "${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/Atmega32_interface_with_eeprom1k.X.${IMAGE_TYPE}.hex"
	
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
