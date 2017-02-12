/*
 * LST2017.c
 *
 *  Created on: 26.12.2016
 *      Author: pet
 */

#include <inttypes.h>
#include "fixedpt.h"

static fixedpt t1_0 = fixedpt_div(400, 1000);
static fixedpt t1_1 = fixedpt_div(384, 1000);
static fixedpt t1_2 = fixedpt_div(368, 1000);
static fixedpt t1_3 = fixedpt_div(352, 1000);
static fixedpt t1_4 = fixedpt_div(336, 1000);
static fixedpt t1_5 = fixedpt_div(320, 1000);
static fixedpt t1_6 = fixedpt_div(304, 1000);
static fixedpt t1_7 = fixedpt_div(288, 1000);
static fixedpt t1_8 = fixedpt_div(272, 1000);
static fixedpt t1_9 = fixedpt_div(256, 1000);
static fixedpt t1_10 = fixedpt_div(256, 1000);
static fixedpt t1_11 = fixedpt_div(240, 1000);
static fixedpt t1_12 = fixedpt_div(224, 1000);
static fixedpt t1_13 = fixedpt_div(208, 1000);
static fixedpt t1_14 = fixedpt_div(192, 1000);
static fixedpt t1_15 = fixedpt_div(176, 1000);
static fixedpt t1_16 = fixedpt_div(160, 1000);
static fixedpt t1_17 = fixedpt_div(152, 1000);
static fixedpt t1_18 = fixedpt_div(144, 1000);
static fixedpt t1_19 = fixedpt_div(136, 1000);
static fixedpt t1_20 = fixedpt_div(128, 1000);
static fixedpt t1_21 = fixedpt_div(120, 1000);
static fixedpt t1_22 = fixedpt_div(112, 1000);
static fixedpt t1_23 = fixedpt_div(104, 1000);
static fixedpt t1_24 = fixedpt_div(96, 1000);
static fixedpt t1_25 = fixedpt_div(88, 1000);
static fixedpt t1_26 = fixedpt_div(80, 1000);
static fixedpt t1_27 = fixedpt_div(72, 1000);
static fixedpt t1_28 = fixedpt_div(64, 1000);
static fixedpt t1_29 = fixedpt_div(56, 1000);
static fixedpt t1_30 = fixedpt_div(48, 1000);
static fixedpt t1_31 = fixedpt_div(40, 1000);
static fixedpt t1_32 = fixedpt_div(32, 1000);
static fixedpt t1_33 = fixedpt_div(24, 1000);
static fixedpt t1_34 = fixedpt_div(16, 1000);
static fixedpt t1_35 = fixedpt_div(8, 1000);
static fixedpt t1_36 = fixedpt_div(0, 1000);

static fixedpt t2_0 = fixedpt_div(400, 1000);
static fixedpt t2_1 = fixedpt_div(384, 1000);
static fixedpt t2_2 = fixedpt_div(368, 1000);
static fixedpt t2_3 = fixedpt_div(352, 1000);
static fixedpt t2_4 = fixedpt_div(336, 1000);
static fixedpt t2_5 = fixedpt_div(320, 1000);
static fixedpt t2_6 = fixedpt_div(304, 1000);
static fixedpt t2_7 = fixedpt_div(288, 1000);
static fixedpt t2_8 = fixedpt_div(272, 1000);
static fixedpt t2_9 = fixedpt_div(256, 1000);
static fixedpt t2_10 = fixedpt_div(256, 1000);
static fixedpt t2_11 = fixedpt_div(240, 1000);
static fixedpt t2_12 = fixedpt_div(224, 1000);
static fixedpt t2_13 = fixedpt_div(208, 1000);
static fixedpt t2_14 = fixedpt_div(192, 1000);
static fixedpt t2_15 = fixedpt_div(176, 1000);
static fixedpt t2_16 = fixedpt_div(160, 1000);
static fixedpt t2_17 = fixedpt_div(152, 1000);
static fixedpt t2_18 = fixedpt_div(144, 1000);
static fixedpt t2_19 = fixedpt_div(136, 1000);
static fixedpt t2_20 = fixedpt_div(128, 1000);
static fixedpt t2_21 = fixedpt_div(120, 1000);
static fixedpt t2_22 = fixedpt_div(112, 1000);
static fixedpt t2_23 = fixedpt_div(104, 1000);
static fixedpt t2_24 = fixedpt_div(96, 1000);
static fixedpt t2_25 = fixedpt_div(88, 1000);
static fixedpt t2_26 = fixedpt_div(80, 1000);
static fixedpt t2_27 = fixedpt_div(72, 1000);
static fixedpt t2_28 = fixedpt_div(64, 1000);
static fixedpt t2_29 = fixedpt_div(56, 1000);
static fixedpt t2_30 = fixedpt_div(48, 1000);
static fixedpt t2_31 = fixedpt_div(40, 1000);
static fixedpt t2_32 = fixedpt_div(32, 1000);
static fixedpt t2_33 = fixedpt_div(24, 1000);
static fixedpt t2_34 = fixedpt_div(16, 1000);
static fixedpt t2_35 = fixedpt_div(8, 1000);
static fixedpt t2_36 = fixedpt_div(0, 1000);


