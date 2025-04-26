/*
 * ECG_Module.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */

#ifndef ECG_MODULE_H_
#define ECG_MODULE_H_

#include <stdint.h>
#include "ECGPkg.h"



typedef struct ECG_Module ECG_Module;

struct ECG_Module{

	uint32_t dataNum;
	uint32_t lead1;
	uint32_t lead2;
	struct TMDQueue * itsTMDQueue;
};

ECG_Module * ECG_Module_Create(void);
void ECG_Module_Init(ECG_Module * const me);
void ECG_Module_acquireValue(ECG_Module * const me);
void ECG_Module_setLeadPair(ECG_Module * const me, uint32_t l1,uint32_t l2);
struct TMDQueue * ECG_Module_getsItsTMDQueue(ECG_Module * const me);
void ECG_Module_setItsTMDQueue(ECG_Module * const me,struct TMDQueue * p_TMDQueue);
void ECG_Module_Cleanup(ECG_Module * const me);
void ECG_Module_Destroy(ECG_Module * const me);

#endif /* ECG_MODULE_H_ */
