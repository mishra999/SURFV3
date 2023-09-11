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
static const char *ng0 = "/home/ise/git/firmware-surf/sim/SURF_TOP_TEST.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static unsigned int ng3[] = {255U, 0U};
static unsigned int ng4[] = {0U, 0U};
static unsigned int ng5[] = {1U, 0U};
static unsigned int ng6[] = {2U, 0U};
static unsigned int ng7[] = {3U, 0U};
static unsigned int ng8[] = {4U, 0U};
static unsigned int ng9[] = {5U, 0U};
static unsigned int ng10[] = {6U, 0U};
static unsigned int ng11[] = {7U, 0U};



static int sp_hk_read(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 848);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(277, ng0);

LAB5:    xsi_set_current_line(278, ng0);
    t5 = (t2 + 88U);
    t6 = *((char **)t5);
    t7 = (t6 + 0U);
    xsi_wp_set_status(t7, 1);
    *((char **)t3) = &&LAB6;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(279, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 11320);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(280, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 11960);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(281, ng0);
    t4 = (t1 + 15960);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 11800);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 6);
    xsi_set_current_line(282, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 11480);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(283, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 16U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(284, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 11320);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(285, ng0);

LAB8:    t4 = (t1 + 2760U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB9;

LAB10:    xsi_set_current_line(286, ng0);
    t4 = (t1 + 10920U);
    t5 = *((char **)t4);
    t4 = (t1 + 16120);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    xsi_set_current_line(287, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 48U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB12;
    goto LAB1;

LAB9:    xsi_set_current_line(285, ng0);
    t6 = (t2 + 88U);
    t7 = *((char **)t6);
    t13 = (t7 + 32U);
    xsi_wp_set_status(t13, 1);
    *((char **)t3) = &&LAB11;
    goto LAB1;

LAB11:    goto LAB8;

LAB12:    xsi_set_current_line(288, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 11480);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(289, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 11960);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(290, ng0);
    t4 = (t2 + 88U);
    t5 = *((char **)t4);
    t6 = (t5 + 64U);
    xsi_wp_set_status(t6, 1);
    *((char **)t3) = &&LAB13;
    goto LAB1;

LAB13:    goto LAB4;

}

static void NetDecl_37_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 17032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 12600);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t6) == 0)
        goto LAB4;

LAB6:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t3 + 4);
    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (~(t15));
    *((unsigned int *)t3) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 20416);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0U);
    t36 = (t0 + 20080);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t3) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

}

static void NetDecl_39_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 17280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 12760);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t6) == 0)
        goto LAB4;

LAB6:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t3 + 4);
    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (~(t15));
    *((unsigned int *)t3) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 20480);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0U);
    t36 = (t0 + 20096);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t3) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

}

static void NetDecl_41_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 17528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 12920);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    *((unsigned int *)t3) = t9;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 15U);
    t15 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t15 & 15U);
    t16 = (t0 + 20544);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t20, 0, 8);
    t21 = 15U;
    t22 = t21;
    t23 = (t3 + 4);
    t24 = *((unsigned int *)t3);
    t21 = (t21 & t24);
    t25 = *((unsigned int *)t23);
    t22 = (t22 & t25);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 | t21);
    t28 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t28 | t22);
    xsi_driver_vfirst_trans(t16, 0, 3U);
    t29 = (t0 + 20112);
    *((int *)t29) = 1;

LAB1:    return;
LAB5:    t10 = *((unsigned int *)t3);
    t11 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t10 | t11);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t12 | t13);
    goto LAB4;

}

static void NetDecl_43_3(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 17776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 13080);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t5 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t6) == 0)
        goto LAB4;

LAB6:    t12 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t12) = 1;

LAB7:    t13 = (t3 + 4);
    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = (~(t15));
    *((unsigned int *)t3) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB9;

LAB8:    t21 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 20608);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0U);
    t36 = (t0 + 20128);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t17 = *((unsigned int *)t3);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t3) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB8;

}

static void NetDecl_48_4(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 18024U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 13240);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    *((unsigned int *)t3) = t9;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 255U);
    t15 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t15 & 255U);
    t16 = (t0 + 20672);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t20, 0, 8);
    t21 = 255U;
    t22 = t21;
    t23 = (t3 + 4);
    t24 = *((unsigned int *)t3);
    t21 = (t21 & t24);
    t25 = *((unsigned int *)t23);
    t22 = (t22 & t25);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 | t21);
    t28 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t28 | t22);
    xsi_driver_vfirst_trans(t16, 0, 7U);
    t29 = (t0 + 20144);
    *((int *)t29) = 1;