static fixedpt TAB1[36] = {t1_0, t1_1, t1_2, t1_3, t1_4, t1_5, t1_6, t1_7, t1_8, t1_9, t1_10, t1_11, t1_12, t1_13, t1_14, t1_15, t1_16, t1_17, t1_18, t1_19, t1_20, t1_21, t1_22, t1_23, t1_24, t1_25, t1_26, t1_27, t1_28, t1_29, t1_30, t1_31, t1_32, t1_33, t1_34, t1_35, t1_36};
//static fixedpt TAB1[36] = {fixedpt_div(400, 1000),fixedpt_div(384, 1000),fixedpt_div(368, 1000),fixedpt_div(352, 1000),fixedpt_div(336, 1000),fixedpt_div(320, 1000),fixedpt_div(304, 1000),fixedpt_div(288, 1000),fixedpt_div(272, 1000),fixedpt_div(256, 1000),fixedpt_div(256, 1000),fixedpt_div(240, 1000),fixedpt_div(224, 1000),fixedpt_div(208, 1000),fixedpt_div(192, 1000),fixedpt_div(176, 1000),fixedpt_div(160, 1000),fixedpt_div(152, 1000),fixedpt_div(144, 1000),fixedpt_div(136, 1000),fixedpt_div(128, 1000),fixedpt_div(120, 1000),fixedpt_div(112, 1000),fixedpt_div(104, 1000),fixedpt_div(96, 1000),fixedpt_div(88, 1000),fixedpt_div(80, 1000),fixedpt_div(72, 1000),fixedpt_div(64, 1000),fixedpt_div(56, 1000),fixedpt_div(48, 1000),fixedpt_div(40, 1000),fixedpt_div(32, 1000),fixedpt_div(24, 1000),fixedpt_div(16, 1000),fixedpt_div(8, 1000),fixedpt_div(0, 1000)};
static int TAB2[36] = { 3000, 2880, 2760, 2640, 2520, 2400, 2280, 2160, 2040,
		1920, 1800, 1680, 1560, 1440, 1320, 1200, 1140, 1080, 1020, 960, 900,
		840, 780, 720, 660, 600, 540, 480, 420, 360, 300, 240, 180, 120, 60, 0 };
static int TAB3[36] = { 900, 864, 828, 792, 756, 720, 684, 648, 612, 576, 540,
		504, 468, 432, 396, 360, 342, 324, 306, 288, 270, 252, 234, 216, 198,
		180, 162, 144, 126, 108, 90, 72, 54, 36, 180 };
static fixedpt TAB4[36] = {t2_0, t2_1, t2_2, t2_3, t2_4, t2_5, t2_6, t2_7, t2_8, t2_9, t2_10, t2_11, t2_12, t2_13, t2_14, t2_15, t2_16, t2_17, t2_18, t2_19, t2_20, t2_21, t2_22, t2_23, t2_24, t2_25, t2_26, t2_27, t2_28, t2_29, t2_30, t2_31, t2_32, t2_33, t2_34, t2_35, t2_36};
static int TAB5[36] = { 1900, 1824, 1748, 1672, 1596, 1520, 1444, 1386, 1292,
		1216, 1140, 1064, 988, 912, 836, 760, 722, 684, 646, 608, 570, 532, 494,
		456, 418, 380, 342, 304, 266, 228, 190, 152, 114, 76, 38, 0 };

