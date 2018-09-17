#ifndef PARTOBJECT_H
#define PARTOBJECT_H

#include <QVector>
#include <QString>

#include "blockobject.h"
#include "settingsobject.h"
#include "QSharedPointer"

class PartObject
{
public:
    explicit PartObject();
    PartObject(const QString &filePath,  QSharedPointer<SettingsObject> config);
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

    int blockCount() const;
    void setBlockCount(const int &blockCount);

    int layerCount() const;
    void setLayerCount(const int &layerCount);

    PartStatus partStatus() const;
    void setPartStatus(const PartStatus &partStatus);

    QString partFilePath() const;
    void setPartFilePath(const QString &partFilePath);

    QVector<int> layerFlags() const;
    void setLayerFlags(const QVector<int> &layerFlags);

    void addBlock(const BlockObject &block);



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

    BlockObject getBlock(const int blockNum) const;

    void clearPart();

    QSharedPointer<QVector<BlockObject> > getBlocks() const;
    void setBlocks(const QSharedPointer<QVector<BlockObject> > &blocks);

private:
    QString m_partFilePath;
    QString m_errorStr;
    QStringList m_gcode;

    QSharedPointer<QVector<BlockObject>> m_blocks;
    int m_blockCount;
    int m_layerCount;
    PartStatus m_partStatus;
    QVector<int> m_layerFlags;
    ParserStatus m_parserStatus;

};

Q_DECLARE_METATYPE(PartObject);


#endif // PARTOBJECT_H