LAB1:    return;
LAB5:    t10 = *((unsigned int *)t3);
    t11 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t10 | t11);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t12 | t13);
    goto LAB4;

}

static void NetDecl_49_5(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 18272U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 13400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    *((unsigned int *)t3) = t9;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 255U);
    t15 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t15 & 255U);
    t16 = (t0 + 20736);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t20, 0, 8);
    t21 = 255U;
    t22 = t21;
    t23 = (t3 + 4);
    t24 = *((unsigned int *)t3);
    t21 = (t21 & t24);
    t25 = *((unsigned int *)t23);
    t22 = (t22 & t25);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 | t21);
    t28 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t28 | t22);
    xsi_driver_vfirst_trans(t16, 0, 7U);
    t29 = (t0 + 20160);
    *((int *)t29) = 1;

LAB1:    return;
LAB5:    t10 = *((unsigned int *)t3);
    t11 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t10 | t11);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t12 | t13);
    goto LAB4;

}

static void NetDecl_50_6(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 18520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(50, ng0);
    t2 = (t0 + 13560);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    *((unsigned int *)t3) = t9;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 255U);
    t15 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t15 & 255U);
    t16 = (t0 + 20800);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t20, 0, 8);
    t21 = 255U;
    t22 = t21;
    t23 = (t3 + 4);
    t24 = *((unsigned int *)t3);
    t21 = (t21 & t24);
    t25 = *((unsigned int *)t23);
    t22 = (t22 & t25);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 | t21);
    t28 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t28 | t22);
    xsi_driver_vfirst_trans(t16, 0, 7U);
    t29 = (t0 + 20176);
    *((int *)t29) = 1;

LAB1:    return;
LAB5:    t10 = *((unsigned int *)t3);
    t11 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t10 | t11);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t12 | t13);
    goto LAB4;

}

static void NetDecl_51_7(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;

LAB0:    t1 = (t0 + 18768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 13720);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t3, 0, 8);
    t6 = (t3 + 4);
    t7 = (t5 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    *((unsigned int *)t3) = t9;
    *((unsigned int *)t6) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t14 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t14 & 255U);
    t15 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t15 & 255U);
    t16 = (t0 + 20864);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memset(t20, 0, 8);
    t21 = 255U;
    t22 = t21;
    t23 = (t3 + 4);
    t24 = *((unsigned int *)t3);
    t21 = (t21 & t24);
    t25 = *((unsigned int *)t23);
    t22 = (t22 & t25);
    t26 = (t20 + 4);
    t27 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t27 | t21);
    t28 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t28 | t22);
    xsi_driver_vfirst_trans(t16, 0, 7U);
    t29 = (t0 + 20192);
    *((int *)t29) = 1;

LAB1:    return;
LAB5:    t10 = *((unsigned int *)t3);
    t11 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t10 | t11);
    t12 = *((unsigned int *)t6);
    t13 = *((unsigned int *)t7);
    *((unsigned int *)t6) = (t12 | t13);
    goto LAB4;

}

