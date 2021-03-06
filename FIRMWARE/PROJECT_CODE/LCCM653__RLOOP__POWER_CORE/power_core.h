/**
 * @file		POWER_CORE.H
 * @brief		Main header file for the power node core functions
 * @author		Lachlan Grogan
 * @copyright	rLoop Inc.
 * @st_fileID	LCCM653R0.FILE.001
 */

#ifndef _POWER_CORE_H_
#define _POWER_CORE_H_
	#include <localdef.h>
	#if C_LOCALDEF__LCCM653__ENABLE_THIS_MODULE == 1U

		#include <LCCM653__RLOOP__POWER_CORE/PI_COMMS/power_core__pi_comms__types.h>
		#include <LCCM653__RLOOP__POWER_CORE/power_core__state_types.h>

		//local fault flags
		#include <LCCM653__RLOOP__POWER_CORE/power_core__fault_flags.h>



		//for software fault tree handling
		#include <MULTICORE/LCCM284__MULTICORE__FAULT_TREE/fault_tree__public.h>


		/*******************************************************************************
		Defines
		*******************************************************************************/





		/*******************************************************************************
		Structures
		*******************************************************************************/

		/** Main Power Node Structure */
		struct _strPWRNODE
		{
			//upper structure guarding
			Luint32 u32Guard1;

			/** fault flags structure */
			struct
			{

				/** Main top level fault system */
				FAULT_TREE__PUBLIC_T sTopLevel;

			}sFaults;

			/** Power on state machines and diagnostics */
			struct
			{

				/** The current Init State */
				E_PWRNODE__INIT_STATES eState;

			}sInit;

			/** DC/DC Converter control layer */
			struct
			{

				/** DC/DC state machine */
				E_PWR_DC__STATE_T eState;

			}sDC;

			/** Pi Comms Layer */
			struct
			{

				/** the current state */
				E_POWER_PICOM__STATE_T eState;

			}sPiComms;


			/** Win32 Functions*/
#ifdef WIN32
			struct
			{
				/** The node temp from the TSYS01 sensor */
				Lfloat32 f32NodeTemperature;

			}sWIN32;

#endif
			//lower structure guarding
			Luint32 u32Guard2;

		};


		/*******************************************************************************
		Function Prototypes
		*******************************************************************************/
		DLL_DECLARATION void vPWRNODE__Init(void);
		DLL_DECLARATION void vPWRNODE__Process(void);

		//fault subsystem
		void vPWRNODE_FAULTS__Init(void);
		void vPWRNODE_FAULTS__Process(void);

		//main application state machine
		void vPWRNODE_SM__Init(void);

		//DC/DC converter system
		void vPWRNODE_DC__Init(void);
		void vPWRNODE_DC__Process(void);

		//BMS interface layer
		void vPWRNODE_BMS__Init(void);
		void vPWRNODE_BMS__Process(void);

		//pi comms interface
		void vPWRNODE_PICOMMS__Init(void);
		void vPWRNODE_PICOMMS__Process(void);

		//CAN
		void vPWRNODE_CAN__Init(void);
		void vPWRNODE_CAN__Process(void);

		//battery temperature system
		void vPWRNODE_BATTTEMP__Init(void);
		void vPWRNODE_BATTTEMP__Process(void);
		void vPWRNODE_BATTTEMP__Start_Search(void);
		Luint8 u8PWRNODE_BATTTEMP__Search_IsBusy(void);

		//node temperature reading
		void vPWRNODE_NODETEMP__Init(void);
		void vPWRNODE_NODETEMP__Process(void);
		Lfloat32 f32PWRNODE_NODETEMP__Get_Temperature_DegC(void);

		//node pressure reading
		void vPWNODE_NODEPRESS__Init(void);
		void vPWNODE_NODEPRESS__Process(void);

#ifdef WIN32
		void vPWRNODE_WIN32__Init(void);
		DLL_DECLARATION void vPWRNODE_WIN32__Set_NodeTemperature(Lfloat32 f32Temperature);
#endif

	#endif //#if C_LOCALDEF__LCCM653__ENABLE_THIS_MODULE == 1U
	//safetys
	#ifndef C_LOCALDEF__LCCM653__ENABLE_THIS_MODULE
		#error
	#endif
#endif //_POWER_CORE_H_

