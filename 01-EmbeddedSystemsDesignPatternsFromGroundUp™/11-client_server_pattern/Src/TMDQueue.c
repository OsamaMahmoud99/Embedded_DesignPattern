/*
 * TMDQueue.c
 *
 *  Created on: Apr 24, 2025
 *      Author: Osama
 */


#include "TMDQueue.h"
#include <stdlib.h>
#include "uart.h"

uint32_t TMDQueue_getNextIndex(TMDQueue * const me, uint32_t index){

	return (index + 1)%QUEUE_SIZE;
}

TMDQueue * TMDQueue_Create(void)
{
	TMDQueue* me = (TMDQueue*)malloc(sizeof(TMDQueue));

	if(me != NULL){
		//init_queue
	}

	return me;
}

void TMDQueue_Init(TMDQueue * const me)
{
	me->head = 0;
	me->size = 0;
}

void TMDQueue_Insert(TMDQueue * const me, const TimeMarkedData tmd)
{
	printf("Inserting at : %d TimeInterval #: %d\n\r", me->head, tmd.timeInterval);
	me->buffer[me->head] = tmd;
	me->head = TMDQueue_getNextIndex(me , me->head);

	if(me->size < QUEUE_SIZE){
		++me->size;
	}
	printf("Storing data value : %d \n\r",tmd.dataValue);


}

uint8_t TMDQueue_isEmpty(TMDQueue * const me)
{
	return (uint8_t)(me->size == 0);
}

TimeMarkedData TMDQueue_remove(TMDQueue * const me, uint32_t index)
{
	TimeMarkedData tmd;

	tmd.timeInterval = 99999;
	tmd.dataValue = 99999;

	if(!TMDQueue_isEmpty(me)&&(index<QUEUE_SIZE)&&(index<me->size)){
		tmd = me->buffer[index];
	}

	return tmd;

}

void TMDQueue_CleanUp(TMDQueue * const me)
{
	//Do something
	printf("Clean up complete...\n\r");
}

void TMDQueue_Destroy(TMDQueue * const me)
{
	if(me != NULL){
		TMDQueue_CleanUp(me);
	}
	free(me);
}
