/*
 * MRE4ABZ.c
 *
 *  Created on: 14.02.2017
 *      Author: pet
 */

#include "fixedpt.h"

void MRE4ABZ(){

	ZRE4 = ZRE4J-FVB-ALTE-JLFREIB+JLHINZU;

	if (ZRE4 < 0) {
		ZRE4 = 0;
	} else {
		ZRE4VP = ZRE4J;
	}
	if (KENNVMT == 33554432) {
		MRE4ABZ_TMP1 = fixedpt_div(ENTSCH, 1677721600);
		ZRE4VP = ZRE4VP - MRE4ABZ_TMP1;
	}
	ZVBEZ = ZVBEZJ - FVB;
	if (ZVBEZ < 0) {
		ZVBEZ = 0;
	}
}
