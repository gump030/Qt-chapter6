#include "MainWindow.h"
#include <QColorDialog>  
#include <QToolBar>  

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	drawWidget = new DrawWidget;	//新建一个DrawWidget对象
	setCentralWidget(drawWidget);	//新建的DrawWidget对象作为主窗口的中央窗体

	createToolBar();				//实现一个工具栏

	setMinimumSize(600, 400);		//设置主窗口的最小尺寸

	showStyle();					//初始化线型，设置控件中的当前值作为初始值
	drawWidget->setWidth(widthSpinBox->value());	//初始化线宽
	drawWidget->setColor(Qt::black);				//初始化颜色为黑色
}

void MainWindow::createToolBar()
{
	QToolBar *toolBar = addToolBar("Tool");		//为主窗口创建一个工具栏对象

	styleLabel = new QLabel(tr("线型风格： "));  //线型风格  
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SolodLine"), static_cast<int>(Qt::SolidLine));
	styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	styleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(showStyle()));

	widthLabel = new QLabel(tr("线宽：")); //设置笔的线宽  
	widthSpinBox = new QSpinBox;
	connect(widthSpinBox, SIGNAL(valueChanged(int)), drawWidget, SLOT(setWidth(int)));

	colorBtn = new QToolButton; //设置按钮的格式  
	QPixmap pixmap(30, 30);
	pixmap.fill(Qt::red);
	colorBtn->setIcon(QIcon(pixmap));
	connect(colorBtn, SIGNAL(clicked(bool)), this, SLOT(showColor()));

	clearBtn = new QToolButton;
	clearBtn->setText(tr("清除"));
	connect(clearBtn, SIGNAL(clicked(bool)), drawWidget, SLOT(clear()));

	toolBar->addWidget(styleLabel);
	toolBar->addWidget(styleComboBox);
	toolBar->addWidget(widthLabel);
	toolBar->addWidget(widthSpinBox);
	toolBar->addWidget(colorBtn);
	toolBar->addWidget(clearBtn);
	//toolBar->setMovable(false); //设置工具条不可拖动  
}

void MainWindow::showStyle()
{
	drawWidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWindow::showColor()
{
	QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
	if (color.isValid())
	{
		drawWidget->setColor(color);
		QPixmap p(20, 20);
		p.fill(color);
		colorBtn->setIcon(QIcon(p));
	}
}
