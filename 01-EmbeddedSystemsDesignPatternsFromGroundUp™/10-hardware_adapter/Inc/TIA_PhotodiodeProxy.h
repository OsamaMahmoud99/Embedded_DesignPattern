/*
 * TIA_PhotodiodeProxy.h
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#ifndef TIA_PHOTODIODEPROXY_H_
#define TIA_PHOTODIODEPROXY_H_

#include <stdint.h>

typedef struct TIA_PhotodiodeProxy TIA_PhotodiodeProxy;

struct TIA_PhotodiodeProxy
{
	uint32_t (*getSpo2)(void);
	uint32_t (*getPulse)(void);
};

uint32_t getSpo2(void);
uint32_t getPulse(void);

#endif /* TIA_PHOTODIODEPROXY_H_ */
