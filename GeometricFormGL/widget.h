#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL/QGLWidget>
#include <vector>
#include <QTimer>
#include "mythread.h"

class my3Dscene : public QGLWidget
{
    Q_OBJECT

public:
    my3Dscene(QWidget *parent = 0);
    ~my3Dscene();

protected:

   void initializeGL();
   void resizeGL(int nWidth, int nHeight);
   void paintGL();

private :

   MyThread thread;

   void paintTriangle();
   void paintRectangle();
   void paintCircle();
   void paintCircle1();
   void paintAll();

   triangleCoord t_coord;
   rectangleCoord r_coord;
   circleCoord c_coord;

   void initTriangle();
   void initRectangle();
   void initCircle();


private slots:
    void moveAll(float r_x0, float r_y0, float c_x0, float c_y0, float t_x1, float t_y1, float t_x2, float t_y2, float t_x3, float t_y3);
   //triangleCoord _t_coord,
};

#endif // WIDGET_H
