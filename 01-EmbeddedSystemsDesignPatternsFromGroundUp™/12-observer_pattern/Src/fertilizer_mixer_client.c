/*
 * fertilizer_mixer_client.c
 *
 *  Created on: Apr 30, 2025
 *      Author: Osama
 */


#include "fertilizer_mixer_client.h"
#include <stdlib.h>
#include "uart.h"

void fertilizer_mixer_client_init(fertilizer_mixer_client_t * const me){
	me->fn_handler = fertilizer_mixer_client_handle_new_data;
}
fertilizer_mixer_client_t * fertilizer_mixer_client_create(void){

fertilizer_mixer_client_t * me   = (fertilizer_mixer_client_t *)malloc(sizeof(fertilizer_mixer_client_t));

	if( me!=NULL){

	  fertilizer_mixer_client_init(me);
	}

	return me;

}

void fertilizer_mixer_client_handle_new_data(void * me, env_data_t data){

   ((fertilizer_mixer_client_t *)me)->data =  data;

	  /*Process data*/
	  //Do somthing..
	  printf("fertilizer_mixer_module : \t New data :  %d %d %d \n\r",
						((fertilizer_mixer_client_t *)me)->data.temperature,
						((fertilizer_mixer_client_t *)me)->data.humidity,
						((fertilizer_mixer_client_t *)me)->data.sprayed);

}


void fertilizer_mixer_client_subscribe(fertilizer_mixer_client_t * const me, env_sensor_t * const server){

	  for(int i=0;i<MAX_CLIENT;i++){

		  //Check if client is already subscribed
			  if(server->clients[i].pObject ==  me){
				  return;
				}
				//Add new client
				if(server->clients[i].pObject == NULL){

				   server->n_client++;
					 server->clients[i].pObject =  me;
					 server->clients[i].fn_handler = me->fn_handler;

					 //Remove duplicate
					for(int j= i+1; j<MAX_CLIENT;j++){
					   if(server->clients[j].pObject == me){
						    server->clients[j].pObject = NULL;
							   server->clients[j].fn_handler =  NULL;
						 }
					}
					return;
				}
		}


}

void fertilizer_mixer_client_unsubscribe(fertilizer_mixer_client_t * const me, env_sensor_t * const server){

    for(int i =0;i<MAX_CLIENT;++i){

		   if(server->clients[i].pObject ==  me){
			     server->clients[i].pObject = NULL;
				   server->clients[i].fn_handler =  NULL;
				    server->n_client--;
				    return;
			 }
		}

}


void fertilizer_mixer_client_destroy(fertilizer_mixer_client_t * const me){

  printf("Client destroyed ... \n\r");
	free(me);
}


