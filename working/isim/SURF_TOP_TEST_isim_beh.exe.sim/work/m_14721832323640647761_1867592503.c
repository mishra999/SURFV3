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
static const char *ng0 = "/home/ise/git/firmware-surf/rtl/lab_adc_test.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {2U, 0U};
static unsigned int ng5[] = {3U, 0U};
static int ng6[] = {0, 0};



static void NetDecl_32_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    t1 = (t0 + 5760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(32, ng0);
    t2 = (t0 + 4048);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 12, t5, 32);
    t7 = (t0 + 8472);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t11, 0, 8);
    t12 = 8191U;
    t13 = t12;
    t14 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t12 = (t12 & t15);
    t16 = *((unsigned int *)t14);
    t13 = (t13 & t16);
    t17 = (t11 + 4);
    t18 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t18 | t12);
    t19 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t19 | t13);
    xsi_driver_vfirst_trans(t7, 0, 12U);
    t20 = (t0 + 8312);
    *((int *)t20) = 1;

LAB1:    return;
}

static void Always_49_1(char *t0)
{
    char t18[8];
    char t32[8];
    char t38[8];
    char t46[8];
    char t54[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;

LAB0:    t1 = (t0 + 6008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 8328);
    *((int *)t2) = 1;
    t3 = (t0 + 6040);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(49, ng0);

LAB5:    xsi_set_current_line(50, ng0);
    t4 = (t0 + 4848);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);

LAB6:    t7 = ((char*)((ng2)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t7, 2);
    if (t8 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t2, 2);
    if (t8 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng4)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t2, 2);
    if (t8 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t8 = xsi_vlog_unsigned_case_compare(t6, 2, t2, 2);
    if (t8 == 1)
        goto LAB13;

LAB14:
LAB15:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB28;

LAB25:    if (t23 != 0)
        goto LAB27;

LAB26:    *((unsigned int *)t18) = 1;

LAB28:    t16 = (t18 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB29;

LAB30:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB35;

LAB32:    if (t23 != 0)
        goto LAB34;

LAB33:    *((unsigned int *)t18) = 1;

LAB35:    t16 = (t18 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB36;

LAB37:
LAB38:
LAB31:    xsi_set_current_line(60, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB42;

LAB39:    if (t23 != 0)
        goto LAB41;

LAB40:    *((unsigned int *)t18) = 1;

LAB42:    memset(t32, 0, 8);
    t16 = (t18 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB43;

LAB44:    if (*((unsigned int *)t16) != 0)
        goto LAB45;

LAB46:    t31 = (t32 + 4);
    t33 = *((unsigned int *)t32);
    t34 = *((unsigned int *)t31);
    t35 = (t33 || t34);
    if (t35 > 0)
        goto LAB47;

LAB48:    memcpy(t54, t32, 8);

LAB49:    t85 = (t54 + 4);
    t86 = *((unsigned int *)t85);
    t87 = (~(t86));
    t88 = *((unsigned int *)t54);
    t89 = (t88 & t87);
    t90 = (t89 != 0);
    if (t90 > 0)
        goto LAB57;

LAB58:
LAB59:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB63;

LAB60:    if (t23 != 0)
        goto LAB62;

LAB61:    *((unsigned int *)t18) = 1;

LAB63:    memset(t32, 0, 8);
    t16 = (t18 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB64;

LAB65:    if (*((unsigned int *)t16) != 0)
        goto LAB66;

LAB67:    t31 = (t32 + 4);
    t33 = *((unsigned int *)t32);
    t34 = (!(t33));
    t35 = *((unsigned int *)t31);
    t40 = (t34 || t35);
    if (t40 > 0)
        goto LAB68;

LAB69:    memcpy(t54, t32, 8);

LAB70:    t94 = (t54 + 4);
    t89 = *((unsigned int *)t94);
    t90 = (~(t89));
    t95 = *((unsigned int *)t54);
    t96 = (t95 & t90);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB82;

LAB83:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 12, 0LL);

LAB84:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB88;

LAB85:    if (t23 != 0)
        goto LAB87;

LAB86:    *((unsigned int *)t18) = 1;

LAB88:    t16 = (t18 + 4);
    t26 = *((unsigned int *)t16);
    t27 = (~(t26));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t27);
    t30 = (t29 != 0);
    if (t30 > 0)
        goto LAB89;

LAB90:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t11 = *((unsigned int *)t2);
    t12 = (~(t11));
    t13 = *((unsigned int *)t3);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB92;

LAB93:
LAB94:
LAB91:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB98;

LAB95:    if (t23 != 0)
        goto LAB97;

LAB96:    *((unsigned int *)t18) = 1;

LAB98:    t16 = (t0 + 4208);
    xsi_vlogvar_wait_assign_value(t16, t18, 0, 0, 1, 0LL);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 4848);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t18, 0, 8);
    t7 = (t4 + 4);
    t9 = (t5 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t13 = (t11 ^ t12);
    t14 = *((unsigned int *)t7);
    t15 = *((unsigned int *)t9);
    t19 = (t14 ^ t15);
    t20 = (t13 | t19);
    t21 = *((unsigned int *)t7);
    t22 = *((unsigned int *)t9);
    t23 = (t21 | t22);
    t24 = (~(t23));
    t25 = (t20 & t24);
    if (t25 != 0)
        goto LAB102;

LAB99:    if (t23 != 0)
        goto LAB101;

LAB100:    *((unsigned int *)t18) = 1;

LAB102:    t16 = (t0 + 4528);
    xsi_vlogvar_wait_assign_value(t16, t18, 0, 0, 1, 0LL);
    goto LAB2;

LAB7:    xsi_set_current_line(51, ng0);
    t9 = (t0 + 1888U);
    t10 = *((char **)t9);
    t9 = (t10 + 4);
    t11 = *((unsigned int *)t9);
    t12 = (~(t11));
    t13 = *((unsigned int *)t10);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB16;

LAB17:
LAB18:    goto LAB15;

LAB9:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 2848U);
    t4 = *((char **)t3);
    memset(t18, 0, 8);
    t3 = (t18 + 4);
    t5 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 4);
    t13 = (t12 & 1);
    *((unsigned int *)t18) = t13;
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 4);
    t19 = (t15 & 1);
    *((unsigned int *)t3) = t19;
    t7 = (t18 + 4);
    t20 = *((unsigned int *)t7);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB15;

LAB11:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 2848U);
    t4 = *((char **)t3);
    memset(t18, 0, 8);
    t3 = (t18 + 4);
    t5 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = (t11 >> 12);
    t13 = (t12 & 1);
    *((unsigned int *)t18) = t13;
    t14 = *((unsigned int *)t5);
    t15 = (t14 >> 12);
    t19 = (t15 & 1);
    *((unsigned int *)t3) = t19;
    t7 = (t18 + 4);
    t20 = *((unsigned int *)t7);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB22;

