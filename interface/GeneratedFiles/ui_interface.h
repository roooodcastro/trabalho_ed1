/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created: Thu 28. Apr 08:30:56 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayoutExpression;
    QLabel *labelValidation;
    QLineEdit *lineEditExpression;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *pushButtonConvert;
    QPushButton *pushButtonEvaluate;
    QHBoxLayout *horizontalLayout;
    QLabel *labelResult;
    QLineEdit *lineEditResult;

    void setupUi(QWidget *InterfaceClass)
    {
        if (InterfaceClass->objectName().isEmpty())
            InterfaceClass->setObjectName(QString::fromUtf8("InterfaceClass"));
        InterfaceClass->resize(360, 120);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InterfaceClass->sizePolicy().hasHeightForWidth());
        InterfaceClass->setSizePolicy(sizePolicy);
        InterfaceClass->setMinimumSize(QSize(360, 120));
        InterfaceClass->setMaximumSize(QSize(360, 120));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        InterfaceClass->setFont(font);
        gridLayout = new QGridLayout(InterfaceClass);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayoutExpression = new QVBoxLayout();
        verticalLayoutExpression->setSpacing(1);
        verticalLayoutExpression->setObjectName(QString::fromUtf8("verticalLayoutExpression"));
        verticalLayoutExpression->setSizeConstraint(QLayout::SetMinimumSize);
        labelValidation = new QLabel(InterfaceClass);
        labelValidation->setObjectName(QString::fromUtf8("labelValidation"));
        labelValidation->setMaximumSize(QSize(16777215, 18));
        QFont font1;
        font1.setPointSize(10);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        labelValidation->setFont(font1);
        labelValidation->setLineWidth(0);
        labelValidation->setAlignment(Qt::AlignCenter);

        verticalLayoutExpression->addWidget(labelValidation);

        lineEditExpression = new QLineEdit(InterfaceClass);
        lineEditExpression->setObjectName(QString::fromUtf8("lineEditExpression"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditExpression->sizePolicy().hasHeightForWidth());
        lineEditExpression->setSizePolicy(sizePolicy1);
        lineEditExpression->setMaximumSize(QSize(16777215, 20));

        verticalLayoutExpression->addWidget(lineEditExpression);


        gridLayout->addLayout(verticalLayoutExpression, 2, 1, 1, 1);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setSpacing(2);
        horizontalLayoutButtons->setObjectName(QString::fromUtf8("horizontalLayoutButtons"));
        pushButtonConvert = new QPushButton(InterfaceClass);
        pushButtonConvert->setObjectName(QString::fromUtf8("pushButtonConvert"));

        horizontalLayoutButtons->addWidget(pushButtonConvert);

        pushButtonEvaluate = new QPushButton(InterfaceClass);
        pushButtonEvaluate->setObjectName(QString::fromUtf8("pushButtonEvaluate"));

        horizontalLayoutButtons->addWidget(pushButtonEvaluate);


        gridLayout->addLayout(horizontalLayoutButtons, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        labelResult = new QLabel(InterfaceClass);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));
        sizePolicy1.setHeightForWidth(labelResult->sizePolicy().hasHeightForWidth());
        labelResult->setSizePolicy(sizePolicy1);
        labelResult->setMaximumSize(QSize(65, 20));

        horizontalLayout->addWidget(labelResult);

        lineEditResult = new QLineEdit(InterfaceClass);
        lineEditResult->setObjectName(QString::fromUtf8("lineEditResult"));
        lineEditResult->setEnabled(true);
        sizePolicy1.setHeightForWidth(lineEditResult->sizePolicy().hasHeightForWidth());
        lineEditResult->setSizePolicy(sizePolicy1);
        lineEditResult->setMaximumSize(QSize(16777215, 20));
        lineEditResult->setFrame(false);
        lineEditResult->setReadOnly(true);

        horizontalLayout->addWidget(lineEditResult);


        gridLayout->addLayout(horizontalLayout, 5, 1, 1, 1);


        retranslateUi(InterfaceClass);

        QMetaObject::connectSlotsByName(InterfaceClass);
    } // setupUi

    void retranslateUi(QWidget *InterfaceClass)
    {
        InterfaceClass->setWindowTitle(QApplication::translate("InterfaceClass", "Conversor & Avaliador", 0, QApplication::UnicodeUTF8));
        labelValidation->setText(QApplication::translate("InterfaceClass", "Digite a express\303\243o desejada:", 0, QApplication::UnicodeUTF8));
        lineEditExpression->setInputMask(QString());
        pushButtonConvert->setText(QApplication::translate("InterfaceClass", "Converter", 0, QApplication::UnicodeUTF8));
        pushButtonEvaluate->setText(QApplication::translate("InterfaceClass", "Avaliar", 0, QApplication::UnicodeUTF8));
        labelResult->setText(QApplication::translate("InterfaceClass", "Resultado:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InterfaceClass: public Ui_InterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
