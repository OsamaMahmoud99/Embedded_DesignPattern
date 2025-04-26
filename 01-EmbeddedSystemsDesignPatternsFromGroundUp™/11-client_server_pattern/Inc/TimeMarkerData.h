/*
 * TimeMarkerData.h
 *
 *  Created on: Apr 24, 2025
 *      Author: Osama
 */

#ifndef TIMEMARKERDATA_H_
#define TIMEMARKERDATA_H_

#include <stdint.h>

typedef struct TimeMarkedData TimeMarkedData;

struct TimeMarkedData {

	uint32_t timeInterval;
	uint32_t dataValue;
};


#endif /* TIMEMARKERDATA_H_ */
