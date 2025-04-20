/*
 * MotorData.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Osama
 */

#ifndef MOTORDATA_H_
#define MOTORDATA_H_
#include "motor.h"



struct Motordata{
	unsigned char on_off;
	DirectionType direction;
	unsigned int speed;
	unsigned char errorStatus;
	unsigned char noPowerError;
	unsigned char noTorqueError;
	unsigned char BITError;
	unsigned char overTemperatureError;
	unsigned char reservedError1;
	unsigned char reservedError2;
	unsigned char unknownError;
};

typedef struct Motordata MotorData;

#endif /* MOTORDATA_H_ */
