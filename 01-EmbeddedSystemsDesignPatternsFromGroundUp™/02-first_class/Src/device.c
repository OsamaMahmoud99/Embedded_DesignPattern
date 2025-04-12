/*
 * device.c
 *
 *  Created on: Apr 12, 2025
 *      Author: Osama
 */

#include "device.h"
#include "uart.h"
#include <stdlib.h>

typedef uint32_t deviceID_T;

struct Device{
	const char * name;
	Address address;
	deviceID_T uuid;
};

uint32_t noOfdevices = 0;

DevicePtr createDevice(const char * name, const Address* address) {

	DevicePtr device = calloc(sizeof(DevicePtr), sizeof(DevicePtr));

	if(device){
		device->name = name;
		noOfdevices++;
		device->address.Port = address->Port;
		device->address.Pin  = address->Pin;
		device->uuid = noOfdevices;

		/*Enable clock access to device port*/
		switch((int)device->address.Port){
			case (int)GPIOA : RCC_AHB1ENR |= GPIOA_EN; break;
			case (int)GPIOB : RCC_AHB1ENR |= GPIOB_EN; break;
			case (int)GPIOC : RCC_AHB1ENR |= GPIOC_EN; break;
			case (int)GPIOD : RCC_AHB1ENR |= GPIOD_EN; break;
			case (int)GPIOE : RCC_AHB1ENR |= GPIOE_EN; break;
			case (int)GPIOF : RCC_AHB1ENR |= GPIOF_EN; break;
			case (int)GPIOG : RCC_AHB1ENR |= GPIOG_EN; break;
			case (int)GPIOH : RCC_AHB1ENR |= GPIOH_EN; break;

		}
	}
	else{
		printf("Low memory,cannot create device\r\n");
	}

	return device;
}

void turnOnDevice(DevicePtr device){

	/*1. configure device as an output device*/
	uint16_t _pin = device->address.Pin;
	device->address.Port->MODER |= (1U<<(_pin*2));
	device->address.Port->MODER |= (0U<<((_pin*2)+1));

	/*2. Turn on device*/
	device->address.Port->ODR |= (1U<<_pin);
	printf(" %s is on \n\r",device->name);
}

void turnOffDevice(DevicePtr device){
	uint16_t _pin = device->address.Pin;

	/*1. Turn off device*/
	device->address.Port->ODR &= ~(1U<<_pin);
	printf(" %s is off \n\r",device->name);

}

void toggleDevice(DevicePtr device){
	uint16_t _pin = device->address.Pin;

	/*1. Toggle device*/
	device->address.Port->ODR ^=(1U<<_pin);
	printf(" %s is toggled \n\r",device->name);
}

State_T readDevice(DevicePtr device){

	State_T bitStatus;

	/*1. configure device as an input device*/
	uint16_t _pin = device->address.Pin;
	device->address.Port->MODER |= (0U<<(_pin*2));
	device->address.Port->MODER |= (0U<<((_pin*2)+1));

	/*2. Read device*/
	if(device->address.Port->IDR & (1U<<_pin)){
		bitStatus = 1;
	}else{
		bitStatus = 0;
	}

	return bitStatus;
}

void destroyDevice(DevicePtr device){

	printf("*** %s destroyed***\n\r",device->name);
	free(device);
}

void displayDeviceInfo(DevicePtr device){
	const char* type;
	uint32_t _pin = device->address.Pin;

	if((device->address.Port->MODER & (1U<<(2*_pin))) != 0){
		type = "Output device";
	}else{
		type = "Input device";
	}

	printf("**************************************\n\r");

	printf("Device name : %s\n\r",device->name);
	printf("Device type: %s\n\r",type);
	printf("The device uuid is %d\n\r",device->uuid);

	printf("**************************************\n\r");

}
