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
static const char *ng0 = "/home/ise/git/firmware-surf/rtl/L0_scaler_single.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {2, 0};
static int ng4[] = {3, 0};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {1U, 0U};



static void Always_38_0(char *t0)
{
    char t7[8];
    char t24[8];
    char t34[8];
    char t47[8];
    char t55[8];
    char t87[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    int t94;

LAB0:    t1 = (t0 + 4552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 6112);
    *((int *)t2) = 1;
    t3 = (t0 + 4584);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(38, ng0);

LAB5:    xsi_set_current_line(40, ng0);
    t4 = (t0 + 3000);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t7, 0, 8);
    t8 = (t7 + 4);
    t9 = (t6 + 4);
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t9);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t8) = t15;
    t16 = (t7 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2120U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t10 = *((unsigned int *)t2);
    t11 = (~(t10));
    t12 = *((unsigned int *)t3);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB11;

LAB12:
LAB13:
LAB8:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 0);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 0);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    t8 = (t0 + 3000);
    t9 = (t0 + 3000);
    t16 = (t9 + 72U);
    t22 = *((char **)t16);
    t23 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t24, t22, 2, t23, 32, 1);
    t25 = (t24 + 4);
    t17 = *((unsigned int *)t25);
    t31 = (!(t17));
    if (t31 == 1)
        goto LAB21;

LAB22:
LAB18:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 != 0);
    if (t21 > 0)
        goto LAB23;

LAB24:
LAB25:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    memset(t24, 0, 8);
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t8) != 0)
        goto LAB28;

LAB29:    t16 = (t24 + 4);
    t30 = *((unsigned int *)t24);
    t32 = *((unsigned int *)t16);
    t33 = (t30 || t32);
    if (t33 > 0)
        goto LAB30;

LAB31:    memcpy(t55, t24, 8);

LAB32:    t86 = (t0 + 3320);
    t88 = (t0 + 3320);
    t89 = (t88 + 72U);
    t90 = *((char **)t89);
    t91 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t87, t90, 2, t91, 32, 1);
    t92 = (t87 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (!(t93));
    if (t94 == 1)
        goto LAB44;

LAB45:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    memset(t24, 0, 8);
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t8) != 0)
        goto LAB48;

LAB49:    t16 = (t24 + 4);
    t30 = *((unsigned int *)t24);
    t32 = *((unsigned int *)t16);
    t33 = (t30 || t32);
    if (t33 > 0)
        goto LAB50;

LAB51:    memcpy(t55, t24, 8);

LAB52:    t86 = (t0 + 3320);
    t88 = (t0 + 3320);
    t89 = (t88 + 72U);
    t90 = *((char **)t89);
    t91 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t87, t90, 2, t91, 32, 1);
    t92 = (t87 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (!(t93));
    if (t94 == 1)
        goto LAB64;

LAB65:    xsi_set_current_line(56, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    memset(t24, 0, 8);
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB66;

LAB67:    if (*((unsigned int *)t8) != 0)
        goto LAB68;

LAB69:    t16 = (t24 + 4);
    t30 = *((unsigned int *)t24);
    t32 = *((unsigned int *)t16);
    t33 = (t30 || t32);
    if (t33 > 0)
        goto LAB70;

LAB71:    memcpy(t55, t24, 8);

LAB72:    t86 = (t0 + 3320);
    t88 = (t0 + 3320);
    t89 = (t88 + 72U);
    t90 = *((char **)t89);
    t91 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t87, t90, 2, t91, 32, 1);
    t92 = (t87 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (!(t93));
    if (t94 == 1)
        goto LAB84;

LAB85:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3000);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t5 = (t7 + 4);
    t6 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 1);
    t12 = (t11 & 1);
    *((unsigned int *)t7) = t12;
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t5) = t15;
    memset(t24, 0, 8);
    t8 = (t7 + 4);
    t17 = *((unsigned int *)t8);
    t18 = (~(t17));
    t19 = *((unsigned int *)t7);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB86;

LAB87:    if (*((unsigned int *)t8) != 0)
        goto LAB88;

LAB89:    t16 = (t24 + 4);
    t30 = *((unsigned int *)t24);
    t32 = *((unsigned int *)t16);
    t33 = (t30 || t32);
    if (t33 > 0)
        goto LAB90;

LAB91:    memcpy(t55, t24, 8);

