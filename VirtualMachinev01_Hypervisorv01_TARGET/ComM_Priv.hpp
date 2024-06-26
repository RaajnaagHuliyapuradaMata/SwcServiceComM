#ifndef COMM_PRIV_H
#define COMM_PRIV_H

#include "ComM.hpp"
#include "ComM_Cfg_Internal.hpp"
#include "Rte_ComM.hpp"
#include "BswM_ComM.hpp"
#include "ComM_Cfg_SchM.hpp"
#include "EcuM.hpp"
#include "Bfx.hpp"
#include "Dcm_Cbk.hpp"

#define COMM_INSTANCE_ID                                           ((uint8)0x00)
#define COMM_INIT_APIID                                            ((uint8)0x01)
#define COMM_DEINIT_APIID                                          ((uint8)0x02)
#define COMM_GET_STATUS_APIID                                      ((uint8)0x03)
#define COMM_GET_INHIBITION_STATUS_APIID                           ((uint8)0x04)
#define COMM_REQ_COMMODE_APIID                                     ((uint8)0x05)
#define COMM_GET_MAX_COMMODE_APIID                                 ((uint8)0x06)
#define COMM_GET_REQ_COMMODE_APIID                                 ((uint8)0x07)
#define COMM_GET_CUR_COMMODE_APIID                                 ((uint8)0x08)
#define COMM_PREVENT_WAKEUP_APIID                                  ((uint8)0x09)
#define COMM_LIMIT_CHNLTO_NOCOMMODE_APIID                          ((uint8)0x0b)
#define COMM_LIMIT_ECUTO_NOCOMMODE_APIID                           ((uint8)0x0c)
#define COMM_READ_INHIBIT_COUNTER_APIID                            ((uint8)0x0d)
#define COMM_RESET_INHIBIT_COUNTER_APIID                           ((uint8)0x0e)
#define COMM_SET_ECUGROUPCLASS_APIID                               ((uint8)0x0f)
#define COMM_GETVERINFO_APIID                                      ((uint8)0x10)
#define COMM_MAINFNC_APIID                                         ((uint8)0x60)
#define COMM_NM_BUS_SLEEPMODE                                      ((uint8)0x1a)
#define COMM_NM_NETWORKMODE                                        ((uint8)0x18)
#define COMM_NM_NETWORKSTART_INDICATION                            ((uint8)0x15)
#define COMM_NM_PREPARE_BUSSLEEPMODE                               ((uint8)0x19)
#define COMM_NM_RESTARTINDICATION                                  ((uint8)0x1b)
#define COMM_DCM_ACTIVEDIAG                                        ((uint8)0x1f)
#define COMM_DCM_INACTIVEDIAG                                      ((uint8)0x20)
#define COMM_COMMUNICATION_ALLOWED                                 ((uint8)0x29)
#define COMM_ECUM_WAKEUP_INDICATION                                ((uint8)0x2a)
#define COMM_ECUM_PNCWAKEUP_INDICATION                             ((uint8)0x38)
#define COMM_BUSSM_MODEINDICATION                                  ((uint8)0x33)
#define COMM_GET_STATE_APIID                                       ((uint8)0x34)
#define COMM_EIRA_CBK_APIID                                        ((uint8)0x35)
#define COMM_ERA_CBK_APIID                                         ((uint8)0x36)
#define COMM_PNC_MAINFNC_APIID                                     ((uint8)0x37)
#define COMM_NVM_REFERENCE_BLOCK                                   ((uint8)0x40)
#define COMM_E_MODE_LIMITATION                                                 2
#define E_NOT_INITIALIZED                                                      3
#define COMM_E_NOT_INITED                                         ((uint8)(0x1))
#define COMM_E_WRONG_PARAMETERS                                   ((uint8)(0x2))
#define COMM_E_ERROR_IN_PROV_SERVICE                              ((uint8)(0x3))
#define COMM_E_CNTR_UNDERFLW                                       ((uint8)0x04)
#define COMM_E_NVM_WRITE_FAILED                                    ((uint8)0x05)
#define COMM_ACTIVE_DIAGNOSTICS                                             TRUE
#define COMM_INACTIVE_DIAGNOSTICS                                          FALSE
#define COMM_NM_VARIANT_FULL                                                TRUE
#define COMM_NM_VARIANT_PASSIVE                                            FALSE
#define COMM_NOT_USED_USER_ID                                      ((uint8)0xFF)
#define COMM_SET_LIMIT_TO_NO_COM(Reg) (void)(Bfx_SetBit_u8u8(&(Reg), 0x01))
#define COMM_SET_PREVENT_WAKEUP(Reg)  (void)(Bfx_SetBit_u8u8(&(Reg), 0x00))
#define COMM_CLR_LIMIT_TO_NO_COM(Reg) (void)(Bfx_ClrBit_u8u8(&(Reg), 0x01))
#define COMM_CLR_PREVENT_WAKEUP(Reg)  (void)(Bfx_ClrBit_u8u8(&(Reg), 0x00))
#define COMM_GET_LIMIT_TO_NO_COM(Reg) (Bfx_GetBit_u8u8_u8((Reg),0x01))
#define COMM_GET_PREVENT_WAKEUP(Reg)  (Bfx_GetBit_u8u8_u8((Reg),0x00))
#define COMM_SET_BIT(Reg,Position)    (void)(Bfx_SetBit_u8u8(&(Reg),Position))

