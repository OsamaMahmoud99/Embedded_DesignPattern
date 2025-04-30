#include "uart.h"
#include "env_sensor.h"
#include "env_display_client.h"
#include "fertilizer_mixer_client.h"


int main(void)
{


	debug_uart_init();

	//Setup server
		 env_sensor_t * sensor = env_sensor_create();

		 //Setup CLIENT 1
		display_client_t * lcd_display = display_client_create();
	  //Subscribe to server
		display_client_subscribe(lcd_display,sensor);

			 //Setup CLIENT 2

		 fertilizer_mixer_client_t  * fertilizer_mixer =  fertilizer_mixer_client_create();
		 //Subscribe to server
		 fertilizer_mixer_client_subscribe(fertilizer_mixer,sensor);

		 env_sensor_get_data(sensor);
		 env_sensor_get_data(sensor);

		  //Test 2
			display_client_unsubscribe(lcd_display,sensor);
			env_sensor_get_data(sensor);
		  env_sensor_get_data(sensor);

			//Test3
			 env_sensor_dumplist(sensor);

			 //Test 4
			  env_sensor_destroy(sensor);
				 display_client_destroy(lcd_display);
		while(1){

		}
}
