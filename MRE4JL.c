/*
 * MRE4JL.c
 *
 *  Created on: 13.02.2017
 *      Author: pet
 */


void MRE4JL() {
	fixedpt factor2 = fixedpt_div(12, 100);
	MRE4JL_TMP1 = fixedpt_div(360, 7);
	fixedpt factor3 = fixedpt_div(MRE4JL_TMP1, 25600);
	fixedpt factorElse = fixedpt_div(360, 100);
	if (LZZ == 256) {
		ZRE4J = fixedpt_div(RE4, 25600);
		ZVBEZJ = fixedpt_div(VBEZ, 25600);
		JLFREIB = fixedpt_div(LZZFREIB, 25600);
		JLHINZU = fixedpt_div(LZZHINZU, 25600);
	} else if (LZZ == 512) {
		ZRE4J = fixedpt_mul(RE4, factor2);
		ZVBEZJ = fixedpt_mul(VBEZ, factor2);
		JLFREIB = fixedpt_mul(LZZFREIB, factor2);
		JLHINZU = fixedpt_mul(LZZHINZU, factor2);
	} else if (LZZ == 768) {
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
		F = 256;
	}
}
