#include "dialog.h"
#include "ui_dialog.h"
#include <qlineedit.h>
#include <qpushbutton.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
QString G = "khjekhfkl";
    this->ui->label->setText(G);

}
