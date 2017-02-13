/*
 * MPARA.c
 *
 *  Created on: 13.02.2017
 *      Author: pet
 */


void MPARA(fixedpt KRV, fixedpt KVZ, fixedpt PVS, fixedpt PVZ) {
	if (KRV < intToFixedpt(2)) {
		if (KRV == 0) {
			BBGRV = intToFixedpt(76200);
		} else {
			BBGRV = intToFixedpt(68400);
		}
		RVSATZAN = fixedpt_div(935, 10000);
		TBSVORV = fixedpt_div(68, 100);
	}
	BBGKVPV = intToFixedpt(52200);
	KVSATZAN = fixedpt_div(KVZ, intToFixedpt(100)) + fixedpt_div(7, 100);
	KVSATZAG = fixedpt_div(7, 100);
	if (PVS == intToFixedpt(1)) {
		PVSATZAN = fixedpt_div(1775, 100000);
		PVSATZAG = fixedpt_div(775, 100000);
	} else {
		PVSATZAN = fixedpt_div(1275, 100000);
		PVSATZAG = fixedpt_div(1275, 100000);
	}
	if (PVZ == intToFixedpt(1)) {
		PVSATZAN_TMP = fixedpt_div(25, 10000);
		PVSATZAN = PVSATZAN_TMP + PVSATZAN;
	}
	W1STKL5 = intToFixedpt(10240);
	W2STKL5 = intToFixedpt(27029);
	W3STKL5 = intToFixedpt(205043);
	GFB = intToFixedpt(8820);
	SOLZFREI = intToFixedpt(972);
}
