// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Copyright (c) 2016, Laird                                                  ++
//                                                                            ++
// Permission to use, copy, modify, and/or distribute this software for any   ++
// purpose with or without fee is hereby granted, provided that the above     ++
// copyright notice and this permission notice appear in all copies.          ++
//                                                                            ++
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES   ++
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF           ++
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR    ++
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES     ++
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN      ++
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR ++
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.                ++
//                                                                            ++
// SPDX-License-Identifier:ISC                                                ++
//                                                                            ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                                                                            ++
// Source to embed firmware upgrader functionality into a host system which   ++
// interacts with specific Laird modules. The host can be a microcontroller   ++
// or full blown OS based PC like Windows/Linex/Mac or other.                 ++
//                                                                            ++
// The source requires a C++ compiler and has been used to create utilities   ++
// supplied by Laird.                                                         ++
//                                                                            ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#if !defined(_TSERIALPORTTARGETVCL_H)     /* prevent multiple inclusions */
#define _TSERIALPORTTARGETVCL_H

/******************************************************************************/
// Include Files
/******************************************************************************/
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ScktComp.hpp>
#include <ComCtrls.hpp>
#include "AdPort.hpp"


#include "Target.h"
#include "project.h"

#include "TSerialPortBase.h"

/******************************************************************************/
// Defines
/******************************************************************************/

/******************************************************************************/
// Macros
/******************************************************************************/

/******************************************************************************/
// Enum Typedefs
/******************************************************************************/

/******************************************************************************/
// Simple (non struct/union) Typedefs
/******************************************************************************/

/******************************************************************************/
// Forward declaration of Class, Struct & Unions
/******************************************************************************/

/******************************************************************************/
// Struct definitions
/******************************************************************************/

/******************************************************************************/
// Class definitions
/******************************************************************************/

class TSerialPortTarget : public TSerialPortBase
{
//Data
private:

//Data
protected:

//Data
public:
    TApdComPort    *mApdComPort;

//Functions
private:

//Functions
protected:
    TParity GetParityEnum(int nParity);   /* for this target */
    void __fastcall OnRxDataAvail(TObject *CP, WORD Count);

//Functions
public:
    TSerialPortTarget(TSerialOnRxData *pOwner);
    virtual ~TSerialPortTarget();

    virtual BOOLEAN IsOpen();
    virtual void Close();
    virtual bool ComOpen(char *pDevName,int nBaudrate,int nParity, int nStopBits, int nDataBits);
    virtual unsigned GetBlock(char *pDest, unsigned nCount);
    virtual void SetBreak(void);
    virtual void ClearBreak(void);
    virtual void FlushRxBuffer(void);
    virtual void FlushTxBuffer(void);
    virtual unsigned PutBlock(unsigned char *pTxBlock, unsigned short nLen);
    virtual void AssertDTR(void);
    virtual void DeassertDTR(void);
    virtual bool GetCtsState(void);

};


/******************************************************************************/
// Union definitions
/******************************************************************************/

/******************************************************************************/
// Global Functions (API etc) exported for other modules
/******************************************************************************/

/*============================================================================*/
/* This function returns the number of receive bytes waiting in an            */
/* underlying buffer waiting to be read                                       */
/* If need be take care of any threading issues                               */
/*============================================================================*/
unsigned int SerialRxDataCount(void);

#endif /* Prevention of multiple inclusion */
/******************************************************************************/
// END OF FILE
/******************************************************************************/
