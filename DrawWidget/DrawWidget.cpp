#include "drawwidget.h"  

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
	setAutoFillBackground(true);    //允许调整控件背景颜色  

	setPalette(QPalette(Qt::white));
	pix = new QPixmap(size());
	pix->fill(Qt::white);
	setMinimumSize(600, 400);    //设置窗体最小大小  
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
	pen.setStyle((Qt::PenStyle)style);	//设置画笔的线形，style表示当前线形是Qt::PenStyle枚举数据中的第几个元素
	pen.setWidth(weight);				//设置画笔的线宽
	pen.setColor(color);				//设置画笔的颜色

	painter->begin(pix);				//
	painter->setPen(pen);				//画笔应用到绘制对象中
	painter->drawLine(startPos, e->pos());//绘制从startPos到鼠标当前位置的直线
	painter->end();
	startPos = e->pos();				//记录鼠标的当前位置，为下次绘制做准备

	update();
}

void DrawWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(QPoint(0, 0), *pix);  //更新绘制区窗体
}

void DrawWidget::resizeEvent(QResizeEvent *event)	//窗体大小改变时，修改可绘制区域
{
	if (height() > pix->height() || width() > pix->width())
	{
		QPixmap *newPix = new QPixmap(size());
		newPix->fill(Qt::white);			//填充新的QPixmap对象的颜色为白色背景色
		QPainter p(newPix);					
		p.drawPixmap(QPoint(0, 0), *pix);	//在newPix中绘制原pix中的内容
		pix = newPix;						//将newPix赋值给pix作为新的绘制图形接受对象
	}
	QWidget::resizeEvent(event);			//完成其余的工作
}

void DrawWidget::clear()
{
	QPixmap *clearPix = new QPixmap(size());
	clearPix->fill(Qt::white);
	pix = clearPix;							//清除绘制区

	update();
}