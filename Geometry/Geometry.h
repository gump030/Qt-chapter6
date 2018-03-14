#pragma once

#include <QtWidgets/QDialog>
#include <qgridlayout.h>
#include <qlabel.h>
#include "ui_Geometry.h"

class Geometry : public QDialog
{
	Q_OBJECT

public:
	Geometry(QWidget *parent = Q_NULLPTR);
	
	void updateLabel();
private:
	QLabel *xLabel;
	QLabel *xValueLabel;
	QLabel *yLabel;
	QLabel *yValueLabel;
	QLabel *FrmLabel;
	QLabel *FrmValueLabel;
	QLabel *posLabel;
	QLabel *posValueLabel;
	QLabel *geoLabel;
	QLabel *geoValueLabel;
	QLabel *widthLabel;
	QLabel *widthValueLabel;
	QLabel *heightLabel;
	QLabel *heightValueLabel;
	QLabel *rectLabel;
	QLabel *rectValueLabel;
	QLabel *sizeLabel;
	QLabel *sizeValueLabel;
	QGridLayout *mainLayout;
protected:
	void moveEvent(QMoveEvent *);
	void resizeEvent(QResizeEvent *);
};
