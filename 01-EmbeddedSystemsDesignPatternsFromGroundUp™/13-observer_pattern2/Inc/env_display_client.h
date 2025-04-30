/*
 * env_display_client.h
 *
 *  Created on: Apr 30, 2025
 *      Author: Osama
 */

#ifndef ENV_DISPLAY_CLIENT_H_
#define ENV_DISPLAY_CLIENT_H_

#include "env_sensor.h"
#include "environmental_data.h"

typedef struct display_client{
   env_data_t data;
	 callback_fn fn_handler;
}display_client_t;


void display_client_init(display_client_t * const me);
display_client_t * display_client_create(void);
void display_client_handle_new_data(void * me, env_data_t data);
void display_client_subscribe(display_client_t * const me, env_sensor_t * const server);
void display_client_unsubscribe(display_client_t * const me, env_sensor_t * const server);
void display_client_destroy(display_client_t * const me);

#endif /* ENV_DISPLAY_CLIENT_H_ */
