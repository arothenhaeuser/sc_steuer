/*
 * MRE4.c
 *
 *  Created on: 13.02.2017
 *      Author: pet
 */

#include "fixedpt.h"
#include "MRE4ALTE.h"

void MRE4() {
	MRE4_TMP1 = intToFixedpt(TAB2[J -1]);
	MRE4_TMP2 = fixedpt_div(MRE4_TMP1, 3072);
	MRE4_TMP3 = fixedpt_div(VBEZB, 25600);
	MRE4_TMP4 = fixedpt_div(VBEZBSO, 25600);

	if (ZVBEZJ == 0) {
		FVBZ = 0;
		FVB = 0;
		FVBZSO = 0;
		FVBSO = 0;
	} else {
	if (VJAHR < 513536) {
		J = 1;
	} else if (VJAHR < 261120) {
		J = (VJAHR - 513024)>>FIXEDPOINT_FRACTION_BITS;
	} else {
		J = 36;
	}
	if (LZZ == 256) {
		VBEZB = fixedpt_mul(VBEZM, ZMVB);
		VBEZB = VBEZB + VBEZS;
		HFVB = fixedpt_mul(MRE4_TMP2, ZMVB);
		FVBZ = fixedpt_mul(MRE4_TMP2, ZMVB); //Auf volle Euro aufrunden
	} else {
		VBEZB = fixedpt_mul(VBEZM, 3072);
		VBEZB = VBEZB + VBEZS;
		HFVB = intToFixedpt(TAB2[J - 1]);
		FVBZ = intToFixedpt(TAB3[J - 1]); //Auf volle Euro aufrunden
	}
	FVB = fixedpt_mul(MRE4_TMP3, TAB1[J - 1]); //Auf volle Cent aufrunden
	if (FVB > HFVB) {
		FVB = HFVB;
	}
	if (FVB > ZVBEZJ) {
		FVB = ZVBEZJ;
	}
	FVBSO = fixedpt_mul(MRE4_TMP4, TAB1[J - 1]); //Auf volle Cent aufrunden
	FVBSO = FVBSO + FVB;
	if (FVBSO > TAB2[J - 1]<<FIXEDPOINT_FRACTION_BITS) {
		FVBSO = intToFixedpt(TAB2[J - 1]);
	}
	VBEZB_VBEZBSO_TMP = VBEZB + VBEZBSO;
	HFVBZSO = fixedpt_div(VBEZB_VBEZBSO_TMP, 25600);
	HFVBZSO = HFVBZSO - FVBSO;
	FVBZSO = FVBZ + MRE4_TMP4; //Auf volle Euro aufrunden
	if (FVBZSO > HFVBZSO) {
		FVBZSO = HFVBZSO; //Auf volle Euro aufrunden
	}
	if (FVBZSO > TAB3[J - 1]<<FIXEDPOINT_FRACTION_BITS) {
		FVBZSO = intToFixedpt(TAB3[J - 1]);
	}
	HFVBZ = fixedpt_div(VBEZB, 25600);
	HFVBZ = HFVBZ  - FVB;
	if (FVBZ > HFVBZ) {
		FVBZ = HFVBZ; //Auf volle Euro aufrunden
	}
	}
	MRE4ALTE();
}
