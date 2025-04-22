/*
 * LTF_PhotodiodeProxy.h
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#ifndef LTF_PHOTODIODEPROXY_H_
#define LTF_PHOTODIODEPROXY_H_

#include <stdint.h>

typedef struct LTF_PhotodiodeProxy LTF_PhotodiodeProxy;

struct LTF_PhotodiodeProxy
{
	uint32_t (*accessSpo2)(void);
	uint32_t (*accessPulse)(void);
};

uint32_t accessSpo2(void);
uint32_t accessPulse(void);


#endif /* LTF_PHOTODIODEPROXY_H_ */
