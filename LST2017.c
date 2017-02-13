/*
 * LST2017.c
 *
 *  Created on: 26.12.2016
 *      Author: pet
 */

#include <inttypes.h>
#include "fixedpt.h"
#include "tables.h"
#include "globalVars.h"
#include "MPARA.c"
#include "MRE4JL.c"
#include "MRE4.c"

void dowork(int INPUT_B_KRV, int INPUT_B_KVZ, int INPUT_B_PVS, int INPUT_B_PVZ,
		int INPUT_A_LZZ, int INPUT_A_RE4, int INPUT_A_VBEZ,
		int INPUT_A_LZZFREIB, int INPUT_A_LZZHINZU, int INPUT_B_AF,
		int INPUT_B_F, int INPUT_B_VJAHR, int INPUT_B_VBEZM, int INPUT_B_ZMVB,
		int INPUT_B_VBEZS) {
	initTables();
	MPARA(intToFixedpt(INPUT_B_KRV), intToFixedpt(INPUT_B_KVZ), intToFixedpt(INPUT_B_PVS), intToFixedpt(INPUT_B_PVZ));
	MRE4JL(intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_A_RE4), intToFixedpt(INPUT_A_VBEZ), intToFixedpt(INPUT_A_LZZFREIB), intToFixedpt(INPUT_A_LZZHINZU), intToFixedpt(INPUT_B_AF), intToFixedpt(INPUT_B_F));
	VBEZBSO = intToFixedpt(0);
	KENNVMT = intToFixedpt(0);
	MRE4(intToFixedpt(INPUT_B_VJAHR), intToFixedpt(INPUT_A_VBEZ), intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_B_VBEZM), intToFixedpt(INPUT_B_ZMVB), intToFixedpt(INPUT_B_VBEZS));
}
