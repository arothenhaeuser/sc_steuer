/*
 * MSONST.c
 *
 *  Created on: 20.02.2017
 *      Author: pet
 */

#include "fixedpt.h"

void MSONST(fixedpt LZZ, fixedpt ZMVB, fixedpt SONSTB, fixedpt JRE4,
		fixedpt JVBEZ, fixedpt VBS, fixedpt STERBE, fixedpt F, fixedpt R,
		fixedpt PKV, fixedpt KRV, fixedpt STKL, fixedpt PKPV, fixedpt VMT,
		fixedpt VKAPA) {
	LZZ = 1;
	if (ZMVB == 0) {
		ZMVB = 12;
	}
	MSONST_TMP2 = 0;
	if (SONSTB == 0) {
		//fixedpt OUTPUT_VKVSONST = MSONST_TMP2; //intToFixedpt(0);
		LSTSO = 0;
		//fixedpt OUTPUT_STS = MSONST_TMP2; //intToFixedpt(0);
		//fixedpt OUTPUT_SOLZS = MSONST_TMP2; //intToFixedpt(0);
		//fixedpt OUTPUT_BKS = MSONST_TMP2; //intToFixedpt(0);
	} else {
		MOSONST();
		UPVKV(PKV);
		VKVSONST = VKV;
		ZRE4J = JRE4 + SONSTB;
		ZRE4J = fixedpt_div(ZRE4J, 1677721600);
		SVBEZJ = JVBEZ + VBS;
		SVBEZJ = fixedpt_div(SVBEZJ, 1677721600);
		VBEZBSO = STERBE;
		MRE4SONST();
		MLSTJAHR(KRV, STKL, PKV, PKPV, VMT, VKAPA);
		WVFRBM = ZVE - GFB;
		WVFRBM = fixedpt_mul(WVFRBM, 1677721600);
		if (WVFRBM < 0) {
			WVFRBM = 0;
		}
		fixedpt OUTPUT_WVFRBM = WVFRBM;
		UPVKV(PKV);
		VKVSONST = VKV - VKVSONST;
		fixedpt OUTPUT_VKVSONST = VKVSONST;
		LSTSO = fixedpt_mul(ST, 1677721600);
		STS = LSTSO - LSTOSO;
		STS = fixedpt_mul(STS, F);
		if (STS < 0) {
			STS = 0;
		}
		fixedpt OUTPUT_STS = STS;
		MSONST_TMP1 = fixedpt_div(55, 100);
		MSONST_TMP4 = STS * MSONST_TMP1;
		fixedpt OUTPUT_SOLZS = MSONST_TMP4;
		if (R > 0) {
			fixedpt OUTPUT_BKS = 1;//STS;
		} else {
			fixedpt OUTPUT_BKS = 0;
		}
	}
}
