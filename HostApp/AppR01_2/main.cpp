#include "widget.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/MenuIcons/cube.png"));
    Widget w;


//    w.setWindowTitle("Printing in the Future");
    w.show();
    return a.exec();
}
