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
static const char *ng0 = "/home/ise/git/firmware-surf/sim/ANITA4_dual_trigger_tb.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3564397177;
extern char *STD_TEXTIO;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );
void ieee_p_3564397177_sub_2250825304603680424_91900896(char *, char *, char *, char *, char *, unsigned char , int );


static void work_a_1702545047_2372691052_p_0(char *t0)
{
    char t8[16];
    char t13[16];
    char t18[16];
    char t23[16];
    char t28[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;

LAB0:    xsi_set_current_line(110, ng0);
    t1 = (t0 + 2272U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5824);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(111, ng0);
    t3 = (t0 + 3488U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t6 = (t5 + 1);
    t3 = (t0 + 3488U);
    t7 = *((char **)t3);
    t3 = (t7 + 0);
    *((int *)t3) = t6;
    xsi_set_current_line(114, ng0);
    t1 = (t0 + 1192U);
    t3 = *((char **)t1);
    t1 = (t0 + 1032U);
    t4 = *((char **)t1);
    t7 = ((IEEE_P_2592010699) + 4000);
    t9 = (t0 + 9848U);
    t10 = (t0 + 9832U);
    t1 = xsi_base_array_concat(t1, t8, t7, (char)97, t3, t9, (char)97, t4, t10, (char)101);
    t11 = (t0 + 1512U);
    t12 = *((char **)t11);
    t14 = ((IEEE_P_2592010699) + 4000);
    t15 = (t0 + 9880U);
    t11 = xsi_base_array_concat(t11, t13, t14, (char)97, t1, t8, (char)97, t12, t15, (char)101);
    t16 = (t0 + 1352U);
    t17 = *((char **)t16);
    t19 = ((IEEE_P_2592010699) + 4000);
    t20 = (t0 + 9864U);
    t16 = xsi_base_array_concat(t16, t18, t19, (char)97, t11, t13, (char)97, t17, t20, (char)101);
    t21 = (t0 + 1832U);
    t22 = *((char **)t21);
    t24 = ((IEEE_P_2592010699) + 4000);
    t25 = (t0 + 9912U);
    t21 = xsi_base_array_concat(t21, t23, t24, (char)97, t16, t18, (char)97, t22, t25, (char)101);
    t26 = (t0 + 1672U);
    t27 = *((char **)t26);
    t29 = ((IEEE_P_2592010699) + 4000);
    t30 = (t0 + 9896U);
    t26 = xsi_base_array_concat(t26, t28, t29, (char)97, t21, t23, (char)97, t27, t30, (char)101);
    t31 = (t0 + 3608U);
    t32 = *((char **)t31);
    t33 = (15 - 11);
    t34 = (t33 * 1U);
    t35 = (0 + t34);
    t31 = (t32 + t35);
    t36 = (2U + 2U);
    t37 = (t36 + 2U);
    t38 = (t37 + 2U);
    t39 = (t38 + 2U);
    t40 = (t39 + 2U);
    memcpy(t31, t26, t40);
    xsi_set_current_line(115, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 3608U);
    t4 = *((char **)t1);
    t33 = (15 - 15);
    t34 = (t33 * 1U);
    t35 = (0 + t34);
    t1 = (t4 + t35);
    memcpy(t1, t3, 4U);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 4568);
    t3 = (t0 + 4112U);
    t4 = (t0 + 3608U);
    t7 = *((char **)t4);
    memcpy(t8, t7, 16U);
    t4 = (t0 + 10024U);
    ieee_p_3564397177_sub_2250825304603680424_91900896(IEEE_P_3564397177, t1, t3, t8, t4, (unsigned char)0, 0);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 4568);
    t3 = (t0 + 3936U);
    t4 = (t0 + 4112U);
    std_textio_writeline(STD_TEXTIO, t1, t3, t4);
    goto LAB3;

}

static void work_a_1702545047_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 5904);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 4816);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 5904);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 4816);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_1702545047_2372691052_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 5256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(132, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 3368U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 5064);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 5968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3368U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 5064);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_1702545047_2372691052_p_3(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    t1 = (t0 + 5504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(142, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(145, ng0);
    t3 = (8 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(146, ng0);
    t2 = (t0 + 6032);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 6096);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 6160);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 6224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(150, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 6160);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 6224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 6032);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 6096);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(155, ng0);
    t3 = (5 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 6160);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(157, ng0);
    t2 = (t0 + 6224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 6032);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(159, ng0);
    t2 = (t0 + 6096);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(160, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB20:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 6032);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(167, ng0);
    t2 = (t0 + 6096);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 6160);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(169, ng0);
    t2 = (t0 + 6224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(170, ng0);
    t3 = (40 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 6288);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(172, ng0);
    t2 = (t0 + 6352);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(173, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB30:    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB28:    xsi_set_current_line(175, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB34:    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB29:    goto LAB28;

LAB31:    goto LAB29;

LAB32:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 6288);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 6352);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(178, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB38:    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB33:    goto LAB32;

LAB35:    goto LAB33;

LAB36:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 6288);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 6352);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_delta(t2, 1U, 1, 0LL);
    xsi_set_current_line(181, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 5312);
    xsi_process_wait(t2, t3);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB37:    goto LAB36;

LAB39:    goto LAB37;

LAB40:    xsi_set_current_line(185, ng0);

LAB46:    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB44:    goto LAB2;

LAB45:    goto LAB44;

LAB47:    goto LAB45;

}


extern void work_a_1702545047_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1702545047_2372691052_p_0,(void *)work_a_1702545047_2372691052_p_1,(void *)work_a_1702545047_2372691052_p_2,(void *)work_a_1702545047_2372691052_p_3};
	xsi_register_didat("work_a_1702545047_2372691052", "isim/ANITA4_dual_trigger_tb_isim_beh.exe.sim/work/a_1702545047_2372691052.didat");
	xsi_register_executes(pe);
}
