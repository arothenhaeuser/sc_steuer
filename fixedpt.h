/*
 * fixedpt.h
 *
 *  Created on: 01.02.2017
 *      Author: pet
 */

#ifndef FIXEDPT_H_
#define FIXEDPT_H_

#define FIXEDPOINT_BITS 64
#define FIXEDPOINT_INTEGER_BITS 40
#define FIXEDPOINT_FRACTION_BITS (FIXEDPOINT_BITS - FIXEDPOINT_INTEGER_BITS)

typedef int64_t fixedpt;
typedef uint64_t fixedptd;

fixedpt intToFixedpt(int in) {
	return in << FIXEDPOINT_FRACTION_BITS;
}

fixedpt fixedpt_mul(fixedpt a, fixedpt b) {
	return ((fixedpt) a * (fixedpt) b) >> FIXEDPOINT_FRACTION_BITS;
}

fixedpt fixedpt_div(fixedpt a, fixedpt b) {
	return ((fixedpt) a << FIXEDPOINT_FRACTION_BITS) / b;
}

#endif /* FIXEDPT_H_ */
