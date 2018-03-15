#include "drawwidget.h"  

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
	setAutoFillBackground(true);    //��������ؼ�������ɫ  

	setPalette(QPalette(Qt::white));
	pix = new QPixmap(size());
	pix->fill(Qt::white);
	setMinimumSize(600, 400);    //���ô�����С��С  
}

void DrawWidget::setStyle(int s)
{
	style = s;
}

void DrawWidget::setWidth(int w)
{
	weight = w;
}

void DrawWidget::setColor(QColor c)
{
	color = c;
}

void DrawWidget::mousePressEvent(QMouseEvent *e)
{
	startPos = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPainter *painter = new QPainter;

	QPen pen;
	pen.setStyle((Qt::PenStyle)style);	//���û��ʵ����Σ�style��ʾ��ǰ������Qt::PenStyleö�������еĵڼ���Ԫ��
	pen.setWidth(weight);				//���û��ʵ��߿�
	pen.setColor(color);				//���û��ʵ���ɫ

	painter->begin(pix);				//
	painter->setPen(pen);				//����Ӧ�õ����ƶ�����
	painter->drawLine(startPos, e->pos());//���ƴ�startPos����굱ǰλ�õ�ֱ��
	painter->end();
	startPos = e->pos();				//��¼���ĵ�ǰλ�ã�Ϊ�´λ�����׼��

	update();
}

void DrawWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(QPoint(0, 0), *pix);  //���»���������
}

void DrawWidget::resizeEvent(QResizeEvent *event)	//�����С�ı�ʱ���޸Ŀɻ�������
{
	if (height() > pix->height() || width() > pix->width())
	{
		QPixmap *newPix = new QPixmap(size());
		newPix->fill(Qt::white);			//����µ�QPixmap�������ɫΪ��ɫ����ɫ
		QPainter p(newPix);					
		p.drawPixmap(QPoint(0, 0), *pix);	//��newPix�л���ԭpix�е�����
		pix = newPix;						//��newPix��ֵ��pix��Ϊ�µĻ���ͼ�ν��ܶ���
	}
	QWidget::resizeEvent(event);			//�������Ĺ���
}

void DrawWidget::clear()
{
	QPixmap *clearPix = new QPixmap(size());
	clearPix->fill(Qt::white);
	pix = clearPix;							//���������

	update();
}