LAB92:    t86 = (t0 + 3320);
    t88 = (t0 + 3320);
    t89 = (t88 + 72U);
    t90 = *((char **)t89);
    t91 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t87, t90, 2, t91, 32, 1);
    t92 = (t87 + 4);
    t93 = *((unsigned int *)t92);
    t94 = (!(t93));
    if (t94 == 1)
        goto LAB104;

LAB105:    goto LAB2;

LAB6:    xsi_set_current_line(41, ng0);
    t22 = ((char*)((ng1)));
    t23 = (t0 + 3000);
    t25 = (t0 + 3000);
    t26 = (t25 + 72U);
    t27 = *((char **)t26);
    t28 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t24, t27, 2, t28, 32, 1);
    t29 = (t24 + 4);
    t30 = *((unsigned int *)t29);
    t31 = (!(t30));
    if (t31 == 1)
        goto LAB9;

LAB10:    goto LAB8;

LAB9:    xsi_vlogvar_wait_assign_value(t23, t22, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB10;

LAB11:    xsi_set_current_line(43, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t0 + 3000);
    t6 = (t0 + 3000);
    t8 = (t6 + 72U);
    t9 = *((char **)t8);
    t16 = ((char*)((ng1)));
    xsi_vlog_generic_convert_bit_index(t7, t9, 2, t16, 32, 1);
    t22 = (t7 + 4);
    t15 = *((unsigned int *)t22);
    t31 = (!(t15));
    if (t31 == 1)
        goto LAB14;

LAB15:    goto LAB13;

LAB14:    xsi_vlogvar_wait_assign_value(t5, t4, 0, *((unsigned int *)t7), 1, 0LL);
    goto LAB15;

LAB16:    xsi_set_current_line(47, ng0);
    t9 = ((char*)((ng1)));
    t16 = (t0 + 3000);
    t22 = (t0 + 3000);
    t23 = (t22 + 72U);
    t25 = *((char **)t23);
    t26 = ((char*)((ng2)));
    xsi_vlog_generic_convert_bit_index(t24, t25, 2, t26, 32, 1);
    t27 = (t24 + 4);
    t30 = *((unsigned int *)t27);
    t31 = (!(t30));
    if (t31 == 1)
        goto LAB19;

LAB20:    goto LAB18;

LAB19:    xsi_vlogvar_wait_assign_value(t16, t9, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB20;

LAB21:    xsi_vlogvar_wait_assign_value(t8, t7, 0, *((unsigned int *)t24), 1, 0LL);
    goto LAB22;

LAB23:    xsi_set_current_line(52, ng0);
    t9 = (t0 + 3160);
    t16 = (t9 + 56U);
    t22 = *((char **)t16);
    t23 = ((char*)((ng2)));
    memset(t24, 0, 8);
    xsi_vlog_unsigned_add(t24, 32, t22, 2, t23, 32);
    t25 = (t0 + 3160);
    xsi_vlogvar_wait_assign_value(t25, t24, 0, 0, 2, 0LL);
    goto LAB25;

LAB26:    *((unsigned int *)t24) = 1;
    goto LAB29;

LAB28:    t9 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB29;

LAB30:    t22 = (t0 + 3160);
    t23 = (t22 + 56U);
    t25 = *((char **)t23);
    t26 = ((char*)((ng1)));
    memset(t34, 0, 8);
    t27 = (t25 + 4);
    t28 = (t26 + 4);
    t35 = *((unsigned int *)t25);
    t36 = *((unsigned int *)t26);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t27);
    t39 = *((unsigned int *)t28);
    t40 = (t38 ^ t39);
    t41 = (t37 | t40);
    t42 = *((unsigned int *)t27);
    t43 = *((unsigned int *)t28);
    t44 = (t42 | t43);
    t45 = (~(t44));
    t46 = (t41 & t45);
    if (t46 != 0)
        goto LAB36;

LAB33:    if (t44 != 0)
        goto LAB35;

LAB34:    *((unsigned int *)t34) = 1;

LAB36:    memset(t47, 0, 8);
    t48 = (t34 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t34);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB37;

LAB38:    if (*((unsigned int *)t48) != 0)
        goto LAB39;

LAB40:    t56 = *((unsigned int *)t24);
    t57 = *((unsigned int *)t47);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t59 = (t24 + 4);
    t60 = (t47 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB41;

LAB42:
LAB43:    goto LAB32;

LAB35:    t29 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB36;

LAB37:    *((unsigned int *)t47) = 1;
    goto LAB40;

LAB39:    t54 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB40;

LAB41:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t24 + 4);
    t70 = (t47 + 4);
    t71 = *((unsigned int *)t24);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (~(t73));
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (~(t77));
    t31 = (t72 & t74);
    t79 = (t76 & t78);
    t80 = (~(t31));
    t81 = (~(t79));
    t82 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t82 & t80);
    t83 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t83 & t81);
    t84 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t84 & t80);
    t85 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t85 & t81);
    goto LAB43;

