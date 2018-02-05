//===========================================================================
// C01: FILE DESCRIPTION
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
// C02: INCLUDE FILES
//===========================================================================
#include <stdio.h>
#include <stdlib.h>
#include <priorityQueue.h>

//===========================================================================
// C03: PRIVATE CONSTANT DEFINITIONS
//===========================================================================
#define QUEUE_SIZE	20	

//--------------------- Debug macros (You can switch define statements to open debugs) --------------------- //
#define DBG printf
//#define DBG_EXT printf
//#define DBG(...)
#define DBG_EXT(...)

//--------------------- Threshold macros for callback functions / events --------------------- //
#define CHECK_HIGHWATER_THRESHOLD(size, length)	( ((length * 100) / HIGH_WATER_MARK_PERCENTAGE) > size )
#define CHECK_LOWWATER_THRESHOLD(size, length)	( ((length * 100) / LOW_WATER_MARK_PERCENTAGE) 	< size )
//===========================================================================
// C04: PRIVATE DATA TYPES
//===========================================================================

//--------------------- This is our single queue (node) --------------------- //
typedef struct Priority_Queue_Element
{
	int priority;
	char* data;

	struct Priority_Queue_Element *nextElement;
	struct Priority_Queue_Element *prevElement;
}Priority_Queue_Element;


//------------------------ This is our queue list ------------------------- //
typedef struct priority_queue_list
{	
	struct Priority_Queue_Element *headElement;
	struct Priority_Queue_Element *lastElement;
	struct Priority_Queue_Element *currentElement;

	int queueLen;
	int maxQueueSize;
}Priority_Queue_List;


//===========================================================================
// C05: PRIVATE DATA DECLARATIONS
//===========================================================================

Priority_Queue_List* PriorityQueueList;

//===========================================================================
// C06: GLOBAL DATA DECLARATIONS
//===========================================================================

//===========================================================================
// C07: PRIVATE FUNCTION PROTOTYPES
//===========================================================================
//---------------------------------------------------------------------------
// Function......: returnErrorWithMessage 
// Description...: Displays the given message and returns false
// Return Value..: FALSE
// Parameters....: Message to be displayed
//---------------------------------------------------------------------------
bool returnErrorWithMessage(char* message);

//---------------------------------------------------------------------------
// Function......: insertToTheQueueAfterSpecificElement 
// Description...: Returns the length of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
bool insertToTheQueueAfterSpecificElement(int priority, int newPriority, char* data);

//---------------------------------------------------------------------------
// Function......: isQueueEmpy 
// Description...: Check the queue state
// Return Value..: Returns true if the queue is empty
// Parameters....:
//---------------------------------------------------------------------------
bool isQueueEmpy();

//---------------------------------------------------------------------------
// Function......: insertTheElementToTheHeadOfTheQueue
// Description...: Insert given element to the head of the queue
// Return Value..: 
// Parameters....: Priority -> Priority of the message
//				 : Priority -> Data of the message
//---------------------------------------------------------------------------
void insertTheElementToTheHeadOfTheQueue(int priority, char* data);

//---------------------------------------------------------------------------
// Function......: deleteTheHeadElementOfTheQueue
// Description...: Deletes the head (first) element of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
void deleteTheHeadElementOfTheQueue(void);

//===========================================================================
// C08: PRIVATE FUNCTIONS
//===========================================================================
//---------------------------------------------------------------------------
// Function......: returnErrorWithMessage 
// Description...: Displays the given message and returns false
// Return Value..: FALSE
// Parameters....: Message to be displayed
//---------------------------------------------------------------------------
bool returnErrorWithMessage(char* message)
{
	printf("%s\r\n", message);
	return FALSE;
}

//---------------------------------------------------------------------------
// Function......: insertTheElementToTheHeadOfTheQueue
// Description...: Insert given element to the head of the queue
// Return Value..: 
// Parameters....: Priority -> Priority of the message
//				 : Priority -> Data of the message
//---------------------------------------------------------------------------
void insertTheElementToTheHeadOfTheQueue(int priority, char* data)
{
	Priority_Queue_Element *link = (struct Priority_Queue_Element*) malloc(sizeof(struct Priority_Queue_Element));
	link->priority = priority;
	link->data = data;

	if(isQueueEmpy()) 
	{
		PriorityQueueList->lastElement = link;
	} 
	else 
	{
		PriorityQueueList->headElement->prevElement = link;
	}

	link->nextElement = PriorityQueueList->headElement;
	PriorityQueueList->headElement = link;
}

//---------------------------------------------------------------------------
// Function......: isQueueEmpy 
// Description...: Check the queue state
// Return Value..: Returns true if the queue is empty
// Parameters....:
//---------------------------------------------------------------------------
bool isQueueEmpy()
{
   return PriorityQueueList->headElement == NULL;
}

