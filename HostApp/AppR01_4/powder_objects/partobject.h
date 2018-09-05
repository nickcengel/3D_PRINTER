#ifndef PARTOBJECT_H
#define PARTOBJECT_H

#include <QVector>
#include <QString>

#include "blockobject.h"
#include "settingsobject.h"

class PartObject
{
public:
    explicit PartObject();
    PartObject(const QString &filePath, SettingsObject *config);
    PartObject(const PartObject &otherPart); // copy constructor
    ~PartObject(); // destructor

    enum PartStatus : uint8_t
    {
        PART_IS_EMPTY,
        PART_IS_VALID,
        PART_IS_INVALID,
    };

    enum ParserStatus : uint8_t
    {
        PARSER_SUCCESS,
        PARSER_INIT,
        PARSER_READY,
        PARSER_FAILED_INVALID_CONFIGURATION,
        PARSER_FAILED_INVALID_PART,
    };

    uint32_t blockCount() const;
    void setBlockCount(const uint32_t &blockCount);

    uint32_t layerCount() const;
    void setLayerCount(const uint32_t &layerCount);

    PartStatus partStatus() const;
    void setPartStatus(const PartStatus &partStatus);

    QString partFilePath() const;
    void setPartFilePath(const QString &partFilePath);

    QVector<uint32_t> layerFlags() const;
    void setLayerFlags(const QVector<uint32_t> &layerFlags);

    void addBlock(BlockObject *block);

    QVector<BlockObject *> blocks() const;
    void setBlocks(QVector<BlockObject *> blocks);

    ParserStatus parserStatus() const;
    void setParserStatus(const ParserStatus &parserStatus);



    QString errorStr() const;
    void setErrorStr(const QString &errorStr);

    QStringList gcode() const;
    void setGcode(const QStringList &gcode);

//    QStringList laserGalvo_commands() const;
//    void setLaserGalvo_commands(const QStringList &laserGalvo_commands);

//    QStringList materialDelivery_commands() const;
//    void setMaterialDelivery_commands(const QStringList &materialDelivery_commands);

    BlockObject *getBlock(int blockNum);

    void clearPart();

private:
    QString m_partFilePath;
    QString m_errorStr;
    QStringList m_gcode;
//    QStringList m_laserGalvo_commands;
//    QStringList m_materialDelivery_commands;

    QVector<BlockObject*> m_blocks;
    uint32_t m_blockCount;
    uint32_t m_layerCount;
    PartStatus m_partStatus;
    QVector<uint32_t> m_layerFlags;
    ParserStatus m_parserStatus;

};

Q_DECLARE_METATYPE(PartObject);


#endif // PARTOBJECT_H
