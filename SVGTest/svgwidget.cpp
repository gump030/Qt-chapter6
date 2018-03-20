#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent)
    :QSvgWidget(parent)
{
    render =renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *e)
{
    const double diff=0.1;				//表示每次滚轮滚动一定的值，图片大小改变的比例
    QSize size =render->defaultSize();	//获取图片显示区的尺寸大小，以便下一步的缩放操作
    int width =size.width();
    int height =size.height();
    if(e->delta()>0)					//利用QWheelEvent的delta()函数获得滚轮滚动的距离值，大于0表示往前滚
    {
        width =int(this->width()+this->width()*diff);	//对图片进行一定的放大
        height =int(this->height()+this->height()*diff);
    }
    else
    {
        width =int(this->width()-this->width()*diff);	//对图片的长宽进行一定的缩小
        height =int(this->height()-this->height()*diff);
    }
    resize(width,height);								//利用新的长宽值对图片进行resize()操作

}
