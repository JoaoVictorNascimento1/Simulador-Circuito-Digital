/********************************************************************************
** Form generated from reading UI file 'newcircuito.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCIRCUITO_H
#define UI_NEWCIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewCircuito
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelNumIn;
    QSpinBox *spinNumIn;
    QLabel *labelNumOut;
    QSpinBox *spinNumOut;
    QLabel *labelNumPortas;
    QSpinBox *spinNumPortas;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewCircuito)
    {
        if (NewCircuito->objectName().isEmpty())
            NewCircuito->setObjectName("NewCircuito");
        NewCircuito->resize(207, 122);
        verticalLayout = new QVBoxLayout(NewCircuito);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelNumIn = new QLabel(NewCircuito);
        labelNumIn->setObjectName("labelNumIn");

        gridLayout->addWidget(labelNumIn, 0, 0, 1, 1);

        spinNumIn = new QSpinBox(NewCircuito);
        spinNumIn->setObjectName("spinNumIn");
        spinNumIn->setMinimum(1);

        gridLayout->addWidget(spinNumIn, 0, 1, 1, 1);

        labelNumOut = new QLabel(NewCircuito);
        labelNumOut->setObjectName("labelNumOut");

        gridLayout->addWidget(labelNumOut, 1, 0, 1, 1);

        spinNumOut = new QSpinBox(NewCircuito);
        spinNumOut->setObjectName("spinNumOut");
        spinNumOut->setMinimum(1);

        gridLayout->addWidget(spinNumOut, 1, 1, 1, 1);

        labelNumPortas = new QLabel(NewCircuito);
        labelNumPortas->setObjectName("labelNumPortas");

        gridLayout->addWidget(labelNumPortas, 2, 0, 1, 1);

        spinNumPortas = new QSpinBox(NewCircuito);
        spinNumPortas->setObjectName("spinNumPortas");
        spinNumPortas->setMinimum(1);

        gridLayout->addWidget(spinNumPortas, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(NewCircuito);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewCircuito);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewCircuito, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewCircuito, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewCircuito);
    } // setupUi

    void retranslateUi(QDialog *NewCircuito)
    {
        NewCircuito->setWindowTitle(QCoreApplication::translate("NewCircuito", "Novo circuito", nullptr));
        labelNumIn->setText(QCoreApplication::translate("NewCircuito", "Numero de entradas:", nullptr));
        labelNumOut->setText(QCoreApplication::translate("NewCircuito", "Numero de sa\303\255das:", nullptr));
        labelNumPortas->setText(QCoreApplication::translate("NewCircuito", "Numero de portas:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewCircuito: public Ui_NewCircuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCIRCUITO_H