LAB23:
LAB24:    goto LAB15;

LAB13:    xsi_set_current_line(54, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 2, 0LL);
    goto LAB15;

LAB16:    xsi_set_current_line(51, ng0);
    t16 = ((char*)((ng3)));
    t17 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 2, 0LL);
    goto LAB18;

LAB19:    xsi_set_current_line(52, ng0);
    t9 = ((char*)((ng4)));
    t10 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 2, 0LL);
    goto LAB21;

LAB22:    xsi_set_current_line(53, ng0);
    t9 = ((char*)((ng5)));
    t10 = (t0 + 4848);
    xsi_vlogvar_wait_assign_value(t10, t9, 0, 0, 2, 0LL);
    goto LAB24;

LAB27:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB28;

LAB29:    xsi_set_current_line(57, ng0);
    t17 = ((char*)((ng6)));
    t31 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t31, t17, 0, 0, 1, 0LL);
    goto LAB31;

LAB34:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB35;

LAB36:    xsi_set_current_line(58, ng0);
    t17 = ((char*)((ng1)));
    t31 = (t0 + 4688);
    xsi_vlogvar_wait_assign_value(t31, t17, 0, 0, 1, 0LL);
    goto LAB38;

LAB41:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB42;

LAB43:    *((unsigned int *)t32) = 1;
    goto LAB46;

LAB45:    t17 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB46;

