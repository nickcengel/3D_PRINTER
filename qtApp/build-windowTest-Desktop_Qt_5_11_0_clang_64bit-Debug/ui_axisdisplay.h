/********************************************************************************
** Form generated from reading UI file 'axisdisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXISDISPLAY_H
#define UI_AXISDISPLAY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AxisDisplay
{
public:
    QFrame *frame;
    QLabel *positionLabel;
    QLabel *unitLabel;
    QLabel *axisLabel;
    QPushButton *incPosButton;
    QPushButton *decPosButton;
    QPushButton *homeButton;
    QLineEdit *jogSizeInput;
    QRadioButton *enableButton;
    QLabel *jogLabel;

    void setupUi(QWidget *AxisDisplay)
    {
        if (AxisDisplay->objectName().isEmpty())
            AxisDisplay->setObjectName(QStringLiteral("AxisDisplay"));
        AxisDisplay->resize(730, 131);
        frame = new QFrame(AxisDisplay);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 711, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        positionLabel = new QLabel(frame);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setGeometry(QRect(320, 10, 381, 91));
        QFont font;
        font.setFamily(QStringLiteral(".SF NS Text Condensed"));
        font.setPointSize(100);
        positionLabel->setFont(font);
        positionLabel->setFrameShape(QFrame::StyledPanel);
        unitLabel = new QLabel(frame);
        unitLabel->setObjectName(QStringLiteral("unitLabel"));
        unitLabel->setGeometry(QRect(650, 60, 41, 41));
        QFont font1;
        font1.setFamily(QStringLiteral(".SF NS Text Condensed"));
        font1.setPointSize(24);
        unitLabel->setFont(font1);
        unitLabel->setFrameShape(QFrame::NoFrame);
        unitLabel->setAlignment(Qt::AlignCenter);
        axisLabel = new QLabel(frame);
        axisLabel->setObjectName(QStringLiteral("axisLabel"));
        axisLabel->setGeometry(QRect(210, 10, 101, 91));
        axisLabel->setFont(font);
        axisLabel->setFrameShape(QFrame::StyledPanel);
        axisLabel->setAlignment(Qt::AlignCenter);
        incPosButton = new QPushButton(frame);
        incPosButton->setObjectName(QStringLiteral("incPosButton"));
        incPosButton->setGeometry(QRect(140, 0, 61, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/arrowUp.svg"), QSize(), QIcon::Normal, QIcon::Off);
        incPosButton->setIcon(icon);
        incPosButton->setIconSize(QSize(48, 48));
        incPosButton->setFlat(true);
        decPosButton = new QPushButton(frame);
        decPosButton->setObjectName(QStringLiteral("decPosButton"));
        decPosButton->setGeometry(QRect(140, 50, 61, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/arrowDown.svg"), QSize(), QIcon::Normal, QIcon::Off);
        decPosButton->setIcon(icon1);
        decPosButton->setIconSize(QSize(48, 48));
        decPosButton->setFlat(true);
        homeButton = new QPushButton(frame);
        homeButton->setObjectName(QStringLiteral("homeButton"));
        homeButton->setGeometry(QRect(80, 0, 71, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Home.svg"), QSize(), QIcon::Normal, QIcon::Off);
        homeButton->setIcon(icon2);
        homeButton->setIconSize(QSize(48, 48));
        homeButton->setFlat(true);
        jogSizeInput = new QLineEdit(frame);
        jogSizeInput->setObjectName(QStringLiteral("jogSizeInput"));
        jogSizeInput->setGeometry(QRect(70, 70, 61, 21));
        jogSizeInput->setFocusPolicy(Qt::ClickFocus);
        jogSizeInput->setAlignment(Qt::AlignCenter);
        enableButton = new QRadioButton(frame);
        enableButton->setObjectName(QStringLiteral("enableButton"));
        enableButton->setGeometry(QRect(10, 10, 71, 41));
        QFont font2;
        font2.setFamily(QStringLiteral(".SF NS Text Condensed"));
        font2.setBold(true);
        font2.setWeight(75);
        enableButton->setFont(font2);
        enableButton->setIconSize(QSize(25, 25));
        enableButton->setChecked(false);
        jogLabel = new QLabel(frame);
        jogLabel->setObjectName(QStringLiteral("jogLabel"));
        jogLabel->setGeometry(QRect(10, 60, 61, 41));
        jogLabel->setFont(font2);
        jogLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        jogLabel->setWordWrap(true);

        retranslateUi(AxisDisplay);

        QMetaObject::connectSlotsByName(AxisDisplay);
    } // setupUi

    void retranslateUi(QWidget *AxisDisplay)
    {
        AxisDisplay->setWindowTitle(QApplication::translate("AxisDisplay", "AxisDisplay", nullptr));
        positionLabel->setText(QApplication::translate("AxisDisplay", "12.345", nullptr));
        unitLabel->setText(QApplication::translate("AxisDisplay", "mm", nullptr));
        axisLabel->setText(QApplication::translate("AxisDisplay", "X", nullptr));
        incPosButton->setText(QString());
        decPosButton->setText(QString());
        homeButton->setText(QString());
        jogSizeInput->setText(QApplication::translate("AxisDisplay", "1", nullptr));
        enableButton->setText(QApplication::translate("AxisDisplay", "Enabled", nullptr));
        jogLabel->setText(QApplication::translate("AxisDisplay", "Jog Size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AxisDisplay: public Ui_AxisDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXISDISPLAY_H
