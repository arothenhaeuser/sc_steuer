/*
 * MLSTJAHR.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */

#include "UPEVP.c"
#include "UPMLST.c"

void MLSTJAHR(){

	UPEVP();

	if (KENNVMT != 1677216) {
		ZVE = ZRE4 - ZTABFB - VSP;
		UPMLST();
	} else {
		MLSTJAHR_TMP2 = fixedpt_div(VMT, 1677721600);
		MLSTJAHR_TMP3 = fixedpt_div(VKAPA, 1677721600);
		ZVE = ZRE4 - ZTABFB - VSP - MLSTJAHR_TMP2 - MLSTJAHR_TMP3;
		if (ZVE < 0) {
			MLSTJAHR_TMP4 = fixedpt_div(VMT, 1677721600);
			MLSTJAHR_TMP5 = fixedpt_div(VKAPA, 1677721600);
			MLSTJAHR_TMP1 = ZVE + MLSTJAHR_TMP4 + MLSTJAHR_TMP5;
			ZVE = fixedpt_div(MLSTJAHR_TMP1, 83886080);
			UPMLST();
			ST = fixedpt_mul(ST, 83886080);
		} else {
			UPMLST();
			STOVMT = ST;
			MLSTJAHR_TMP6 = fixedpt_div((VMT+VKAPA), 8388608000);
			ZVE = ZVE + MLSTJAHR_TMP6;
			UPMLST();
			MLSTJAHR_TMP7 = fixedpt_mul((ST-STOVMT), 83886080);
			ST = MLSTJAHR_TMP7 + STOVMT;
		}
	}

}
