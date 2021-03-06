/**
 * @file		POWER_CORE__DC_CONVERTER.C
 * @brief		Fault handing subsystem
 * @author		Lachlan Grogan
 * @copyright	rLoop Inc.
 */
/**
 * @addtogroup RLOOP
 * @{ */
/**
 * @addtogroup POWER_NODE
 * @ingroup RLOOP
 * @{ */
/**
 * @addtogroup POWER_NODE__DC_CONVERTER
 * @ingroup POWER_NODE
 * @{ */

#include "../power_core.h"
#if C_LOCALDEF__LCCM653__ENABLE_THIS_MODULE == 1U
#if C_LOCALDEF__LCCM652__ENABLE_DC_CONVERTER == 1U

extern struct _strPWRNODE sPWRNODE;

/***************************************************************************//**
 * @brief
 * Init the DC/DC Converter system
 *
 */
void vPWRNODE_DC__Init(void)
{

	//configure our states
	sPWRNODE.sDC.eState = DC_STATE__RESET;

	//Setup the hardware pins
	//GPIOA0
	vRM4_GIO__Set_BitDirection(gioPORTA, 0U, GIO_DIRECTION__OUTPUT);

	//set to ON
	vRM4_GIO__Set_Bit(gioPORTA, 0U, 1U);

}

/***************************************************************************//**
 * @brief
 * Process the DC/DC converter control
 *
 */
void vPWRNODE_DC__Process(void)
{
	//todo, process the watchdog, etc.

	switch(sPWRNODE.sDC.eState)
	{

		case DC_STATE__RESET:
			//just come out of reset
			break;

		case DC_STATE__CHECK_WDT_PET:
			//do we need to pet the WDT in its current window?
			break;

		case DC_STATE__CHECK_POD_SAFE:
			//do we need to implement the Pod safe command?
			break;


	}//switch(sPWRNODE.sDC.eState)

}

/***************************************************************************//**
 * @brief
 * To implement pod safe, first we need to unlock the function with a separate command
 * This will provent spurious safes.
 *
 * @param[in]		u32UnlockKey			The key, should be ABCD1298
 */
void vPWRNODE_DC__Pod_Safe_Unlock(Luint32 u32UnlockKey)
{
	if(u32UnlockKey == 0xABCD1298)
	{
		//OK to unlock
	}
	else
	{
		//error, wrong unlock command
	}

}


#endif //C_LOCALDEF__LCCM652__ENABLE_DC_CONVERTER
#endif //#if C_LOCALDEF__LCCM653__ENABLE_THIS_MODULE == 1U
//safetys
#ifndef C_LOCALDEF__LCCM653__ENABLE_THIS_MODULE
	#error
#endif
/** @} */
/** @} */
/** @} */

