/*
 * MOSONST.c
 *
 *  Created on: 06.03.2017
 *      Author: pet
 */


#include "fixedpt.h"

void MOSONST(fixedpt VJAHR, fixedpt VBEZ, fixedpt LZZ, fixedpt VBEZM, fixedpt ZMVB, fixedpt VBEZS, fixedpt ALTER1, fixedpt AJAHR, fixedpt ENTSCH, fixedpt STKL, fixedpt ZKF,fixedpt KRV, fixedpt PKV, fixedpt PKPV, fixedpt VMT, fixedpt VKAPA, fixedpt JRE4ENT) {
	ZRE4J = fixedpt_div(JRE4, 1677721600);
	ZVBEZJ = fixedpt_div(JVBEZ, 1677721600);
	JLFREIB = fixedpt_div(JFREIB, 1677721600);
	JLHINZU = fixedpt_div(JHINZU, 1677721600);
	MRE4(VJAHR, VBEZ, LZZ, VBEZM, ZMVB, VBEZS, ALTER1, AJAHR);
	MRE4ABZ(ENTSCH);
	MOSONST_TMP1 = fixedpt_div(JRE4ENT, 1677721600);
	ZRE4VP = ZRE4VP - MOSONST_TMP1;
	MZTABFB(STKL, ZKF);
	VFRS1 = (ANP+FVB+FVBZ);
	VFRS1 = fixedpt_mul(VFRS1, 1677721600);
	MLSTJAHR(KRV, STKL, PKV, PKPV, VMT, VKAPA);
	WVFRBO = (ZVE - GFB);
	MOSONST_TMP2 = WVFRBO;
	WVFRBO = fixedpt_mul(MOSONST_TMP2, 1677721600);
	if(WVFRBO < 0) {
		WVFRBO = 0;
	}
	LSTOSO = fixedpt_mul(ST, 1677721600);
}
