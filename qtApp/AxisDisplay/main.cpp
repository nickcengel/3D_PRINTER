#include "axisdisplay.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AxisDisplay w;
    w.setEnabled(true);
    w.show();

    return a.exec();
}
