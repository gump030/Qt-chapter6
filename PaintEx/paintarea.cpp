#include "paintarea.h"
#include <qpainter.h>

PaintArea::PaintArea(QWidget *parent) :
	QWidget(parent)
{
	setPalette(QPalette(Qt::white));
	setAutoFillBackground(true);	//���ô���ı���ɫ,��ɫ
	setMinimumSize(400, 400);		//������С��С
}

void PaintArea::setShape(Shape s)
{
	shape = s;
	update();
}

void PaintArea::setPen(QPen p)
{
	pen = p;
	update();
}

void PaintArea::setBrush(QBrush b)
{
	brush = b;
	update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
	fillRule = rule;
	update();		//�ػ�����������
}

void PaintArea::paintEvent(QPaintEvent *)
{
	QPainter p(this);		//����һ��QPainter����						
	p.setPen(pen);			//����QPainter����Ļ��ʺͻ�ˢ
	p.setBrush(brush);

	QRect rect(50, 100, 300, 200);	//����һ����������Ϊ�������Σ�Բ�Ƿ��ε���׼��

	static const QPoint points[4] =	//����һ��QPoint�����飬�����ĸ��㣬Ϊ������Σ�����߼�����׼��
	{
		QPoint(150, 100),
		QPoint(300, 150),
		QPoint(350, 250),
		QPoint(100, 300)
	};
	int startAngle = 30 * 16;	//��ʼ��
	int spanAngle = 120 * 16;	//��Ƚ�

	QPainterPath path;			//
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);

	switch (shape)
	{
	case Line:		//ֱ��
		p.drawLine(rect.topLeft(), rect.bottomRight()); break;
	case Rectangle:	//������
		p.drawRect(rect); break;
	case RoundRect:	//Բ�Ƿ���	
		p.drawRoundRect(rect); break;
	case Ellipse:	//��Բ
		p.drawEllipse(rect); break;
	case Polygon:	//�����
		p.drawPolygon(points, 4); break;
	case Polyline:	//�����
		p.drawPolyline(points, 4); break;
	case Points:	//��
		p.drawPoints(points, 4); break;
	case Arc:		//��
		p.drawArc(rect, startAngle, spanAngle); break;
	case Path:		//·��	
		p.drawPath(path); break;
	case Text:		//����
		p.drawText(rect, Qt::AlignCenter, tr("Hello Qt!")); break;
	case Pixmap:	//ͼƬ
		p.drawPixmap(0, 0, QPixmap("226.png")); break;
	default:	break;
	}
}