#include "settings_item.h"
#include <QStringList>

Settings_Item::Settings_Item(const QVector<QVariant> &data, Settings_Item *parent)
{
    parentItem = parent;
    itemData = data;
}

Settings_Item::~Settings_Item()
{
    qDeleteAll(childItems);
}

Settings_Item *Settings_Item::child(int number)
{
    return childItems.value(number);
}

int Settings_Item::childCount() const
{
    return childItems.count();
}

int Settings_Item::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<Settings_Item*>(this));

    return 0;
}

int Settings_Item::columnCount() const
{
    return itemData.count();
}

QVariant Settings_Item::data(int column) const
{
    return itemData.value(column);
}

bool Settings_Item::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QVector<QVariant> data(columns);
        Settings_Item *item = new Settings_Item(data, this);
        childItems.insert(position, item);
    }

    return true;
}

bool Settings_Item::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    foreach (Settings_Item *child, childItems)
        child->insertColumns(position, columns);

    return true;
}

Settings_Item *Settings_Item::parent()
{
    return parentItem;
}

bool Settings_Item::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}

bool Settings_Item::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    foreach (Settings_Item *child, childItems)
        child->removeColumns(position, columns);

    return true;
}

bool Settings_Item::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}
