/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _HOST_IO_H    /* Guard against multiple inclusion */
#define _HOST_IO_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */


#include "driver/usart/drv_usart.h"

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

#define USART0_RX_BUFF_SIZE 16
#define USART0_TX_BUFF_SIZE 255

#define HOST_PACKET_INDEX 0
#define CLIENT_PACKET_INDEX 1
#define HOST_IO_INDEX 2
#define HOST_IO_READ_FLAG 0x0

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************
    typedef uint8_t HOST_IO_PACKET_INDEX;

    typedef enum {
        PACKET_LOOK_FOR_START = 1,
        PACKET_LOOK_FOR_DATA = 2,
        PACKET_LOOK_FOR_CMD = 3,
        PACKET_RECEIVED = 4,
        PACKET_PROCESSING = 5,
        PACKET_SEND_START = 6,
        PACKET_SEND_PENDING = 7,
        PACKET_SENT = 8,
        HOST_IO_IDLE = 9,
        PACKET_ERROR = 10
    } HOST_IO_STATES;

    typedef enum {
        NO_HOST_REQUEST = 0,
        HOST_WRITE_BLOCK = 1,
        HOST_WRITE_REG = 2,
        HOST_READ_REG = 3,
        HOST_PING_CLIENT = 4
    } HOST_REQUEST_MODES;

    typedef enum {
        NO_CLIENT_REPLY = 0,
        CLIENT_SHORT_REPLY = 1,
        CLIENT_LONG_REPLY = 2,
        CLIENT_ECHO_HOST = 3,
    } CLIENT_REPLY_MODES;

    /* List of possible commanded states */
    typedef enum {
        DISABLE = 0,
        ENABLE = 1,
        RELATIVE_MOVE = 2,
        ABSOLUTE_MOVE = 3,
        UNKNOWN_COMPONENT_STATE = 4
    } HOST_IO_COMPONENT_STATES;

    /* List of data parameter labels in the order they are expected to arrive */
    typedef enum {
        L_STATE = 0,
        L_POWER = 1,
        G_STATE = 2,
        G_SPEED = 3,
        X_POS = 4,
        Y_POS = 5,
        END_HOST_DATA = 6,
        X_MEASUREMENT_0 = 7,
        X_MEASUREMENT_1 = 8,
        Y_MEASUREMENT_0 = 9,
        Y_MEASUREMENT_1 = 10,
        END_PACKET_DATA = 11,
    } HOST_IO_DATA_LABELS;

    /* data type for storing information received from PC */
    typedef struct {
        HOST_IO_COMPONENT_STATES laserState;
        uint8_t laserPower;
        HOST_IO_COMPONENT_STATES galvoState;
        int32_t gSpeed;
        int32_t xPosition;
        int32_t yPosition;

        // each bit in the array corresponds to a parameter.
        // Set true when valid data is read from PC 
        bool activeParameter[END_PACKET_DATA];

        // Used to step through each parameter field
        // filling with data from PC

        HOST_REQUEST_MODES RequestMode;
        CLIENT_REPLY_MODES ReplyMode;

        int32_t x_start;
        int32_t x_end;
        int32_t y_start;
        int32_t y_end;
    } HOST_IO_PACKET;

    typedef struct {
        DRV_HANDLE usartHandle;

        HOST_IO_STATES state;

        HOST_IO_PACKET HostPacket;
        HOST_IO_PACKET ClientPacket;
    } HOST_IO_OBJ;

    // *****************************************************************************
    // *****************************************************************************
    // Section: Local Functions
    // *****************************************************************************
    // *****************************************************************************

    int stringToInt(uint8_t *str);

    // *****************************************************************************
    // *****************************************************************************
    // Section: HostIO Access Functions
    // *****************************************************************************
    // *****************************************************************************
    void HostIO_Clear_Packet(void);

    int HostIO_Get_PacketData(const HOST_IO_DATA_LABELS label);
    void HostIO_Set_PacketData(const HOST_IO_DATA_LABELS label, int value);

    
    bool HostIO_ParameterIsActive(const HOST_IO_DATA_LABELS label);
    void HostIO_Add_ActiveParameter(const HOST_IO_DATA_LABELS label, int value);
    
    HOST_REQUEST_MODES HostIO_RequestMode(void);
    void HostIO_Set_RequestMode(HOST_REQUEST_MODES hMode);

    CLIENT_REPLY_MODES HostIO_ReplyMode(void);
    void HostIO_Set_ReplyMode(CLIENT_REPLY_MODES rMode);

    // *****************************************************************************
    // *****************************************************************************
    // Section: ClientIO Access Functions
    // *****************************************************************************
    // *****************************************************************************
    void ClientIO_Clear_Packet(void);

    int ClientIO_Get_PacketData(const HOST_IO_DATA_LABELS label);
    void ClientIO_Set_PacketData(const HOST_IO_DATA_LABELS label, int value);

    
    bool ClientIO_ParameterIsActive(const HOST_IO_DATA_LABELS label);
    void ClientIO_Add_ActiveParameter(const HOST_IO_DATA_LABELS label, int value);
    
    HOST_REQUEST_MODES ClientIO_RequestMode();
    void ClientIO_Set_RequestMode(HOST_REQUEST_MODES hMode);

    CLIENT_REPLY_MODES ClientIO_ReplyMode();
    void ClientIO_Set_ReplyMode(CLIENT_REPLY_MODES rMode);

    // *****************************************************************************
    // *****************************************************************************
    // Section: HostIo Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    HOST_IO_STATES HostIO_State(void);
    void HostIO_Set_State(const HOST_IO_STATES hState);

    void HostIO_Add_ClientPacket_To_TxBuffer(uint8_t *usartTXbuf, uint16_t *usartTXcount, uint16_t *tx_length);
    
    void HostIO_Send_ClientReply(uint8_t *usartTXbuf, uint16_t *usartTXcount, uint16_t *tx_length, HOST_IO_STATES *pState);

    void HostIO_Initialize(void);
    DRV_HANDLE HostIO_Open(void);
    void HostIO_Reply_Tasks(void);

    bool HostIO_Send_BootMessage(void);
    // *****************************************************************************
    // *****************************************************************************
    // Section: CallBack Functions
    // *****************************************************************************
    // *****************************************************************************
    void HostIO_USART_ReceiveEventHandler(const SYS_MODULE_INDEX index);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
