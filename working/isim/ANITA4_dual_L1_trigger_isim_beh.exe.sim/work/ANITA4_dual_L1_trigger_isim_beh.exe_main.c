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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    unisims_ver_m_12026317184123736351_0824577468_init();
    unisims_ver_m_12026317184123736351_2607553651_init();
    work_m_04386578844503833695_1049221391_init();
    work_m_00644071671512501317_1747271114_init();
    work_m_15743966522019218039_0126259420_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_15743966522019218039_0126259420");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