LAB44:    xsi_vlogvar_wait_assign_value(t86, t55, 0, *((unsigned int *)t87), 1, 0LL);
    goto LAB45;

LAB46:    *((unsigned int *)t24) = 1;
    goto LAB49;

LAB48:    t9 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB49;

LAB50:    t22 = (t0 + 3160);
    t23 = (t22 + 56U);
    t25 = *((char **)t23);
    t26 = ((char*)((ng2)));
    memset(t34, 0, 8);
    t27 = (t25 + 4);
    t28 = (t26 + 4);
    t35 = *((unsigned int *)t25);
    t36 = *((unsigned int *)t26);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t27);
    t39 = *((unsigned int *)t28);
    t40 = (t38 ^ t39);
    t41 = (t37 | t40);
    t42 = *((unsigned int *)t27);
    t43 = *((unsigned int *)t28);
    t44 = (t42 | t43);
    t45 = (~(t44));
    t46 = (t41 & t45);
    if (t46 != 0)
        goto LAB56;

LAB53:    if (t44 != 0)
        goto LAB55;

LAB54:    *((unsigned int *)t34) = 1;

LAB56:    memset(t47, 0, 8);
    t48 = (t34 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t34);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB57;

LAB58:    if (*((unsigned int *)t48) != 0)
        goto LAB59;

LAB60:    t56 = *((unsigned int *)t24);
    t57 = *((unsigned int *)t47);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t59 = (t24 + 4);
    t60 = (t47 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB61;

LAB62:
LAB63:    goto LAB52;

LAB55:    t29 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB56;

LAB57:    *((unsigned int *)t47) = 1;
    goto LAB60;

LAB59:    t54 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB60;

LAB61:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t24 + 4);
    t70 = (t47 + 4);
    t71 = *((unsigned int *)t24);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (~(t73));
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (~(t77));
    t31 = (t72 & t74);
    t79 = (t76 & t78);
    t80 = (~(t31));
    t81 = (~(t79));
    t82 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t82 & t80);
    t83 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t83 & t81);
    t84 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t84 & t80);
    t85 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t85 & t81);
    goto LAB63;

LAB64:    xsi_vlogvar_wait_assign_value(t86, t55, 0, *((unsigned int *)t87), 1, 0LL);
    goto LAB65;

LAB66:    *((unsigned int *)t24) = 1;
    goto LAB69;

LAB68:    t9 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB69;

LAB70:    t22 = (t0 + 3160);
    t23 = (t22 + 56U);
    t25 = *((char **)t23);
    t26 = ((char*)((ng3)));
    memset(t34, 0, 8);
    t27 = (t25 + 4);
    t28 = (t26 + 4);
    t35 = *((unsigned int *)t25);
    t36 = *((unsigned int *)t26);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t27);
    t39 = *((unsigned int *)t28);
    t40 = (t38 ^ t39);
    t41 = (t37 | t40);
    t42 = *((unsigned int *)t27);
    t43 = *((unsigned int *)t28);
    t44 = (t42 | t43);
    t45 = (~(t44));
    t46 = (t41 & t45);
    if (t46 != 0)
        goto LAB76;

LAB73:    if (t44 != 0)
        goto LAB75;

LAB74:    *((unsigned int *)t34) = 1;

LAB76:    memset(t47, 0, 8);
    t48 = (t34 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t34);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t48) != 0)
        goto LAB79;

LAB80:    t56 = *((unsigned int *)t24);
    t57 = *((unsigned int *)t47);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t59 = (t24 + 4);
    t60 = (t47 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB81;

LAB82:
LAB83:    goto LAB72;

LAB75:    t29 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB76;

LAB77:    *((unsigned int *)t47) = 1;
    goto LAB80;

LAB79:    t54 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB80;

LAB81:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t24 + 4);
    t70 = (t47 + 4);
    t71 = *((unsigned int *)t24);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (~(t73));
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (~(t77));
    t31 = (t72 & t74);
    t79 = (t76 & t78);
    t80 = (~(t31));
    t81 = (~(t79));
    t82 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t82 & t80);
    t83 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t83 & t81);
    t84 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t84 & t80);
    t85 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t85 & t81);
    goto LAB83;

