#include "mygraphicsview.h"
#include <cmath>

MyGraphicsView::MyGraphicsView(QWidget *parent):
QGraphicsView (parent), rubberBand(nullptr){
    pen.setWidth(2);
    pen.setBrush(Qt::red);

    scaleX =  2.107;
    scaleY = 1.891;
//    scaleY =  3.153;
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{
//    startPoint = ev->pos();
//      qDebug()<<"START POINT!: "<<startPoint;
//     if(!rubberBand)
//             rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
//        rubberBand->setGeometry(QRect(startPoint,QSize()));
//        rubberBand->show();
//        QGraphicsView::mousePressEvent(ev);

    if(flags.mode == -1) {return;}

    if(!flags.resize)
    {
       QPoint init_p= event->pos();
       flags.initial_position_flag = 1;
       point.init_p = init_p;
       qDebug()<<"i"<<init_p;
    }

     if(flags.resize == 1)
     {
        QPoint resize_p = event->pos();

        getNearestPoint(resize_p);
        if(!flags.nearest_point)
        {
           point.init_p = resize_p;
        }

       else
        {
           point.end_p = resize_p;
        }
     }
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
//     rubberBand->setGeometry(QRect(startPoint,ev->pos()).normalized());
//     QGraphicsView::mouseMoveEvent(ev);

    if(flags.mode == -1) {return;}

    if(!flags.resize)
    {
       QPoint moved_p= event->pos();
       flags.end_position_flag = 1;
       point.end_p = moved_p;
       qDebug()<<"moved: "<<moved_p;
    }

    if(flags.resize)
    {
       QPoint moved_p= event->pos();
       flags.end_position_flag = 1;

       if(!flags.nearest_point)
       {
          point.init_p = moved_p;
       }

      else
       {
          point.end_p = moved_p;
       }
    }
    update();

}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
//    endPoint = ev->pos();
//    qDebug()<<"END POINT!: "<<endPoint;

//    rect = rubberBand->geometry();
//    rubberBand->hide();

//    update();
//    QGraphicsView::mouseReleaseEvent(ev);

    if(flags.mode == -1) {return;}

    if(!flags.resize)
    {
       QPoint end_p= event->pos();
       point.end_p = end_p;
       flags.resize = 1;
       qDebug()<<"res: "<<end_p;
    }
    else
    {
       QPoint resize_p= event->pos();
       if(!flags.nearest_point)
       {
          point.init_p = resize_p;
       }
      else
       {
          point.end_p = resize_p;
       }
    }

}

