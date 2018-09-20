#include "widget.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    a.setWindowIcon(QIcon(":/icons/MenuIcons/cube.png"));
    w.setWindowTitle("Printing in the Future");
    return a.exec();
}
