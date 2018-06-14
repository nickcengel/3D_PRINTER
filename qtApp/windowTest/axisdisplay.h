#ifndef AXISDISPLAY_H
#define AXISDISPLAY_H

#include <QWidget>

namespace Ui {
class AxisDisplay;
}

class AxisDisplay : public QWidget
{
    Q_OBJECT

    public
       slots:
          void setPosition(float value);
          void setAxisLabel(char axis_);
          void setEnabled(bool state);

      signals:
          void enableButtonPressed(bool state_);
          void jogDistanceChanged(float dist);
          void incPosition(float jog);
          void decPosition(float jog);
          void homing(bool isHoming);

  private slots:
          void on_enableButton_clicked();
          void on_jogSizeInput_returnPressed();
          void on_incPosButton_clicked();
          void on_decPosButton_clicked();
          void on_homeButton_clicked();

public:
    explicit AxisDisplay(QWidget *parent = 0);
    void enableControls(bool status_);

    ~AxisDisplay();

private:
    Ui::AxisDisplay *ui;
    bool state;
    float currentPosition;
    char axis;
    float jogDistance;
};

#endif // AXISDISPLAY_H
