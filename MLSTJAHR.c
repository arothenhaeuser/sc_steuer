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

	if (KENNVMT != 256) {
		ZVE = ZRE4 - ZTABFB - VSP;
		UPMLST();
	} else {
		MLSTJAHR_TMP2 = fixedpt_div(VMT, 25600);
		MLSTJAHR_TMP3 = fixedpt_div(VKAPA, 25600);
		ZVE = ZRE4 - ZTABFB - VSP - MLSTJAHR_TMP2 - MLSTJAHR_TMP3;
		if (ZVE < 0) {
			MLSTJAHR_TMP4 = fixedpt_div(VMT, 25600);
			MLSTJAHR_TMP5 = fixedpt_div(VKAPA, 25600);
			MLSTJAHR_TMP1 = ZVE + MLSTJAHR_TMP4 + MLSTJAHR_TMP5;
			ZVE = fixedpt_div(MLSTJAHR_TMP1, 1280);
			UPMLST();
			ST = fixedpt_mul(ST, 1280);
		} else {
			UPMLST();
			STOVMT = ST;
			MLSTJAHR_TMP6 = fixedpt_div((VMT+VKAPA), 128000);
			ZVE = ZVE + MLSTJAHR_TMP6;
			UPMLST();
			MLSTJAHR_TMP7 = fixedpt_mul((ST-STOVMT), 1280);
			ST = MLSTJAHR_TMP7 + STOVMT;
		}
	}

}