LAB84:    xsi_vlogvar_wait_assign_value(t86, t55, 0, *((unsigned int *)t87), 1, 0LL);
    goto LAB85;

LAB86:    *((unsigned int *)t24) = 1;
    goto LAB89;

LAB88:    t9 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB89;

LAB90:    t22 = (t0 + 3160);
    t23 = (t22 + 56U);
    t25 = *((char **)t23);
    t26 = ((char*)((ng4)));
    memset(t34, 0, 8);
    t27 = (t25 + 4);
    t28 = (t26 + 4);
    t35 = *((unsigned int *)t25);
    t36 = *((unsigned int *)t26);
    t37 = (t35 ^ t36);
    t38 = *((unsigned int *)t27);
    t39 = *((unsigned int *)t28);
    t40 = (t38 ^ t39);
    t41 = (t37 | t40);
    t42 = *((unsigned int *)t27);
    t43 = *((unsigned int *)t28);
    t44 = (t42 | t43);
    t45 = (~(t44));
    t46 = (t41 & t45);
    if (t46 != 0)
        goto LAB96;

LAB93:    if (t44 != 0)
        goto LAB95;

LAB94:    *((unsigned int *)t34) = 1;

LAB96:    memset(t47, 0, 8);
    t48 = (t34 + 4);
    t49 = *((unsigned int *)t48);
    t50 = (~(t49));
    t51 = *((unsigned int *)t34);
    t52 = (t51 & t50);
    t53 = (t52 & 1U);
    if (t53 != 0)
        goto LAB97;

LAB98:    if (*((unsigned int *)t48) != 0)
        goto LAB99;

LAB100:    t56 = *((unsigned int *)t24);
    t57 = *((unsigned int *)t47);
    t58 = (t56 & t57);
    *((unsigned int *)t55) = t58;
    t59 = (t24 + 4);
    t60 = (t47 + 4);
    t61 = (t55 + 4);
    t62 = *((unsigned int *)t59);
    t63 = *((unsigned int *)t60);
    t64 = (t62 | t63);
    *((unsigned int *)t61) = t64;
    t65 = *((unsigned int *)t61);
    t66 = (t65 != 0);
    if (t66 == 1)
        goto LAB101;

LAB102:
LAB103:    goto LAB92;

LAB95:    t29 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB96;

LAB97:    *((unsigned int *)t47) = 1;
    goto LAB100;

LAB99:    t54 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB100;

LAB101:    t67 = *((unsigned int *)t55);
    t68 = *((unsigned int *)t61);
    *((unsigned int *)t55) = (t67 | t68);
    t69 = (t24 + 4);
    t70 = (t47 + 4);
    t71 = *((unsigned int *)t24);
    t72 = (~(t71));
    t73 = *((unsigned int *)t69);
    t74 = (~(t73));
    t75 = *((unsigned int *)t47);
    t76 = (~(t75));
    t77 = *((unsigned int *)t70);
    t78 = (~(t77));
    t31 = (t72 & t74);
    t79 = (t76 & t78);
    t80 = (~(t31));
    t81 = (~(t79));
    t82 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t82 & t80);
    t83 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t83 & t81);
    t84 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t84 & t80);
    t85 = *((unsigned int *)t55);
    *((unsigned int *)t55) = (t85 & t81);
    goto LAB103;

LAB104:    xsi_vlogvar_wait_assign_value(t86, t55, 0, *((unsigned int *)t87), 1, 0LL);
    goto LAB105;

}

