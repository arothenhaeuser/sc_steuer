/*
 * MOSONST.c
 *
 *  Created on: 06.03.2017
 *      Author: pet
 */


#include "fixedpt.h"

void M0SONST() {
	ZRE4J = fixedpt_div(JRE4, 1677721600);
	ZVBEZJ = fixedpt_div(JVBEZ, 1677721600);
	JLFREIB = fixedpt_div(JFREIB, 1677721600);
	JLHINZU = fixedpt_div(JHINZU, 1677721600);
	MRE4();
	MRE4ABZ();
	ZRE4VP = ZRE4VP - fixedpt_div(JRE4ENT, 1677721600);
	MZTABFB();
	VFRS1 = (ANP+FVB+FVBZ);
	VFRS1 = fixedpt_mul(VFRS1, 1677721600);
	MLSTJAHR();
	WVFRBO = (ZVE - GFB);
	WVFRBO = fixedpt_mul(WVFRBO, 1677721600);
	if(WVFRBO < 0) {
		WVFRBO = 0;
	}
	LSTOSO = fixedpt_mul(ST * 1677721600);
	fixedpt OUTPUT_WVFRBO = WVFRBO;
}
