#ifndef BLOCKCONTROLLER_H
#define BLOCKCONTROLLER_H

#include <QObject>

class BlockController : public QObject
{
    Q_OBJECT
public:
    explicit BlockController(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BLOCKCONTROLLER_H