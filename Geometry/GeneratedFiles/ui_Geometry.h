/********************************************************************************
** Form generated from reading UI file 'Geometry.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOMETRY_H
#define UI_GEOMETRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_GeometryClass
{
public:

    void setupUi(QDialog *GeometryClass)
    {
        if (GeometryClass->objectName().isEmpty())
            GeometryClass->setObjectName(QStringLiteral("GeometryClass"));
        GeometryClass->resize(600, 400);

        retranslateUi(GeometryClass);

        QMetaObject::connectSlotsByName(GeometryClass);
    } // setupUi

    void retranslateUi(QDialog *GeometryClass)
    {
        GeometryClass->setWindowTitle(QApplication::translate("GeometryClass", "Geometry", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GeometryClass: public Ui_GeometryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOMETRY_H
