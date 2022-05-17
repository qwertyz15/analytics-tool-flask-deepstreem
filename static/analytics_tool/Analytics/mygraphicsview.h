#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QPainter>
#include <QRubberBand>

#include <QPoint>
#include <QDebug>
#include <QLabel>



class MyGraphicsView : public QGraphicsView
    {
    Q_OBJECT
    public:
    MyGraphicsView(QWidget *parent = nullptr);
protected:

private:
QRubberBand *rubberBand;

   QRect rect;
   QPoint startPoint, endPoint;

public:

   float scaleX, scaleY;
   void mouseMoveEvent(QMouseEvent *ev) override;
   void mousePressEvent(QMouseEvent *ev) override;
   void mouseReleaseEvent(QMouseEvent *ev) override;
   void paintEvent(QPaintEvent *event) override;
   void getNearestPoint(QPoint p);

   void getCoordinates(QPoint leftTop, QPoint rightBottom);

   void save(int mode);

   QPen pen;

   struct controls {
     int initial_position_flag = 0;
     int end_position_flag = 0;
     int resize = 0;
     int nearest_point = 0;
     int mode = -1;
     int direction = 0;
   } flags;

   struct LineCrossings{
       QPair <QPoint, QPoint> line;
       QPair <QPoint, QPoint> direction;
       int mode;
   } linecrossing;

   struct points {
     QPoint init_p;
     QPoint end_p;
     QPoint resize_p;
     QList<QPair <QPoint, QPoint>> saved_rect_points;
     QList<LineCrossings> saved_line_points;
     QList<QPair <QPoint, QPoint>> saved_direction_points;
   } point;


};

#endif // MYGRAPHICSVIEW_H
