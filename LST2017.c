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
#include "MRE4ABZ.c"
#include "MBERECH.c"

void dowork(
			int INPUT_A_RE4,
			int INPUT_A_VBEZ,
			int INPUT_A_LZZFREIB,
			int INPUT_A_LZZHINZU,
			int INPUT_A_ENTSCH,		//MRE4ABZ
			int INPUT_A_STKL,		//MBERECH
			int INPUT_A_ZKF,		//MBERECH
			int INPUT_A_KRV,		//MBERECH
			int INPUT_A_PKV,		//MBERECH
			int INPUT_A_PKPV,		//MBERECH
			int INPUT_A_F,			//MBERECH
			int INPUT_A_R,			//MBERECH
			int INPUT_B_VMT,		//MBERECH
			int INPUT_B_VKAPA,		//MBERECH
			int INPUT_B_LZZ,		//MBERECH
			int INPUT_B_KRV,
			int INPUT_B_KVZ,
			int INPUT_B_PVS,
			int INPUT_B_PVZ,
			int INPUT_A_LZZ,
			int INPUT_B_AF,
			int INPUT_B_F,
			int INPUT_B_VJAHR,
			int INPUT_B_VBEZM,
			int INPUT_B_ZMVB,
			int INPUT_B_VBEZS,
			int INPUT_B_SONSTB,		//MSONST
			int INPUT_A_JRE4,		//MSONST
			int INTPUT_A_JVBEZ,		//MSONST
			int INPUT_B_VBS,		//MSONST
			int INTPUT_B_STERBE		//MSONST
			) {
	initTables();
	MPARA(intToFixedpt(INPUT_B_KRV), intToFixedpt(INPUT_B_KVZ), intToFixedpt(INPUT_B_PVS), intToFixedpt(INPUT_B_PVZ));
	MRE4JL(intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_A_RE4), intToFixedpt(INPUT_A_VBEZ), intToFixedpt(INPUT_A_LZZFREIB), intToFixedpt(INPUT_A_LZZHINZU), intToFixedpt(INPUT_B_AF), intToFixedpt(INPUT_B_F));
	VBEZBSO = intToFixedpt(0);
	KENNVMT = intToFixedpt(0);
	MRE4(intToFixedpt(INPUT_B_VJAHR), intToFixedpt(INPUT_A_VBEZ), intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_B_VBEZM), intToFixedpt(INPUT_B_ZMVB), intToFixedpt(INPUT_B_VBEZS));
	MRE4ABZ(intToFixedpt(INPUT_A_ENTSCH));
	MBERECH(intToFixedpt(INPUT_A_STKL), intToFixedpt(INPUT_A_ZKF), intToFixedpt(INPUT_A_KRV), intToFixedpt(INPUT_A_PKV),
			intToFixedpt(INPUT_A_PKPV), intToFixedpt(INPUT_B_VMT), intToFixedpt(INPUT_B_VKAPA), intToFixedpt(INPUT_A_F),
			intToFixedpt(INPUT_B_LZZ), intToFixedpt(INPUT_A_ENTSCH), intToFixedpt(INPUT_A_R));
	MSONST(intToFixedpt(INPUT_A_LZZ), intToFixedpt(INPUT_B_ZMVB), intToFixedpt(INPUT_B_SONSTB), intToFixedpt(INPUT_A_JRE4), intToFixedpt(INTPUT_A_JVBEZ), intToFixedpt(INPUT_B_VBS), intToFixedpt(INTPUT_B_STERBE));
}
