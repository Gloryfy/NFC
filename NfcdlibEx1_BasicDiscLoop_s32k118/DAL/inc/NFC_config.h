//===========================================================================//
//文件说明：芯片NFC的驱动配置模块头文件声明
//基于环境S32

// kai 2020.01.06

#ifndef _NFC_CFG_H
#define _NFC_CFG_H

//宏定义
#define KW_TRUE 1
#define KW_FALSE 0

void NFC_CAN_Config (void);

extern void NFC_CAN_RX_ISR (void);

extern void NFC_CAN_NO_ACK_ISR (void);

extern void NFC_CAN_Error_ISR (void);

extern void NFC_CAN_BUSOFF_ISR (void);

extern unsigned char NFC_CAN_Send_Frame (unsigned long int id, unsigned char *p_buff, unsigned char len);

#endif


