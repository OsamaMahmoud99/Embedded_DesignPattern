/*
 * fertilizer_mixer_client.h
 *
 *  Created on: Apr 30, 2025
 *      Author: Osama
 */

#ifndef FERTILIZER_MIXER_CLIENT_H_
#define FERTILIZER_MIXER_CLIENT_H_

#include "env_sensor.h"
#include "environmental_data.h"

typedef struct fertilizer_mixer_client{
   env_data_t data;
   callback_fn fn_handler;
}fertilizer_mixer_client_t;


void fertilizer_mixer_client_init(fertilizer_mixer_client_t * const me);
fertilizer_mixer_client_t * fertilizer_mixer_client_create(void);
void fertilizer_mixer_client_handle_new_data(void * me, env_data_t data);
void fertilizer_mixer_client_subscribe(fertilizer_mixer_client_t * const me, env_sensor_t * const server);
void fertilizer_mixer_client_unsubscribe(fertilizer_mixer_client_t * const me, env_sensor_t * const server);
void fertilizer_mixer_client_destroy(fertilizer_mixer_client_t * const me);


#endif /* FERTILIZER_MIXER_CLIENT_H_ */
