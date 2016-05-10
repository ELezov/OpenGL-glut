#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QMutexLocker>
#include <QMutex>

struct triangleCoord
{
    float x1,x2,x3,y1,y2,y3,z1,z2,z3;
};

struct rectangleCoord
{
    float x0,y0;
};

struct circleCoord
{
    float x0,y0;
};

class MyThread : public QThread
{
    Q_OBJECT

public:
   MyThread(QObject *parent=0);
   ~MyThread();

protected :
    void run();

private:
    QMutex mutex;

    void calcCircle();
    void calcSin();
    void calcWhirl();

    float whirlVar;
    float sinVar;
    float circleVar;

    triangleCoord t_coord;
    rectangleCoord r_coord;
    circleCoord c_coord;

    void initTriangle();
    void initRectangle();
    void initCircle();

signals:
    void calcReady(float,float,float,float,
                   float,float,float,float,float,float);
    //void finished();
};

#endif // MYTHREAD_H
