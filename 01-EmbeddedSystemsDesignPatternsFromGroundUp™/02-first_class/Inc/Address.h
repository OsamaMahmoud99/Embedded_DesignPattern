/*
 * Address.h
 *
 *  Created on: Apr 12, 2025
 *      Author: Osama
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include "REGS.h"

typedef struct{

	GPIO_TypeDef *Port;
	Pin_Type Pin;

}Address;

#endif /* ADDRESS_H_ */
