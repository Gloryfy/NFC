//===========================================================================//
//�ļ�˵����NFC����������ģ��
//���ڻ���S32
//�޶��汾��V0.1
//�޶��ˣ�
//�޶�ʱ�䣺
//�޶�˵����
//===========================================================================//
//
//�ļ�����
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
//����˵����NFC CAN ���շ�������жϻص�
//����˵������
//���˵������
//����˵������
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
//����˵����NFC CAN �����жϻص�
//����˵������
//���˵������
//����˵������
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
		if(0x00000004  & get_can_error_states){   // ���߹ر��ж�
			NFC_CAN_BUSOFF_ISR();
		}else if(0x00000012  & get_can_error_states){ // ���ִ����ҽڵ㴦�ڱ�������ڵ�״̬
			//ecr=FLEXCAN_GetErrorCounters(base);
			//if(128==FLEXCAN_GetErrorCounters(base)){
			NFC_CAN_Error_ISR();
			//}
		}
	}
}

//===========================================================================//
//����˵����NFC CAN �������ýӿ�
//����˵����mask��     0����Ӧֵ����ƥ�� ��1����Ӧֵ�������ƥ��
//���˵������
//����˵������
//===========================================================================//
void NFC_CAN_Receive_Config (uint8_t mbs,uint32_t id,uint32_t mask,uint8_t len)
{
    flexcan_data_info_t flexcan_rx_data_info_t={
    	.msg_id_type=FLEXCAN_MSG_ID_STD,
		.is_remote=false,
		.fd_enable=false,
		.data_length=len,
    };
    // mask��     0����Ӧλ����ƥ�� ��1����Ӧλ�������ƥ��
    FLEXCAN_DRV_SetRxIndividualMask(INST_CANCOM0,FLEXCAN_MSG_ID_STD,mbs,mask);
    FLEXCAN_DRV_ConfigRxMb(INST_CANCOM0,mbs,&flexcan_rx_data_info_t,id);
}

#if 0
//===========================================================================//
//����˵����NFC CAN �������ýӿ�
//����˵������
//���˵������
//����˵������
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
//����˵����NFC CAN��ʼ������
//����˵������
//���˵������
//����˵������
//1. ����Ҫ��500Kbps, 16bit, 81%������(ʵ�����õ����ۼ���ӦΪ81.25)
//2. ���Ľ����ж�/BUSOFF�ж�/NO ACK�ж�/���������ж�ʹ��
//3. CAN �˲�������ʹ��
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
	// ���ý��� MB
	NFC_CAN_Receive_Config(0x00,0x00,0x00,0x08);
	// ��������
	FLEXCAN_DRV_Receive(INST_CANCOM0,0x00,&flexcan_rx_msgbuff_t);
}

//===========================================================================//
//����˵����NFC CAN���ͱ��Ľӿ�
//����˵������
//���˵������
//˵������
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
//����˵����NFC CAN���ձ��Ľ����жϷ������ӿ�
//����˵������
//���˵������
//˵������
//===========================================================================//
void NFC_CAN_RX_ISR (void)
{
	FLEXCAN_DRV_Receive(INST_CANCOM0,0x00,&flexcan_rx_msgbuff_t);
}

//===========================================================================//
//����˵����NFC CAN BUSOFF�жϷ������ӿ�
//����˵����
//���˵����
//˵������
//===========================================================================//
void NFC_CAN_BUSOFF_ISR (void)
{
    
}

//===========================================================================//
//����˵����NFC CAN ���������жϷ������ӿ�
//����˵������
//���˵������
//˵������
//===========================================================================//
void NFC_CAN_Error_ISR (void)
{
    
}

//===========================================================================//
//����˵����NFC CAN no ACK �жϷ������ӿ�
//����˵������
//���˵������
//˵������
//===========================================================================//
void NFC_CAN_NO_ACK_ISR (void)
{
    
}

