#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent)
    :QSvgWidget(parent)
{
    render =renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *e)
{
    const double diff=0.1;				//��ʾÿ�ι��ֹ���һ����ֵ��ͼƬ��С�ı�ı���
    QSize size =render->defaultSize();	//��ȡͼƬ��ʾ���ĳߴ��С���Ա���һ�������Ų���
    int width =size.width();
    int height =size.height();
    if(e->delta()>0)					//����QWheelEvent��delta()������ù��ֹ����ľ���ֵ������0��ʾ��ǰ��
    {
        width =int(this->width()+this->width()*diff);	//��ͼƬ����һ���ķŴ�
        height =int(this->height()+this->height()*diff);
    }
    else
    {
        width =int(this->width()-this->width()*diff);	//��ͼƬ�ĳ������һ������С
        height =int(this->height()-this->height()*diff);
    }
    resize(width,height);								//�����µĳ���ֵ��ͼƬ����resize()����

}