LAB47:    t36 = (t0 + 2848U);
    t37 = *((char **)t36);
    memset(t38, 0, 8);
    t36 = (t38 + 4);
    t39 = (t37 + 4);
    t40 = *((unsigned int *)t37);
    t41 = (t40 >> 4);
    t42 = (t41 & 1);
    *((unsigned int *)t38) = t42;
    t43 = *((unsigned int *)t39);
    t44 = (t43 >> 4);
    t45 = (t44 & 1);
    *((unsigned int *)t36) = t45;
    memset(t46, 0, 8);
    t47 = (t38 + 4);
    t48 = *((unsigned int *)t47);
    t49 = (~(t48));
    t50 = *((unsigned int *)t38);
    t51 = (t50 & t49);
    t52 = (t51 & 1U);
    if (t52 != 0)
        goto LAB50;

LAB51:    if (*((unsigned int *)t47) != 0)
        goto LAB52;

LAB53:    t55 = *((unsigned int *)t32);
    t56 = *((unsigned int *)t46);
    t57 = (t55 & t56);
    *((unsigned int *)t54) = t57;
    t58 = (t32 + 4);
    t59 = (t46 + 4);
    t60 = (t54 + 4);
    t61 = *((unsigned int *)t58);
    t62 = *((unsigned int *)t59);
    t63 = (t61 | t62);
    *((unsigned int *)t60) = t63;
    t64 = *((unsigned int *)t60);
    t65 = (t64 != 0);
    if (t65 == 1)
        goto LAB54;

LAB55:
LAB56:    goto LAB49;

LAB50:    *((unsigned int *)t46) = 1;
    goto LAB53;

LAB52:    t53 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t53) = 1;
    goto LAB53;

LAB54:    t66 = *((unsigned int *)t54);
    t67 = *((unsigned int *)t60);
    *((unsigned int *)t54) = (t66 | t67);
    t68 = (t32 + 4);
    t69 = (t46 + 4);
    t70 = *((unsigned int *)t32);
    t71 = (~(t70));
    t72 = *((unsigned int *)t68);
    t73 = (~(t72));
    t74 = *((unsigned int *)t46);
    t75 = (~(t74));
    t76 = *((unsigned int *)t69);
    t77 = (~(t76));
    t8 = (t71 & t73);
    t78 = (t75 & t77);
    t79 = (~(t8));
    t80 = (~(t78));
    t81 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t81 & t79);
    t82 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t82 & t80);
    t83 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t83 & t79);
    t84 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t84 & t80);
    goto LAB56;

LAB57:    xsi_set_current_line(60, ng0);
    t91 = ((char*)((ng2)));
    t92 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t92, t91, 0, 0, 12, 0LL);
    goto LAB59;

LAB62:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB63;

LAB64:    *((unsigned int *)t32) = 1;
    goto LAB67;

LAB66:    t17 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB67;

LAB68:    t36 = (t0 + 4848);
    t37 = (t36 + 56U);
    t39 = *((char **)t37);
    t47 = ((char*)((ng3)));
    memset(t38, 0, 8);
    t53 = (t39 + 4);
    t58 = (t47 + 4);
    t41 = *((unsigned int *)t39);
    t42 = *((unsigned int *)t47);
    t43 = (t41 ^ t42);
    t44 = *((unsigned int *)t53);
    t45 = *((unsigned int *)t58);
    t48 = (t44 ^ t45);
    t49 = (t43 | t48);
    t50 = *((unsigned int *)t53);
    t51 = *((unsigned int *)t58);
    t52 = (t50 | t51);
    t55 = (~(t52));
    t56 = (t49 & t55);
    if (t56 != 0)
        goto LAB74;

LAB71:    if (t52 != 0)
        goto LAB73;

LAB72:    *((unsigned int *)t38) = 1;

LAB74:    memset(t46, 0, 8);
    t60 = (t38 + 4);
    t57 = *((unsigned int *)t60);
    t61 = (~(t57));
    t62 = *((unsigned int *)t38);
    t63 = (t62 & t61);
    t64 = (t63 & 1U);
    if (t64 != 0)
        goto LAB75;

LAB76:    if (*((unsigned int *)t60) != 0)
        goto LAB77;

LAB78:    t65 = *((unsigned int *)t32);
    t66 = *((unsigned int *)t46);
    t67 = (t65 | t66);
    *((unsigned int *)t54) = t67;
    t69 = (t32 + 4);
    t85 = (t46 + 4);
    t91 = (t54 + 4);
    t70 = *((unsigned int *)t69);
    t71 = *((unsigned int *)t85);
    t72 = (t70 | t71);
    *((unsigned int *)t91) = t72;
    t73 = *((unsigned int *)t91);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB79;

LAB80:
LAB81:    goto LAB70;

