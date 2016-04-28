################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Crystalfontz128x128_ST7735.obj: ../Crystalfontz128x128_ST7735.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Crystalfontz128x128_ST7735.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj: ../HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTCC3100.obj: ../MQTTCC3100.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTCC3100.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTClient.obj: ../MQTTClient.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTClient.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTConnectClient.obj: ../MQTTConnectClient.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTConnectClient.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTConnectServer.obj: ../MQTTConnectServer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTConnectServer.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTDeserializePublish.obj: ../MQTTDeserializePublish.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTDeserializePublish.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTFormat.obj: ../MQTTFormat.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTFormat.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTPacket.obj: ../MQTTPacket.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTPacket.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTSerializePublish.obj: ../MQTTSerializePublish.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTSerializePublish.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTSubscribeClient.obj: ../MQTTSubscribeClient.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTSubscribeClient.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTSubscribeServer.obj: ../MQTTSubscribeServer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTSubscribeServer.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTUnsubscribeClient.obj: ../MQTTUnsubscribeClient.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTUnsubscribeClient.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

MQTTUnsubscribeServer.obj: ../MQTTUnsubscribeServer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="MQTTUnsubscribeServer.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

board.obj: ../board.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="board.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

cli_uart.obj: ../cli_uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="cli_uart.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

context.obj: ../context.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="context.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

device.obj: ../device.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="device.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

display.obj: ../display.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="display.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

driver.obj: ../driver.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="driver.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

events.obj: ../events.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="events.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

flowcont.obj: ../flowcont.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="flowcont.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

fontfixed6x8.obj: ../fontfixed6x8.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="fontfixed6x8.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

fs.obj: ../fs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="fs.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

lcd_display.obj: ../lcd_display.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="lcd_display.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

line.obj: ../line.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="line.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

msp432_startup_ccs.obj: ../msp432_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="msp432_startup_ccs.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

my_mqtt.obj: ../my_mqtt.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="my_mqtt.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

myinit.obj: ../myinit.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="myinit.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

netapp.obj: ../netapp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="netapp.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

netcfg.obj: ../netcfg.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="netcfg.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

nonos.obj: ../nonos.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="nonos.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

ped_adc.obj: ../ped_adc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="ped_adc.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

socket.obj: ../socket.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="socket.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

spawn.obj: ../spawn.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="spawn.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

spi_cc3100.obj: ../spi_cc3100.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="spi_cc3100.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

string.obj: ../string.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="string.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

uart_cc3100.obj: ../uart_cc3100.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="uart_cc3100.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

wlan.obj: ../wlan.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include" --include_path="/home/daniel/Programs/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="/home/daniel/Programs/ti/workspace2/final_ece461/driverlib/MSP432P4xx" --include_path="/home/daniel/Programs/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.6/include" --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="wlan.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


