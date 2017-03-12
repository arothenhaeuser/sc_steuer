/*
 * UPVKV.c
 *
 *  Created on: 15.02.2017
 *      Author: pet
 */


void UPVKV () {

	if (PKV > 0) {
		if (VSP2 > VSP3) {
			VKV = fixedpt_mul(VSP2, 1677721600);
		} else {
			VKV = fixedpt_mul(VSP3, 1677721600);
		}
	} else {
		VKV = 0;
	}

}
