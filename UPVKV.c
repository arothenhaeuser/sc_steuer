/*
 * UPVKV.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPVKV (fixedpt PKV) {

	if (PKV > 0) {
		if (VSP2 > VSP3) {
			VKV = fixedpt_mul(VSP2, intToFixedpt(100));
		} else {
			VKV = fixedpt_mul(VSP3, intToFixedpt(100));
		}
	} else {
		VKV = 0;
	}

}