static void Always_78_1(char *t0)
{
    char t6[8];
    char t31[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
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
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;

LAB0:    t1 = (t0 + 4800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 6128);
    *((int *)t2) = 1;
    t3 = (t0 + 4832);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(78, ng0);

LAB5:    xsi_set_current_line(79, ng0);
    t4 = (t0 + 1640U);
    t5 = *((char **)t4);
    t4 = (t0 + 3640);
    xsi_vlogvar_wait_assign_value(t4, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t5) == 0)
        goto LAB6;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;

LAB9:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB11;

LAB10:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t6 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3480);
    t12 = (t5 + 56U);
    t13 = *((char **)t12);
    memset(t31, 0, 8);
    t14 = (t31 + 4);
    t23 = (t13 + 4);
    t7 = *((unsigned int *)t13);
    t8 = (t7 >> 0);
    *((unsigned int *)t31) = t8;
    t9 = *((unsigned int *)t23);
    t10 = (t9 >> 0);
    *((unsigned int *)t14) = t10;
    t11 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t11 & 127U);
    t15 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t15 & 127U);
    xsi_vlogtype_concat(t6, 8, 8, 2U, t31, 7, t4, 1);
    t29 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t29, t6, 0, 0, 8, 0LL);

LAB14:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB11:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB10;

LAB12:    xsi_set_current_line(81, ng0);
    t29 = ((char*)((ng5)));
    t30 = (t0 + 3480);
    xsi_vlogvar_wait_assign_value(t30, t29, 0, 0, 8, 0LL);
    goto LAB14;

}

static void Cont_86_2(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 5048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t5 + 4);
    t7 = (t4 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (t8 >> 7);
    t10 = (t9 & 1);
    *((unsigned int *)t5) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 7);
    t13 = (t12 & 1);
    *((unsigned int *)t6) = t13;
    t14 = (t0 + 6240);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memset(t18, 0, 8);
    t19 = 1U;
    t20 = t19;
    t21 = (t5 + 4);
    t22 = *((unsigned int *)t5);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = (t18 + 4);
    t25 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t25 | t19);
    t26 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t26 | t20);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t27 = (t0 + 6144);
    *((int *)t27) = 1;

LAB1:    return;
}

static void Cont_89_3(char *t0)
{
    char t4[8];
    char t12[8];
    char t27[8];
    char t35[8];
    char t43[8];
    char t71[8];
    char t86[8];
    char t94[8];
    char t102[8];
    char t130[8];
    char t145[8];
    char t153[8];
    char t161[8];
    char t189[8];
    char t205[8];
    char t214[8];
    char t222[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    char *t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    char *t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    char *t106;
    char *t107;
    char *t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    char *t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    char *t137;
    char *t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    char *t143;
    char *t144;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    char *t160;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    char *t165;
    char *t166;
    char *t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    char *t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    int t180;
    unsigned int t181;
    unsigned int t182;
    unsigned int t183;
    int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    char *t196;
    char *t197;
    unsigned int t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    char *t202;
    char *t203;
    char *t204;
    char *t206;
    char *t207;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    unsigned int t211;
    unsigned int t212;
    unsigned int t213;
    char *t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    char *t221;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    char *t226;
    char *t227;
    char *t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    char *t236;
    char *t237;
    unsigned int t238;
    unsigned int t239;
    unsigned int t240;
    int t241;
    unsigned int t242;
    unsigned int t243;
    unsigned int t244;
    int t245;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    unsigned int t249;
    char *t250;
    char *t251;
    char *t252;
    char *t253;
    char *t254;
    unsigned int t255;
    unsigned int t256;
    char *t257;
    unsigned int t258;
    unsigned int t259;
    char *t260;
    unsigned int t261;
    unsigned int t262;
    char *t263;

LAB0:    t1 = (t0 + 5296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2280U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4);
    t5 = (t3 + 4);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    memset(t12, 0, 8);
    t13 = (t4 + 4);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t4);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t13) != 0)
        goto LAB6;

LAB7:    t20 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t22 = (!(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB8;

LAB9:    memcpy(t43, t12, 8);

LAB10:    memset(t71, 0, 8);
    t72 = (t43 + 4);
    t73 = *((unsigned int *)t72);
    t74 = (~(t73));
    t75 = *((unsigned int *)t43);
    t76 = (t75 & t74);
    t77 = (t76 & 1U);
    if (t77 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t72) != 0)
        goto LAB20;

LAB21:    t79 = (t71 + 4);
    t80 = *((unsigned int *)t71);
    t81 = (!(t80));
    t82 = *((unsigned int *)t79);
    t83 = (t81 || t82);
    if (t83 > 0)
        goto LAB22;

LAB23:    memcpy(t102, t71, 8);

LAB24:    memset(t130, 0, 8);
    t131 = (t102 + 4);
    t132 = *((unsigned int *)t131);
    t133 = (~(t132));
    t134 = *((unsigned int *)t102);
    t135 = (t134 & t133);
    t136 = (t135 & 1U);
    if (t136 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t131) != 0)
        goto LAB34;

