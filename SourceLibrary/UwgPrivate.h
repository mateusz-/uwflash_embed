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

#if !defined(_UWGPRIVATE_H)     /* prevent multiple inclusions */
#define _UWGPRIVATE_H

/******************************************************************************/
/* Include Files*/
/******************************************************************************/

/******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/* Defines*/
/******************************************************************************/

/******************************************************************************/
/* Macros*/
/******************************************************************************/

#if defined(UWG_SINGLE_HEAP_MANAGER)
#define UwgMALLOC(_x_)          UwgMalloc_((_x_))
#define UwgFREE(_x_)            UwgFree_((VOID **)(_x_))
#else
#define UwgMALLOC(_x_)          UwgMalloc_((_x_))
#define UwgFREE(_x_)            UwgFree_((VOID **)(_x_))
#endif

#define UwgASSERT(cond)         DEVASSERT(cond)
#define UwgMESSAGE(msg)         DEVMESSAGE(msg)
#define UwgFAIL(msg)            DEVFAIL(msg)

#define UwgASSERT1(cond)        DEVASSERT1(cond)
#define UwgMESSAGE1(msg)        DEVMESSAGE1(msg)
#define UwgFAIL1(msg)           DEVFAIL1(msg)

#define UwgASSERT2(cond)        DEVASSERT2(cond)
#define UwgMESSAGE2(msg)        DEVMESSAGE2(msg)
#define UwgFAIL2(msg)           DEVFAIL2(msg)

#define UwgASSERT3(cond)        DEVASSERT3(cond)
#define UwgMESSAGE3(msg)        DEVMESSAGE3(msg)
#define UwgFAIL3(msg)           DEVFAIL3(msg)

#if DEBUGLEVEL>=4
    #define UwgASSERTPC(cond)   _DEVASSERT_ALWAYS_(cond)
    #define UwgMESSAGEPC(msg)   _DEVMESSAGE_ALWAYS_(msg)
    #define UwgFAILPC(msg)      _DEVFAIL_ALWAYS_(msg)

#else
    #define UwgASSERTPC(cond)   /* */
    #define UwgMESSAGEPC(msg)   /* */
    #define UwgFAILPC(msg)      /* */
#endif


/******************************************************************************/
/* Simple (non struct/union) Typedefs*/
/******************************************************************************/

/******************************************************************************/
/* Enum Typedefs*/
/******************************************************************************/

/******************************************************************************/
/* Forward declaration of Class, Struct & Unions*/
/******************************************************************************/

/******************************************************************************/
/* Class definitions*/
/******************************************************************************/

/******************************************************************************/
/* Struct definitions*/
/******************************************************************************/


/******************************************************************************/
/* Union definitions*/
/******************************************************************************/

/******************************************************************************/
/* Global Functions (API etc) exported for other modules*/
/******************************************************************************/

#if !defined(UWG_SINGLE_HEAP_MANAGER)
VOID *UwgMalloc_( UI32 size );
VOID  UwgFree_( VOID **pMemBlock );
#endif


/******************************************************************************/
/* UwgSomeFile.c */ /* CHANGE THIS */
/******************************************************************************/

/* Function protypes here */

/******************************************************************************/
/* UwgOtherFile.c */ /* CHANGE THIS */
/******************************************************************************/

/* Function protypes here */


/******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif /* Prevention of multiple inclusion */
/******************************************************************************/
/* END OF FILE*/
/******************************************************************************/
