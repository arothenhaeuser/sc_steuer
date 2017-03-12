/*
 * MZTABFB.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


#include "fixedpt.h"

void MZTABFB(){

	ANP = 0;

	if (ZVBEZ >= 0) {
		if (ZVBEZ < FVBZ) {
			FVBZ = ZVBEZ;
		}
	}

	if (STKL < 1536) {
		if (ZVBEZ > 0) {
			if (ZVBEZ-FVBZ < 26112) {
				ANP = ZVBEZ - FVBZ;	// Auf volle Euro aufrunden
			} else {
				ANP = intToFixedpt(102);
			}
		}
	} else {
		FVBZ = 0;
		FVBZSO = 0;
	}

	if (STKL < 1536) {
		if (ZRE4 > ZVBEZ) {
			if (ZRE4-ZVBEZ < 256000) {
				ANP = ANP + ZRE4 - ZVBEZ;	// Auf volle Euro aufrunden
			} else {
				ANP = ANP + 25600;
			}
		}
	}

	KZTAB = 256;
	switch (STKL) {
	case 256:
		SAP = 9216;
		KFB = fixedpt_mul(ZKF, 1883136);
		break;
	case 512:
		EFA = 488448;
		SAP = 9216;
		KFB = fixedpt_mul(ZKF, 1883136);
		break;
	case 768:
		KZTAB = 512;
		SAP = 9216;
		KFB = fixedpt_mul(ZKF, 1883136);
		break;
	case 1024:
		SAP = 9216;
		KFB = fixedpt_mul(ZKF, 1883136);
		break;
	case 1280:
		SAP = 9216;
		KFB = 0;
		break;
	default:
		KFB = 0;
		break;
	}

	ZTABFB = EFA + ANP + SAP + FVBZ;

}
