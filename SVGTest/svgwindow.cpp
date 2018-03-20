#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent)
    :QScrollArea(parent)
{
    svgWidget =new SvgWidget;
    setWidget(svgWidget);
}

void SvgWindow::setFile(QString fileName)
{
    svgWidget->load(fileName);				//将新的SVG文件加载到svgWidget中显示
    QSvgRenderer *render =svgWidget->renderer();	
    svgWidget->resize(render->defaultSize());	//使svgWidget按照SVG图片的默认尺寸进行显示
}

void SvgWindow::mousePressEvent(QMouseEvent *event)
{
    mousePressPos =event->pos();
    scrollBarValuesOnMousePress.rx()=horizontalScrollBar()->value();
    scrollBarValuesOnMousePress.ry()=verticalScrollBar()->value();
    event->accept();
}
//当鼠标键按下并拖拽鼠标时触发mouseMoveEvent()函数，通过滑动条的位置设置实现图片拖拽的效果。

void SvgWindow::mouseMoveEvent(QMouseEvent *event)
{
    horizontalScrollBar()->setValue(scrollBarValuesOnMousePress.x()-event->pos().x()+mousePressPos.x());	//对水平滑动条的新位置进行设置
    verticalScrollBar()->setValue(scrollBarValuesOnMousePress.y()-event->pos().y()+mousePressPos.y());      //对垂直滑动条的新位置进行设置
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    event->accept();
}
