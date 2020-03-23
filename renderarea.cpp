#include "renderarea.h"

#include <QColor>
#include <QPainter>
#include <qmath.h>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
    m_backgrounColor(245,240,250),
    m_shapeColor(15,20,10),
    m_shape(Astroid){onShapeChange();}



QSize RenderArea::minimumSizeHint() const {
    return QSize(100,100);
}
QSize RenderArea::sizeHint() const {
    return QSize(400,200);

}

void RenderArea::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);


    // we drawhere

    QPoint centerPoint = this->rect().center();
    painter.setBrush(m_backgrounColor);
    painter.setPen(m_shapeColor);
    painter.drawRect(this->rect());

    m_step = m_intervalLength/m_stepCount/2;
    for (float t=-m_intervalLength; t <m_intervalLength; t+=m_step) {
       QPointF point = compute(t);
       QPoint pixel;
       pixel.setX(point.x()*m_scale+centerPoint.x());
       pixel.setY(point.y()*m_scale+centerPoint.y());
       painter.drawPoint(pixel);
    }
}

void RenderArea::onShapeChange()
{
    switch (m_shape) {
    case Astroid:
        m_stepCount = 256;
        m_scale = 50;
        m_intervalLength = 2 * M_PI;
        break;

    case Cycloid:
        m_stepCount = 128;
        m_scale = 4;
        m_intervalLength = 6 * M_PI;
        break;

    case HuygensCycloid:
        m_stepCount = 256;
        m_scale = 4;
        m_intervalLength = 4 * M_PI;
        break;

    case HypoCycloid:
        m_stepCount = 256;
        m_scale = 15;
        m_intervalLength = 2 * M_PI;
        break;
   case Line:
        m_stepCount = 128;
        m_scale = 50;
        m_intervalLength = 1;
        break;

    default: break;
    }
}

QPointF RenderArea::compute(float t){
    switch (m_shape) {
    case Astroid: return compute_astroid(t); break;

    case Cycloid: return compute_cycloid(t); break;

    case HuygensCycloid: return compute_huygenscycloid(t); break;

    case HypoCycloid: return compute_hypocycloid(t); break;

    case Line: return compute_line(t);
    default:break;
    }
    return QPointF(0,0);
}


QPointF RenderArea::compute_astroid(float t){
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * pow(cos_t,3);
    float y = 2 * pow(sin_t,3);
    return QPointF(x,y);
}

QPointF RenderArea::compute_cycloid(float t){
    //float cos_t = cos(t);
    //float sin_t = sin(t);
    float x = 1.5 * (1-cos(t));
    float y = 1.5 * (t - sin(t));
    return QPointF(x,y);
}

QPointF RenderArea::compute_huygenscycloid(float t){

    float x = 4 * (cos(t) * 3 - cos(3*t));
    float y = 4 * (sin(t) * 3 - sin(3*t));
    return QPointF(x,y);
}

QPointF RenderArea::compute_hypocycloid(float t){

    float x = 2 * (cos(t) * 2 + cos(2*t));
    float y = 2 * (sin(t) * 2 - sin(2*t));
    return QPointF(x,y);
}

QPointF RenderArea::compute_line(float t){

    float x = 1+t;
    float y = 1+t;
    return QPointF(x,y);
}



