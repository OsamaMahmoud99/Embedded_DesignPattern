/*
 * env_sensor.c
 *
 *  Created on: Apr 30, 2025
 *      Author: Osama
 */


#include "env_sensor.h"
#include <stdlib.h>
#include "uart.h"
#include "adc_driver.h"
#include "gpio_driver.h"

void env_sensor_init(env_sensor_t * const me){
   for(int i=0;i<MAX_CLIENT;i++){
		 me->clients[i].pObject=NULL;
		 me->clients[i].fn_handler =NULL;
	 }

}
env_sensor_t * env_sensor_create(void){
  env_sensor_t * me = (env_sensor_t *)malloc(sizeof(env_sensor_t));
	if( me !=NULL){
	  env_sensor_init(me);
	}
  return me;
}
void env_sensor_get_data(env_sensor_t * const me){

	temp_sensor_init();

   me->data.temperature = read_chip_temperature();
   pa1_analog_init();

	 me->data.humidity    =  pa1_analog_read();

	 p13_button_init();
	 me->data.sprayed     = get_p13_button_state();

	//Notify all clients
	 env_sensor_notify(me);
}


void env_sensor_notify(env_sensor_t * const me){

	for(int i=0;i<MAX_CLIENT;i++){
	   if(me->clients[i].pObject !=NULL && me->clients[i].fn_handler !=NULL){
		   me->clients[i].fn_handler(me->clients[i].pObject,me->data);
		 }
	}
}


void env_sensor_dumplist(env_sensor_t * const me){

	 printf("Dumplist :  \t number of clients: %d\n\r",me->n_client);

	for(int i=0;i<MAX_CLIENT;i++){
	  if(me->clients[i].pObject !=NULL && me->clients[i].fn_handler !=NULL){
		   printf("\t pObect:   0x%X \t fn_handler: 0x%X\n\r",(uint32_t)me->clients[i].pObject,(uint32_t)me->clients[i].fn_handler);
			}

	}

}


void env_sensor_destroy(env_sensor_t * const me){

	  //Do somthing..
	  free(me);

}



