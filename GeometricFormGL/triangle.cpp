#include "triangle.h"

Triangle::Triangle(QGLWidget *parent) :

    x0(-200.0f),
    y0(0.0f),
    t(10.1f)
{
}

void Triangle::setX0()
{
    if(x0>201)
    {
        t=-t;
    }
    if(x0<-201)
    {
        t=-t;
    }
    x0=x0+t+100;
   // qDebug() << x0 ;

    a++;
}

void Triangle::setY0()
{
    y0=cos(x0/5)*5;
}

void Triangle::slotMove()
{
    setX0();
    setY0();

    glBegin(GL_TRIANGLES);
        glColor3d(0,0,1);
        glVertex3d(x0,y0,0);

        glColor3d(0,1,0);
        glVertex3d(x0+15.5,y0+15.5,0);

        glColor3d(1,0,0);
        glVertex3d(x0,y0+15.5,0);
    glEnd();

    //updateGL();
}

