/*
 * MZTABFB.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


#include "fixedpt.h"

void MZTABFB(fixedpt STKL, fixedpt ZKF){

	ANP = 0;

	if (ZVBEZ >= 0) {
		if (ZVBEZ < FVBZ) {
			FVBZ = ZVBEZ;
		}
	}

	if (STKL < 6) {
		if (ZVBEZ > 0) {
			if (ZVBEZ-FVBZ < intToFixedpt(102)) {
				ANP = ZVBEZ - FVBZ;	// Auf volle Euro aufrunden
			} else {
				ANP = intToFixedpt(102);
			}
		}
	} else {
		FVBZ = 0;
		FVBZSO = 0;
	}

	if (STKL < 6) {
		if (ZRE4 > ZVBEZ) {
			if (ZRE4-ZVBEZ < intToFixedpt(1000)) {
				ANP = ANP + ZRE4 - ZVBEZ;	// Auf volle Euro aufrunden
			} else {
				ANP = ANP + intToFixedpt(1000);
			}
		}
	}

	KZTAB = intToFixedpt(1);

	switch (STKL) {
	case 1:
		SAP = intToFixedpt(36);
		KFB = fixedpt_mul(ZKF, intToFixedpt(7356));
		break;
	case 2:
		EFA = intToFixedpt(1908);
		SAP = intToFixedpt(36);
		KFB = fixedpt_mul(ZKF, intToFixedpt(7356));
		break;
	case 3:
		KZTAB = intToFixedpt(2);
		SAP = intToFixedpt(36);
		KFB = fixedpt_mul(ZKF, intToFixedpt(7356));
		break;
	case 4:
		SAP = intToFixedpt(36);
		KFB = fixedpt_mul(ZKF, intToFixedpt(7356));
		break;
	case 5:
		SAP = intToFixedpt(36);
		KFB = 0;
		break;
	default:
		KFB = 0;
		break;
	}

	ZTABFB = EFA + ANP + SAP + FVBZ;

}
