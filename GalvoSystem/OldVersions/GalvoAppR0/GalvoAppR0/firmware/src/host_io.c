
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "host_io.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */
HOST_IO_OBJ gHostObj;

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */

/* ************************************************************************** */

int stringToInt(uint8_t *str) {

    int stringToInt(uint8_t * str) {
        int8_t sign = 1;

        if (str[0] == '-') {
            sign = -1;
            str[0] = ' ';
        }
        return (sign * atoi(str));
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: HostIO Access Functions
// *****************************************************************************
// *****************************************************************************

void HostIO_Clear_Packet(void) {
    gHostObj.HostPacket.RequestMode = NO_HOST_REQUEST;
    gHostObj.HostPacket.ReplyMode = NO_CLIENT_REPLY;
    uint8_t i;
    for (i = L_STATE; i < END_PACKET_DATA; i++) {
        gHostObj.HostPacket.activeParameter[i] = 0;
        HostIO_Set_PacketData(i, 0);
    }

}

int HostIO_Get_PacketData(const HOST_IO_DATA_LABELS label) {
    switch (label) {
        case L_STATE:
        {
            return (int) gHostObj.HostPacket.laserState;
            break;
        }
        case L_POWER:
        {
            return gHostObj.HostPacket.laserPower;
            break;
        }
        case G_STATE:
        {
            return (int) gHostObj.HostPacket.galvoState;
            break;
        }
        case G_SPEED:
        {
            return gHostObj.HostPacket.gSpeed;
            break;
        }
        case X_POS:
        {
            return gHostObj.HostPacket.xPosition;
            break;
        }
        case Y_POS:
        {
            return gHostObj.HostPacket.yPosition;
            break;
        }
        case X_MEASUREMENT_0:
        {
            return gHostObj.HostPacket.x_start;
            break;
        }
        case X_MEASUREMENT_1:
        {
            return gHostObj.HostPacket.x_end;
            break;
        }
        case Y_MEASUREMENT_0:
        {
            return gHostObj.HostPacket.y_start;
            break;
        }
        case Y_MEASUREMENT_1:
        {
            return gHostObj.HostPacket.y_end;
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}

void HostIO_Set_PacketData(const HOST_IO_DATA_LABELS label, int value) {
    switch (label) {
        case L_STATE:
        {
            gHostObj.HostPacket.laserState = (HOST_IO_COMPONENT_STATES) value;
            break;
        }
        case L_POWER:
        {
            gHostObj.HostPacket.laserPower = value;
            break;
        }
        case G_STATE:
            gHostObj.HostPacket.galvoState = (HOST_IO_COMPONENT_STATES) value;
            break;
        case G_SPEED:
        {
            gHostObj.HostPacket.gSpeed = value;
            break;
        }
        case X_POS:
        {
            gHostObj.HostPacket.xPosition = value;
            break;
        }
        case Y_POS:
        {
            gHostObj.HostPacket.yPosition = value;
            break;
        }
        case X_MEASUREMENT_0:
        {
            gHostObj.HostPacket.x_start = value;
            break;
        }
        case X_MEASUREMENT_1:
        {
            gHostObj.HostPacket.x_end = value;
            break;
        }
        case Y_MEASUREMENT_0:
        {
            gHostObj.HostPacket.y_start = value;
            break;
        }
        case Y_MEASUREMENT_1:
        {
            gHostObj.HostPacket.y_end = value;
            break;
        }
        default:
            break;
    }
}

void HostIO_Add_ActiveParameter(const HOST_IO_DATA_LABELS label, int value) {
    switch (label) {
        case L_STATE:
        {
            gHostObj.HostPacket.laserState = (HOST_IO_COMPONENT_STATES) value;
            gHostObj.HostPacket.activeParameter[L_STATE] = 1;
            break;
        }
        case L_POWER:
        {
            gHostObj.HostPacket.laserPower = value;
            gHostObj.HostPacket.activeParameter[L_POWER] = 1;
            break;
        }
        case G_STATE:
        {
            gHostObj.HostPacket.galvoState = (HOST_IO_COMPONENT_STATES) value;
            gHostObj.HostPacket.activeParameter[G_STATE] = 1;
            break;
        }
        case G_SPEED:
        {
            gHostObj.HostPacket.gSpeed = value;
            gHostObj.HostPacket.activeParameter[G_SPEED] = 1;
            break;
        }
        case X_POS:
        {
            gHostObj.HostPacket.xPosition = value;
            gHostObj.HostPacket.activeParameter[X_POS] = 1;
            break;
        }
        case Y_POS:
        {
            gHostObj.HostPacket.yPosition = value;
            gHostObj.HostPacket.activeParameter[Y_POS] = 1;
            break;
        }
        case X_MEASUREMENT_0:
        {
            gHostObj.HostPacket.x_start = value;
            gHostObj.HostPacket.activeParameter[X_MEASUREMENT_0] = 1;
            break;
        }
        case X_MEASUREMENT_1:
        {
            gHostObj.HostPacket.x_end = value;
            gHostObj.HostPacket.activeParameter[X_MEASUREMENT_1] = 1;
            break;
        }
        case Y_MEASUREMENT_0:
        {
            gHostObj.HostPacket.y_start = value;
            gHostObj.HostPacket.activeParameter[Y_MEASUREMENT_0] = 1;
            break;
        }
        case Y_MEASUREMENT_1:
        {
            gHostObj.HostPacket.y_end = value;
            gHostObj.HostPacket.activeParameter[Y_MEASUREMENT_1] = 1;
            break;
        }
        default:
            break;
    }
}

bool HostIO_ParameterIsActive(const HOST_IO_DATA_LABELS label) {
    return gHostObj.HostPacket.activeParameter[label];
}

HOST_REQUEST_MODES HostIO_RequestMode(void) {
    return gHostObj.HostPacket.RequestMode;
}

void HostIO_Set_RequestMode(HOST_REQUEST_MODES hMode) {
    gHostObj.HostPacket.RequestMode = hMode;
}

CLIENT_REPLY_MODES HostIO_ReplyMode(void) {
    return gHostObj.HostPacket.ReplyMode;
}

void HostIO_Set_ReplyMode(CLIENT_REPLY_MODES rMode) {
    gHostObj.HostPacket.ReplyMode = rMode;
}

// *****************************************************************************
// *****************************************************************************
// Section: ClientIO Access Functions
// *****************************************************************************
// *****************************************************************************

void ClientIO_Clear_Packet(void) {
    gHostObj.ClientPacket.RequestMode = NO_HOST_REQUEST;
    gHostObj.ClientPacket.ReplyMode = NO_CLIENT_REPLY;
    uint8_t i;
    for (i = L_STATE; i < END_PACKET_DATA; i++) {
        gHostObj.ClientPacket.activeParameter[i] = 0;
        HostIO_Set_PacketData(i, 0);
    }
}

int ClientIO_Get_PacketData(const HOST_IO_DATA_LABELS label) {
    switch (label) {
        case L_STATE:
        {
            return (int) gHostObj.ClientPacket.laserState;
            break;
        }
        case L_POWER:
        {
            return gHostObj.ClientPacket.laserPower;
            break;
        }
        case G_STATE:
        {
            return (int) gHostObj.ClientPacket.galvoState;
            break;
        }
        case G_SPEED:
        {
            return gHostObj.ClientPacket.gSpeed;
            break;
        }
        case X_POS:
        {
            return gHostObj.ClientPacket.xPosition;
            break;
        }
        case Y_POS:
        {
            return gHostObj.ClientPacket.yPosition;
            break;
        }
        case X_MEASUREMENT_0:
        {
            return gHostObj.ClientPacket.x_start;
            break;
        }
        case X_MEASUREMENT_1:
        {
            return gHostObj.ClientPacket.x_end;
            break;
        }
        case Y_MEASUREMENT_0:
        {
            return gHostObj.ClientPacket.y_start;
            break;
        }
        case Y_MEASUREMENT_1:
        {
            return gHostObj.ClientPacket.y_end;
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}

void ClientIO_Set_PacketData(const HOST_IO_DATA_LABELS label, int value) {
    switch (label) {
        case L_STATE:
        {
            gHostObj.ClientPacket.laserState = (HOST_IO_COMPONENT_STATES) value;
            gHostObj.ClientPacket.activeParameter[L_STATE] = 1;
            break;
        }
        case L_POWER:
        {
            gHostObj.ClientPacket.laserPower = value;
            gHostObj.ClientPacket.activeParameter[L_POWER] = 1;
            break;
        }
        case G_STATE:
        {
            gHostObj.ClientPacket.galvoState = (HOST_IO_COMPONENT_STATES) value;
            gHostObj.ClientPacket.activeParameter[G_STATE] = 1;
            break;
        }
        case G_SPEED:
        {
            gHostObj.ClientPacket.gSpeed = value;
            gHostObj.ClientPacket.activeParameter[G_SPEED] = 1;
            break;
        }
        case X_POS:
        {
            gHostObj.ClientPacket.xPosition = value;
            gHostObj.ClientPacket.activeParameter[X_POS] = 1;
            break;
        }
        case Y_POS:
        {
            gHostObj.ClientPacket.yPosition = value;
            gHostObj.ClientPacket.activeParameter[Y_POS] = 1;
            break;
        }
        case X_MEASUREMENT_0:
        {
            gHostObj.ClientPacket.x_start = value;
            gHostObj.ClientPacket.activeParameter[X_MEASUREMENT_0] = 1;
            break;
        }
        case X_MEASUREMENT_1:
        {
            gHostObj.ClientPacket.x_end = value;
            gHostObj.ClientPacket.activeParameter[X_MEASUREMENT_1] = 1;
            break;
        }
        case Y_MEASUREMENT_0:
        {
            gHostObj.ClientPacket.y_start = value;
            gHostObj.ClientPacket.activeParameter[Y_MEASUREMENT_0] = 1;
            break;
        }
        case Y_MEASUREMENT_1:
        {
            gHostObj.ClientPacket.y_end = value;
            gHostObj.ClientPacket.activeParameter[Y_MEASUREMENT_1] = 1;
            break;
        }
        default:
            break;
    }
}

bool ClientIO_ParameterIsActive(const HOST_IO_DATA_LABELS label) {
    return gHostObj.ClientPacket.activeParameter[label];
}

void ClientIO_Add_ActiveParameter(const HOST_IO_DATA_LABELS label, int value) {
    switch (label) {
        case L_STATE:
        {
            gHostObj.ClientPacket.laserState = (HOST_IO_COMPONENT_STATES) value;
            gHostObj.ClientPacket.activeParameter[L_STATE] = 1;
            break;
        }
        case L_POWER:
        {
            gHostObj.ClientPacket.laserPower = value;
            gHostObj.ClientPacket.activeParameter[L_POWER] = 1;
            break;
        }
        case G_STATE:
        {
            gHostObj.ClientPacket.galvoState = (HOST_IO_COMPONENT_STATES) value;
            gHostObj.ClientPacket.activeParameter[G_STATE] = 1;
            break;
        }
        case G_SPEED:
        {
            gHostObj.ClientPacket.gSpeed = value;
            gHostObj.ClientPacket.activeParameter[G_SPEED] = 1;
            break;
        }
        case X_POS:
        {
            gHostObj.ClientPacket.xPosition = value;
            gHostObj.ClientPacket.activeParameter[X_POS] = 1;
            break;
        }
        case Y_POS:
        {
            gHostObj.ClientPacket.yPosition = value;
            gHostObj.ClientPacket.activeParameter[Y_POS] = 1;
            break;
        }
        case X_MEASUREMENT_0:
        {
            gHostObj.ClientPacket.x_start = value;
            gHostObj.ClientPacket.activeParameter[X_MEASUREMENT_0] = 1;
            break;
        }
        case X_MEASUREMENT_1:
        {
            gHostObj.ClientPacket.x_end = value;
            gHostObj.ClientPacket.activeParameter[X_MEASUREMENT_1] = 1;
            break;
        }
        case Y_MEASUREMENT_0:
        {
            gHostObj.ClientPacket.y_start = value;
            gHostObj.ClientPacket.activeParameter[Y_MEASUREMENT_0] = 1;
            break;
        }
        case Y_MEASUREMENT_1:
        {
            gHostObj.ClientPacket.y_end = value;
            gHostObj.ClientPacket.activeParameter[Y_MEASUREMENT_1] = 1;
            break;
        }
        default:
            break;
    }
}

HOST_REQUEST_MODES ClientIO_RequestMode(void) {
    return gHostObj.ClientPacket.RequestMode;
}

void ClientIO_Set_RequestMode(HOST_REQUEST_MODES hMode) {
    gHostObj.ClientPacket.RequestMode = hMode;
}

CLIENT_REPLY_MODES ClientIO_ReplyMode() {
    return gHostObj.ClientPacket.ReplyMode;
}

void ClientIO_Set_ReplyMode(CLIENT_REPLY_MODES rMode) {
    gHostObj.ClientPacket.ReplyMode = rMode;
}

// *****************************************************************************
// *****************************************************************************
// Section: HostIo Interface Functions
// *****************************************************************************
// *****************************************************************************

void HostIO_Set_State(const HOST_IO_STATES hState) {
    gHostObj.state = hState;
}

HOST_IO_STATES HostIO_State() {
    return gHostObj.state;
}

void HostIO_Add_ClientPacket_To_TxBuffer(uint8_t *usartTXbuf, uint16_t *usartTXcount, uint16_t *tx_length) {
    if (ClientIO_ReplyMode() == CLIENT_ECHO_HOST) {
        usartTXbuf[3] = 'e';
        usartTXbuf[4] = 'c';
        usartTXbuf[5] = 'h';
        usartTXbuf[6] = 'o';
        *usartTXcount = 0;
    } else if ((HostIO_RequestMode() == HOST_WRITE_BLOCK) && (ClientIO_ReplyMode() == CLIENT_SHORT_REPLY)) {
        *tx_length = 0;
        memset(usartTXbuf, 0, *usartTXcount);
        *usartTXcount = 0;
        strcpy(usartTXbuf, "\r\n@ok  \r\n\r\n");
    } else if ((ClientIO_ReplyMode() == CLIENT_LONG_REPLY)
            || (HostIO_RequestMode() == HOST_WRITE_REG) || (HostIO_RequestMode() == HOST_READ_REG)) {
        HOST_IO_DATA_LABELS parameterIndex;

        for (parameterIndex = L_STATE; parameterIndex < END_PACKET_DATA; parameterIndex++) {
            uint8_t messageValBuf[8];
            uint8_t messageStrBuf[32];
            if (ClientIO_ParameterIsActive(parameterIndex) || (ClientIO_ReplyMode() == CLIENT_LONG_REPLY)) {
                switch (parameterIndex) {
                    case L_STATE:
                    {
                        strcpy(messageStrBuf, "Laser State: ");
                        break;
                    }
                    case L_POWER:
                    {
                        strcpy(messageStrBuf, "Laser Power: ");
                        break;
                    }
                    case G_STATE:
                    {
                        strcpy(messageStrBuf, "Galvo State: ");
                        break;
                    }
                    case G_SPEED:
                    {
                        strcpy(messageStrBuf, "Galvo Speed: ");
                        break;
                    }
                    case X_POS:
                    {
                        strcpy(messageStrBuf, "Galvo X Position: ");
                        break;
                    }
                    case Y_POS:
                    {
                        strcpy(messageStrBuf, "Galvo Y Position: ");
                        break;
                    }
                    case X_MEASUREMENT_0:
                    {
                        strcpy(messageStrBuf, "Measured X Start: ");
                        break;
                    }
                    case X_MEASUREMENT_1:
                    {
                        strcpy(messageStrBuf, "Measured X End: ");
                        break;
                    }
                    case Y_MEASUREMENT_0:
                    {
                        strcpy(messageStrBuf, "Measured Y Start: ");
                        break;
                    }
                    case Y_MEASUREMENT_1:
                    {
                        strcpy(messageStrBuf, "Measured Y End: ");
                        break;
                    }
                    default:
                        break;

                }
                if (ClientIO_ParameterIsActive(parameterIndex)) {
                    const int val = ClientIO_Get_PacketData(parameterIndex);
                    itoa(messageValBuf, val, 10);
                    strcat(messageValBuf, "\r\n");
                    strcat(messageStrBuf, messageValBuf);
                } else if (ClientIO_ReplyMode() == CLIENT_LONG_REPLY) {
                    strcat(messageStrBuf, "~\r\n");
                }

                if ((strlen(usartTXbuf) + strlen(messageStrBuf)) < USART0_TX_BUFF_SIZE)
                    strcat(usartTXbuf, messageStrBuf);
            }
        }
    }
}

void HostIO_Send_ClientReply(uint8_t *usartTXbuf, uint16_t *usartTXcount, uint16_t *tx_length, HOST_IO_STATES * pState) {
    DRV_USART0_WriteByte(usartTXbuf[*usartTXcount]);
    (*usartTXcount)++;
    if (*usartTXcount >= (*tx_length - 1)) {
        HostIO_Reply_Tasks();
        *pState = PACKET_SENT;
    }
}

void HostIO_Initialize(void) {

    HOST_IO_OBJ * hObj = &gHostObj;
    hObj->usartHandle = DRV_HANDLE_INVALID;
    hObj->state = HOST_IO_IDLE;
    HostIO_Clear_Packet();
    ClientIO_Clear_Packet();
    DRV_USART_ByteReceiveCallbackSet(DRV_USART_INDEX_0,
            HostIO_USART_ReceiveEventHandler);
}

DRV_HANDLE HostIO_Open(void) {

    HOST_IO_OBJ * hObj = &gHostObj;
     bool appInitialized = true;
    static bool bootMsent = false;

    if (hObj->usartHandle == DRV_HANDLE_INVALID) {
        hObj->usartHandle =
                DRV_USART0_Open(DRV_USART_INDEX_0,
                DRV_IO_INTENT_READWRITE | DRV_IO_INTENT_NONBLOCKING);
        appInitialized &= (DRV_HANDLE_INVALID != hObj->usartHandle);
    }
    if (appInitialized ) {

          //bootMsent = HostIO_Send_BootMessage();
        
        
        return hObj->usartHandle ;
    } else
        return  DRV_HANDLE_INVALID;
}
//
//bool HostIO_Send_BootMessage() {
//    static uint8_t bootBuf[766];
//    static uint16_t bootCount = 0;
//    static uint16_t bootLength = 0;
//    if (bootLength == 0) {
//        memset(bootBuf, 0, USART0_TX_BUFF_SIZE);
//        strcpy(bootBuf, "Welcome to the Future!\r\n");
//        strcat(bootBuf, "* ~ Packet Order ~ *\r\n");
//        strcat(bootBuf, "[Cmd]+[Lcmd]+[Lpwr]+[Gcmd]+[Gspd]+[Xpos]+[Ypos]+[;]\r\n");
//        strcat(bootBuf, " * ~ [Cmd] Options ~ *\r\n");
//        strcat(bootBuf, "[$]+data[0:6] = Write ordered packet w/ verbose reply\r\n");
//        strcat(bootBuf, "[%]+data[0:6] = Write ordered packet w/ confirm only\r\n");
//        strcat(bootBuf, "[/]+[label]+[data] = Write single data\r\n");
//        strcat(bootBuf, "[?]+[label] = Read single data\r\n");
//        strcat(bootBuf, "[!] = Ping\r\n");
//        strcat(bootBuf, "[;] = End packet\r\n\r\n");
//        strcat(bootBuf, "* ~ Label Options ~ *\r\n");
//        strcat(bootBuf, "[L]|[P]|[G]|[S]|[X,x]|[Y,y]\r\n");
//        strcat(bootBuf, "Lower case indicates measurement (Read only)\r\n");
//        strcat(bootBuf, "Use [$]|[%]+[~] to skip data field\r\n");
//        strcat(bootBuf, "[+] = single space delimiter\r\n\r\n");
//        bootLength = strlen(bootBuf);
//        if (bootLength > 766)
//            bootLength = 766;
//    }
//
//    if (!DRV_USART0_TransmitBufferIsFull()) {
//        DRV_USART0_WriteByte(bootBuf[bootCount]);
//        bootCount += 1;
//    }
//    if (bootCount >= (bootLength - 1))
//        return 0;
//    else
//        return 1;
//}



void HostIO_Reply_Tasks(void) {
    static uint8_t USART0_TX_Buffer[USART0_TX_BUFF_SIZE];
    static uint16_t client_replyLength = 0;
    static uint16_t USART0_TX_Count = 0;

    HOST_IO_OBJ * hObj = &gHostObj;

    switch (hObj->state) {
        case PACKET_SEND_START:
        {
            HostIO_Add_ClientPacket_To_TxBuffer(USART0_TX_Buffer, &USART0_TX_Count, &client_replyLength);
            break;
        }
        case PACKET_SEND_PENDING:
        {
            if (!DRV_USART0_TransmitBufferIsFull())
                HostIO_Send_ClientReply(USART0_TX_Buffer, &USART0_TX_Count, &client_replyLength, &(hObj->state));
            break;
        }
        default:
            break;
    }
}



// *****************************************************************************
// *****************************************************************************
// Section: CallBack Functions
// *****************************************************************************
// *****************************************************************************

void HostIO_USART_ReceiveEventHandler(const SYS_MODULE_INDEX index) {
    static uint8_t USART0_RX_Buffer[USART0_RX_BUFF_SIZE];
    static uint8_t USART0_RX_Count = 0;

    static HOST_IO_DATA_LABELS parameterIndex;
    static HOST_IO_DATA_LABELS endParameter = END_HOST_DATA;

    const uint8_t currentByte = DRV_USART0_ReadByte();
    DRV_USART0_WriteByte(currentByte);

    if ((USART0_RX_Count < USART0_RX_BUFF_SIZE - 2)
            && (parameterIndex < endParameter)) {

        switch (HostIO_State()) {
            case PACKET_LOOK_FOR_START:
            {
                if (currentByte == '$') {
                    HostIO_Set_State(PACKET_LOOK_FOR_DATA);
                    HostIO_Set_RequestMode(HOST_WRITE_BLOCK);
                    ClientIO_Set_RequestMode(HOST_WRITE_BLOCK);
                    ClientIO_Set_ReplyMode(CLIENT_LONG_REPLY);
                    parameterIndex = L_STATE;

                } else if (currentByte == '%') {
                    HostIO_Set_State(PACKET_LOOK_FOR_DATA);
                    HostIO_Set_RequestMode(HOST_WRITE_BLOCK);
                    ClientIO_Set_RequestMode(HOST_WRITE_BLOCK);
                    ClientIO_Set_ReplyMode(CLIENT_SHORT_REPLY);
                    parameterIndex = L_STATE;

                } else if (currentByte == '/') {
                    HostIO_Set_State(PACKET_LOOK_FOR_CMD);
                    HostIO_Set_RequestMode(HOST_WRITE_REG);
                    ClientIO_Set_RequestMode(HOST_WRITE_REG);
                    ClientIO_Set_ReplyMode(CLIENT_SHORT_REPLY);
                    parameterIndex = L_STATE;

                } else if (currentByte == '?') {
                    HostIO_Set_State(HOST_READ_REG);
                    HostIO_Set_RequestMode(HOST_READ_REG);
                    ClientIO_Set_RequestMode(HOST_READ_REG);
                    ClientIO_Set_ReplyMode(CLIENT_SHORT_REPLY);
                    parameterIndex = L_STATE;

                } else if (currentByte == '!') {
                    HostIO_Set_State(PACKET_RECEIVED);
                    HostIO_Set_RequestMode(HOST_PING_CLIENT);
                    ClientIO_Set_RequestMode(HOST_PING_CLIENT);
                    ClientIO_Set_ReplyMode(CLIENT_ECHO_HOST);
                }
                break;
            } // END PACKET_LOOK_FOR_START
            case PACKET_LOOK_FOR_DATA:
            {
                if (((currentByte >= '0') && (currentByte <= '9'))
                        || ((currentByte == '-') && (USART0_RX_Count == 0))) {
                    USART0_RX_Buffer[USART0_RX_Count] = currentByte;
                    USART0_RX_Count++;
                } else if (currentByte == '~') {
                    parameterIndex++;
                    USART0_RX_Count = 0;
                } else if ((currentByte == ' ') && (USART0_RX_Count > 0)) {

                    int currentVal = stringToInt(USART0_RX_Buffer);
                    HostIO_Add_ActiveParameter(parameterIndex, currentVal);
                    parameterIndex++;
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    if (parameterIndex >= END_HOST_DATA) {
                        HostIO_Set_State(PACKET_RECEIVED);
                        memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                        USART0_RX_Count = 0;
                        parameterIndex = 0;
                    }
                } else if (currentByte == ';') {
                    if (USART0_RX_Count > 0) {
                        const int currentParameter = stringToInt(USART0_RX_Buffer);
                        HostIO_Add_ActiveParameter(parameterIndex, currentParameter);
                    }
                    HostIO_Set_State(PACKET_RECEIVED);
                    memset(USART0_RX_Buffer, 0, USART0_RX_Count);
                    USART0_RX_Count = 0;
                    parameterIndex = 0;
                }
                break;
            }
            case PACKET_LOOK_FOR_CMD:
            {
                bool validCmd = 1;
                switch (currentByte) {
                    case 'L':
                    {
                        parameterIndex = L_STATE;
                        break;
                    }
                    case 'P':
                    {
                        parameterIndex = L_POWER;
                        break;
                    }
                    case 'G':
                    {
                        parameterIndex = G_STATE;
                        break;
                    }
                    case 'S':
                    {
                        parameterIndex = G_SPEED;
                        break;
                    }
                    case 'X':
                    {
                        parameterIndex = X_POS;
                        break;
                    }
                    case 'Y':
                    {
                        parameterIndex = Y_POS;
                        break;
                    }
                    case 'x':
                    {
                        if (HostIO_RequestMode() == HOST_READ_REG)
                            parameterIndex = X_MEASUREMENT_0;
                        else
                            validCmd = 0;
                        break;
                    }
                    case 'y':
                    {
                        if (HostIO_RequestMode() == HOST_READ_REG)
                            parameterIndex = Y_MEASUREMENT_0;
                        else
                            validCmd = 0;
                        break;
                    }
                    default:
                        validCmd = 0;
                }
                if (validCmd) {
                    if (HostIO_RequestMode() == HOST_WRITE_REG) {
                        HostIO_Set_State(PACKET_LOOK_FOR_DATA);
                        endParameter = parameterIndex + 1;
                    } else if (HostIO_RequestMode() == HOST_READ_REG) {
                        HostIO_Add_ActiveParameter(parameterIndex, HOST_IO_READ_FLAG);
                        HostIO_Set_State(PACKET_RECEIVED);
                    }
                } else {
                    HostIO_Set_State(PACKET_LOOK_FOR_START);
                    USART0_RX_Count = 0;
                    parameterIndex = 0;
                }
            }
            default:
                break;
        }
    } else if ((USART0_RX_Count >= USART0_RX_BUFF_SIZE - 2)) {
        if (parameterIndex < END_HOST_DATA) {
            const int currentParameter = stringToInt(USART0_RX_Buffer);
            HostIO_Add_ActiveParameter(parameterIndex, currentParameter);
            memset(USART0_RX_Buffer, 0, USART0_RX_Count);
            USART0_RX_Count = 0;
        } else {
            HostIO_Set_State(PACKET_RECEIVED);
            memset(USART0_RX_Buffer, 0, sizeof (USART0_RX_Buffer));
            USART0_RX_Count = 0;
            parameterIndex = 0;
        }
        /* We received all the data we expected to get */
    } else if (parameterIndex >= END_HOST_DATA) {
        HostIO_Set_State(PACKET_RECEIVED);
        memset(USART0_RX_Buffer, 0, sizeof (USART0_RX_Buffer));
        USART0_RX_Count = 0;
        parameterIndex = 0;
    }
}




/* *****************************************************************************
 End of File
 */
