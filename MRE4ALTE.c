/*
 * MRE4ALTE.c
 *
 *  Created on: 07.03.2017
 *      Author: pet
 */



#include "fixedpt.h"
#include "tables.h"

void MRE4ALTE() {
	if(ALTER1 == 0) {
		ALTE = 0;
	} else {
		if(AJAHR < 513536){
			K = 1;
		} else {
			if(AJAHR < 522240){
				K = fixedptToInt(AJAHR - 513024);
			} else {
				K = 36;
			}
		}
		BMG = ZRE4J -ZVBEZJ;
		ALTE = fixedpt_mul(BMG, TAB4[K]);
		HBALTE = intToFixedpt(TAB5[K]);
		if(ALTE > HBALTE){
			ALTE = HBALTE;
		}
	}
}
