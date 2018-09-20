//#ifndef PRINT_TOOLS_H
//#define PRINT_TOOLS_H

//#include <QObject>
//#include "hardware_drivers.h"
//#include "gcode_tools.h"

//using namespace GCODE_BLOCK_NS;

//namespace PRINT_CONTROL_NS {


//class Printer_State
//{

//public:
//    Printer_State();
//    Laser_Galvo_Device *laser_galvo();
//    Material_Delivery_Device *plate();
//    Material_Delivery_Device *hopper();
//    Material_Delivery_Device *spreader();



//private:
//    Laser_Galvo_Device m_laser_galvo;
//    Material_Delivery_Device m_plate;
//    Material_Delivery_Device m_hopper;
//    Material_Delivery_Device m_spreader;
//};

//enum PRINT_CONTROLLER_STATES : uint8_t
//{
//    NO_PART,
//    PART_LOADED,
//    PRINT_INITIALIZE,
//    PRINT_READY,

//    PRINT_SEND_BLOCK,
//    PRINT_WAIT_FOR_REPLY,
//    PRINT_BLOCK_COMPLETE,
//    PRINT_GET_NEXT_BLOCK,

//    PRINT_LAYER_COMPLETE,
//    PRINT_GET_NEXT_LAYER,
//    PRINT_COMPLETE,

//    PRINT_PAUSED,
//    PRINT_RESUME,
//    PRINT_STOPPED,

//    PRINT_DEINITIALIZE
//};


//class Print_System_Controller : public QObject
//{
//    Q_OBJECT
//public:
//    explicit Print_System_Controller(QObject *parent = nullptr);
//    Block *pendingBlock;
//    Layer *currentLayer;
//    Part *currentPart;


//    void Run_Print_Routine();
//    void send_block();

//signals:
//    void Laser_Galvo_Command(QString cs);
//    void Material_Delivery_Command(QString cs);


//public slots:
//    void Laser_Galvo_Socket(QString rs);
//    void Material_Delivery_Socket(QString rs);

//    void Controller_Load_Part_Slot(Part &p);

//    void Controller_Start_Slot();
//    //    void Controller_Stop_Slot();
//    //    void Controller_Pause_Slot();
//    //    void Controller_Resume_Slot();


//private:
//    bool lg_pending;
//    bool md_pending;
//    int L_blockNumber;
//    int L_blockMax;
//    int current_layerNumber;
//    int total_layers;
//    int current_blockNumber;
//    int total_blocks;
//    bool paused;
//    bool resume;
//    Printer_State printerState;
//    PRINT_CONTROLLER_STATES controllerState;
//    PRINT_CONTROLLER_STATES previous_controllerState;
//};

//}

//#endif // PRINT_TOOLS_H




