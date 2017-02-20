/*
 * MSONST.c
 *
 *  Created on: 20.02.2017
 *      Author: pet
 */


#include "fixedpt.h"

void MSONST(fixedpt LZZ, fixedpt ZMVB, fixedpt SONSTB, fixedpt JRE4, fixedpt JVBEZ, fixedpt VBS, fixedpt STERBE) {
	LZZ = 1;
	if(ZMVB == 0){
		ZMVB = 12;
	}
	if(SONSTB == 0){
		fixedpt OUTPUT_VKVSONST = 0;
		LSTSO = 0;
		fixedpt OUTPUT_STS = 0;
		fixedpt OUTPUT_SOLZS = 0;
		fixedpt OUTPUT_BKS = 0;
	} else {
		MOSONST();
		UPVKV();
		fixedpt OUTPUT_VKVSONST = VKV;
		ZRE4J = JRE4 + SONSTB;
		ZRE4J = fixedpt_div(ZRE4J, 1677721600);
		SVBEZJ = JVBEZ + VBS;
		SVBEZJ = fixedpt_div(SVBEZJ, 1677721600);
		VBEZBSO = STERBE;
		MRE4SONST();
		MLSTJAHR();
		WVFRBM = ZVE - GFB;
		WVFRMB = fixedpt_mul(WVFRMB, 1677721600);
		if(WVFRMB < 0){
			WVFRMB = 0;
		}
		UPVKV();
		VKVSONST = VKV - VKVSONST;
		LSTSO = fixedpt_mul(ST, 1677721600);
		//TODO
	}
}
