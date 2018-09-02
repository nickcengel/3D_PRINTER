#ifndef GCODE_PARSER_H
#define GCODE_PARSER_H

#include <QObject>
#include <QRegExp>

#include "system_objects/partobject.h"
#include "system_objects/settingsobject.h"

class GCode_Parser : public QObject
{
    Q_OBJECT
public:
    explicit GCode_Parser(PartObject &part, const QString &filePath, SettingsObject &configuration, QObject *parent = nullptr);

    enum ParserStatus : uint8_t
    {
        PARSER_SUCCESS,
        PARSER_INIT,
        PARSER_READY,
        PARSER_FAILED_INVALID_CONFIGURATION,
        PARSER_FAILED_INVALID_PART,
    };
    Q_ENUM(ParserStatus)


    BlockObject parse_line(const QString &gline, BlockObject::PositionMode *positionMode, uint32_t blockN, uint32_t layerN);
    void process_partFile();

    ParserStatus status() const;
    void setStatus(const ParserStatus &status);

signals:

public slots:

private:
    ParserStatus m_status;
    PartObject *m_part;
    QVector<BlockObject> *m_blocks;
    SettingsObject *m_configuration;
};

#endif // GCODE_PARSER_H