LAB35:    t138 = (t130 + 4);
    t139 = *((unsigned int *)t130);
    t140 = (!(t139));
    t141 = *((unsigned int *)t138);
    t142 = (t140 || t141);
    if (t142 > 0)
        goto LAB36;

LAB37:    memcpy(t161, t130, 8);

LAB38:    memset(t189, 0, 8);
    t190 = (t161 + 4);
    t191 = *((unsigned int *)t190);
    t192 = (~(t191));
    t193 = *((unsigned int *)t161);
    t194 = (t193 & t192);
    t195 = (t194 & 1U);
    if (t195 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t190) != 0)
        goto LAB48;

LAB49:    t197 = (t189 + 4);
    t198 = *((unsigned int *)t189);
    t199 = (!(t198));
    t200 = *((unsigned int *)t197);
    t201 = (t199 || t200);
    if (t201 > 0)
        goto LAB50;

LAB51:    memcpy(t222, t189, 8);

LAB52:    t250 = (t0 + 6304);
    t251 = (t250 + 56U);
    t252 = *((char **)t251);
    t253 = (t252 + 56U);
    t254 = *((char **)t253);
    memset(t254, 0, 8);
    t255 = 1U;
    t256 = t255;
    t257 = (t222 + 4);
    t258 = *((unsigned int *)t222);
    t255 = (t255 & t258);
    t259 = *((unsigned int *)t257);
    t256 = (t256 & t259);
    t260 = (t254 + 4);
    t261 = *((unsigned int *)t254);
    *((unsigned int *)t254) = (t261 | t255);
    t262 = *((unsigned int *)t260);
    *((unsigned int *)t260) = (t262 | t256);
    xsi_driver_vfirst_trans(t250, 0, 0);
    t263 = (t0 + 6160);
    *((int *)t263) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB6:    t19 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB7;

LAB8:    t25 = (t0 + 2280U);
    t26 = *((char **)t25);
    memset(t27, 0, 8);
    t25 = (t27 + 4);
    t28 = (t26 + 4);
    t29 = *((unsigned int *)t26);
    t30 = (t29 >> 1);
    t31 = (t30 & 1);
    *((unsigned int *)t27) = t31;
    t32 = *((unsigned int *)t28);
    t33 = (t32 >> 1);
    t34 = (t33 & 1);
    *((unsigned int *)t25) = t34;
    memset(t35, 0, 8);
    t36 = (t27 + 4);
    t37 = *((unsigned int *)t36);
    t38 = (~(t37));
    t39 = *((unsigned int *)t27);
    t40 = (t39 & t38);
    t41 = (t40 & 1U);
    if (t41 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t36) != 0)
        goto LAB13;

LAB14:    t44 = *((unsigned int *)t12);
    t45 = *((unsigned int *)t35);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = (t12 + 4);
    t48 = (t35 + 4);
    t49 = (t43 + 4);
    t50 = *((unsigned int *)t47);
    t51 = *((unsigned int *)t48);
    t52 = (t50 | t51);
    *((unsigned int *)t49) = t52;
    t53 = *((unsigned int *)t49);
    t54 = (t53 != 0);
    if (t54 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t35) = 1;
    goto LAB14;

LAB13:    t42 = (t35 + 4);
    *((unsigned int *)t35) = 1;
    *((unsigned int *)t42) = 1;
    goto LAB14;

LAB15:    t55 = *((unsigned int *)t43);
    t56 = *((unsigned int *)t49);
    *((unsigned int *)t43) = (t55 | t56);
    t57 = (t12 + 4);
    t58 = (t35 + 4);
    t59 = *((unsigned int *)t57);
    t60 = (~(t59));
    t61 = *((unsigned int *)t12);
    t62 = (t61 & t60);
    t63 = *((unsigned int *)t58);
    t64 = (~(t63));
    t65 = *((unsigned int *)t35);
    t66 = (t65 & t64);
    t67 = (~(t62));
    t68 = (~(t66));
    t69 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t69 & t67);
    t70 = *((unsigned int *)t49);
    *((unsigned int *)t49) = (t70 & t68);
    goto LAB17;

LAB18:    *((unsigned int *)t71) = 1;
    goto LAB21;

LAB20:    t78 = (t71 + 4);
    *((unsigned int *)t71) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB21;

