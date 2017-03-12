/*
 * MOSONST.c
 *
 *  Created on: 06.03.2017
 *      Author: pet
 */


#include "fixedpt.h"

void MOSONST() {
	ZRE4J = fixedpt_div(JRE4, 25600);
	ZVBEZJ = fixedpt_div(JVBEZ, 25600);
	JLFREIB = fixedpt_div(JFREIB, 25600);
	JLHINZU = fixedpt_div(JHINZU, 25600);
	MRE4();
	MRE4ABZ();
	MOSONST_TMP1 = fixedpt_div(JRE4ENT, 25600);
	ZRE4VP = ZRE4VP - MOSONST_TMP1;
	MZTABFB();
	VFRS1 = (ANP+FVB+FVBZ);
	VFRS1 = fixedpt_mul(VFRS1, 25600);
	MLSTJAHR();
	WVFRBO = (ZVE - GFB);
	MOSONST_TMP2 = WVFRBO;
	WVFRBO = fixedpt_mul(MOSONST_TMP2, 25600);
	if(WVFRBO < 0) {
		WVFRBO = 0;
	}
	LSTOSO = fixedpt_mul(ST, 25600);
}
