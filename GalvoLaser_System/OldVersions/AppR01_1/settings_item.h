#ifndef SETTINGS_ITEM_H
#define SETTINGS_ITEM_H

#include <QList>
#include <QVariant>
#include <QVector>


class Settings_Item
{
public:
    explicit Settings_Item(const QVector<QVariant> &data, Settings_Item *parent = nullptr);
    ~Settings_Item();

    Settings_Item *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    Settings_Item *parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);

private:
    QList<Settings_Item*> childItems;
    QVector<QVariant> itemData;
    Settings_Item *parentItem;
};

#endif // SETTINGS_ITEM_H
