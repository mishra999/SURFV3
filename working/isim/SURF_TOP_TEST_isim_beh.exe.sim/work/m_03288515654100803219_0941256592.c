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
static const char *ng0 = "/home/ise/git/firmware-surf/rtl/dac_address_remap.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {8, 0};
static unsigned int ng3[] = {1U, 0U};
static int ng4[] = {12, 0};
static unsigned int ng5[] = {2U, 0U};
static int ng6[] = {14, 0};
static unsigned int ng7[] = {3U, 0U};
static int ng8[] = {16, 0};
static unsigned int ng9[] = {4U, 0U};
static int ng10[] = {20, 0};
static unsigned int ng11[] = {5U, 0U};
static int ng12[] = {22, 0};
static unsigned int ng13[] = {6U, 0U};
static int ng14[] = {9, 0};
static unsigned int ng15[] = {7U, 0U};
static int ng16[] = {13, 0};
static unsigned int ng17[] = {8U, 0U};
static int ng18[] = {15, 0};
static unsigned int ng19[] = {9U, 0U};
static int ng20[] = {17, 0};
static unsigned int ng21[] = {10U, 0U};
static int ng22[] = {21, 0};
static unsigned int ng23[] = {11U, 0U};
static int ng24[] = {23, 0};
static unsigned int ng25[] = {12U, 0U};
static int ng26[] = {10, 0};
static unsigned int ng27[] = {13U, 0U};
static int ng28[] = {11, 0};
static unsigned int ng29[] = {14U, 0U};
static int ng30[] = {18, 0};
static unsigned int ng31[] = {15U, 0U};
static int ng32[] = {19, 0};
static unsigned int ng33[] = {16U, 0U};
static int ng34[] = {0, 0};
static unsigned int ng35[] = {17U, 0U};
static int ng36[] = {1, 0};
static unsigned int ng37[] = {18U, 0U};
static int ng38[] = {2, 0};
static unsigned int ng39[] = {19U, 0U};
static int ng40[] = {3, 0};
static unsigned int ng41[] = {20U, 0U};
static int ng42[] = {4, 0};
static unsigned int ng43[] = {21U, 0U};
static int ng44[] = {5, 0};
static unsigned int ng45[] = {22U, 0U};
static int ng46[] = {6, 0};
static unsigned int ng47[] = {23U, 0U};
static int ng48[] = {7, 0};
static unsigned int ng49[] = {24U, 0U};
static int ng50[] = {24, 0};
static unsigned int ng51[] = {25U, 0U};
static int ng52[] = {25, 0};
static unsigned int ng53[] = {26U, 0U};
static int ng54[] = {26, 0};
static unsigned int ng55[] = {27U, 0U};
static int ng56[] = {27, 0};
static unsigned int ng57[] = {28U, 0U};
static int ng58[] = {28, 0};
static unsigned int ng59[] = {29U, 0U};
static int ng60[] = {29, 0};
static unsigned int ng61[] = {30U, 0U};
static int ng62[] = {30, 0};
static unsigned int ng63[] = {31U, 0U};
static int ng64[] = {31, 0};



static void Always_20_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;

LAB0:    t1 = (t0 + 2520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(20, ng0);
    t2 = (t0 + 3088);
    *((int *)t2) = 1;
    t3 = (t0 + 2552);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(20, ng0);

LAB5:    xsi_set_current_line(21, ng0);
    t4 = (t0 + 1048U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t4, 5);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng13)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng15)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng17)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng19)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng21)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB27;

LAB28:    t2 = ((char*)((ng23)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB29;

LAB30:    t2 = ((char*)((ng25)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng27)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng29)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng31)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng33)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng35)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng37)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng39)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB45;

