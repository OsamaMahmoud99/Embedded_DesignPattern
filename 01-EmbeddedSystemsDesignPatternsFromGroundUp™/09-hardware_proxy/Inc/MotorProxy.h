/*
 * MotorProxy.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Osama
 */

#ifndef MOTORPROXY_H_
#define MOTORPROXY_H_

#include "MotorData.h"
#include <stdlib.h>
#include <stdint.h>


struct MotorProxy{

	uint32_t *motorData;
	volatile uint32_t *motorAddr;
	uint32_t rotaryArmLength;
	const char *name;

};

typedef struct MotorProxy MotorProxy;

void MotorProxy_Initialize(MotorProxy *const me);
void MotorProxy_CleanUp(MotorProxy *const me);
MotorProxy * MotorProxy_Create(const char *name);
void MotorProxy_Destroy(MotorProxy *const me);
void Motorproxy_enable(MotorProxy *const me);
void MotorProxy_disable(MotorProxy *const me);
void MotorProxy_configure(MotorProxy *const me, uint32_t length, volatile uint32_t *location, int32_t *MotorData);

DirectionType MotorProxy_accessMotorDirection(MotorProxy *const me);
uint32_t MotorProxy_accessMotorSpeed(MotorProxy *const me);
uint32_t MotorProxy_accessMotorState(MotorProxy *const me);
void MotorProxy_writeMotorSpeed(MotorProxy *const me, const DirectionType direction, uint32_t speed);
void MotorProxy_clearErrorStatus(MotorProxy *const me);



#endif /* MOTORPROXY_H_ */