fixedpt BBGRV = 0;
fixedpt RVSATZAN = 0;
fixedpt TBSVORV = 0;
fixedpt BBGKVPV = 0;
fixedpt KVSATZAN = 0;
fixedpt KVSATZAG = 0;
fixedpt PVSATZAN = 0;
fixedpt PVSATZAN_TMP = 0;
fixedpt PVSATZAG = 0;
fixedpt W1STKL5 = 0;
fixedpt W2STKL5 = 0;
fixedpt W3STKL5 = 0;
fixedpt GFB = 0;
fixedpt SOLZFREI = 0;
fixedpt ZRE4J = 0;
fixedpt ZVBEZJ = 0;
fixedpt JLFREIB = 0;
fixedpt JLHINZU = 0;
fixedpt VBEZBSO = 0;
fixedpt KENNVMT = 0;
fixedpt ZVBEZJ = 0;
fixedpt FVBZ = 0;
fixedpt FVB = 0;
fixedpt FVBZSO = 0;
fixedpt FVBSO = 0;
int J = 0;
fixedpt VBEZB = 0;
fixedpt VBEZB_VBEZBSO_TMP = 0;
fixedpt HFVB = 0;
fixedpt HFVBZSO = 0;
fixedpt HFVBZ = 0;
fixedpt MRE4_TMP1 = 0;
fixedpt MRE4_TMP2 = 0;
fixedpt MRE4_TMP3 = 0;
fixedpt MRE4_TMP4 = 0;

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

void MRE4JL(fixedpt LZZ, fixedpt RE4, fixedpt VBEZ, fixedpt LZZFREIB, fixedpt LZZHINZU, fixedpt AF,
		fixedpt F) {
	fixedpt factor2 = fixedpt_div(12, 100);
	fixedpt factor3 = fixedpt_div(fixedpt_div(360, 7), 1677721600);
	fixedpt factorElse = fixedpt_div(360, 100);
	if (LZZ == 16777216) {
		ZRE4J = fixedpt_div(RE4, 1677721600);
		ZVBEZJ = fixedpt_div(VBEZ, 1677721600);
		JLFREIB = fixedpt_div(LZZFREIB, 1677721600);
		JLHINZU = fixedpt_div(LZZHINZU, 1677721600);
	} else if (LZZ == 33554432) {
		ZRE4J = fixedpt_mul(RE4, factor2);
		ZVBEZJ = fixedpt_mul(VBEZ, factor2);
		JLFREIB = fixedpt_mul(LZZFREIB, factor2);
		JLHINZU = fixedpt_mul(LZZHINZU, factor2);
	} else if (LZZ == 3) {
		ZRE4J = fixedpt_mul(RE4, factor3);
		ZVBEZJ = fixedpt_mul(VBEZ, factor3);
		JLFREIB = fixedpt_mul(LZZFREIB, factor3);
		JLHINZU = fixedpt_mul(LZZHINZU, factor3);
	} else {
		ZRE4J = fixedpt_mul(RE4, factorElse);
		ZVBEZJ = fixedpt_mul(VBEZ, factorElse);
		JLFREIB = fixedpt_mul(LZZFREIB, factorElse);
		JLHINZU = fixedpt_mul(LZZHINZU, factorElse);
	}
	if (AF == 0) {
		F = 1;
	}
}

fixedpt calcZVBEZJ(fixedpt VBEZ, fixedpt LZZ) {
	fixedpt ret = 0;
	switch (LZZ) {
	case 33554432:
		ret = fixedpt_mul(VBEZ, 201326592);
		break;
	case 50331648:
		ret = fixedpt_mul(VBEZ, 872415232);
		break;
	case 67108864:
		ret = fixedpt_mul(VBEZ, 6123683840);
		break;
	default:
		break;
	}
	return ret;
}

