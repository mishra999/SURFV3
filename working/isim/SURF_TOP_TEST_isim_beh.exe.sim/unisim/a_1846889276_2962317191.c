/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_381452733968206518_503743352(char *, unsigned char );


static void unisim_a_1846889276_2962317191_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;

LAB0:    t1 = (t0 + 3160U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)1);
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    t5 = ((unsigned char)1 == (unsigned char)1);
    if (t5 == 1)
        goto LAB18;

LAB19:    t6 = ((unsigned char)1 == (unsigned char)0);
    t4 = t6;

LAB20:    if (t4 != 0)
        goto LAB15;

LAB17:    if ((unsigned char)0 == 0)
        goto LAB21;

LAB22:
LAB16:
LAB25:    *((char **)t1) = &&LAB26;

LAB1:    return;
LAB4:    t7 = ((unsigned char)0 == (unsigned char)1);
    if (t7 == 1)
        goto LAB10;

LAB11:    t8 = ((unsigned char)0 == (unsigned char)0);
    t6 = t8;

LAB12:    if (t6 != 0)
        goto LAB7;

LAB9:    if ((unsigned char)0 == 0)
        goto LAB13;

LAB14:
LAB8:    goto LAB5;

LAB7:    t2 = (t0 + 2048U);
    t9 = *((char **)t2);
    t2 = (t9 + 0);
    *((unsigned char *)t2) = (unsigned char)0;
    goto LAB8;

LAB10:    t6 = (unsigned char)1;
    goto LAB12;

LAB13:    t2 = (t0 + 6109);
    xsi_report(t2, 72U, (unsigned char)3);
    goto LAB14;

LAB15:    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((unsigned char *)t2) = (unsigned char)0;
    goto LAB16;

LAB18:    t4 = (unsigned char)1;
    goto LAB20;

LAB21:    t2 = (t0 + 6181);
    xsi_report(t2, 75U, (unsigned char)3);
    goto LAB22;

LAB23:    goto LAB2;

LAB24:    goto LAB23;

LAB26:    goto LAB24;

}

static void unisim_a_1846889276_2962317191_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1512U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t3 != t5);
    if (t6 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3728);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    t1 = (t0 + 1352U);
    t7 = *((char **)t1);
    t8 = *((unsigned char *)t7);
    t9 = ieee_p_2592010699_sub_381452733968206518_503743352(IEEE_P_2592010699, t8);
    t1 = (t0 + 3808);
    t10 = (t1 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t9;
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t5 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t3);
    t6 = ieee_p_2592010699_sub_381452733968206518_503743352(IEEE_P_2592010699, t5);
    t1 = (t0 + 3872);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = t6;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

}


extern void unisim_a_1846889276_2962317191_init()
{
	static char *pe[] = {(void *)unisim_a_1846889276_2962317191_p_0,(void *)unisim_a_1846889276_2962317191_p_1};
	xsi_register_didat("unisim_a_1846889276_2962317191", "isim/SURF_TOP_TEST_isim_beh.exe.sim/unisim/a_1846889276_2962317191.didat");
	xsi_register_executes(pe);
}