LAB22:    t84 = (t0 + 2280U);
    t85 = *((char **)t84);
    memset(t86, 0, 8);
    t84 = (t86 + 4);
    t87 = (t85 + 4);
    t88 = *((unsigned int *)t85);
    t89 = (t88 >> 2);
    t90 = (t89 & 1);
    *((unsigned int *)t86) = t90;
    t91 = *((unsigned int *)t87);
    t92 = (t91 >> 2);
    t93 = (t92 & 1);
    *((unsigned int *)t84) = t93;
    memset(t94, 0, 8);
    t95 = (t86 + 4);
    t96 = *((unsigned int *)t95);
    t97 = (~(t96));
    t98 = *((unsigned int *)t86);
    t99 = (t98 & t97);
    t100 = (t99 & 1U);
    if (t100 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t95) != 0)
        goto LAB27;

LAB28:    t103 = *((unsigned int *)t71);
    t104 = *((unsigned int *)t94);
    t105 = (t103 | t104);
    *((unsigned int *)t102) = t105;
    t106 = (t71 + 4);
    t107 = (t94 + 4);
    t108 = (t102 + 4);
    t109 = *((unsigned int *)t106);
    t110 = *((unsigned int *)t107);
    t111 = (t109 | t110);
    *((unsigned int *)t108) = t111;
    t112 = *((unsigned int *)t108);
    t113 = (t112 != 0);
    if (t113 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t94) = 1;
    goto LAB28;

LAB27:    t101 = (t94 + 4);
    *((unsigned int *)t94) = 1;
    *((unsigned int *)t101) = 1;
    goto LAB28;

LAB29:    t114 = *((unsigned int *)t102);
    t115 = *((unsigned int *)t108);
    *((unsigned int *)t102) = (t114 | t115);
    t116 = (t71 + 4);
    t117 = (t94 + 4);
    t118 = *((unsigned int *)t116);
    t119 = (~(t118));
    t120 = *((unsigned int *)t71);
    t121 = (t120 & t119);
    t122 = *((unsigned int *)t117);
    t123 = (~(t122));
    t124 = *((unsigned int *)t94);
    t125 = (t124 & t123);
    t126 = (~(t121));
    t127 = (~(t125));
    t128 = *((unsigned int *)t108);
    *((unsigned int *)t108) = (t128 & t126);
    t129 = *((unsigned int *)t108);
    *((unsigned int *)t108) = (t129 & t127);
    goto LAB31;

LAB32:    *((unsigned int *)t130) = 1;
    goto LAB35;

LAB34:    t137 = (t130 + 4);
    *((unsigned int *)t130) = 1;
    *((unsigned int *)t137) = 1;
    goto LAB35;

LAB36:    t143 = (t0 + 2280U);
    t144 = *((char **)t143);
    memset(t145, 0, 8);
    t143 = (t145 + 4);
    t146 = (t144 + 4);
    t147 = *((unsigned int *)t144);
    t148 = (t147 >> 3);
    t149 = (t148 & 1);
    *((unsigned int *)t145) = t149;
    t150 = *((unsigned int *)t146);
    t151 = (t150 >> 3);
    t152 = (t151 & 1);
    *((unsigned int *)t143) = t152;
    memset(t153, 0, 8);
    t154 = (t145 + 4);
    t155 = *((unsigned int *)t154);
    t156 = (~(t155));
    t157 = *((unsigned int *)t145);
    t158 = (t157 & t156);
    t159 = (t158 & 1U);
    if (t159 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t154) != 0)
        goto LAB41;

