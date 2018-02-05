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
// Author..............: 	CEYHAN ILERI
// Creation-Date.......:	18.07.2017
//
// Modification History:
// ---------------------
//
//===========================================================================

//===========================================================================
// C02: INCLUDE FILES
//===========================================================================
#include <stdio.h>
#include <stdlib.h>
#include <priorityQueue.h>

//===========================================================================
// C03: PRIVATE CONSTANT DEFINITIONS
//===========================================================================

#define DBG printf
//#define DBG_EXT printf
//#define DBG(...)
#define DBG_EXT(...)

//===========================================================================
// C04: PRIVATE DATA TYPES
//===========================================================================

//===========================================================================
// C05: PRIVATE DATA DECLARATIONS
//===========================================================================

//===========================================================================
// C06: GLOBAL DATA DECLARATIONS
//===========================================================================

//===========================================================================
// C07: PRIVATE FUNCTION PROTOTYPES
//===========================================================================

//===========================================================================
// C08: PRIVATE FUNCTIONS
//===========================================================================
//---------------- Implement this events the way you want. ----------------// 
void highWaterEvent(int index)
{
	DBG("Buffer is almost full.Be careful!\r\n");
}

void lowWaterEvent(int index)
{
	DBG("Buffer is almost empty.Papa needs food!\r\n");
}
//===========================================================================
// C09: GLOBAL FUNCTIONS
//===========================================================================
int main()
{
	char* fetchedData;
	int counter = 0;
	int len = 0;

	call_back highWaterCallbackFunction = highWaterEvent;
	call_back lowWaterCallbackFunction  = lowWaterEvent;

	queueInit();

	queueInsert(9, 	"TEST9", 	highWaterCallbackFunction);
	queueInsert(11, "TEST11", 	highWaterCallbackFunction);
	queueInsert(12, "TEST12", 	highWaterCallbackFunction);
	queueInsert(2, 	"TEST2", 	highWaterCallbackFunction);
	queueInsert(10, "TEST10", 	highWaterCallbackFunction);
	queueInsert(8, 	"TEST8", 	highWaterCallbackFunction);
	queueInsert(3, 	"TEST3", 	highWaterCallbackFunction);
	queueInsert(12, "TEST1212",	highWaterCallbackFunction);
	queueInsert(7, 	"TEST7", 	highWaterCallbackFunction);
	queueInsert(5, 	"TEST5", 	highWaterCallbackFunction);
	queueInsert(6, 	"TEST6", 	highWaterCallbackFunction);

	DBG("\r\n-------------CURRENT QUEUE-------------\r\n");
	dumpQueueFromHeadToTail();
	DBG("\r\n");

	len = getQueueLength();
	for(counter = 0; counter < len; counter++)
	{
		fetchedData= queueFetch(lowWaterCallbackFunction);
		DBG("Fetched : %s\r\n", fetchedData);
		DBG("New queue : \r\n");
		dumpQueueFromHeadToTail();
	}

    return 0;
}

