/*
 * UPVKV.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPVKV () {

	if (PKV > 0) {
		if (VSP2 > VSP3) {
			VKV = fixedpt_mul(VSP2, 25600);
		} else {
			VKV = fixedpt_mul(VSP3, 25600);
		}
	} else {
		VKV = 0;
	}

}
