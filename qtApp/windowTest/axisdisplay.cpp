#include "axisdisplay.h"
#include "ui_axisdisplay.h"

AxisDisplay::AxisDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AxisDisplay)
{
    ui->setupUi(this);
    currentPosition = 0;
    axis = 'X';
    this->setPosition(currentPosition);
    this->setAxisLabel(axis);
    jogDistance = ui->jogSizeInput->text().toFloat();
    state = 0;
}

AxisDisplay::~AxisDisplay()
{
    delete ui;
}

void AxisDisplay::enableControls(bool status_){
    ui->incPosButton->setEnabled(status_);
    ui->decPosButton->setEnabled(status_);
    ui->homeButton->setEnabled(status_);
    ui->positionLabel->setEnabled(status_);
    ui->jogSizeInput->setEnabled(status_);
    ui->axisLabel->setEnabled(status_);
    ui->unitLabel->setEnabled(status_);
    ui->jogLabel->setEnabled(status_);
}

void AxisDisplay::setPosition(float value){
    currentPosition = value;
    QString b = QString::number(currentPosition);
    ui->positionLabel->setText(b);
}

void AxisDisplay::setAxisLabel(char axis_){
    axis = axis_;
    QString b = QString(QChar::fromLatin1(axis_));
    ui->axisLabel->setText(b);
}

void AxisDisplay::setEnabled(bool state_){
    state = state_;
    ui->enableButton->setChecked(state);
    enableControls(state);

}

void AxisDisplay::on_enableButton_clicked()
{
    emit enableButtonPressed(ui->enableButton->isChecked());

}

void AxisDisplay::on_jogSizeInput_returnPressed()
{
    jogDistance = ui->jogSizeInput->text().toFloat();
    emit jogDistanceChanged(jogDistance);
}

void AxisDisplay::on_incPosButton_clicked()
{
    emit incPosition(jogDistance);
}


void AxisDisplay::on_decPosButton_clicked()
{
    emit incPosition(-jogDistance);
}

void AxisDisplay::on_homeButton_clicked()
{
    emit homing(true);
}
