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
// CONDITIONAL COMPILE DEFINES
/******************************************************************************/

/******************************************************************************/
// Include Files
/******************************************************************************/
#include "target.h"

#include "UwfUpgrade.h"
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

//=============================================================================
// Return the tick count since startup in milliseconds
//                                        ^^^^^^^^^^^^
//=============================================================================
unsigned int /* in milliseconds */
MiscGetTickCount(
    void
    )
{
    /* TODO - return the current millisecond count */

    //return GetTickCount();
}

//=============================================================================
// Returns true if application is to be closed.
// It will be polled as often as possible by the downloader engine and so you
// can add stuff that can make other things happen.
//
// Note Serial Port Rx Polling is done in function PollSerialRxData() which is
// called from the routine which calls this function, so don't call in this
// function
//=============================================================================
bool
MiscPollBackgroundTarget(
    void
    )
{
    /* TODO - add code here you want to get polled */

    return false;
}

//=============================================================================
// This function is equivalent to fopen in normal 'c' file i/o.
//
// This will be called be the engine to open the uwf file which contains the
// firmware which will have been supplied by Laird. Assume that the open will
// be for read access only.
//
// Ignore both filename and mode parameters.
//
// If you have the file in some linear memory space and you know the address
// then just initialise an offset counter to 0 and reference that counter
// when StdFREAD is called to return data from that offset onwards
//
//=============================================================================
void * /* this pointer will be used by StdFREAD() and StdFCLOSE() */
StdFOPEN (
    const char * filename, /* meaningless - ignore */
    const char * mode /* ignore as this function only called to read file */
    )
{
    /* TODO - initialise access to the .uwf file provided by Laird */

    //return fopen(xxx,yyy);
}

//=============================================================================
// This function is equivalent to fread in normal 'c' file i/o.
//
// Just return (size * count) bytes from the offset you initialise to 0
// in StdFOPEN and then increment the offset by (size * count). The data is
// returned in 'ptr' buffer
//
//=============================================================================
size_t
StdFREAD(
    void * ptr,     /* destination buffer pointer */
    size_t size,    /* (size * count) bytes are to be read */
    size_t count,   /* (size * count) bytes are to be read */
    void * stream   /* will have been returned by StdFOPEN() */
    )
{
    /* TODO - return (size * count) bytes starting from offset */

    //return fread(ptr,size,count,(FILE *)stream);
}

//=============================================================================
// This function is equivalent to fclose in normal 'c' file i/o and best
// action is to reset the offset you defined for StdFOPEN to say -1.
//
//=============================================================================
int
StdFCLOSE(
    void * stream  /* will have been returned by StdFOPEN() */
    )
{
    /* TODO - close access to the Laird provided uwf file  */

    //return fclose((FILE *)stream);
}


/******************************************************************************/
// END OF FILE
/******************************************************************************/