void MyGraphicsView::paintEvent(QPaintEvent *event)
{

//    QGraphicsView::paintEvent(ev);
//    QPainter painter(this->viewport());

//    painter.setBrush(QBrush(QColor(0,0,255,0)));
//     if(!rect.isNull()){
//          painter.drawRect(rect);
//     }

    QGraphicsView::paintEvent(event);

    QPainter painter(this->viewport());

    if(!point.saved_line_points.isEmpty())
    {

        painter.setPen(pen);

        QListIterator<LineCrossings> iter(point.saved_line_points);
            while(iter.hasNext())
            {
                LineCrossings points;
                points = iter.next();

                if(points.mode == 0){pen.setBrush(Qt::yellow);painter.setPen(pen);}
                else {pen.setBrush(Qt::green);painter.setPen(pen);}
               painter.drawLine(QPoint(points.line.first.x() / scaleX ,points.line.first.y() / scaleY), QPoint(points.line.second.x() / scaleX,points.line.second.y() / scaleY));

               painter.drawLine(QPoint(points.direction.first.x() / scaleX,points.direction.first.y() / scaleY), QPoint(points.direction.second.x() /scaleX,points.direction.second.y() / scaleY));

               double angle = atan2 (points.direction.second.y() / scaleY - points.direction.first.y() / scaleY, points.direction.second.x() /scaleX
                                     - points.direction.first.x() / scaleX) + M_PI;

               int x1 = points.direction.second.x() / scaleX + sqrt(pow(points.direction.second.x() / scaleX - points.direction.first.x() / scaleX, 2)
                                               + pow(points.direction.second.y() / scaleY - points.direction.first.y() / scaleY, 2))/5 * cos(angle - 50);
               int y1 = points.direction.second.y() / scaleY+ sqrt(pow(points.direction.second.x()/ scaleX - points.direction.first.x()/ scaleX, 2)
                                               + pow(points.direction.second.y() / scaleY - points.direction.first.y() / scaleY, 2))/5  * sin(angle - 50);
               int x2 = points.direction.second.x()  / scaleX + sqrt(pow(points.direction.second.x()/ scaleX - points.direction.first.x()/ scaleX, 2)
                                               + pow(points.direction.second.y()/ scaleY - points.direction.first.y()/ scaleY, 2))/5  * cos(angle + 50);
               int y2 = points.direction.second.y() / scaleY+ sqrt(pow(points.direction.second.x()/ scaleX - points.direction.first.x()/ scaleX, 2)
                                               + pow(points.direction.second.y()/ scaleY - points.direction.first.y()/ scaleY, 2))/5  * sin(angle + 50);

               painter.drawLine(QPoint(points.direction.second.x() / scaleX,points.direction.second.y() / scaleY ), QPoint(x1,y1) );
               painter.drawLine(QPoint(points.direction.second.x() / scaleX, points.direction.second.y() / scaleY ), QPoint(x2,y2) );
            }

    }

    if(!point.saved_rect_points.isEmpty())
    {

        pen.setBrush(Qt::red);painter.setPen(pen);

        QListIterator<QPair <QPoint, QPoint>> iter(point.saved_rect_points);
            while(iter.hasNext())
            {
                QPair <QPoint, QPoint> points;
                points = iter.next();

                QRect r1(points.first, points.second);
                painter.drawRect(r1);
            }

    }

    if(!point.saved_direction_points.isEmpty())
    {

        pen.setBrush(Qt::blue);
        painter.setPen(pen);

        QListIterator<QPair <QPoint, QPoint>> iter(point.saved_direction_points);
            while(iter.hasNext())
            {
                QPair <QPoint, QPoint> points;
                points = iter.next();

                painter.drawLine(QPoint(points.first.x() / scaleX,points.first.y() / scaleY), QPoint(points.second.x() /scaleX,points.second.y() / scaleY));

                double angle = atan2 (points.second.y() / scaleY - points.first.y() / scaleY, points.second.x() /scaleX
                                      - points.first.x() / scaleX) + M_PI;

                int x1 = points.second.x() / scaleX + sqrt(pow(points.second.x() / scaleX - points.first.x() / scaleX, 2)
                                                + pow(points.second.y() / scaleY - points.first.y() / scaleY, 2))/5 * cos(angle - 50);
                int y1 = points.second.y() / scaleY+ sqrt(pow(points.second.x()/ scaleX - points.first.x()/ scaleX, 2)
                                                + pow(points.second.y() / scaleY - points.first.y() / scaleY, 2))/5  * sin(angle - 50);
                int x2 = points.second.x()  / scaleX + sqrt(pow(points.second.x()/ scaleX - points.first.x()/ scaleX, 2)
                                                + pow(points.second.y()/ scaleY - points.first.y()/ scaleY, 2))/5  * cos(angle + 50);
                int y2 = points.second.y() / scaleY+ sqrt(pow(points.second.x()/ scaleX - points.first.x()/ scaleX, 2)
                                                + pow(points.second.y()/ scaleY - points.first.y()/ scaleY, 2))/5  * sin(angle + 50);

                painter.drawLine(QPoint(points.second.x() / scaleX,points.second.y() / scaleY ), QPoint(x1,y1) );
                painter.drawLine(QPoint(points.second.x() / scaleX, points.second.y() / scaleY ), QPoint(x2,y2) );

            }

    }


    if(flags.initial_position_flag && flags.end_position_flag)
    {

        painter.setPen(pen);

        if(flags.mode == 1)
        {
            QRect r1(point.init_p, point.end_p );
            painter.drawRect(r1);
        }

        if(flags.mode == 0)
        {
            painter.drawLine(point.init_p,point.end_p );
        }

        if(flags.mode == 2)
        {
           painter.drawLine(point.init_p,point.end_p );

           double angle = atan2 (point.end_p.y()- point.init_p.y(), point.end_p.x() - point.init_p.x()) + M_PI;

           int x1 = point.end_p.x()+ sqrt(pow(point.end_p.x() - point.init_p.x(), 2) + pow(point.end_p.y()- point.init_p.y() , 2))/5 * cos(angle - 50);
           int y1 = point.end_p.y()+ sqrt(pow(point.end_p.x() - point.init_p.x(), 2) + pow(point.end_p.y() - point.init_p.y(), 2))/5  * sin(angle - 50);
           int x2 = point.end_p.x() + sqrt(pow(point.end_p.x()- point.init_p.x(), 2) + pow(point.end_p.y() - point.init_p.y(), 2))/5  * cos(angle + 50);
           int y2 = point.end_p.y()+ sqrt(pow(point.end_p.x() - point.init_p.x(), 2) + pow(point.end_p.y() - point.init_p.y(), 2))/5  * sin(angle + 50);

           painter.drawLine(QPoint(point.end_p.x(),point.end_p.y() ), QPoint(x1,y1) );
           painter.drawLine(QPoint(point.end_p.x(),point.end_p.y()), QPoint(x2,y2) );
        }

        if(flags.mode == 3)
        {
            painter.drawLine(point.init_p,point.end_p );

            double angle = atan2 (point.end_p.y()- point.init_p.y(), point.end_p.x() - point.init_p.x()) + M_PI;

            int x1 = point.end_p.x()+ sqrt(pow(point.end_p.x() - point.init_p.x(), 2) + pow(point.end_p.y()- point.init_p.y() , 2))/5 * cos(angle - 50);
            int y1 = point.end_p.y()+ sqrt(pow(point.end_p.x() - point.init_p.x(), 2) + pow(point.end_p.y() - point.init_p.y(), 2))/5  * sin(angle - 50);
            int x2 = point.end_p.x() + sqrt(pow(point.end_p.x()- point.init_p.x(), 2) + pow(point.end_p.y() - point.init_p.y(), 2))/5  * cos(angle + 50);
            int y2 = point.end_p.y()+ sqrt(pow(point.end_p.x() - point.init_p.x(), 2) + pow(point.end_p.y() - point.init_p.y(), 2))/5  * sin(angle + 50);

            painter.drawLine(QPoint(point.end_p.x(),point.end_p.y() ), QPoint(x1,y1) );
            painter.drawLine(QPoint(point.end_p.x(),point.end_p.y()), QPoint(x2,y2) );
        }



    }


}

