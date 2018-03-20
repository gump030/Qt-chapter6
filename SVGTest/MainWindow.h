#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "svgwindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	void createMenu();
public slots:
	void slotOpenFile();
private:
	SvgWindow * svgWindow; 		//�Ա������غ�������ѡ����ļ���
};
