/******************************************************************************
**              Copyright (C) 2007 TDK Systems Europe Ltd
**
** Project:
**
** Module:      TSerialPortTargetEx.CPP
**
*******************************************************************************/

/******************************************************************************/
// CONDITIONAL COMPILE DEFINES
/******************************************************************************/

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "target.h"
#include "TSerialPortTarget.h"

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

TSerialPortTarget *gpSerialPort=NULL;


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

//=============================================================================
//=============================================================================

/******************************************************************************/
/******************************************************************************/
// Global Functions or Public Members
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
// Global Functions Non Class Members
/******************************************************************************/
/******************************************************************************/

/*=============================================================================*/
/*=============================================================================*/
TSerialPortBase *GetSerialPort(TSerialOnRxData *pOnRxData)
{
	gpSerialPort = new TSerialPortTarget(pOnRxData);
	return gpSerialPort;
}

/*=============================================================================*/
/*=============================================================================*/
void PollSerialRxData()
{
    unsigned int nRxCount=SerialRxDataCount();

    if( nRxCount )
    {
        gpSerialPort->OnSerialReceive(nRxCount);
    }
}

/******************************************************************************/
// END OF FILE
/******************************************************************************/




