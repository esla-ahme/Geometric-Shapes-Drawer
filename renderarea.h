#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    enum shapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid,Line};

    void setBackgroundColor(QColor clr){m_backgrounColor=clr;}
    QColor getBackgrounColor(void)const{return m_backgrounColor;}


    shapeType getShape() const{return m_shape;}

    void setShape(const shapeType &shape){m_shape = shape; onShapeChange();}

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

private:
    //members
    QColor m_backgrounColor;
    QColor m_shapeColor;
    shapeType m_shape;
    int m_stepCount;
    float m_scale;
    float m_intervalLength;
    float m_step = m_intervalLength/m_stepCount;

    //functions
    void onShapeChange(void);
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygenscycloid(float t);
    QPointF compute_hypocycloid(float t);
     QPointF compute_line(float t);
};

#endif // RENDERAREA_H