//---------------------------------------------------------------------------
// Function......: insertToTheQueueAfterSpecificElement 
// Description...: Returns the length of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
bool insertToTheQueueAfterSpecificElement(int priority, int newPriority, char* data) 
{
	Priority_Queue_Element *temp = PriorityQueueList->headElement; 
	
	if(PriorityQueueList->headElement == NULL) 
	{
		return FALSE;
	}

	while(temp->priority != priority) 
	{
		if(temp->nextElement == NULL) 
		{
			return false;
		} 
		else 
		{           
			temp = temp->nextElement;
		}
	}
	
	struct Priority_Queue_Element *newLink = (struct Priority_Queue_Element*) malloc(sizeof(struct Priority_Queue_Element));
	newLink->priority = newPriority;
	newLink->data = data;

	if(temp == PriorityQueueList->lastElement) 
	{
		newLink->nextElement = NULL; 
		PriorityQueueList->lastElement = newLink; 
	} 
	else 
	{
		newLink->nextElement = temp->nextElement;         
		temp->nextElement->prevElement = newLink;
	}
	
	newLink->prevElement = temp; 
	temp->nextElement = newLink; 

	return true; 
}

//---------------------------------------------------------------------------
// Function......: deleteTheHeadElementOfTheQueue
// Description...: Deletes the head (first) element of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
void deleteTheHeadElementOfTheQueue(void)
{
	if(PriorityQueueList->headElement->nextElement == NULL)
	{
		PriorityQueueList->lastElement = NULL;
	} 
	else 
	{
		PriorityQueueList->headElement->nextElement->prevElement = NULL;
	}

	PriorityQueueList->headElement = PriorityQueueList->headElement->nextElement;
}

//===========================================================================
// C09: GLOBAL FUNCTIONS
//===========================================================================
//---------------------------------------------------------------------------
// Function......: queueInit
// Description...: Initialize the queue (Assigns the maximum size).
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
void queueInit (void)
{
	PriorityQueueList = (Priority_Queue_List *)calloc(1, sizeof (Priority_Queue_List));

	PriorityQueueList->queueLen 		= 0;
	PriorityQueueList->maxQueueSize 	= QUEUE_SIZE;
	PriorityQueueList->headElement		= NULL;
	PriorityQueueList->lastElement		= NULL;
	PriorityQueueList->currentElement	= NULL;
}

//---------------------------------------------------------------------------
// Function......: queueInsert
// Description...: Insert data and it's priority to the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
BOOL queueInsert (int priority, char* data, call_back highWaterCallbackFunction)
{
	DBG("----------------------------------------------\r\n");
	if( PriorityQueueList->queueLen == PriorityQueueList->maxQueueSize )
	{
		return returnErrorWithMessage("Queue is full!");
	}

	if( isQueueEmpy() )
	{
		insertTheElementToTheHeadOfTheQueue(priority, data);
	}
	else if( (priority) > (PriorityQueueList->headElement->priority) )
	{
		insertTheElementToTheHeadOfTheQueue(priority, data);
	}
	else
	{
		PriorityQueueList->currentElement = PriorityQueueList->headElement;
		while((PriorityQueueList->currentElement->nextElement != NULL) && ((priority) < (PriorityQueueList->currentElement->nextElement->priority)))
		{
			PriorityQueueList->currentElement = PriorityQueueList->currentElement->nextElement;
		}

		if ( ! insertToTheQueueAfterSpecificElement(PriorityQueueList->currentElement->priority, priority, data) )
			returnErrorWithMessage("Error inserting element...");
	}

	DBG("New queue element -> index    : %d\r\n", PriorityQueueList->queueLen);
	DBG("New queue element -> data     : %s\r\n", data);
	DBG("New queue element -> prioirty : %d\r\n", priority);
	DBG("----------------------------------------------\r\n");

	if( CHECK_HIGHWATER_THRESHOLD( PriorityQueueList->maxQueueSize, PriorityQueueList->queueLen ) )
	{
		highWaterCallbackFunction(PriorityQueueList->queueLen);
	}

	PriorityQueueList->queueLen++;
	return TRUE;
}

//---------------------------------------------------------------------------
// Function......: queueFetch (pop)
// Description...: Fethes the data with the lowest priority
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
char* queueFetch (call_back lowWaterCallbackFunction)
{
	char* retChar;

	if( PriorityQueueList->queueLen == 0 )
	{
		return NULL;		
	}

	retChar = PriorityQueueList->headElement->data;
	deleteTheHeadElementOfTheQueue();

	if( CHECK_LOWWATER_THRESHOLD( PriorityQueueList->maxQueueSize, PriorityQueueList->queueLen ) )
	{
		lowWaterCallbackFunction(PriorityQueueList->queueLen);
	}

	PriorityQueueList->queueLen--;
	return retChar;
}

//---------------------------------------------------------------------------
// Function......: getQueueLength 
// Description...: Returns the length of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
int getQueueLength (void)
{
	return 	PriorityQueueList->queueLen;
}

//---------------------------------------------------------------------------
// Function......: dumpQueueFromHeadToTail 
// Description...: Returns the length of the queue
// Return Value..: 
// Parameters....:
//---------------------------------------------------------------------------
void dumpQueueFromHeadToTail() {

	struct Priority_Queue_Element *ptr = PriorityQueueList->headElement;
		
	while(ptr != NULL) 
	{        
		DBG("%d - %s\r\n",ptr->priority,ptr->data);
		ptr = ptr->nextElement;
	}
	
	DBG("-------------------------------------\r\n");
}
