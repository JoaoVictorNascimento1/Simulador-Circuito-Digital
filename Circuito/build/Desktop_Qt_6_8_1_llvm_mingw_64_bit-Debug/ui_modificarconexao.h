/********************************************************************************
** Form generated from reading UI file 'modificarconexao.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARCONEXAO_H
#define UI_MODIFICARCONEXAO_H

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

class Ui_ModificarConexao
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpinBox *spinInput1;
    QSpinBox *spinInput2;
    QLabel *labelInput3;
    QLabel *labelPorta;
    QLabel *labelIdPorta;
    QLabel *labelInput2;
    QLabel *labelInput1;
    QSpinBox *spinInput3;
    QLabel *labelInput4;
    QSpinBox *spinInput4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ModificarConexao)
    {
        if (ModificarConexao->objectName().isEmpty())
            ModificarConexao->setObjectName("ModificarConexao");
        ModificarConexao->resize(176, 186);
        verticalLayout = new QVBoxLayout(ModificarConexao);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        spinInput1 = new QSpinBox(ModificarConexao);
        spinInput1->setObjectName("spinInput1");

        gridLayout->addWidget(spinInput1, 1, 1, 1, 1);

        spinInput2 = new QSpinBox(ModificarConexao);
        spinInput2->setObjectName("spinInput2");

        gridLayout->addWidget(spinInput2, 2, 1, 1, 1);

        labelInput3 = new QLabel(ModificarConexao);
        labelInput3->setObjectName("labelInput3");

        gridLayout->addWidget(labelInput3, 3, 0, 1, 1);

        labelPorta = new QLabel(ModificarConexao);
        labelPorta->setObjectName("labelPorta");

        gridLayout->addWidget(labelPorta, 0, 0, 1, 1);

        labelIdPorta = new QLabel(ModificarConexao);
        labelIdPorta->setObjectName("labelIdPorta");

        gridLayout->addWidget(labelIdPorta, 0, 1, 1, 1);

        labelInput2 = new QLabel(ModificarConexao);
        labelInput2->setObjectName("labelInput2");

        gridLayout->addWidget(labelInput2, 2, 0, 1, 1);

        labelInput1 = new QLabel(ModificarConexao);
        labelInput1->setObjectName("labelInput1");

        gridLayout->addWidget(labelInput1, 1, 0, 1, 1);

        spinInput3 = new QSpinBox(ModificarConexao);
        spinInput3->setObjectName("spinInput3");

        gridLayout->addWidget(spinInput3, 3, 1, 1, 1);

        labelInput4 = new QLabel(ModificarConexao);
        labelInput4->setObjectName("labelInput4");

        gridLayout->addWidget(labelInput4, 4, 0, 1, 1);

        spinInput4 = new QSpinBox(ModificarConexao);
        spinInput4->setObjectName("spinInput4");

        gridLayout->addWidget(spinInput4, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(ModificarConexao);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ModificarConexao);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ModificarConexao, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ModificarConexao, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ModificarConexao);
    } // setupUi

    void retranslateUi(QDialog *ModificarConexao)
    {
        ModificarConexao->setWindowTitle(QCoreApplication::translate("ModificarConexao", "Modificar conexao", nullptr));
        labelInput3->setText(QCoreApplication::translate("ModificarConexao", "Id da entrada 3:", nullptr));
        labelPorta->setText(QCoreApplication::translate("ModificarConexao", "PORTA:", nullptr));
        labelIdPorta->setText(QString());
        labelInput2->setText(QCoreApplication::translate("ModificarConexao", "Id da entrada 2:", nullptr));
        labelInput1->setText(QCoreApplication::translate("ModificarConexao", "Id da entrada 1:", nullptr));
        labelInput4->setText(QCoreApplication::translate("ModificarConexao", "Id da entrada 4:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificarConexao: public Ui_ModificarConexao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARCONEXAO_H
