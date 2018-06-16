#ifndef BLOCKIO_H
#define BLOCKIO_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <qfiledialog.h>
#include <QString>
#include <QStringList>

// A "BLOCK" will represent a single line of GCODE. It serves as a intermediary data structure
// between the GCODE file and the GCODE interpreter.
// Each Block is filled by passing it a string that contains a single line from a GCODE document.
// A Block by default contains variables for holding all messages that can be sent to the machine
// from a GCODE file. A "pending" flag is used to indicate that the data of a particular variable is
// changed by the current instance of Block.

namespace BlockIO {

// Codes : lists the accepted commands:
//      M0 - PROGRAM PAUSE
//      M2 - END PROGRAM
//      M3 - TURN LASER ON
//      M5 - TURN LASER OFF
//      G0 - RAPID MOVE
//      G1 - LINEAR MOVE
//      G4 - DWELL
//      G28 - HOME AXIS
//      G90 - ABSOLUTE POSITIONING
//      G91 - RELATIVE POSITIONING
enum Code {NO_CODE, M0, M2, M3, M5, G0, G1, G4, G28, G90, G91};

enum AxisTitle{X,Y,Z,A,B};

enum AxisStatus{a,bc,d};

enum TaskMap{NONE, POS, POS_SP, HOME, REL, EN, EN_POW, POW, DWELL};

struct axis_settings_t
{

    int portNumber;
    int deviceNumber;
    AxisTitle axisTitle;
    float positionMin;
    float positionMax;
    float speedMin;
    float speedMax;
    float homeOffset;
    axis_settings_t() {}
    axis_settings_t(int portNumber_, int deviceNumber_, AxisTitle axisTitle_,
                    float positionMin_, float positionMax_, float speedMin_,
                    float speedMax_, float homeOffset_);
};

struct machine_settings_t
{
    axis_settings_t x_settings;
    axis_settings_t y_settings;
    axis_settings_t z_settings;
    axis_settings_t a_settings;
    axis_settings_t b_settings;

    machine_settings_t() {}
    machine_settings_t(axis_settings_t x_settings, axis_settings_t y_settings,
                       axis_settings_t z_settings, axis_settings_t a_settings,
                       axis_settings_t b_settings);
};

struct message_t
{
    TaskMap map;
    float data[2];

    message_t() : map(NONE), data{0,0} {}
    message_t(TaskMap aMap, float adata);
};


class Block{
public:
    Block();
    Block(const QString toParse, machine_settings_t *settings);
    void makeBlock(const QString toParse, machine_settings_t *settings);

    message_t x_axis() const;
    void set_x_axis(const message_t &x_axis);
    void set_x_axis(const TaskMap m, const float data0);
    void set_x_axis(const TaskMap m, const float data0, const float data1);

    message_t y_axis() const;
    void set_y_axis(const message_t &y_axis);
    void set_y_axis(const TaskMap m, const float data0);
    void set_y_axis(const TaskMap m, const float data0, const float data1);

    message_t z_axis() const;
    void set_z_axis(const message_t &z_axis);
    void set_z_axis(const TaskMap m, const float data0);
    void set_z_axis(const TaskMap m, const float data0, const float data1);

    message_t a_axis() const;
    void set_a_axis(const message_t &a_axis);
    void set_a_axis(const TaskMap m, const float data0);
    void set_a_axis(const TaskMap m, const float data0, const float data1);

    message_t b_axis() const;
    void set_b_axis(const message_t &b_axis);
    void set_b_axis(const TaskMap m, const float data0);
    void set_b_axis(const TaskMap m, const float data0, const float data1);

    message_t laser() const;
    void set_laser(const message_t &laser);
    void set_laser(const TaskMap m, const float data0);
    void set_laser(const TaskMap m, const float data0, const float data1);

    message_t dwell() const;
    void set_dwell(const message_t &dwell);
    void set_dwell(const TaskMap m, const float data0);
    void set_dwell(const TaskMap m, const float data0, const float data1);

    bool newLayerFlag() const;
    void setNewLayer(bool flag);

    bool isBlockValid() const;
    void setBlockValid(bool valid);

    Code code() const;
    void setCode(const Code &code);

    QString com_err() const;
    void set_com_err(const QString &com_err);

private:
    QString m_com_err;
    message_t m_x_axis;
    message_t m_y_axis;
    message_t m_z_axis;
    message_t m_a_axis;
    message_t m_b_axis;
    message_t m_laser;
    message_t m_dwell;
    Code m_code;
    bool m_newLayer;
    bool m_blockValid;
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

private:
    bool m_layerValid;
    QVector <Block> m_layer;

};


class LayerGroup
{
public:
    LayerGroup(QString fileName, machine_settings_t settings);
    void convertGcode();

    bool isGroupValid() const;
    void validateGroup();

private:
    bool m_groupValid;
    QString m_fileName;
    machine_settings_t m_settings;
    QVector <Layer> m_layerGroup;
};


}



#endif
