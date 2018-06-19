#ifndef MYOB_H
#define MYOB_H

#include <QObject>

class myob : public QObject
{
    Q_OBJECT
public:
    explicit myob(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYOB_H