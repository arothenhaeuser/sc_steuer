/*
 * fixedpt.h
 *
 *  Created on: 01.02.2017
 *      Author: pet
 */

#ifndef FIXEDPT_H_
#define FIXEDPT_H_

#define FIXEDPOINT_BITS 32
#define FIXEDPOINT_INTEGER_BITS 8
#define FIXEDPOINT_FRACTION_BITS (FIXEDPOINT_BITS - FIXEDPOINT_INTEGER_BITS)

typedef int32_t fixedpt;
typedef uint32_t fixedptd;

fixedpt intToFixedpt(int in) {
	return in << FIXEDPOINT_FRACTION_BITS;
}

fixedpt fixedpt_mul(fixedpt a, fixedpt b) {
	return ((fixedpt) a * (fixedpt) b) >> FIXEDPOINT_FRACTION_BITS;
}

fixedpt fixedpt_div(fixedpt a, fixedpt b) {
	return ((fixedpt) a << FIXEDPOINT_FRACTION_BITS) / b;
}

int fixedptToInt(fixedpt a) {
    return a >> FIXEDPOINT_FRACTION_BITS;
}

#endif /* FIXEDPT_H_ */
