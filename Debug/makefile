################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./MQTTCC3100.obj" \
"./MQTTClient.obj" \
"./MQTTConnectClient.obj" \
"./MQTTConnectServer.obj" \
"./MQTTDeserializePublish.obj" \
"./MQTTFormat.obj" \
"./MQTTPacket.obj" \
"./MQTTSerializePublish.obj" \
"./MQTTSubscribeClient.obj" \
"./MQTTSubscribeServer.obj" \
"./MQTTUnsubscribeClient.obj" \
"./MQTTUnsubscribeServer.obj" \
"./board.obj" \
"./cli_uart.obj" \
"./device.obj" \
"./driver.obj" \
"./events.obj" \
"./flowcont.obj" \
"./fs.obj" \
"./main.obj" \
"./msp432_startup_ccs.obj" \
"./myinit.obj" \
"./netapp.obj" \
"./netcfg.obj" \
"./nonos.obj" \
"./socket.obj" \
"./spawn.obj" \
"./spi_cc3100.obj" \
"./uart_cc3100.obj" \
"./wlan.obj" \
"../msp432p401r.cmd" \
"../msp432p4xx_driverlib.lib" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
final_ece461.out \

EXE_OUTPUTS__QUOTED += \
"final_ece461.out" \

BIN_OUTPUTS += \
final_ece461.hex \

BIN_OUTPUTS__QUOTED += \
"final_ece461.hex" \


# All Target
all: final_ece461.out

# Tool invocations
final_ece461.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP432 Linker'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off -z -m"final_ece461.map" --heap_size=1024 --stack_size=512 -i"/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" -i"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/lib" -i"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="final_ece461_linkInfo.xml" --rom_model -o "final_ece461.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

final_ece461.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP432 Hex Utility'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armhex"  -o "final_ece461.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "MQTTCC3100.pp" "MQTTClient.pp" "MQTTConnectClient.pp" "MQTTConnectServer.pp" "MQTTDeserializePublish.pp" "MQTTFormat.pp" "MQTTPacket.pp" "MQTTSerializePublish.pp" "MQTTSubscribeClient.pp" "MQTTSubscribeServer.pp" "MQTTUnsubscribeClient.pp" "MQTTUnsubscribeServer.pp" "board.pp" "cli_uart.pp" "device.pp" "driver.pp" "events.pp" "flowcont.pp" "fs.pp" "main.pp" "msp432_startup_ccs.pp" "myinit.pp" "netapp.pp" "netcfg.pp" "nonos.pp" "socket.pp" "spawn.pp" "spi_cc3100.pp" "uart_cc3100.pp" "wlan.pp" 
	-$(RM) "MQTTCC3100.obj" "MQTTClient.obj" "MQTTConnectClient.obj" "MQTTConnectServer.obj" "MQTTDeserializePublish.obj" "MQTTFormat.obj" "MQTTPacket.obj" "MQTTSerializePublish.obj" "MQTTSubscribeClient.obj" "MQTTSubscribeServer.obj" "MQTTUnsubscribeClient.obj" "MQTTUnsubscribeServer.obj" "board.obj" "cli_uart.obj" "device.obj" "driver.obj" "events.obj" "flowcont.obj" "fs.obj" "main.obj" "msp432_startup_ccs.obj" "myinit.obj" "netapp.obj" "netcfg.obj" "nonos.obj" "socket.obj" "spawn.obj" "spi_cc3100.obj" "uart_cc3100.obj" "wlan.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

