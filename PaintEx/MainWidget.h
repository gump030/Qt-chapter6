#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include <qlabel.h>
#include <qcombobox.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
//#include <QGradient>
#include "paintarea.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

private:
	PaintArea * paintArea;

	QLabel *shapeLabel;
	QComboBox *shapeComboBox;
	QLabel *penWidthLabel;
	QSpinBox *penWidthSpinBox;
	QLabel *penColorLabel;
	QFrame *penColorFrame;
	QPushButton *penColorBtn;
	QLabel *penStyleLabel;
	QComboBox *penStyleComboBox;
	QLabel *penCapLabel;
	QComboBox *penCapComboBox;
	QLabel *penJoinLabel;
	QComboBox *penJoinComboBox;
	QLabel *fillRuleLabel;
	QComboBox *fillRuleComboBox;
	QLabel *spreadLabel;
	QComboBox *spreadComboBox;
	//QGridient::Spread spread;
	QLabel *brushStyleLabel;
	QComboBox *brushStyleComboBox;
	QLabel *brushColorLabel;
	QFrame *brushColorFrame;
	QPushButton *brushColorBtn;

	QGridLayout *rightLayout;

private slots:
	void ShowShape(int);
	void ShowPenWidth(int);
	void ShowPenColor();
	void ShowPenStyle(int);
	void ShowPenCap(int);
	void ShowPenJoin(int);
	void ShowSpreadStyle();
	void ShowFillRule();
	void ShowBrushColor();
	void ShowBrush(int);
};
