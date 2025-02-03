/********************************************************************************
** Form generated from reading UI file 'modificarporta.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARPORTA_H
#define UI_MODIFICARPORTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModificarPorta
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelNumInputs;
    QLabel *labelIdPorta;
    QComboBox *comboTipoPorta;
    QSpinBox *spinNumInputs;
    QLabel *labelPorta;
    QLabel *labelTipoPorta;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ModificarPorta)
    {
        if (ModificarPorta->objectName().isEmpty())
            ModificarPorta->setObjectName("ModificarPorta");
        ModificarPorta->resize(176, 130);
        verticalLayout = new QVBoxLayout(ModificarPorta);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelNumInputs = new QLabel(ModificarPorta);
        labelNumInputs->setObjectName("labelNumInputs");

        gridLayout->addWidget(labelNumInputs, 2, 0, 1, 1);

        labelIdPorta = new QLabel(ModificarPorta);
        labelIdPorta->setObjectName("labelIdPorta");

        gridLayout->addWidget(labelIdPorta, 0, 1, 1, 1);

        comboTipoPorta = new QComboBox(ModificarPorta);
        comboTipoPorta->setObjectName("comboTipoPorta");

        gridLayout->addWidget(comboTipoPorta, 1, 1, 1, 1);

        spinNumInputs = new QSpinBox(ModificarPorta);
        spinNumInputs->setObjectName("spinNumInputs");
        spinNumInputs->setMinimum(1);
        spinNumInputs->setMaximum(4);

        gridLayout->addWidget(spinNumInputs, 2, 1, 1, 1);

        labelPorta = new QLabel(ModificarPorta);
        labelPorta->setObjectName("labelPorta");

        gridLayout->addWidget(labelPorta, 0, 0, 1, 1);

        labelTipoPorta = new QLabel(ModificarPorta);
        labelTipoPorta->setObjectName("labelTipoPorta");

        gridLayout->addWidget(labelTipoPorta, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(ModificarPorta);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ModificarPorta);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ModificarPorta, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ModificarPorta, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ModificarPorta);
    } // setupUi

    void retranslateUi(QDialog *ModificarPorta)
    {
        ModificarPorta->setWindowTitle(QCoreApplication::translate("ModificarPorta", "Modificar porta", nullptr));
        labelNumInputs->setText(QCoreApplication::translate("ModificarPorta", "N\302\272 de entradas:", nullptr));
        labelIdPorta->setText(QString());
        labelPorta->setText(QCoreApplication::translate("ModificarPorta", "PORTA:", nullptr));
        labelTipoPorta->setText(QCoreApplication::translate("ModificarPorta", "Tipo da porta:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificarPorta: public Ui_ModificarPorta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARPORTA_H
