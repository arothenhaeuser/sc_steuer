/*
 * tables.h
 *
 *  Created on: 13.02.2017
 *      Author: pet
 */

#ifndef TABLES_H_
#define TABLES_H_

fixedpt TAB1[36];
int TAB2[36];
int TAB3[36];
fixedpt TAB4[36];
int TAB5[36];

void initTables() {
	TAB1[0] = fixedpt_div(400, 1000);
	TAB1[1] = fixedpt_div(384, 1000);
	TAB1[2] = fixedpt_div(368, 1000);
	TAB1[3] = fixedpt_div(352, 1000);
	TAB1[4] = fixedpt_div(336, 1000);
	TAB1[5] = fixedpt_div(320, 1000);
	TAB1[6] = fixedpt_div(304, 1000);
	TAB1[7] = fixedpt_div(288, 1000);
	TAB1[8] = fixedpt_div(272, 1000);
	TAB1[9] = fixedpt_div(256, 1000);
	TAB1[10] = fixedpt_div(240, 1000);
	TAB1[11] = fixedpt_div(224, 1000);
	TAB1[12] = fixedpt_div(208, 1000);
	TAB1[13] = fixedpt_div(192, 1000);
	TAB1[14] = fixedpt_div(176, 1000);
	TAB1[15] = fixedpt_div(160, 1000);
	TAB1[16] = fixedpt_div(152, 1000);
	TAB1[17] = fixedpt_div(144, 1000);
	TAB1[18] = fixedpt_div(136, 1000);
	TAB1[19] = fixedpt_div(128, 1000);
	TAB1[20] = fixedpt_div(120, 1000);
	TAB1[21] = fixedpt_div(112, 1000);
	TAB1[22] = fixedpt_div(104, 1000);
	TAB1[23] = fixedpt_div(96, 1000);
	TAB1[24] = fixedpt_div(88, 1000);
	TAB1[25] = fixedpt_div(80, 1000);
	TAB1[26] = fixedpt_div(72, 1000);
	TAB1[27] = fixedpt_div(64, 1000);
	TAB1[28] = fixedpt_div(56, 1000);
	TAB1[29] = fixedpt_div(48, 1000);
	TAB1[30] = fixedpt_div(40, 1000);
	TAB1[31] = fixedpt_div(32, 1000);
	TAB1[32] = fixedpt_div(24, 1000);
	TAB1[33] = fixedpt_div(16, 1000);
	TAB1[34] = fixedpt_div(8, 1000);
	TAB1[35] = fixedpt_div(0, 1000);
	TAB2[0] = 3000;
	TAB2[1] = 2880;
	TAB2[2] = 2760;
	TAB2[3] = 2640;
	TAB2[4] = 2520;
	TAB2[5] = 2400;
	TAB2[6] = 2280;
	TAB2[7] = 2160;
	TAB2[8] = 2040;
	TAB2[9] = 1920;
	TAB2[10] = 1800;
	TAB2[11] = 1680;
	TAB2[12] = 1560;
	TAB2[13] = 1440;
	TAB2[14] = 1320;
	TAB2[15] = 1200;
	TAB2[16] = 1140;
	TAB2[17] = 1080;
	TAB2[18] = 1020;
	TAB2[19] = 960;
	TAB2[20] = 900;
	TAB2[21] = 840;
	TAB2[22] = 780;
	TAB2[23] = 720;
	TAB2[24] = 660;
	TAB2[25] = 600;
	TAB2[26] = 540;
	TAB2[27] = 480;
	TAB2[28] = 420;
	TAB2[29] = 360;
	TAB2[30] = 300;
	TAB2[31] = 240;
	TAB2[32] = 180;
	TAB2[33] = 120;
	TAB2[34] = 60;
	TAB2[35] = 0;
	TAB3[0] = 900;
	TAB3[1] = 864;
	TAB3[2] = 828;
	TAB3[3] = 792;
	TAB3[4] = 756;
	TAB3[5] = 720;
	TAB3[6] = 684;
	TAB3[7] = 648;
	TAB3[8] = 612;
	TAB3[9] = 576;
	TAB3[10] = 540;
	TAB3[11] = 504;
	TAB3[12] = 468;
	TAB3[13] = 432;
	TAB3[14] = 396;
	TAB3[15] = 360;
	TAB3[16] = 342;
	TAB3[17] = 324;
	TAB3[18] = 306;
	TAB3[19] = 288;
	TAB3[20] = 270;
	TAB3[21] = 252;
	TAB3[22] = 234;
	TAB3[23] = 216;
	TAB3[24] = 198;
	TAB3[25] = 180;
	TAB3[26] = 162;
	TAB3[27] = 144;
	TAB3[28] = 126;
	TAB3[29] = 108;
	TAB3[30] = 90;
	TAB3[31] = 72;
	TAB3[32] = 54;
	TAB3[33] = 36;
	TAB3[34] = 18;
	TAB3[35] = 0;
	TAB4 = TAB1;
	TAB5[0] = 1900;
	TAB5[1] = 1824;
	TAB5[2] = 1748;
	TAB5[3] = 1672;
	TAB5[4] = 1596;
	TAB5[5] = 1520;
	TAB5[6] = 1444;
	TAB5[7] = 1386;
	TAB5[8] = 1292;
	TAB5[9] = 1216;
	TAB5[10] = 1140;
	TAB5[11] = 1064;
	TAB5[12] = 988;
	TAB5[13] = 912;
	TAB5[14] = 836;
	TAB5[15] = 760;
	TAB5[16] = 722;
	TAB5[17] = 684;
	TAB5[18] = 646;
	TAB5[19] = 608;
	TAB5[20] = 570;
	TAB5[21] = 532;
	TAB5[22] = 494;
	TAB5[23] = 456;
	TAB5[24] = 418;
	TAB5[25] = 380;
	TAB5[26] = 342;
	TAB5[27] = 304;
	TAB5[28] = 266;
	TAB5[29] = 228;
	TAB5[30] = 190;
	TAB5[31] = 152;
	TAB5[32] = 114;
	TAB5[33] = 76;
	TAB5[34] = 38;
	TAB5[35] = 0;
}


#endif /* TABLES_H_ */
