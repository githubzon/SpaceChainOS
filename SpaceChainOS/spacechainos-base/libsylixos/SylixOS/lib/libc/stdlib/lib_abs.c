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
** ��   ��   ��: lib_abs.c
**
** ��   ��   ��: Han.Hui (����)
**
** �ļ���������: 2011 �� 03 �� 04 ��
**
** ��        ��: ����ֵ����.
*********************************************************************************************************/
#define  __SYLIXOS_KERNEL
#include "../SylixOS/kernel/include/k_kernel.h"
/*********************************************************************************************************
** ��������: lib_abs
** ��������: 
** �䡡��  : 
** �䡡��  : 
** ȫ�ֱ���: 
** ����ģ��: 
*********************************************************************************************************/
INT  lib_abs (INT  i)
{
    return  ((i >= 0) ? (i) : (-i));
}
/*********************************************************************************************************
** ��������: lib_labs
** ��������: 
** �䡡��  : 
** �䡡��  : 
** ȫ�ֱ���: 
** ����ģ��: 
*********************************************************************************************************/
LONG  lib_labs (LONG  l)
{
    return  ((l >= 0) ? (l) : (-l));
}
/*********************************************************************************************************
** ��������: lib_labs
** ��������: 
** �䡡��  : 
** �䡡��  : 
** ȫ�ֱ���: 
** ����ģ��: 
*********************************************************************************************************/
long long  lib_llabs (long long ll)
{
    return  ((ll >= 0) ? (ll) : (-ll));
}
/*********************************************************************************************************
  END
*********************************************************************************************************/