/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{
	uint_8_ i;
	uint_32_ Register_offset,RegisterVal,Bit_offset;
	extern IntCtrl_InterruptCfgType IntCtrl_InterruptCfg[];
		/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	APINT=(uint_32_)(((uint_32_)0x05FA<<16|(uint_32_)interrupt_grouping_xxy<<8));
	
      
	
		/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
		 for(i=0; i<NUM_OF_ACTIVATED_INTERRUPTS;i++)
	{
		IntCtrl_InterruptType   Loc_InterruptNum = IntCtrl_InterruptCfg[i].InterruptNum;
		uint_8_    Loc_GroupPri  = IntCtrl_InterruptCfg[i].GroupPri;
		uint_8_ Loc_SubGroupPri	 = IntCtrl_InterruptCfg[i].SubGroupPri;
		
		/*TODO ENABLE\disable configured Interrupts*/
		
		Register_offset = Loc_InterruptNum/32;
		Bit_offset = Loc_InterruptNum%32;
		RegisterVal = NVIC_EN(Register_offset);
		
		set_bit_(RegisterVal,Bit_offset);
		
	/*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
		uint_32_* pri_address=(uint_32_*)(CORTEXM4_PERI_BASE_ADDRESS+0x400+(Loc_InterruptNum/4)*4);
		*pri_address |=(uint_32_)( Loc_SubGroupPri|Loc_GroupPri<<1)<<((8)*(Loc_InterruptNum%4))<<5;
		
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