LAB73:    t59 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t59) = 1;
    goto LAB74;

LAB75:    *((unsigned int *)t46) = 1;
    goto LAB78;

LAB77:    t68 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t68) = 1;
    goto LAB78;

LAB79:    t75 = *((unsigned int *)t54);
    t76 = *((unsigned int *)t91);
    *((unsigned int *)t54) = (t75 | t76);
    t92 = (t32 + 4);
    t93 = (t46 + 4);
    t77 = *((unsigned int *)t92);
    t79 = (~(t77));
    t80 = *((unsigned int *)t32);
    t8 = (t80 & t79);
    t81 = *((unsigned int *)t93);
    t82 = (~(t81));
    t83 = *((unsigned int *)t46);
    t78 = (t83 & t82);
    t84 = (~(t8));
    t86 = (~(t78));
    t87 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t87 & t84);
    t88 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t88 & t86);
    goto LAB81;

LAB82:    xsi_set_current_line(61, ng0);
    t98 = (t0 + 2848U);
    t99 = *((char **)t98);
    t98 = (t0 + 4048);
    xsi_vlogvar_wait_assign_value(t98, t99, 0, 0, 12, 0LL);
    goto LAB84;

LAB87:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB88;

LAB89:    xsi_set_current_line(64, ng0);
    t17 = ((char*)((ng1)));
    t31 = (t0 + 4368);
    xsi_vlogvar_wait_assign_value(t31, t17, 0, 0, 1, 0LL);
    goto LAB91;

LAB92:    xsi_set_current_line(65, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t0 + 4368);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    goto LAB94;

LAB97:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB98;

LAB101:    t10 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB102;

}

static void Cont_71_2(char *t0)
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
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 6256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 4528);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8536);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 8344);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_72_3(char *t0)
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
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 6504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 4368);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8600);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 8360);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_73_4(char *t0)
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
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 6752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 4208);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 8664);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1U;
    t11 = t10;
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t5, 0, 0);
    t18 = (t0 + 8376);
    *((int *)t18) = 1;

LAB1:    return;
}

static void implSig1_execute(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;

LAB0:    t1 = (t0 + 7000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1728U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t4 + 4);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB7;

LAB5:    if (*((unsigned int *)t2) == 0)
        goto LAB4;

LAB6:    t10 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t10) = 1;

LAB7:    t11 = (t3 + 4);
    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    *((unsigned int *)t3) = t14;
    *((unsigned int *)t11) = 0;
    if (*((unsigned int *)t12) != 0)
        goto LAB9;

LAB8:    t19 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t19 & 1U);
    t20 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t20 & 1U);
    t21 = (t0 + 8728);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memset(t25, 0, 8);
    t26 = 1U;
    t27 = t26;
    t28 = (t3 + 4);
    t29 = *((unsigned int *)t3);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = (t25 + 4);
    t32 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t32 | t26);
    t33 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t33 | t27);
    xsi_driver_vfirst_trans(t21, 0, 0);
    t34 = (t0 + 8392);
    *((int *)t34) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t3) = 1;
    goto LAB7;

LAB9:    t15 = *((unsigned int *)t3);
    t16 = *((unsigned int *)t12);
    *((unsigned int *)t3) = (t15 | t16);
    t17 = *((unsigned int *)t11);
    t18 = *((unsigned int *)t12);
    *((unsigned int *)t11) = (t17 | t18);
    goto LAB8;

}

static void implSig2_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 7248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng3)));
    t3 = (t0 + 8792);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig3_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 7496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng2)));
    t3 = (t0 + 8856);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig4_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 7744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng3)));
    t3 = (t0 + 8920);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig5_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 7992U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng2)));
    t3 = (t0 + 8984);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}


extern void work_m_14721832323640647761_1867592503_init()
{
	static char *pe[] = {(void *)NetDecl_32_0,(void *)Always_49_1,(void *)Cont_71_2,(void *)Cont_72_3,(void *)Cont_73_4,(void *)implSig1_execute,(void *)implSig2_execute,(void *)implSig3_execute,(void *)implSig4_execute,(void *)implSig5_execute};
	xsi_register_didat("work_m_14721832323640647761_1867592503", "isim/SURF_TOP_TEST_isim_beh.exe.sim/work/m_14721832323640647761_1867592503.didat");
	xsi_register_executes(pe);
}
