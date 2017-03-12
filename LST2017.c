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
#include "MRE4ALTE.c"
#include "MRE4ABZ.c"
#include "MBERECH.c"
#include "MSONST.c"
#include "MVMT.c"

void dowork(int INPUT_A_RE4, int INPUT_B_VBEZ, int INPUT_A_LZZFREIB,
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
		int INPUT_B_KVZ,		//
		int INPUT_B_PVS,		//
		int INPUT_B_PVZ,		//
		int INPUT_B_AF,		//
		int INPUT_B_VJAHR,		//
		int INPUT_B_VBEZM,		//
		int INPUT_B_ZMVB,		//
		int INPUT_B_VBEZS,		//
		int INPUT_B_SONSTB,		//MSONST
		int INPUT_B_VBS,		//MSONST
		int INPUT_B_STERBE,		//MSONST
		int INPUT_A_ALTER1, int INPUT_A_AJAHR, int INPUT_B_SONSTENT,
		int INPUT_B_JRE4ENT) {

    RE4 = intToFixedpt(INPUT_A_RE4);
    VBEZ = intToFixedpt(INPUT_B_VBEZ);
    LZZFREIB = intToFixedpt(INPUT_A_LZZFREIB);
    LZZHINZU = intToFixedpt(INPUT_A_LZZHINZU);
    ENTSCH = intToFixedpt(INPUT_A_ENTSCH);
    STKL = intToFixedpt(INPUT_A_STKL);
    ZKF = intToFixedpt(INPUT_A_ZKF);
    KRV = intToFixedpt(INPUT_A_KRV);
    PKV = intToFixedpt(INPUT_A_PKV);
    PKPV = intToFixedpt(INPUT_A_PKPV);
    F = intToFixedpt(INPUT_A_F);
    R = intToFixedpt(INPUT_A_R);
    VMT = intToFixedpt(INPUT_B_VMT);
    VKAPA = intToFixedpt(INPUT_B_VKAPA);
    LZZ = intToFixedpt(INPUT_B_LZZ);
    KVZ = intToFixedpt(INPUT_B_KVZ);
    PVS = intToFixedpt(INPUT_B_PVS);
    PVZ = intToFixedpt(INPUT_B_PVZ);
    AF = intToFixedpt(INPUT_B_AF);
    VJAHR = intToFixedpt(INPUT_B_VJAHR);
    VBEZM = intToFixedpt(INPUT_B_VBEZM);
    ZMVB = intToFixedpt(INPUT_B_ZMVB);
    VBEZS = intToFixedpt(INPUT_B_VBEZS);
    SONSTB = intToFixedpt(INPUT_B_SONSTB);
    VBS = intToFixedpt(INPUT_B_VBS);
    STERBE = intToFixedpt(INPUT_B_STERBE);
    ALTER1 = intToFixedpt(INPUT_A_ALTER1);
    AJAHR = intToFixedpt(INPUT_A_AJAHR);
    SONSTENT = intToFixedpt(INPUT_B_SONSTENT);
    JRE4ENT = intToFixedpt(INPUT_B_JRE4ENT);


	initTables();


	MPARA();
	MRE4JL();
	VBEZBSO = intToFixedpt(0);
	KENNVMT = intToFixedpt(0);
	MRE4();
	MRE4ABZ();
	MBERECH();
	MSONST();
	MVMT();

	int OUTPUT_BK = fixedptToInt(BK);
	int OUTPUT_BKS = fixedptToInt(BKS);
	int OUTPUT_BKV = fixedptToInt(BKV);
	int OUTPUT_LSTLZZ = fixedptToInt(LSTLZZ);
	int OUTPUT_SOLZLZZ = fixedptToInt(SOLZLZZ);
	int OUTPUT_SOLZS = fixedptToInt(SOLZS);
	int OUTPUT_SOLZV = fixedptToInt(SOLZV);
	int OUTPUT_STS = fixedptToInt(STS);
	int OUTPUT_STV = fixedptToInt(STV);
	int OUTPUT_VKVLZZ = fixedptToInt(VKVLZZ);
	int OUTPUT_VKVSONST = fixedptToInt(VKVSONST);

	int OUTPUT_VFRB = fixedptToInt(VFRB);
	int OUTPUT_VFRBS2 = fixedptToInt(VFRBS2);
	int OUTPUT_WVFRB = fixedptToInt(WVFRB);
	int OUTPUT_WVFRBM = fixedptToInt(WVFRBM);
	int OUTPUT_WVFRBO = fixedptToInt(WVFRBO);
}
