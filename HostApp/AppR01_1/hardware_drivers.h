#ifndef HARDWARE_DRIVERS_H
#define HARDWARE_DRIVERS_H
#include "QString"

namespace HARDWARE_NS{
enum AXIS_NUMBER : uint8_t {ALL_AXIS, X, Y, Z, A, B, L, NO_AXIS};
enum DEVICE_NUMBER : uint8_t{
    ALL_DEVICES,
    LASER_GALVO,
    BUILD_PLATE,
    HOP_SPRD,
    NO_DEVICE};

struct axis_settings_t
{
    uint8_t portNumber;
    uint8_t deviceNumber;
    uint8_t axisNumber;
    float positionMin;
    float positionMax;
    float speedMin;
    float speedMax;
    float homeOffset;
    float uStepPerMM;
    axis_settings_t() {}
    axis_settings_t(uint8_t aPortNumber, uint8_t aDeviceNumber, uint8_t anAxisNumber,
                    float aPositionMin, float aPositionMax, float aSpeedMin,
                    float aSpeedMax, float aHomeOffset, float microStepsPerMM){
        portNumber = aPortNumber;
        deviceNumber = aDeviceNumber;
        axisNumber = anAxisNumber;
        positionMin = aPositionMin;
        positionMax = aPositionMax;
        speedMin = aSpeedMin;
        speedMax = aSpeedMax;
        homeOffset = aHomeOffset;
        uStepPerMM = microStepsPerMM;
    }
};

struct machine_settings_t
{
    axis_settings_t l_settings;
    axis_settings_t x_settings;
    axis_settings_t y_settings;
    axis_settings_t z_settings;
    axis_settings_t a_settings;
    axis_settings_t b_settings;

    machine_settings_t() {}
    machine_settings_t(axis_settings_t L_settings, axis_settings_t X_settings, axis_settings_t Y_settings,
                       axis_settings_t Z_settings, axis_settings_t A_settings,
                       axis_settings_t B_settings){
        l_settings = L_settings;
        x_settings = X_settings;
        y_settings = Y_settings;
        z_settings = Z_settings;
        a_settings = A_settings;
        b_settings = B_settings;
    }
};

enum POSITION_MODE : uint8_t {RELATIVE, ABSOLUTE};

namespace ZABER {

enum ZABR_REPLY_STATUS : uint8_t {
    IDLE,
    BUSY,
    NO_STATUS};

enum ZABR_CMD_TYPE : uint8_t {
    TYPE_ERROR,
    M_INFO,       //  #
    M_ALERT,      //  !
    M_COMMAND,    //  /
    M_REPLY,      //  @
    NO_TYPE};

enum ZABR_REPLY_FLAG : uint8_t {
    FLAG_ERROR,
    OK,
    REJECTED,
    DID_NOT_FIND_END,
    NO_FLAG};

enum ZABR_REPLY_FLAG_DATA : uint8_t {
    FLAG_DATA_ERROR,
    AGAIN,
    BAD_AXIS,
    BAD_COMMAND,
    BAD_DATA,
    BAD_MESSAGE_ID,
    DEVICE_ONLY,
    NO_ACCESS,
    PARKED,
    STATUS_BUSY,
    NO_FLAG_DATA};

enum ZABR_REPLY_WARNING : uint8_t {
    WARNING_FLAG_ERROR,
    DRIVER_DISABLED,
    ENCODER_ERROR,
    STALLED,
    LIMIT_ERROR,
    NOT_HOMED,
    UNEXPECTED_LIMIT_TRIG,
    INVALID_CALIBRATION,
    VOLTAGE_ERROR,
    TEMPERATURE_ERROR,
    UNEXPECTED_DISPLACEMENT,
    NO_REFERENCE_POSITION,
    BUSY_WITH_MANUAL_CONTRL,
    COMMAND_INTERRUPTED,
    UPDATE_OR_RESET_PENDING,
    NO_WARNING_FLAG};
}

enum MD_TASKS : uint8_t {
    CHANGE_MD_CMD_TYPE = 0x1,
    CHANGE_MD_POSITION_MODE = 0x2,
    CHANGE_MD_SPEED = 0x4,
    CHANGE_MD_POSITION = 0x8,
    CHANGE_MD_ENABLED = 0x10,
    CHANGE_MD_STOPPED = 0x20,
    DO_MD_GO_HOME = 0x40
};

enum  LG_TASKS : uint16_t {
    CHANGE_LG_CMD_TYPE = 0x1,
    CHANGE_LG_POSITION_MODE = 0x2,
    CHANGE_LG_SPEED = 0x4,
    CHANGE_LG_X_POSITION = 0x8,
    DO_LG_X_GO_HOME = 0x10,
    CHANGE_LG_Y_POSITION = 0x20,
    DO_LG_Y_GO_HOME = 0x40,
    CHANGE_LASER_ARMED = 0x80,
    CHANGE_LASER_ENABLED = 0x100,
    CHANGE_LASER_POWER = 0x200,
};


class Axis
{
public:
    uint8_t get_axisNumber();
    void set_axisNumber(uint8_t n);
    float get_position();
    bool is_homed();
    void set_homed(bool h);
    void clear_go_home();
    float get_uStepPerMM();
    void set_uStepPerMM(float k);
    float position;

private:
    uint8_t axisNumber;
    float uStepPerMM;
    bool homed;
    bool go_home;
};

class Laser
{
public:
    bool is_armed();
    bool is_enabled();
    float get_power();
    uint8_t get_axisNumber();
    void set_axisNumber(uint8_t n);
    bool armed;
    bool enabled;
    float power;
private:
    uint8_t axisNumber;
};

class Device
{
public:
    uint8_t get_deviceNumber();
    void set_deviceNumber(uint8_t n);
    bool is_deviceActive();
    void activate_device();
    void deactivate_device();
    POSITION_MODE get_positionMode();
    QString get_deviceString();
    void set_deviceString(QString s);
protected:
    POSITION_MODE positionMode;
private:
    uint8_t deviceNumber;
    bool deviceActive;

    QString deviceString;
};

class Material_Delivery_Device : public Device, public Axis
{
public:
    Material_Delivery_Device();
    uint8_t task;
    void set_positionMode(POSITION_MODE m);
    void set_position(float p);
    void set_speed(float v);
    void go_home();
    float get_speed();
    void make_commandString();
    bool is_enabled();
    void set_enable_disable(bool e);
    bool is_stopped();
    void set_clear_stop(bool s);
private:
    bool enabled;
    bool stopped;
    float speed;
};

class Laser_Galvo_Device : public Device
{
public:
    Laser_Galvo_Device();
    void set_positionMode(POSITION_MODE m);
    void set_x_position(float x);
    void x_go_home();
    void y_go_home();
    void set_y_position(float y);
    void set_speed(float v);
    void set_arm_disarm(bool a);
    void set_enable_disable(bool e);
    void set_power(float p);
    void make_commandString();
    uint16_t task;
    Axis x_axis;
    Axis y_axis;
    float get_speed();
    Laser laser;
private:
    float speed;
};


}



#endif // HARDWARE_DRIVERS

