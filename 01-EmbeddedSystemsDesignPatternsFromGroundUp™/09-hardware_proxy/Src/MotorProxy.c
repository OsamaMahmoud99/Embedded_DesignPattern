/*
 * MotorProxy.c
 *
 *  Created on: Apr 18, 2025
 *      Author: Osama
 */


#include "MotorProxy.h"

static MotorData unmarshal(uint32_t encodedMData);
static uint32_t marshal(const MotorData mData);
static void _MotorProxy_Init(MotorProxy *const me, const char *name);

void MotorProxy_Initialize(MotorProxy *const me)
{
	MotorData mData;
	if(!me->motorData){
		return;
	}

	mData.on_off = 1;
	mData.direction = 0;
	mData.speed = 0;
	mData.errorStatus = 0;
	mData.noPowerError = 0;
	mData.noTorqueError = 0;
	mData.BITError = 0;
	mData.overTemperatureError = 0;
	mData.reservedError1 = 0;
	mData.reservedError2 = 0;
	mData.unknownError = 0;

	(*(volatile uint32_t *)(*me->motorAddr)) = marshal(mData);
	printf("%s,0x%X\n\r",__func__,*me->motorAddr);
}

static void _MotorProxy_Init(MotorProxy *const me, const char *name)
{
	me->motorAddr = NULL;
	me->name = name;
}

void MotorProxy_CleanUp(MotorProxy *const me)
{

}

MotorProxy * MotorProxy_Create(const char *name)
{
	MotorProxy * me = (MotorProxy *)malloc(sizeof(MotorProxy));

	if(me){
		_MotorProxy_Init(me, name);
	}
	return me;
}

void MotorProxy_Destroy(MotorProxy *const me)
{
	if(me){
		MotorProxy_CleanUp(me);
	}
	free(me);
}

void Motorproxy_enable(MotorProxy *const me)
{
	if(!me->motorData){
		return;
	}

	(*(volatile uint32_t *)(*me->motorAddr)) |= 1;

	printf("%s, 0x%X\n\r",__func__,*me->motorAddr);
}

void MotorProxy_disable(MotorProxy *const me)
{
	if(!me->motorData){
			return;
		}

	(*(volatile uint32_t *)(*me->motorAddr)) &= ~1;

}

void MotorProxy_configure(MotorProxy *const me, uint32_t length, volatile uint32_t *location, int32_t *MotorData)
{
	me->rotaryArmLength = length;
	me->motorAddr = location;
	me->motorData = MotorData;

	printf("%s, 0x%X\n\r",__func__,*me->motorAddr);
}

DirectionType MotorProxy_accessMotorDirection(MotorProxy *const me)
{
	MotorData mData;
	if(!me->motorData){
		return 0;
	}
	mData = unmarshal((*(volatile uint32_t *)(*me->motorAddr)));

	return mData.direction;
}

uint32_t MotorProxy_accessMotorSpeed(MotorProxy *const me)
{
	MotorData mData;
	if(!me->motorData){
		return 0;
	}
	mData = unmarshal((*(volatile uint32_t *)(*me->motorAddr)));

	return mData.speed;
}

uint32_t MotorProxy_accessMotorState(MotorProxy *const me)
{
	MotorData mData;
	if(!me->motorData){
		return 0;
	}
	mData = unmarshal((*(volatile uint32_t *)(*me->motorAddr)));

	return mData.errorStatus;
}

void MotorProxy_writeMotorSpeed(MotorProxy *const me, const DirectionType direction, uint32_t speed)
{
	MotorData mData;
	double dpi,dArmLength,dSpeed,dAdjSpeed;

	dpi = 3.14159;

	if(!me->motorData){
		return;
	}

	mData = unmarshal((*(volatile uint32_t *)(*me->motorAddr)));
	mData.direction = direction;

	if(me->rotaryArmLength > 0){
		dSpeed = speed;
		dArmLength = me->rotaryArmLength;
		dAdjSpeed = dSpeed/2.0/dpi/dArmLength*10.0;
		mData.speed = (int)dAdjSpeed;
	}
	else{
		mData.speed = speed;
	}

	(*(volatile uint32_t *)(*me->motorAddr)) |= marshal(mData);
	printf("%s, 0x%X\n\r",__func__,*me->motorAddr);

	return;
}

void MotorProxy_clearErrorStatus(MotorProxy *const me)
{
	if(!me->motorData){
		return;
	}

	(*(volatile uint32_t *)(*me->motorAddr)) &=~(1<<8);
}

static uint32_t marshal(const MotorData mData)
{
	uint32_t deviceCmd;
	deviceCmd=0;
	if(mData.on_off){
		deviceCmd |= 1;
	}

	if(mData.direction == FORWARD){
		deviceCmd |= (2<<1);
	}
	else if(mData.direction == REVERSE){
		deviceCmd |= (1<<1);
	}

	if(mData.speed < 32){
		deviceCmd |= (mData.speed<<3);
	}

	if(mData.errorStatus){
		deviceCmd |= (1<<8);
	}

	if(mData.noPowerError){
		deviceCmd |= (1<<9);
	}

	if(mData.noTorqueError){
		deviceCmd |= (1<<10);
	}

	if(mData.BITError){
		deviceCmd |= (1<<11);
	}

	if(mData.overTemperatureError){
		deviceCmd |= (1<<12);
	}

	if(mData.reservedError1){
		deviceCmd |= (1<<13);
	}

	if(mData.reservedError2){
		deviceCmd |= (1<<14);
	}

	if(mData.unknownError){
		deviceCmd |= (1<<15);
	}

	return deviceCmd;
}

static MotorData unmarshal(uint32_t encodedMData)
{
	MotorData mData;
	int temp;

	mData.on_off = encodedMData & 1;
	temp = (encodedMData & (3<<1))>>1;
	if(temp == 1){
		mData.direction = REVERSE;
	}
	else if(temp == 2){
		mData.direction = FORWARD;
	}
	else
		mData.direction = NO_DIRECTION;

	mData.speed = encodedMData &(31<<3);
	mData.errorStatus = encodedMData & (1<<8);
	mData.noPowerError = encodedMData & (1<<9);
	mData.noTorqueError = encodedMData & (1<<10);
	mData.BITError = encodedMData & (1<<11);
	mData.overTemperatureError = encodedMData &(1<<12);
	mData.reservedError1 = encodedMData & (1<<13);
	mData.reservedError2 = encodedMData & (1<<14);
	mData.unknownError = encodedMData & (1<<15);

	return mData;
}
