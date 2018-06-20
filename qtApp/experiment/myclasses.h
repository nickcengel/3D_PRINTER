#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <QString>
#include <QVector>
enum DeviceNumber {ALL_DEVICES, LASER_GALVO, BUILD_PLATE, HOP_SPRD, NO_DEVICE};
enum AxisNumber {ALL_AXIS, X, Y, Z, A, B, NO_AXIS};
enum Mode {MODE_ERROR, ABSOLUTE, RELATIVE, NO_MODE};
enum Message_Task {TASK_ERROR, DISABLE, ENABLE, MOVE_ABS, MOVE_REL, MOVE_ABS_AT_SPEED, MOVE_REL_AT_SPEED,
           STOP, GO_HOME, GET_STATUS, NO_TASK};
enum Status{STATUS_ERROR, ENABLED, DISABLED, IDLE, BUSY, STATUS_UNKOWN};
enum Code {CODE_ERROR, M0, M2, M3, M5, G0, G1, G4, G28, G90, G91, NO_CODE};

/// An Axis' physical and electrical constraints
struct axis_settings_t
{
    int portNumber;
    int deviceNumber;
    AxisNumber axisTitle;
    float positionMin;
    float positionMax;
    float speedMin;
    float speedMax;
    float homeOffset;
    axis_settings_t() {}
    axis_settings_t(int aPortNumber, int aDeviceNumber, AxisNumber anAxisTitle,
                    float aPositionMin, float aPositionMax, float aSpeedMin,
                    float aSpeedMax, float aHomeOffset){
        portNumber = aPortNumber;
        deviceNumber = aDeviceNumber;
        axisTitle = anAxisTitle;
        positionMin = aPositionMin;
        positionMax = aPositionMax;
        speedMin = aSpeedMin;
        speedMax = aSpeedMax;
        homeOffset = aHomeOffset;
    }
};

/// A group of axis settings with other machine parameters
struct machine_settings_t
{
    axis_settings_t x_settings;
    axis_settings_t y_settings;
    axis_settings_t z_settings;
    axis_settings_t a_settings;
    axis_settings_t b_settings;

    machine_settings_t() {}
    machine_settings_t(axis_settings_t X_settings, axis_settings_t Y_settings,
                       axis_settings_t Z_settings, axis_settings_t A_settings,
                       axis_settings_t B_settings){
        x_settings = X_settings;
        y_settings = Y_settings;
        z_settings = Z_settings;
        a_settings = A_settings;
        b_settings = B_settings;
    }
};


enum DeviceNumber {ALL_DEVICES, LASER_GALVO, BUILD_PLATE, HOP_SPRD, NO_DEVICE};
enum AxisNumber {ALL_AXIS, X, Y, Z, A, B, NO_AXIS};
enum Mode {MODE_ERROR, ABSOLUTE, RELATIVE, NO_MODE};
enum Message_Task {TASK_ERROR, DISABLE, ENABLE, MOVE_ABS, MOVE_REL, MOVE_ABS_AT_SPEED, MOVE_REL_AT_SPEED,
           STOP, GO_HOME, GET_STATUS, NO_TASK};
enum Status{STATUS_ERROR, ENABLED, DISABLED, IDLE, BUSY, STATUS_UNKOWN};
class Message
{

public:

    Message();
    Message(const DeviceNumber dn, const AxisNumber an);

    DeviceNumber getDeviceNumber() const;
    void setDeviceNumber(const DeviceNumber &deviceNumber);

    AxisNumber axisNumber() const;
    void setAxisNumber(const AxisNumber &number);

    Mode getMode() const;
    void setMode(const Mode &mode);

    Message_Task getTask() const;
    void setTask(const Message_Task &task);

    Status getStatus() const;
    void setStatus(const Status &status);

    float getPosition_mm() const;
    void setPosition_mm(float position_mm);

    int getPosition_ms() const;
    void setPosition_ms(int position_ms);

    int getSpeed() const;
    void setSpeed(int speed);

    int getPower() const;
    void setPower(int power);

    QString getMessage_string() const;
    void setMessage_string(const QString &message_string);

private:
    DeviceNumber m_deviceNumber;
    AxisNumber m_axisNumber;
    Mode m_mode;
    Message_Task m_task;
    Status m_status;

    QString m_message_string;

    float m_position_mm;
    int m_position_ms;
    int m_speed;
    int m_power;
};

class Block
{
public:
    Block();
    Block(QString toParse, Mode &previousMode, machine_settings_t *settings);

    Message *L_Axis();
    Message *X_Axis();
    Message *Y_Axis();
    Message *Z_Axis();
    Message *A_Axis();
    Message *B_Axis();

    float getDwell() const;
    void setDwell(float dwell);

    Code getCode() const;
    void setCode(const Code &code);

    QString getComments() const;
    void setComments(const QString &comments);

    QString getErrors() const;
    void setErrors(const QString &errors);

    bool isNewLayer() const;
    void setNewLayer(bool newLayer);

    bool isBlockValid() const;
    void setBlockValid(bool blockValid);

    Mode getPreviousMode() const;
    void setPreviousMode(const Mode &previousMode);

private:
    Message m_L_Axis;
    Message m_X_Axis;
    Message m_Y_Axis;
    Message m_Z_Axis;
    Message m_A_Axis;
    Message m_B_Axis;

    float m_dwell;

    Code m_code;

    Mode m_previousMode;

    QString m_comments;
    QString m_errors;

    bool m_newLayer;
    int m_layerNumber;
    int m_blockNumber;
    bool m_blockValid;

    void makeBlock(const QString toParse, Mode previousMode, machine_settings_t *settings);
};

class Layer
{
public:
    Layer();
    Layer(QVector <Block> someBlocks);

    QVector<Block> get() const;
    Block getBlock(int blockNumber) const;

    void addBlock(Block aBlock);
    bool isLayerValid() const;
    void setLayerValid(bool layerValid);
    bool validateLayer();
    void clearLayer();

private:
    bool m_layerValid;
    QVector <Block> m_layer;

};
























#endif // MYCLASSES_H
