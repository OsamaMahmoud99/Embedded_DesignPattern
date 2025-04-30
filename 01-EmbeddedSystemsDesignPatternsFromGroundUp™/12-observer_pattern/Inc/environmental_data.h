/*
 * environmental_data.h
 *
 *  Created on: Apr 30, 2025
 *      Author: Osama
 */

#ifndef ENVIRONMENTAL_DATA_H_
#define ENVIRONMENTAL_DATA_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct environmental_data{
  uint32_t temperature;
	uint32_t humidity;
	bool sprayed;

}env_data_t;

#endif /* ENVIRONMENTAL_DATA_H_ */