LAB46:    t2 = ((char*)((ng41)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB47;

LAB48:    t2 = ((char*)((ng43)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB49;

LAB50:    t2 = ((char*)((ng45)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB51;

LAB52:    t2 = ((char*)((ng47)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB53;

LAB54:    t2 = ((char*)((ng49)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB55;

LAB56:    t2 = ((char*)((ng51)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng53)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng55)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng57)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB63;

LAB64:    t2 = ((char*)((ng59)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB65;

LAB66:    t2 = ((char*)((ng61)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB67;

LAB68:    t2 = ((char*)((ng63)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 5, t2, 5);
    if (t6 == 1)
        goto LAB69;

LAB70:
LAB71:    goto LAB2;

LAB7:    xsi_set_current_line(22, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t8, t7, 0, 0, 5, 0LL);
    goto LAB71;

LAB9:    xsi_set_current_line(23, ng0);
    t3 = ((char*)((ng4)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB11:    xsi_set_current_line(24, ng0);
    t3 = ((char*)((ng6)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB13:    xsi_set_current_line(25, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB15:    xsi_set_current_line(26, ng0);
    t3 = ((char*)((ng10)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB17:    xsi_set_current_line(27, ng0);
    t3 = ((char*)((ng12)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB19:    xsi_set_current_line(28, ng0);
    t3 = ((char*)((ng14)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB21:    xsi_set_current_line(29, ng0);
    t3 = ((char*)((ng16)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB23:    xsi_set_current_line(30, ng0);
    t3 = ((char*)((ng18)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB25:    xsi_set_current_line(31, ng0);
    t3 = ((char*)((ng20)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB27:    xsi_set_current_line(32, ng0);
    t3 = ((char*)((ng22)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB29:    xsi_set_current_line(33, ng0);
    t3 = ((char*)((ng24)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB31:    xsi_set_current_line(34, ng0);
    t3 = ((char*)((ng26)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB33:    xsi_set_current_line(35, ng0);
    t3 = ((char*)((ng28)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB35:    xsi_set_current_line(36, ng0);
    t3 = ((char*)((ng30)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB37:    xsi_set_current_line(37, ng0);
    t3 = ((char*)((ng32)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB39:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng34)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB41:    xsi_set_current_line(39, ng0);
    t3 = ((char*)((ng36)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB43:    xsi_set_current_line(40, ng0);
    t3 = ((char*)((ng38)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB45:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng40)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB47:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng42)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB49:    xsi_set_current_line(43, ng0);
    t3 = ((char*)((ng44)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB51:    xsi_set_current_line(44, ng0);
    t3 = ((char*)((ng46)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB53:    xsi_set_current_line(45, ng0);
    t3 = ((char*)((ng48)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB55:    xsi_set_current_line(46, ng0);
    t3 = ((char*)((ng50)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB57:    xsi_set_current_line(47, ng0);
    t3 = ((char*)((ng52)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB59:    xsi_set_current_line(48, ng0);
    t3 = ((char*)((ng54)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB61:    xsi_set_current_line(49, ng0);
    t3 = ((char*)((ng56)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB63:    xsi_set_current_line(50, ng0);
    t3 = ((char*)((ng58)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB65:    xsi_set_current_line(51, ng0);
    t3 = ((char*)((ng60)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB67:    xsi_set_current_line(52, ng0);
    t3 = ((char*)((ng62)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

LAB69:    xsi_set_current_line(53, ng0);
    t3 = ((char*)((ng64)));
    t4 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t4, t3, 0, 0, 5, 0LL);
    goto LAB71;

}

static void Cont_57_1(char *t0)
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

LAB0:    t1 = (t0 + 2768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 3184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 31U;
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
    xsi_driver_vfirst_trans(t5, 0, 4);
    t18 = (t0 + 3104);
    *((int *)t18) = 1;

LAB1:    return;
}


extern void work_m_03288515654100803219_0941256592_init()
{
	static char *pe[] = {(void *)Always_20_0,(void *)Cont_57_1};
	xsi_register_didat("work_m_03288515654100803219_0941256592", "isim/SURF_TOP_TEST_isim_beh.exe.sim/work/m_03288515654100803219_0941256592.didat");
	xsi_register_executes(pe);
}
