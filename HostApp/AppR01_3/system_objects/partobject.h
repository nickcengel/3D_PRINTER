#ifndef PARTOBJECT_H
#define PARTOBJECT_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QSharedPointer>

#include "blockobject.h"
#include "settingsobject.h"

class PartObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint32_t blockCount READ blockCount WRITE setBlockCount)
    Q_PROPERTY(uint32_t layerCount READ layerCount WRITE setLayerCount)
    Q_PROPERTY(QVector<BlockObject*> *blocks READ blocks WRITE setBlocks)
    Q_PROPERTY(PartStatus partStatus READ partStatus WRITE setPartStatus)
    Q_PROPERTY(QString partFilePath READ partFilePath WRITE setPartFilePath)
    Q_PROPERTY(ParserStatus parserStatus READ parserStatus WRITE setParserStatus)
    Q_PROPERTY(QString errorStr READ errorStr WRITE setErrorStr)

public:
    explicit PartObject(QObject *parent = nullptr);
    PartObject(const QString &filePath, QSharedPointer<SettingsObject> config, QObject *parent = nullptr);
    PartObject(const PartObject &otherPart); // copy constructor
    ~PartObject(); // destructor

    enum PartStatus : uint8_t
    {
        PART_IS_EMPTY,
        PART_IS_VALID,
        PART_IS_INVALID,
    };
    Q_ENUM(PartStatus)

    enum ParserStatus : uint8_t
    {
        PARSER_SUCCESS,
        PARSER_INIT,
        PARSER_READY,
        PARSER_FAILED_INVALID_CONFIGURATION,
        PARSER_FAILED_INVALID_PART,
    };
    Q_ENUM(ParserStatus)

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

    QVector<BlockObject *> *blocks() const;
    void setBlocks(QVector<BlockObject *> *blocks);

    ParserStatus parserStatus() const;
    void setParserStatus(const ParserStatus &parserStatus);



    QString errorStr() const;
    void setErrorStr(const QString &errorStr);

signals:

private:
    QString m_partFilePath;
    QString m_errorStr;
    QVector<BlockObject*> *m_blocks;
    uint32_t m_blockCount;
    uint32_t m_layerCount;
    PartStatus m_partStatus;
    QVector<uint32_t> m_layerFlags;
    ParserStatus m_parserStatus;

public slots:
};

Q_DECLARE_METATYPE(PartObject);


#endif // PARTOBJECT_H
