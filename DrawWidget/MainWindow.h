#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <QLabel>  
#include <QComboBox>  
#include <QSpinBox>  
#include <QToolButton>  
#include "DrawWidget.h"  

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void createToolBar();
public slots:
	void showStyle();
	void showColor();
private:
	DrawWidget * drawWidget;
	QLabel *styleLabel;
	QComboBox *styleComboBox;
	QLabel *widthLabel;
	QSpinBox *widthSpinBox;
	QToolButton *colorBtn;
	QToolButton *clearBtn;
};
