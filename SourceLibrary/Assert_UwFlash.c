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

/******************************************************************************/
/* Target Build Definition Header File */
/******************************************************************************/
#include "Target.h"

/******************************************************************************/
/* CONDITIONAL COMPILE DEFINES*/
/******************************************************************************/

/******************************************************************************/
/* Include Files*/
/******************************************************************************/
#include "project.h"
#include <stdio.h>  /* printf(), vprintf() */
#include <conio.h> /* getch() */
#include <stdarg.h>
#include <stdlib.h> /* exit() */

/******************************************************************************/
/* Local Defines*/
/******************************************************************************/

/******************************************************************************/
/* Local Macros*/
/******************************************************************************/

/******************************************************************************/
/* Local Forward Class,Struct & Union Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Local Class,Struct,Union Typedefs*/
/******************************************************************************/

/******************************************************************************/
/* External Variable Declarations*/
/******************************************************************************/

/******************************************************************************/
/* Global/Static Variable Declarations*/
/******************************************************************************/

/******************************************************************************/
/* External Function Declarations*/
/******************************************************************************/
VOID DisplayTraceMessage(char *pMsg);
UI16 DisplayAssertMessage(char *pMsg);

/******************************************************************************/
/* Local Forward Function Declarations*/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/* Local Functions or Private Members*/
/******************************************************************************/
/******************************************************************************/


/******************************************************************************/
/******************************************************************************/
/* Global Functions or Public Members*/
/******************************************************************************/
/******************************************************************************/
/*============================================================================*/
/*============================================================================*/
VOID
RelMessage(
    CHAR *pPrintfFormat,
    CHAR *pCondition,
    CHAR *pFilename,
    INT lineNum,
    INT nExitCode
    )
{
#if ASSERT_MSG_BUF_LEN > 0
    char *pMsgBuf = (char *)malloc(ASSERT_MSG_BUF_LEN+4);
    if(pMsgBuf)
    {
        sprintf(pMsgBuf,pPrintfFormat,pCondition,pFilename,lineNum);
        /* Display the message on console */
        DisplayAssertMessage(pMsgBuf);
    }

    if(nExitCode)
    {
        exit(nExitCode);
    }
#else
    for(;;);
#endif
}

/*============================================================================*/
/*============================================================================*/
VOID
RelFail(
    INT nExitCode
    )
{
#if ASSERT_MSG_BUF_LEN > 0
    exit(nExitCode);
#else
    for(;;);
#endif
}

/*============================================================================*/
#if DEBUGLEVEL>=1
/*============================================================================*/
VOID
DevMessage(
    CHAR *pPrintfFormat,
    CHAR *pCondition,
    CHAR *pFilename,
    INT lineNum,
    INT nExitCode
    )
{
    RelMessage( pPrintfFormat, pCondition, pFilename, lineNum, nExitCode );
}
#endif

/*============================================================================*/
#if DEBUGLEVEL>=1
/*============================================================================*/
VOID
DevFail(
    INT nExitCode
    )
{
    exit(nExitCode);
}
#endif

/*============================================================================*/
#if DEBUGLEVEL>=1
/*============================================================================*/
VOID DevTrace(CONST CHAR* pcPrintfFormat, ...)
{
    char *pMsgBuf = (char *)malloc(ASSERT_MSG_BUF_LEN+4);
    if(pMsgBuf)
    {
        va_list l;
        va_start(l, pcPrintfFormat);
        vsprintf(pMsgBuf,pcPrintfFormat, l);
        va_end(l);

        /* Display the message on console */
        DisplayTraceMessage(pMsgBuf);

        free(pMsgBuf);
    }
}
#endif


/******************************************************************************/
/* END OF FILE*/
/******************************************************************************/
