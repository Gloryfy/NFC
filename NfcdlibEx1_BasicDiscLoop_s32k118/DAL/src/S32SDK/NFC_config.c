//===========================================================================//
//文件说明：NFC的驱动配置模块
//基于环境S32
//修订版本：V0.1
//修订人：
//修订时间：
//修订说明：
//===========================================================================//
//
//文件包含
//kai

// kai 2020.01.06

#include "NFC_config.h"
#include "flexcan_driver.h" // kai 2020.12.30
#include "canCom0.h"    // kai 2020.12.30

static flexcan_msgbuff_t flexcan_rx_msgbuff_t={
		.msgId=0,
		.dataLen=0,
		.data={0,0,0,0,0,0,0,0},
};

//===========================================================================//
//函数说明：NFC CAN 接收发送完成中断回调
//输入说明：无
//输出说明：无
//配置说明：无
//===========================================================================//
void User_CAN_IRQ_Callback_Callback(uint8_t instance, flexcan_event_type_t eventType,
                                   uint32_t buffIdx, flexcan_state_t *flexcanState){
	(void)buffIdx;
	(void)flexcanState;
	(void)instance;
	if(FLEXCAN_EVENT_RX_COMPLETE==eventType){
		NFC_CAN_RX_ISR();
	}
}

//===========================================================================//
//函数说明：NFC CAN 错误中断回调
//输入说明：无
//输出说明：无
//配置说明：无
//===========================================================================//
void User_CAN_Error_Callback_Callback(uint8_t instance, flexcan_event_type_t eventType,
        flexcan_state_t *flexcanState){
	//uint32_t ecr=0;
	(void)flexcanState;
	//CAN_Type * base = CAN0;
	uint32_t get_can_error_states=0;
	if(FLEXCAN_EVENT_ERROR==eventType){
		get_can_error_states=FLEXCAN_DRV_GetErrorStatus(instance);
		if(0x00002000 & get_can_error_states){
			NFC_CAN_NO_ACK_ISR();
		}
		if(0x00000004  & get_can_error_states){   // 总线关闭中断
			NFC_CAN_BUSOFF_ISR();
		}else if(0x00000012  & get_can_error_states){ // 出现错误且节点处于被动错误节点状态
			//ecr=FLEXCAN_GetErrorCounters(base);
			//if(128==FLEXCAN_GetErrorCounters(base)){
			NFC_CAN_Error_ISR();
			//}
		}
	}
}

//===========================================================================//
//函数说明：NFC CAN 接收配置接口
//输入说明：mask：     0：对应值不必匹配 ；1：对应值必须进行匹配
//输出说明：无
//配置说明：无
//===========================================================================//
void NFC_CAN_Receive_Config (uint8_t mbs,uint32_t id,uint32_t mask,uint8_t len)
{
    flexcan_data_info_t flexcan_rx_data_info_t={
    	.msg_id_type=FLEXCAN_MSG_ID_STD,
		.is_remote=false,
		.fd_enable=false,
		.data_length=len,
    };
    // mask：     0：对应位不必匹配 ；1：对应位必须进行匹配
    FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0,FLEXCAN_MSG_ID_STD,mbs,mask);
    FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0,mbs,&flexcan_rx_data_info_t,id);
}

#if 0
//===========================================================================//
//函数说明：NFC CAN 发送配置接口
//输入说明：无
//输出说明：无
//配置说明：无
//===========================================================================//
void NFC_CAN_Send_Config (uint8_t mbs,uint32_t id)
{
    flexcan_data_info_t flexcan_tx_data_info_t={
    	.msg_id_type=FLEXCAN_MSG_ID_STD,
		.is_remote=false,
		.fd_enable=false,
		.data_length=8,
    };
    FLEXCAN_DRV_ConfigTxMb(INST_CANCOM0,mbs,&flexcan_tx_data_info_t,id);
}
#endif
//===========================================================================//
//函数说明：NFC CAN初始化函数
//输入说明：无
//输出说明：无
//配置说明：无
//1. 配置要求500Kbps, 16bit, 81%采样点(实际配置的理论计数应为81.25)
//2. 报文接收中断/BUSOFF中断/NO ACK中断/被动错误中断使能
//3. CAN 滤波器配置使能
//===========================================================================//
void NFC_CAN_Config (void)
{
    // Initialize CAN
    FLEXCAN_DRV_Init(INST_CANCOM0,&canCom0_State,&canCom0_InitConfig0);
	// Set ID mask type
	FLEXCAN_DRV_SetRxMaskType(INST_CANCOM0,FLEXCAN_RX_MASK_INDIVIDUAL);
	// Set Callback
	FLEXCAN_DRV_InstallEventCallback(INST_CANCOM0,User_CAN_IRQ_Callback_Callback,NULL);
	FLEXCAN_DRV_InstallErrorCallback(INST_CANCOM0,User_CAN_Error_Callback_Callback,NULL);
	// 配置接收 MB
	NFC_CAN_Receive_Config(0x00,0x00,0x00,0x08);
	// 启动接收
	FLEXCAN_DRV_Receive(INST_CANCOM0,0x00,&flexcan_rx_msgbuff_t);
}

//===========================================================================//
//函数说明：NFC CAN发送报文接口
//输入说明：无
//输出说明：无
//说明：无
//===========================================================================//
unsigned char NFC_CAN_Send_Frame (unsigned long int id, unsigned char *p_buff, unsigned char len)
{
    unsigned char Result = KW_TRUE;
    status_t ret=STATUS_SUCCESS;
    flexcan_data_info_t flexcan_tx_data_info_t={
        	.msg_id_type=FLEXCAN_MSG_ID_STD,
			.is_remote=false,
			.fd_enable=false,
			.data_length=len,
    };
    ret=FLEXCAN_DRV_SendBlocking(INST_CANCOM0,0x01,&flexcan_tx_data_info_t,id,p_buff,5);
    if(STATUS_SUCCESS!=ret){
    	Result=KW_FALSE;
    }
    return Result;
}
    
//===========================================================================//
//函数说明：NFC CAN接收报文接收中断服务函数接口
//输入说明：无
//输出说明：无
//说明：无
//===========================================================================//
void NFC_CAN_RX_ISR (void)
{
	FLEXCAN_DRV_Receive(INST_CANCOM0,0x00,&flexcan_rx_msgbuff_t);
}

//===========================================================================//
//函数说明：NFC CAN BUSOFF中断服务函数接口
//输入说明：
//输出说明：
//说明：无
//===========================================================================//
void NFC_CAN_BUSOFF_ISR (void)
{
    
}

//===========================================================================//
//函数说明：NFC CAN 被动错误中断服务函数接口
//输入说明：无
//输出说明：无
//说明：无
//===========================================================================//
void NFC_CAN_Error_ISR (void)
{
    
}

//===========================================================================//
//函数说明：NFC CAN no ACK 中断服务函数接口
//输入说明：无
//输出说明：无
//说明：无
//===========================================================================//
void NFC_CAN_NO_ACK_ISR (void)
{
    
}

