/*
 * MRE4SONST.c
 *
 *  Created on: 07.03.2017
 *      Author: pet
 */


#include "fixedpt.h"
#include "MRE4.c"
#include "MRE4ABZ.c"
#include "MZTABFB.c"

void MRE4SONST(fixedpt SONSTENT, ) {
	MRE4();
	FVB = FVBSO;
	MRE4ABZ();
	MRE4SONST_TMP1 = fixedpt_div(JRE4ENT, 1677721600);
	MRE4SONST_TMP2 = fixedpt_div(SONSTENT, 1677721600);
	ZRE4VP = ZRE4VP - MRE4SONST_TMP1 - MRE4SONST_TMP2;
	FVBZ = FVBZSO;
	MZTABFB();
	MRE4SONST_TMP3 = ANP + FVB + FVBZ;
	VFRBS2 = fixedpt_mul(MRE4SONST_TMP3, 1677721600);
	VFRBS2 = VFRBS2 - VFRBS1;
	fixedpt OUTPUT_VFRBS2 = VFRBS1;
}