#ifndef C_ZERO
#define C_ZERO  ((uint8)0x00)
#endif

#ifndef C_ONE
#define C_ONE   ((uint8)0x01)
#endif

#define COMM_WAKEUP_INHIBITION  ((uint8)0x01)
#define COMM_LIMIT_TO_NOCOM  ((uint8)0x02)
#define COMM_COMSIGNAL_INVALID_ID    ((uint16)0xFFFF)
#define COMM_MAX_U16  ((uint16)0xFFFF)
#define COMM_GET_FEATURE_PNC_ENABLED  (TRUE)
#define COMM_GET_CHANNEL_LIST     ComM_ChanelList
#define COMM_GET_USER_LIST       ComM_UserList
#define COMM_GET_PNC_LIST        ComM_PncList
#define COMM_GET_EIRASIG_TABLE    ComM_EIRA_RxSig
#define COMM_GET_ERASIG_TABLE     ComM_ERA_RxSig
#define ComM_Config     NULL_PTR

typedef boolean ComM_DiagnosticType;

typedef enum{
  COMM_PREVENTWAKEUP = 0
   ,  COMM_LIMITTONOCOM
}ComM_InhibitionType;

typedef struct{
   VAR(ComM_InitStatusType,COMM_VAR) ComM_InitStatus;
}ComM_GlobalVarType;

typedef struct {
   VAR(ComM_StateType, AUTOMATIC) ChannelState_e;
   VAR(uint32, AUTOMATIC) LightTimeoutCtr_u32;
   VAR(uint16, AUTOMATIC) MinFullComTimeoutCtr_u16;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) ChannelMode_u8;
   VAR(Type_SwcServiceComM_tMode, AUTOMATIC) BusSmMode_u8;
   VAR(uint8, AUTOMATIC) UserRequestCtr_u8;
   VAR(uint8, AUTOMATIC) PassiveRequestState_u8;
   VAR(uint8, AUTOMATIC) PncRequestCtr_u8;
   VAR(Type_SwcServiceComM_tStatusInhibition, AUTOMATIC) InhibitionReqStatus_u8;
   VAR(boolean, AUTOMATIC) NmNetworkRequestStatus_b;
   VAR(ComM_DiagnosticType, AUTOMATIC) DiagnosticRequestState_b;
   VAR(boolean, AUTOMATIC) CommunicationAllowed_b;
   VAR(boolean, AUTOMATIC) NmBusSleepIndicationStatus_b;
   VAR(boolean, AUTOMATIC) NmPrepareBusSleepIndicationStatus_b;
   VAR(boolean, AUTOMATIC) NmNetworkModeStatus_b;
} ComM_ChannelVarType;

