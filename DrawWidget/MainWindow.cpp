#include "MainWindow.h"
#include <QColorDialog>  
#include <QToolBar>  

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	drawWidget = new DrawWidget;	//�½�һ��DrawWidget����
	setCentralWidget(drawWidget);	//�½���DrawWidget������Ϊ�����ڵ����봰��

	createToolBar();				//ʵ��һ��������

	setMinimumSize(600, 400);		//���������ڵ���С�ߴ�

	showStyle();					//��ʼ�����ͣ����ÿؼ��еĵ�ǰֵ��Ϊ��ʼֵ
	drawWidget->setWidth(widthSpinBox->value());	//��ʼ���߿�
	drawWidget->setColor(Qt::black);				//��ʼ����ɫΪ��ɫ
}

void MainWindow::createToolBar()
{
	QToolBar *toolBar = addToolBar("Tool");		//Ϊ�����ڴ���һ������������

	styleLabel = new QLabel(tr("���ͷ�� "));  //���ͷ��  
	styleComboBox = new QComboBox;
	styleComboBox->addItem(tr("SolodLine"), static_cast<int>(Qt::SolidLine));
	styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
	styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
	styleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
	styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
	connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(showStyle()));

	widthLabel = new QLabel(tr("�߿�")); //���ñʵ��߿�  
	widthSpinBox = new QSpinBox;
	connect(widthSpinBox, SIGNAL(valueChanged(int)), drawWidget, SLOT(setWidth(int)));

	colorBtn = new QToolButton; //���ð�ť�ĸ�ʽ  
	QPixmap pixmap(30, 30);
	pixmap.fill(Qt::red);
	colorBtn->setIcon(QIcon(pixmap));
	connect(colorBtn, SIGNAL(clicked(bool)), this, SLOT(showColor()));

	clearBtn = new QToolButton;
	clearBtn->setText(tr("���"));
	connect(clearBtn, SIGNAL(clicked(bool)), drawWidget, SLOT(clear()));

	toolBar->addWidget(styleLabel);
	toolBar->addWidget(styleComboBox);
	toolBar->addWidget(widthLabel);
	toolBar->addWidget(widthSpinBox);
	toolBar->addWidget(colorBtn);
	toolBar->addWidget(clearBtn);
	//toolBar->setMovable(false); //���ù����������϶�  
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
