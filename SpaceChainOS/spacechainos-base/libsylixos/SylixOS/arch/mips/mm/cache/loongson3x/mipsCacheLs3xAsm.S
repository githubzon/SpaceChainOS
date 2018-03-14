;/*********************************************************************************************************
;**
;**                                    �й�������Դ��֯
;**
;**                                   Ƕ��ʽʵʱ����ϵͳ
;**
;**                                       SylixOS(TM)
;**
;**                               Copyright  All Rights Reserved
;**
;**--------------�ļ���Ϣ--------------------------------------------------------------------------------
;**
;** ��   ��   ��: mipsCacheLs3xAsm.S
;**
;** ��   ��   ��: Jiao.JinXing (������)
;**
;** �ļ���������: 2016 �� 11 �� 02 ��
;**
;** ��        ��: Loongson3x ��ϵ���� CACHE ����.
;*********************************************************************************************************/

#ifndef ASSEMBLY
#define ASSEMBLY 1
#endif

#include <arch/assembler.h>
#include <config/kernel/cache_cfg.h>

#if LW_CFG_CACHE_EN > 0

    EXPORT_LABEL(ls3xCacheDisableHw)
    EXPORT_LABEL(ls3xCacheEnableHw)

    FILE_BEGIN()

;/*********************************************************************************************************
;  ���� CACHE
;*********************************************************************************************************/

FUNC_DEF(ls3xCacheDisableHw)
    .set    push
    .set    noreorder
    .set    volatile

    JR      RA
    NOP

    .set    pop
    FUNC_END(ls3xCacheDisableHw)

;/*********************************************************************************************************
;  ʹ�� CACHE
;*********************************************************************************************************/

FUNC_DEF(ls3xCacheEnableHw)
    .set    push
    .set    noreorder
    .set    volatile

    MFC0(T0, CP0_CONFIG)
    ANDI    T0 , T0 , M_ConfigK0
    LI      T1 , MIPS_CACHABLE_NONCOHERENT
    BEQ     T0 , T1 , 1f
    NOP

    MFC0(T0, CP0_CONFIG)
    AND     T0 , T0 , ~M_ConfigK0
    ORI     T0 , MIPS_CACHABLE_NONCOHERENT
    MTC0(T0, CP0_CONFIG)

1:
    JR      RA
    NOP

    .set    pop
    FUNC_END(ls3xCacheEnableHw)

    FILE_END()

#endif
;/*********************************************************************************************************
;  END
;*********************************************************************************************************/