LAB42:    t162 = *((unsigned int *)t130);
    t163 = *((unsigned int *)t153);
    t164 = (t162 | t163);
    *((unsigned int *)t161) = t164;
    t165 = (t130 + 4);
    t166 = (t153 + 4);
    t167 = (t161 + 4);
    t168 = *((unsigned int *)t165);
    t169 = *((unsigned int *)t166);
    t170 = (t168 | t169);
    *((unsigned int *)t167) = t170;
    t171 = *((unsigned int *)t167);
    t172 = (t171 != 0);
    if (t172 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB38;

LAB39:    *((unsigned int *)t153) = 1;
    goto LAB42;

LAB41:    t160 = (t153 + 4);
    *((unsigned int *)t153) = 1;
    *((unsigned int *)t160) = 1;
    goto LAB42;

LAB43:    t173 = *((unsigned int *)t161);
    t174 = *((unsigned int *)t167);
    *((unsigned int *)t161) = (t173 | t174);
    t175 = (t130 + 4);
    t176 = (t153 + 4);
    t177 = *((unsigned int *)t175);
    t178 = (~(t177));
    t179 = *((unsigned int *)t130);
    t180 = (t179 & t178);
    t181 = *((unsigned int *)t176);
    t182 = (~(t181));
    t183 = *((unsigned int *)t153);
    t184 = (t183 & t182);
    t185 = (~(t180));
    t186 = (~(t184));
    t187 = *((unsigned int *)t167);
    *((unsigned int *)t167) = (t187 & t185);
    t188 = *((unsigned int *)t167);
    *((unsigned int *)t167) = (t188 & t186);
    goto LAB45;

LAB46:    *((unsigned int *)t189) = 1;
    goto LAB49;

LAB48:    t196 = (t189 + 4);
    *((unsigned int *)t189) = 1;
    *((unsigned int *)t196) = 1;
    goto LAB49;

LAB50:    t202 = (t0 + 3480);
    t203 = (t202 + 56U);
    t204 = *((char **)t203);
    memset(t205, 0, 8);
    t206 = (t205 + 4);
    t207 = (t204 + 4);
    t208 = *((unsigned int *)t204);
    t209 = (t208 >> 7);
    t210 = (t209 & 1);
    *((unsigned int *)t205) = t210;
    t211 = *((unsigned int *)t207);
    t212 = (t211 >> 7);
    t213 = (t212 & 1);
    *((unsigned int *)t206) = t213;
    memset(t214, 0, 8);
    t215 = (t205 + 4);
    t216 = *((unsigned int *)t215);
    t217 = (~(t216));
    t218 = *((unsigned int *)t205);
    t219 = (t218 & t217);
    t220 = (t219 & 1U);
    if (t220 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t215) != 0)
        goto LAB55;

LAB56:    t223 = *((unsigned int *)t189);
    t224 = *((unsigned int *)t214);
    t225 = (t223 | t224);
    *((unsigned int *)t222) = t225;
    t226 = (t189 + 4);
    t227 = (t214 + 4);
    t228 = (t222 + 4);
    t229 = *((unsigned int *)t226);
    t230 = *((unsigned int *)t227);
    t231 = (t229 | t230);
    *((unsigned int *)t228) = t231;
    t232 = *((unsigned int *)t228);
    t233 = (t232 != 0);
    if (t233 == 1)
        goto LAB57;

LAB58:
LAB59:    goto LAB52;

LAB53:    *((unsigned int *)t214) = 1;
    goto LAB56;

LAB55:    t221 = (t214 + 4);
    *((unsigned int *)t214) = 1;
    *((unsigned int *)t221) = 1;
    goto LAB56;

LAB57:    t234 = *((unsigned int *)t222);
    t235 = *((unsigned int *)t228);
    *((unsigned int *)t222) = (t234 | t235);
    t236 = (t189 + 4);
    t237 = (t214 + 4);
    t238 = *((unsigned int *)t236);
    t239 = (~(t238));
    t240 = *((unsigned int *)t189);
    t241 = (t240 & t239);
    t242 = *((unsigned int *)t237);
    t243 = (~(t242));
    t244 = *((unsigned int *)t214);
    t245 = (t244 & t243);
    t246 = (~(t241));
    t247 = (~(t245));
    t248 = *((unsigned int *)t228);
    *((unsigned int *)t228) = (t248 & t246);
    t249 = *((unsigned int *)t228);
    *((unsigned int *)t228) = (t249 & t247);
    goto LAB59;

}

static void implSig1_execute(char *t0)
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

LAB0:    t1 = (t0 + 5544U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng6)));
    t3 = (t0 + 6368);
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

LAB0:    t1 = (t0 + 5792U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng6)));
    t3 = (t0 + 6432);
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


extern void work_m_09658959687003746573_2252966720_init()
{
	static char *pe[] = {(void *)Always_38_0,(void *)Always_78_1,(void *)Cont_86_2,(void *)Cont_89_3,(void *)implSig1_execute,(void *)implSig2_execute};
	xsi_register_didat("work_m_09658959687003746573_2252966720", "isim/SURF_TOP_TEST_isim_beh.exe.sim/work/m_09658959687003746573_2252966720.didat");
	xsi_register_executes(pe);
}
