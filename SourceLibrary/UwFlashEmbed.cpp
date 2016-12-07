/******************************************************************************
**              Copyright (C) 2016 Laird
**
** Project:     Console mode UwFlash Upgrade Utility
**
** Module:      UwFlashEmbed.CPP
**
*******************************************************************************/

/******************************************************************************/
// CONDITIONAL COMPILE DEFINES
/******************************************************************************/

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "target.h"

#include "UwfUpgrade.h"
#include "UwFlashEmbed.h"
#include "AtUpgradeUITarget.h"


/******************************************************************************/
// Local Defines
/******************************************************************************/

/******************************************************************************/
// Local Macros
/******************************************************************************/

/******************************************************************************/
// Local Forward Class,Struct & Union Declarations
/******************************************************************************/

/******************************************************************************/
// Local Class,Struct,Union Typedefs
/******************************************************************************/

/******************************************************************************/
// External Variable Declarations
/******************************************************************************/

/******************************************************************************/
// Global/Static Variable Declarations
/******************************************************************************/

/******************************************************************************/
// External Function Declarations
/******************************************************************************/

/******************************************************************************/
// Local Forward Function Declarations
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
// Local Functions or Private Members
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
// Global Functions Non Class Members
/******************************************************************************/
/******************************************************************************/

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void UwFlashUpgradeFirmare(void)
{
    /* create and initialise user interface ... */
    AtUpgradeUITarget *pAtUpgradeUITarget = new AtUpgradeUITarget();
    gpAtUpgradeUI = pAtUpgradeUITarget;

    /* configure upgrade ... */
    gAtConfig.mTargetType = TARGET_PLATFORM;
    gAtConfig.mUserCommParms.mnBaudrate = UART_BAUDRATE_NORMAL_OPERATION;
    gAtConfig.SerialPortNameSet(SERIALPORT_DEVICE_NAME);  /* comport the module can be accessed */

    gUwfUpgrade.Start(UWF_FILENAME);
}



/******************************************************************************/
// END OF FILE
/******************************************************************************/

