/*
 * MRE4ABZ.c
 *
 *  Created on: 14.02.2017
 *      Author: pet
 */

#include "fixedpt.h"

void MRE4ABZ(fixedpt ENTSCH){

	ZRE4 = ZRE4J-FVB-ALTE-JLFREIB+JLHINZU;

	if (ZRE4 < 0) {
		ZRE4 = 0;
	} else {
		ZRE4VP = ZRE4J;
	}
	if (KENNVMT == intToFixedpt(2)) {
		ZRE4VP = ZRE4VP - fixedpt_div(ENTSCH, intToFixedpt(100));
	}
	ZVBEZ = ZVBEZJ - FVB;
	if (ZVBEZ < 0) {
		ZVBEZ = 0;
	}
}
