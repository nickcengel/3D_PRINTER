#include "partobject.h"

PartObject::PartObject(QObject *parent) : QObject(parent)
{

}

PartObject::PartObject(const PartObject &otherPart)
{
    m_blockCount = otherPart.blockCount();
    m_layerCount = otherPart.layerCount();
    m_layerFlags = otherPart.layerFlags();
    m_blocks = otherPart.blocks();
    m_partFilePath = otherPart.partFilePath();
    m_partStatus = otherPart.partStatus();
}

PartObject::~PartObject()
{

}

uint32_t PartObject::blockCount() const
{
    return m_blockCount;
}

void PartObject::setBlockCount(const uint32_t &blockCount)
{
    m_blockCount = blockCount;
}

uint32_t PartObject::layerCount() const
{
    return m_layerCount;
}

void PartObject::setLayerCount(const uint32_t &layerCount)
{
    m_layerCount = layerCount;
}



PartObject::PartStatus PartObject::partStatus() const
{
    return m_partStatus;
}

void PartObject::setPartStatus(const PartStatus &partStatus)
{
    m_partStatus = partStatus;
}

QString PartObject::partFilePath() const
{
    return m_partFilePath;
}

void PartObject::setPartFilePath(const QString &partFilePath)
{
    m_partFilePath = partFilePath;
}


QVector<uint32_t> PartObject::layerFlags() const
{
    return m_layerFlags;
}

void PartObject::setLayerFlags(const QVector<uint32_t> &layerFlags)
{
    m_layerFlags = layerFlags;
}

QVector<BlockObject> PartObject::blocks() const
{
    return m_blocks;
}

void PartObject::setBlocks(const QVector<BlockObject> &blocks)
{
    m_blocks = blocks;
}