static void Always_121_8(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 19016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 18824);
    xsi_process_wait(t2, 15000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(121, ng0);
    t4 = (t0 + 12440);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 12440);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Always_122_9(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 19264U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 19072);
    xsi_process_wait(t2, 4000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(122, ng0);
    t4 = (t0 + 12600);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 12600);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Always_216_10(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;

LAB0:    t1 = (t0 + 19512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(216, ng0);

LAB4:    xsi_set_current_line(217, ng0);
    t2 = (t0 + 19320);
    xsi_process_wait(t2, 500000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(218, ng0);
    t3 = (t0 + 20208);
    *((int *)t3) = 1;
    t4 = (t0 + 19544);
    *((char **)t4) = t3;
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(219, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 13400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(220, ng0);
    t2 = (t0 + 20224);
    *((int *)t2) = 1;
    t3 = (t0 + 19544);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(221, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 13400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(222, ng0);
    t2 = (t0 + 19320);
    xsi_process_wait(t2, 500000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(223, ng0);
    t2 = (t0 + 20240);
    *((int *)t2) = 1;
    t3 = (t0 + 19544);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(224, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 13400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(225, ng0);
    t2 = (t0 + 20256);
    *((int *)t2) = 1;
    t3 = (t0 + 19544);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(226, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 13400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    goto LAB2;

}

static void Initial_231_11(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    t1 = (t0 + 19760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(231, ng0);

LAB4:    xsi_set_current_line(233, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 11320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(234, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 11480);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(235, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 11640);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(236, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 11800);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);
    xsi_set_current_line(237, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 11960);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(238, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 12120);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(239, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12280);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 6);
    xsi_set_current_line(240, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12440);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(241, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12600);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(242, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12760);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(243, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 12920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(244, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 13080);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(245, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 13240);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(246, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 13400);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(247, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 13560);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(248, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 13720);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(249, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 13880);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(250, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 14040);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(251, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 14200);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 12);
    xsi_set_current_line(252, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 14360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(253, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 14520);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(254, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 14680);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 12);
    xsi_set_current_line(255, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 14840);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(256, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 15000);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(257, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 15160);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 12);
    xsi_set_current_line(258, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 15320);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(259, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 15480);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(260, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 15640);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 12);
    xsi_set_current_line(263, ng0);
    t2 = (t0 + 19568);
    xsi_process_wait(t2, 2000500000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(264, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB8:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB10:    if (t15 != 0)
        goto LAB11;

LAB6:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB7:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(265, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB14:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB16:    if (t15 != 0)
        goto LAB17;

LAB12:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB13:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(266, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB20:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB22:    if (t15 != 0)
        goto LAB23;

LAB18:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB19:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(267, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB26:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB28:    if (t15 != 0)
        goto LAB29;

LAB24:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB25:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(268, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB32:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB34:    if (t15 != 0)
        goto LAB35;

LAB30:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB31:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(269, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB38:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB40:    if (t15 != 0)
        goto LAB41;

LAB36:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB37:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(270, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB44:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB46:    if (t15 != 0)
        goto LAB47;

LAB42:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB43:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    xsi_set_current_line(271, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 19568);
    t4 = (t0 + 848);
    t5 = xsi_create_subprogram_invocation(t3, 0, t0, t4, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t4, t5);
    t6 = (t0 + 15960);
    xsi_vlogvar_assign_value(t6, t2, 0, 0, 6);

LAB50:    t7 = (t0 + 19664);
    t8 = *((char **)t7);
    t9 = (t8 + 80U);
    t10 = *((char **)t9);
    t11 = (t10 + 272U);
    t12 = *((char **)t11);
    t13 = (t12 + 0U);
    t14 = *((char **)t13);
    t15 = ((int  (*)(char *, char *))t14)(t0, t8);

LAB52:    if (t15 != 0)
        goto LAB53;

LAB48:    t8 = (t0 + 848);
    xsi_vlog_subprogram_popinvocation(t8);

LAB49:    t16 = (t0 + 19664);
    t17 = *((char **)t16);
    t16 = (t0 + 16120);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    t20 = (t0 + 15800);
    xsi_vlogvar_assign_value(t20, t19, 0, 0, 32);
    t21 = (t0 + 848);
    t22 = (t0 + 19568);
    t23 = 0;
    xsi_delete_subprogram_invocation(t21, t17, t0, t22, t23);
    goto LAB1;

LAB9:;
LAB11:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB8;
    goto LAB1;

LAB15:;
LAB17:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB14;
    goto LAB1;

LAB21:;
LAB23:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB20;
    goto LAB1;

LAB27:;
LAB29:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB26;
    goto LAB1;

LAB33:;
LAB35:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB32;
    goto LAB1;

LAB39:;
LAB41:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB38;
    goto LAB1;

LAB45:;
LAB47:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB44;
    goto LAB1;

LAB51:;
LAB53:    t7 = (t0 + 19760U);
    *((char **)t7) = &&LAB50;
    goto LAB1;

}


extern void work_m_14339473519789354963_1399156637_init()
{
	static char *pe[] = {(void *)NetDecl_37_0,(void *)NetDecl_39_1,(void *)NetDecl_41_2,(void *)NetDecl_43_3,(void *)NetDecl_48_4,(void *)NetDecl_49_5,(void *)NetDecl_50_6,(void *)NetDecl_51_7,(void *)Always_121_8,(void *)Always_122_9,(void *)Always_216_10,(void *)Initial_231_11};
	static char *se[] = {(void *)sp_hk_read};
	xsi_register_didat("work_m_14339473519789354963_1399156637", "isim/SURF_TOP_TEST_isim_beh.exe.sim/work/m_14339473519789354963_1399156637.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
