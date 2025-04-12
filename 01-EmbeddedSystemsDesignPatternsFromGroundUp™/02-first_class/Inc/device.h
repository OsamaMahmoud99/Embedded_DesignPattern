/*
 * device.h
 *
 *  Created on: Apr 12, 2025
 *      Author: Osama
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#include "Address.h"
#include <stdbool.h>

typedef bool State_T;

/*pointer to an incomplete type
 * this hides implementation details
 */
typedef struct Device* DevicePtr;

DevicePtr createDevice(const char * name, const Address* address);

void turnOnDevice(DevicePtr device);
void turnOffDevice(DevicePtr device);
void toggleDevice(DevicePtr device);

State_T readDevice(DevicePtr device);
void destroyDevice(DevicePtr device);
void displayDeviceInfo(DevicePtr device);

#endif /* DEVICE_H_ */
