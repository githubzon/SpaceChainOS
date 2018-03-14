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
** ��   ��   ��: ptimerDev.h
**
** ��   ��   ��: Han.Hui (����)
**
** �ļ���������: 2013 �� 11 �� 20 ��
**
** ��        ��: Linux ���� timerfd ʵ��.
*********************************************************************************************************/

#ifndef __TIMERDEV_H
#define __TIMERDEV_H

/*********************************************************************************************************
  �ü�����
*********************************************************************************************************/
#if (LW_CFG_PTIMER_EN > 0) && (LW_CFG_TIMERFD_EN > 0)

/*********************************************************************************************************
  �豸·��
*********************************************************************************************************/

#define LW_TMRFD_DEV_PATH   "/dev/timerfd"

/*********************************************************************************************************
  �豸���ļ��ṹ
*********************************************************************************************************/

typedef struct {
    LW_DEV_HDR          TD_devhdrHdr;                                   /*  �豸ͷ                      */
} LW_TMRFD_DEV;
typedef LW_TMRFD_DEV   *PLW_TMRFD_DEV;

typedef struct {
#define LW_TIMER_FILE_MAGIC 0x35ac796d
    UINT32              TF_uiMagic;
    INT                 TF_iFlag;                                       /*  ���ļ���ѡ��              */
    timer_t             TF_timer;
    LW_OBJECT_HANDLE    TF_ulReadLock;
    LW_SEL_WAKEUPLIST   TF_selwulist;
} LW_TMRFD_FILE;
typedef LW_TMRFD_FILE  *PLW_TMRFD_FILE;

/*********************************************************************************************************
  ��ʼ������
*********************************************************************************************************/

LW_API INT  API_TimerfdDrvInstall(VOID);
LW_API INT  API_TimerfdDevCreate(VOID);

#define timerfdDrv          API_TimerfdDrvInstall
#define timerfdDevCreate    API_TimerfdDevCreate

#endif                                                                  /*  LW_CFG_PTIMER_EN > 0        */
                                                                        /*  LW_CFG_TIMERFD_EN > 0       */
#endif                                                                  /*  __TIMERDEV_H                */
/*********************************************************************************************************
  END
*********************************************************************************************************/