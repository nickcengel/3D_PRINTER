#include <QtWidgets>

#include "settings_item.h"
#include "settings_model.h"

Settings_Model::Settings_Model(const QStringList &headers, const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QVector<QVariant> rootData;
    foreach (QString header, headers)
        rootData << header;

    rootItem = new Settings_Item(rootData);
    setupModelData(data.split(QString("\n")), rootItem);
}

Settings_Model::~Settings_Model()
{
    delete rootItem;
}

int Settings_Model::columnCount(const QModelIndex & /* parent */) const
{
    return rootItem->columnCount();
}

QVariant Settings_Model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    Settings_Item *item = getItem(index);

    return item->data(index.column());
}

Qt::ItemFlags Settings_Model::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return nullptr;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

Settings_Item *Settings_Model::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        Settings_Item *item = static_cast<Settings_Item*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

QVariant Settings_Model::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex Settings_Model::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    Settings_Item *parentItem = getItem(parent);

    Settings_Item *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

bool Settings_Model::insertColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginInsertColumns(parent, position, position + columns - 1);
    success = rootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool Settings_Model::insertRows(int position, int rows, const QModelIndex &parent)
{
    Settings_Item *parentItem = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
    endInsertRows();

    return success;
}

QModelIndex Settings_Model::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    Settings_Item *childItem = getItem(index);
    Settings_Item *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}

bool Settings_Model::removeColumns(int position, int columns, const QModelIndex &parent)
{
    bool success;

    beginRemoveColumns(parent, position, position + columns - 1);
    success = rootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (rootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}

bool Settings_Model::removeRows(int position, int rows, const QModelIndex &parent)
{
    Settings_Item *parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

int Settings_Model::rowCount(const QModelIndex &parent) const
{
    Settings_Item *parentItem = getItem(parent);

    return parentItem->childCount();
}

bool Settings_Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    Settings_Item *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index);

    return result;
}


bool Settings_Model::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

void Settings_Model::setupModelData(const QStringList &lines, Settings_Item *parent)
{
    QList<Settings_Item*> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].at(position) != ' ')
                break;
            ++position;
        }

        QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
            QVector<QVariant> columnData;
            for (int column = 0; column < columnStrings.count(); ++column)
                columnData << columnStrings[column];

            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

            // Append a new item to the current parent's list of children.
            Settings_Item *parent = parents.last();
            parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
            for (int column = 0; column < columnData.size(); ++column){
                parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
            }
        }

        ++number;
    }
}