typedef struct {
     VAR(uint16, AUTOMATIC) WakeUpInhibitionCtr_u16;
     VAR(uint16, AUTOMATIC) LimitToNoComCtr_u16;
     VAR(Type_SwcServiceComM_tMode, AUTOMATIC) RequestedUserMode_t;
     VAR(Type_SwcServiceComM_tMode, AUTOMATIC) IndicatedUserMode_t;
     VAR(uint8, AUTOMATIC) numChannelsInFullCom_u8;
     VAR(uint8, AUTOMATIC) numChannelsInSilentCom_u8;
     VAR(uint8, AUTOMATIC) numChannelsInNoCom_u8;
} ComM_UserVarType;

typedef struct{
   VAR(ComM_PncModeType, AUTOMATIC) PncState_e;
   VAR(uint16, AUTOMATIC) PrepareSleepTimer_u16;
   VAR(uint8, AUTOMATIC) UserRequestCnt_u8;
   VAR(uint8, AUTOMATIC) EIRACnt_u8;
   VAR(boolean, AUTOMATIC) WakeUpStatus_b;
}ComM_PncRamStructType;

typedef struct{
   VAR(boolean, AUTOMATIC) ActiveRequest_b;
   VAR(boolean, AUTOMATIC) PassiveRequest_b;
}ComM_RequestStructType;

typedef struct{
   VAR(boolean, AUTOMATIC) activeRequestState_b;
   VAR(boolean, AUTOMATIC) wakeupRequestState_b;
   VAR(boolean, AUTOMATIC) passiveRequestState_b;
}ComM_PncEventStructType;

typedef struct{
   uint8                                        ComMEcuGroupClassification_u8;
   uint16                                       Inhibitioncounter_u16;
   VAR(uint8,COMM_VAR)                          ComMNoWakeup_u8[COMM_NVM_NO_WAKEUP_SIZE] ;
}ComM_NvMStorageType;

extern VAR(ComM_GlobalVarType,COMM_VAR) ComM_GlobalStruct;
extern VAR(ComM_ChannelVarType,COMM_VAR) ComM_ChannelStruct[];
extern VAR(ComM_NvMStorageType,COMM_VAR) ComM_NvMblock;
extern VAR(ComM_UserVarType,COMM_VAR) ComM_UserStruct[];

extern FUNC(void, COMM_CODE) ComM_LUpdateChannelModes(
   NetworkHandleType Channel,
   Type_SwcServiceComM_tMode PreviousMode,
   Type_SwcServiceComM_tMode CurrentMode);
extern FUNC(void, COMM_CODE) ComM_LTranslateInhibitionStatus(
   NetworkHandleType Channel,
   ComM_InhibitionType InhibitionType,
   boolean Status);
extern FUNC(void, COMM_CODE) ComM_LPncToChannelInterface(PNCHandleType PncIndex,ComM_PncModeType PncState,ComM_PncModeType PncPreviousState);
extern FUNC(void, COMM_CODE) ComM_LPncMainFunction (VAR(PNCHandleType, AUTOMATIC) PncIndex);
extern FUNC(void, COMM_CODE) ComM_EIRA_CallBack(uint8 PnBusId);
extern FUNC(void, COMM_CODE) ComM_ERA_CallBack(uint8 PnBusId,ComM_PncGatewayType channelGwType);
extern FUNC(void, COMM_CODE) ComM_LChannelMainFunction (VAR(NetworkHandleType, AUTOMATIC) ChannelIndex);
extern FUNC(Type_SwcServiceComM_tMode, COMM_CODE) ComM_LgetLeastBusSmMode(Type_SwcServiceComM_tUserHandle UserIndex);
extern FUNC(void, COMM_CODE) ComM_LRteNotifyLowestComMode (Type_SwcServiceComM_tUserHandle UserIndex);
extern FUNC(void, COMM_CODE) ComM_LSyncWakeUpIndication(void);
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LProcessLimitToNoCom(VAR(NetworkHandleType, COMM_VAR) Channel,VAR(boolean, COMM_VAR) Status);

#endif

