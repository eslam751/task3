/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define interrupt_grouping_xxx		0x4
#define interrupt_grouping_xxy		0x5
#define interrupt_grouping_xyy		0x6
#define interrupt_grouping_yyy		0x7
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	GPIO_Port_A,
	GPIO_Port_B,
	GPIO_Port_C,
	GPIO_Port_D,
	GPIO_Port_E,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator_0,
	PWM0_Generator_1,
	PWM0_Generator_2,
	QEI0,
	ADC0_Sequence_0,
	ADC0_Sequence_1,
	ADC0_Sequence_2,
	ADC0_Sequence_3,
	Watchdog_Timers_0_and_1,
	Bit_Timer_0A,
	Bit_Timer_0B,
	Bit_Timer_1A,
	Bit_Timer_1B,
	Bit_Timer_2A,
	Bit_Timer_2B,
	Analog_Comparator_0,
	Analog_Comparator_1,
	System_Control=28,
	Flash_Memory_Control_EEPROM_Control,
	GPIO_Port_F,
	UART2=33,
	SSI1,
	Bit_Timer_3A,
	Bit_Timer_3B,
	I2C1,
	QEI1,
	CAN0,
	CAN1,
	Hibernation_Module=43,
	USB,
	PWM_Generator_3,
	μDMA_Software,
	μDMA_Error,
	ADC1_Sequence_0,
	ADC1_Sequence_1,
	ADC1_Sequence_2,
	ADC1_Sequence_3,
	SSI2=57,
	SSI3,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	I2C2=68,
	I2C3,
	Bit_Timer_4A,
	Bit_Timer_4B,
	Bit_Timer_5A=92,
	Bit_Timer_5B,
}IntCtrl_InterruptType;

typedef struct
{
	IntCtrl_InterruptType   InterruptNum;
	uint_8_ 				GroupPri;
	uint_8_ 				SubGroupPri;	
}IntCtrl_InterruptCfgType;
 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
