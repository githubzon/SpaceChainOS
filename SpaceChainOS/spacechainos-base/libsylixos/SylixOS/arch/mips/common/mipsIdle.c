/*********************************************************************************************************
**
**                                    �й�������Դ��֯
**
**                                   Ƕ��ʽʵʱ����ϵͳ
**
**                                SylixOS(TM)  LW : long wing
**
**                               Copyright All Rights Reserved
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**
** ��   ��   ��: mipsIdle.c
**
** ��   ��   ��: Han.hui (����)
**
** �ļ���������: 2017 �� 04 �� 14 ��
**
** ��        ��: MIPS ��ϵ���� IDLE ���ܳ���.
*********************************************************************************************************/
#define  __SYLIXOS_KERNEL
#include "SylixOS.h"
#include "arch/mips/common/cp0/mipsCp0.h"
/*********************************************************************************************************
  ��ຯ��
*********************************************************************************************************/
extern VOID  mipsWaitInstruction(VOID);
/*********************************************************************************************************
** ��������: mipsIdleHookGet
** ��������: R4K ������
** �䡡��  : NONE
** �䡡��  : NONE
** ȫ�ֱ���:
** ����ģ��:
*********************************************************************************************************/
VOIDFUNCPTR  mipsIdleHookGet (CPCHAR  pcMachineName)
{
    if ((lib_strcmp(pcMachineName, MIPS_MACHINE_LS1X)   == 0) ||
        (lib_strcmp(pcMachineName, MIPS_MACHINE_24KF)   == 0) ||
        (lib_strcmp(pcMachineName, MIPS_MACHINE_JZ47XX) == 0)) {
        return  (mipsWaitInstruction);

    } else if ((lib_strcmp(pcMachineName, MIPS_MACHINE_LS3X) == 0)) {
        UINT32  uiPrid = mipsCp0PRIdRead();

        if ((uiPrid & 0xf) == PRID_REV_LOONGSON2K) {
            return  (mipsWaitInstruction);

        } else if ((uiPrid & 0xf) != PRID_REV_LOONGSON3A_R1) {
            return  (mipsWaitInstruction);
        }
    }

    return  (LW_NULL);
}
/*********************************************************************************************************
  END
*********************************************************************************************************/