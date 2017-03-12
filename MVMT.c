/*
 * MVMT.c
 *
 *  Created on: 07.03.2017
 *      Author: pet
 */

#include "fixedpt.h"

void MVMT() {
	if(VKAPA < 0) {
		VKAPA = 0;
	}
	if((VMT + VKAPA) > 0) {
		if(LSTSO == 0) {
			MOSONST();
			LST1 = LSTOSO;
		} else {
			LST1 = LSTSO;
		}
		VBEZBSO = STERBE + VKAPA;
		MVMT_TMP1 = JRE4 + SONSTB + VMT + VKAPA;
		ZRE4J = fixedpt_div(MVMT_TMP1, 1677721600);
		MVMT_TMP2 = JVBEZ + VBS + VKAPA;
		ZVBEZJ = fixedpt_div(MVMT_TMP2, 1677721600);
		KENNVMT = 33554432;
		MRE4SONST();
		MLSTJAHR();
		LST3 = fixedpt_mul(ST, 1677721600);
		MRE4ABZ();
		MVMT_TMP3 = fixedpt_div(JRE4ENT, 1677721600);
		MVMT_TMP4 = fixedpt_div(SONSTENT, 1677721600);
		ZRE4VP = ZRE4VP - MVMT_TMP3 - MVMT_TMP4;
		KENNVMT = 16777216;
		MLSTJAHR();
		LST2 = fixedpt_mul(ST, 1677721600);
		STV = LST2 - LST1;
		LST3 = LST3 - LST1;
		if(LST3 < STV) {
			STV = LST3;
		}
		if(STV < 0) {
			STV = 0;
		} else {
			MVMT_TMP5 = fixedpt_mul(STV, F);
			STV = MVMT_TMP5;
		}
		MVMT_TMP6 = fixedpt_div(922746880, 167772160);
		MVMT_TMP7 = fixedpt_mul(STV, MVMT_TMP6);
		SOLZV = fixedpt_div(MVMT_TMP7, 1677721600);
		if(R > 0) {
			BKV = STV;
		} else {
			BKV = 0;
		}
	} else {
		STV = 0;
		SOLZV = 0;
		BKV = 0;
	}
}
