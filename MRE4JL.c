/*
 * MRE4JL.c
 *
 *  Created on: 13.02.2017
 *      Author: pet
 */


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
