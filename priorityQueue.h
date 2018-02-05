//===========================================================================
// I01: FILE DESCRIPTION
//===========================================================================
// Company.............: 	
// Project.............:  	Priority Queue Implementation
// Target..............: 	Linux
// Description.........: 	According to the wikipedia (sorry about that!) a priority queue is an abstract data type which is like a regular queue or stack data structure, 
// 							but where additionally each element has a "priority" associated with it. In a priority queue, 
//							an element with high priority is served before an element with low priority.
// Compiler............: 	GCC
// Version.............: 	1.0
// Author..............: 	Ceyhan ILERI
// Creation-Date.......:	18.07.2017
//
// Modification History:
// ---------------------
//
//===========================================================================

//===========================================================================
// I02: INCLUDE FILES
//===========================================================================
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//===========================================================================
// I03: CONSTANT DEFINITIONS
//===========================================================================

#define HIGH_WATER_MARK_PERCENTAGE 30
#define LOW_WATER_MARK_PERCENTAGE 10

typedef enum BOOL
{
	FALSE,
	TRUE
}BOOL;

//===========================================================================
// I04: DATA TYPES
//===========================================================================

typedef void (*call_back) (int argument);

//===========================================================================
// I04: EXTERN DATA BLOCK
//===========================================================================

//===========================================================================
// I05: FUNCTION PROTOTYPES
//===========================================================================
//---------------------------------------------------------------------------
// Function......: queueInit
// Description...: Initialize the queue (Assigns the maximum size).
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
void queueInit (void);

//---------------------------------------------------------------------------
// Function......: queueInsert (push)
// Description...: Insert data and it's priority to the queue
// Return Value..: True if the operations is successfull
// Parameters....: priority 		-> priority of the message
//				 : data 			-> data of the message
//				 : callbackFunction -> HIGH_WATER_MARK event function. 
//									   Users should implement this function in their own code. 
//---------------------------------------------------------------------------
BOOL queueInsert (int priority, char* data, call_back callbackFunction);

//---------------------------------------------------------------------------
// Function......: queueFetch (pop)
// Description...: Fethes the data with the lowest priority
// Return Value..: 
// Parameters....: callbackFunction -> LOW_WATER_MARK event function. 
//									   Users should implement this function in their own code. 
//---------------------------------------------------------------------------
char* queueFetch (call_back callbackFunction);

//---------------------------------------------------------------------------
// Function......: getQueueLength 
// Description...: Returns the length of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
int getQueueLength (void);

//---------------------------------------------------------------------------
// Function......: dumpQueueFromHeadToTail 
// Description...: Returns the length of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
void dumpQueueFromHeadToTail();


