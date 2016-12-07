/******************************************************************************
**              Copyright (C) 2015 Laird Technologies
**
** Project:     Console mode UwFlash Upgrade Utility
**
** Module:      UwFlashCon.CPP
**
*******************************************************************************/

/******************************************************************************/
// CONDITIONAL COMPILE DEFINES
/******************************************************************************/

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "target.h"

#include <stdio.h>
#include "UwFlashEmbed.h"
#include "Misc.h"


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
#pragma argsused
int main(int argc, char* argv[])
{
    unsigned int nElapsed;
    unsigned int nStartTick = MiscGetTickCount();
    /* go for upgrade ... */
    UwFlashUpgradeFirmare();
    nElapsed   = MiscElapsedTime(nStartTick)/1000;

    printf("\nTime=%d seconds",nElapsed);

    return 0;
}



/******************************************************************************/
// END OF FILE
/******************************************************************************/

