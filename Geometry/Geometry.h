#pragma once

#include <QtWidgets/QDialog>
#include "ui_Geometry.h"

class Geometry : public QDialog
{
	Q_OBJECT

public:
	Geometry(QWidget *parent = Q_NULLPTR);

private:
	Ui::GeometryClass ui;
};
