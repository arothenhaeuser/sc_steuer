/*
 * MSONST.c
 *
 *  Created on: 20.02.2017
 *      Author: pet
 */

#include "fixedpt.h"
#include "MRE4SONST.c"
#include "MOSONST.c"

void MSONST() {
	LZZ = 16777216;
	if (ZMVB == 0) {
		ZMVB = 201326592;
	}
	if (SONSTB == 0) {
		VKVSONST = 0;
		LSTSO = 0;
		STS = 0;
		SOLZS = 0;
		BKS = 0;
	} else {
		MOSONST();
		UPVKV();
		VKVSONST = VKV;
		ZRE4J = JRE4 + SONSTB;
		ZRE4J = fixedpt_div(ZRE4J, 1677721600);
		SVBEZJ = JVBEZ + VBS;
		SVBEZJ = fixedpt_div(SVBEZJ, 1677721600);
		VBEZBSO = STERBE;
		MRE4SONST();
		MLSTJAHR();
		WVFRBM = ZVE - GFB;
		WVFRBM = fixedpt_mul(WVFRBM, 1677721600);
		if (WVFRBM < 0) {
			WVFRBM = 0;
		}
		UPVKV();
		VKVSONST = VKV - VKVSONST;
		LSTSO = fixedpt_mul(ST, 1677721600);
		STS = LSTSO - LSTOSO;
		STS = fixedpt_mul(STS, F);
		if (STS < 0) {
			STS = 0;
		}
		MSONST_TMP1 = fixedpt_div(55, 100);
		SOLZS = fixedpt_mul(STS, MSONST_TMP1);
		if (R > 0) {
			BKS = STS;
		} else {
			BKS = 0;
		}
	}
}
