#include "mythread.h"
#include <QDebug>
#include <math.h>



/*
 https://habrahabr.ru/post/150274/
 Правильное использование QThread
*/


MyThread::MyThread(QObject *parent)
    : QThread(parent),
      sinVar(0.11f),
      circleVar(0.01f),
      whirlVar(0.0f)
{
    initTriangle();
    initCircle();
    initRectangle();
}

MyThread::~MyThread()
{
}

void MyThread::run()
{
    forever{
        calcCircle();
        calcSin();
        calcWhirl();

        emit calcReady(r_coord.x0,r_coord.y0,c_coord.x0,c_coord.y0,
                       t_coord.x1,t_coord.y1,t_coord.x2,t_coord.y2,t_coord.x3,t_coord.y3);

        msleep(4);
    }
}

void MyThread::initTriangle()
{
    //1
    t_coord.x1=0;
    t_coord.y1=10;
    t_coord.z1=0;
    //2
    t_coord.x2=8;
    t_coord.y2=-5;
    t_coord.z2=0;
    //3
    t_coord.x3=-8;
    t_coord.y3=-5;
    t_coord.z3=0;
}

void MyThread::initRectangle()
{
    r_coord.x0=-150;
    r_coord.y0=50;

}

void MyThread::initCircle()
{
    c_coord.x0=150;
    c_coord.y0=-50;
}


void MyThread::calcWhirl()
{
    //mutex.lock();
    float r=40;
    float t=3.1415f * 2.0f/3;

    t_coord.x1=r*cos(3.14f/2.0f+whirlVar);
    t_coord.x2=r*cos(3.14f/2.0f+2*t+whirlVar);
    t_coord.x3=r*cos(3.14f/2.0f+t+whirlVar);
    t_coord.y1=r*sin(3.14f/2.0f+whirlVar);
    t_coord.y2=r*sin(3.14f/2.0f+2*t+whirlVar);
    t_coord.y3=r*sin(3.14f/2.0f+t+whirlVar);

    whirlVar+=0.01f;
   // mutex.unlock();

}
void MyThread::calcSin()
{
   // mutex.lock();
    if(r_coord.x0>160 || r_coord.x0<-160) sinVar=-sinVar;

    r_coord.x0+=sinVar;
    r_coord.y0=sin(r_coord.x0/10)*15;
   // mutex.unlock();
}

void MyThread::calcCircle()
{
   // mutex.lock();
    float r=50;
    c_coord.y0=r*cos(circleVar);
    c_coord.x0=r*sin(circleVar);

    circleVar+=0.01f;
   // mutex.unlock();
}