void MyGraphicsView::getNearestPoint(QPoint p)
{
    int d0 = sqrt(pow(p.x() - point.init_p.x(), 2) + pow(p.y() - point.init_p.y(), 2));
    int d1 = sqrt(pow(p.x() - point.end_p.x(), 2) + pow(p.y() - point.end_p.y(), 2));
    if(d0<d1)
    {
        flags.nearest_point = 0;
    }
    else
    {
         flags.nearest_point = 1;
    }
}

void MyGraphicsView::save(int mode)
{

    point.init_p.setX(point.init_p.x() * scaleX);
    point.init_p.setY(point.init_p.y() * scaleY);

    point.end_p.setX(point.end_p.x() * scaleX);
    point.end_p.setY(point.end_p.y() * scaleY);


    QPair<QPoint, QPoint> points_pair;
        points_pair.first = point.init_p;
        points_pair.second = point.end_p;


    if(flags.mode == 0)
    {      
        linecrossing.line = points_pair;
        linecrossing.mode = mode;
        point.saved_line_points.append(linecrossing);

        qDebug()<< "line : "<< linecrossing.line;
    }

    if(flags.mode == 2)
    {
        point.saved_line_points[point.saved_line_points.length()-1].direction = points_pair;
    }

    if(flags.mode == 1)
    {
        point.saved_rect_points.append(points_pair);
    }

    if(flags.mode == 3)
    {
        point.saved_direction_points.append(points_pair);
    }

    update();
}











