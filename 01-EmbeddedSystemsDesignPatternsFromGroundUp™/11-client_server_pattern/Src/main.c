#include "uart.h"
#include "SystemManager.h"

int main(void)
{


	debug_uart_init();

	SystemManager *p_SystemManager;
		p_SystemManager = SystemManager_Create();

		ECG_Module_acquireValue(&(p_SystemManager->itsECG_Module));
		ECG_Module_acquireValue(&(p_SystemManager->itsECG_Module));
		ECG_Module_acquireValue(&(p_SystemManager->itsECG_Module));
		ECG_Module_acquireValue(&(p_SystemManager->itsECG_Module));
		ECG_Module_acquireValue(&(p_SystemManager->itsECG_Module));

		printf("\n\r");
		//Client 1
		HistogramDisplay_getValue(&(p_SystemManager->itsHistogramDisplay));
		HistogramDisplay_getValue(&(p_SystemManager->itsHistogramDisplay));
		HistogramDisplay_getValue(&(p_SystemManager->itsHistogramDisplay));
		HistogramDisplay_getValue(&(p_SystemManager->itsHistogramDisplay));
		 printf("\n\r");


		//Client 2
		QRSDetector_getDataSample(&(p_SystemManager->itsQRSDetector));
		QRSDetector_getDataSample(&(p_SystemManager->itsQRSDetector));
			 printf("\n\r");

	  //Client 1

		HistogramDisplay_getValue(&(p_SystemManager->itsHistogramDisplay));
		 printf("\n\r");

		//Client 3
		ArrythmiaDetector_getDataSample(&(p_SystemManager->itsArrythmiaDetector));
		ArrythmiaDetector_getDataSample(&(p_SystemManager->itsArrythmiaDetector));
		ArrythmiaDetector_getDataSample(&(p_SystemManager->itsArrythmiaDetector));
		 printf("\n\r");

		//Client 2

		QRSDetector_getDataSample(&(p_SystemManager->itsQRSDetector));
		QRSDetector_getDataSample(&(p_SystemManager->itsQRSDetector));
		 printf("\n\r");

		//Client 3
		ArrythmiaDetector_getDataSample(&(p_SystemManager->itsArrythmiaDetector));

		printf("Done...\n\r");

		while(1){

		}
}
