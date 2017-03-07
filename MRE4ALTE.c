/*
 * MRE4ALTE.c
 *
 *  Created on: 07.03.2017
 *      Author: pet
 */



#include "fixedpt.h"
#include "tables.h"

void MRE4ALTE(fixedpt ALTER1, fixedpt AJAHR, ) {
	if(ALTER1 == 0) {
		ALTE = 0;
	} else {
		if(AJAHR < 33655095296){
			K = 16777216;
		} else {
			if(AJAHR < 34225520640){
				K = AJAHR - 33621540864;
			} else {
				K = 603979776;
			}
		}
		BMG = ZRE4J -ZVBEZJ;
		ALTE = fixedpt_mul(BMG, TAB4(K));
		HBALTE = TAB5(K);
		if(ALTE > HBALTE){
			ALTE = HBALTE;
		}
	}
}
