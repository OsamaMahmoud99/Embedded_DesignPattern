
#include <stdio.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "MotorProxy.h"

//Client 1: Motor_Dashboard
void Motor_Dashboard(MotorProxy* motor){

	uint32_t getSpeed = MotorProxy_accessMotorSpeed(motor);
	uint32_t getState = MotorProxy_accessMotorState(motor);
	DirectionType getDirection = MotorProxy_accessMotorDirection(motor);

	printf("******************DashBoard******************\n\r");
	printf("Motor name : %s\n\r",motor->name);
	printf("Motor current direction : %d, speed : %d, state : %d\n\r", getDirection,getSpeed,getState);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\r");
}

//Client 2: Motor_Controller
void Motor_Controller(MotorData *motor, DirectionType direction, uint32_t speed){
	MotorProxy_writeMotorSpeed(motor, direction, speed);
}

int main(void)
{


	debug_uart_init();

	RCC->AHB1ENR |= (1U<<1);
	RCC->AHB1ENR |= (1U<<2);

	MotorProxy *motor1;
	MotorProxy *motor2;

	const char* motor1_name = "Base";
	motor1 = MotorProxy_Create(motor1_name);
	volatile uint32_t motor1_location = 0x40020414U; // GPIOB->ODR
	uint32_t motor1_data = 100;
	uint32_t motor1_armlength = 2;

	const char* motor2_name = "Shoulder";
	motor2 = MotorProxy_Create(motor2_name);
	volatile uint32_t motor2_location = 0x40020814U; // GPIOC->ODR
	uint32_t motor2_data = 100;
	uint32_t motor2_armlength = 15;

	MotorProxy_configure(motor1, motor1_armlength, &motor1_location, &motor1_data);
	MotorProxy_Initialize(motor1);
	Motorproxy_enable(motor1);

	MotorProxy_configure(motor2, motor2_armlength, &motor2_location, &motor1_data);
	MotorProxy_Initialize(motor2);
	Motorproxy_enable(motor2);

	Motor_Controller(motor1, FORWARD, 1);
	Motor_Controller(motor2, FORWARD, 1);

	Motor_Dashboard(motor1);
	Motor_Dashboard(motor2);

    while(1)
    {
    }
}