void MRE4(fixedpt VJAHR, fixedpt VBEZ, fixedpt LZZ, fixedpt VBEZM, fixedpt ZMVB, fixedpt VBEZS) {
	MRE4_TMP1 = intToFixedpt(TAB2[J -1]);
	MRE4_TMP2 = fixedpt_div(MRE4_TMP1, 201326592);
	MRE4_TMP3 = fixedpt_div(VBEZB, 1677721600);
	MRE4_TMP4 = fixedpt_div(VBEZBSO, 1677721600);

	ZVBEZJ = calcZVBEZJ(VBEZ, LZZ);

	if (ZVBEZJ == 0) {
		FVBZ = 0;
		FVB = 0;
		FVBZSO = 0;
		FVBSO = 0;
	} else {
		if (VJAHR < 33655095296) {
			J = 1;
		} else if (VJAHR < 17112760320) {
			J = (VJAHR - 33621540864)>>FIXEDPOINT_FRACTION_BITS;
		} else {
			J = 36;
		}
		fixedpt tab1Val = TAB1[J - 1];
		if (LZZ == intToFixedpt(1)) {
			VBEZB = fixedpt_mul(VBEZM, ZMVB) + VBEZS;
			HFVB = fixedpt_mul(MRE4_TMP2, ZMVB);
			FVBZ = fixedpt_mul(MRE4_TMP2, ZMVB); //Auf volle Euro aufrunden
		} else {
			VBEZB = VBEZM * 201326592 + VBEZS;
			HFVB = intToFixedpt(TAB2[J - 1]);
			FVBZ = intToFixedpt(TAB3[J - 1]); //Auf volle Euro aufrunden
		}
		FVB = fixedpt_mul(MRE4_TMP3, tab1Val); //Auf volle Cent aufrunden
		if (FVB > HFVB) {
			FVB = HFVB;
		}
		if (FVB > ZVBEZJ) {
			FVB = ZVBEZJ;
		}
		FVBSO = FVB + fixedpt_mul(MRE4_TMP4, tab1Val); //Auf volle Cent aufrunden
		if (FVBSO > intToFixedpt(TAB2[J - 1])) {
			FVBSO = intToFixedpt(TAB2[J - 1]);
		}
		VBEZB_VBEZBSO_TMP = (VBEZB + VBEZBSO);
		HFVBZSO = fixedpt_div(VBEZB_VBEZBSO_TMP, 1677721600) - FVBSO;
		FVBZSO = FVBZ + MRE4_TMP4; //Auf volle Euro aufrunden
		if (FVBZSO > HFVBZSO) {
			FVBZSO = HFVBZSO; //Auf volle Euro aufrunden
		}
		if (FVBZSO > intToFixedpt(TAB3[J - 1])) {
			FVBZSO = intToFixedpt(TAB3[J - 1]);
		}
		HFVBZ = VBEZB/100 - FVB;
		if (FVBZ > HFVBZ) {
			FVBZ = HFVBZ; //Auf volle Euro aufrunden
		}
	}
	//MRE4ALTE();
}

void dowork(int INPUT_B_KRV, int INPUT_B_KVZ, int INPUT_B_PVS, int INPUT_B_PVZ,
		int INPUT_A_LZZ, int INPUT_A_RE4, int INPUT_A_VBEZ,
		int INPUT_A_LZZFREIB, int INPUT_A_LZZHINZU, int INPUT_B_AF,
		int INPUT_B_F, int INPUT_B_VJAHR, int INPUT_B_VBEZM, int INPUT_B_ZMVB,
		int INPUT_B_VBEZS) {
	MPARA(intToFixedpt(INPUT_B_KRV), intToFixedpt(INPUT_B_KVZ), intToFixedpt(INPUT_B_PVS), intToFixedpt(INPUT_B_PVZ));
	MRE4JL(intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_A_RE4), intToFixedpt(INPUT_A_VBEZ), intToFixedpt(INPUT_A_LZZFREIB), intToFixedpt(INPUT_A_LZZHINZU), intToFixedpt(INPUT_B_AF), intToFixedpt(INPUT_B_F));
	VBEZBSO = intToFixedpt(0);
	KENNVMT = intToFixedpt(0);
	//MRE4(intToFixedpt(INPUT_B_VJAHR), intToFixedpt(INPUT_A_VBEZ), intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_B_VBEZM), intToFixedpt(INPUT_B_ZMVB), intToFixedpt(INPUT_B_VBEZS));
}
