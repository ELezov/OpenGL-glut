#include <QtGui>
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

my3Dscene::my3Dscene(QWidget *parent) :
    QGLWidget(parent)

{
   initTriangle();
   initCircle();
   initRectangle();

  // timer.start(50);

  // connect(&timer,SIGNAL(timeout()),this,SLOT(moveAll()));

   //начала потока
   thread.start();
   //при запуске потока будет вызван метод moveALL
   connect(&thread,SIGNAL(calcReady(float,float,float,float,
                                    float,float,float,float,float,float)),
           this,SLOT(moveAll(float,float,float,float,
                             float,float,float,float,float,float)));

}

my3Dscene::~my3Dscene()
{

}

void my3Dscene::initializeGL()
{
    //установка цвета фона
    glClearColor(0.0,0.0,0.0,0.0);
    //включение буфера глубины
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_ALPHA_TEST);
    //включение смешивания цветов
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Инициализация массивов
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

}

//Установление области вывода, размеры окна вывода
void my3Dscene::resizeGL(int nWidth, int nHeight)
{
    //режим вывода
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;

    if (nWidth>=nHeight)
       glOrtho(-100.0/ratio, 100.0/ratio, -100.0, 100.0, -100.0, 100.0);
    else
       glOrtho(-100.0, 100.0, -100.0*ratio, 100.0*ratio, -100.0, 100.0);

    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void my3Dscene::paintGL()
{
    //очистка буффера
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //включение режима просмотра
    glMatrixMode(GL_MODELVIEW);
    //Считывание матриц
    glLoadIdentity();
    //Рисование
    paintAll();

}
//Отрисовка сцены
void my3Dscene::paintAll()
{
    paintTriangle();
    paintRectangle();
    paintCircle();
    paintCircle1();
}

//Отрисовка треугольника
void my3Dscene::paintTriangle()
{
    glBegin(GL_TRIANGLES);
        glColor3d(0.4,1,0.1);
        glVertex3d(t_coord.x1,t_coord.y1,0);

        glColor3d(0.1,0.1,0.4);
        glVertex3d(t_coord.x2,t_coord.y2,0);

        glColor3d(0.1,0.4,0.1);
        glVertex3d(t_coord.x3,t_coord.y3,0);
    glEnd();
}
//Отрисовка квадрата
void my3Dscene::paintRectangle()
{
    glBegin(GL_QUADS);
        glColor3d(0,0,1);
        glVertex3d(r_coord.x0+30,r_coord.y0+30,0);

        glColor3d(0,1,0);
        glVertex3d(r_coord.x0+30,r_coord.y0-30,0);

        glColor3d(1,0,0);
        glVertex3d(r_coord.x0-30,r_coord.y0-30,0);

        glColor3d(1,0,0);
        glVertex3d(r_coord.x0-30,r_coord.y0+30,0);
    glEnd();
}
//Отрисовка круга
void my3Dscene::paintCircle()
{
    const float r=30;
    const float sides=5;
    glBegin( GL_TRIANGLE_FAN );
                  for(int i = 0; i <= sides; i++ )
                  {
                      float a = (float)i / sides * 3.1415f * 2.0f;
                      float dx=cos(a)*r;
                      float dy=sin(a)*r;
                      glColor3d(1-dx/r,dx/r,1-dy/r);
                      glVertex2f( c_coord.x0 + dx,c_coord.y0 + dy);
                  }
    glEnd();
}


//Отрисовка круга!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void my3Dscene::paintCircle1()
{
    const float r=40;
    const float sides=40;
    glBegin( GL_TRIANGLE_FAN );
                  for(int i = 0; i <= sides; i++ )
                  {
                      float a = (float)i / sides * 3.1415f * 2.0f;
                      float dx=cos(a)*r;
                      float dy=sin(a)*r;
                      glColor3d(1,1,1);
                      glVertex2f( c_coord.x0 + dx,c_coord.y0 + dy);
                  }
    glEnd();
}







//Инициализация треугольника
void my3Dscene::initTriangle()
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

//Инициализация прямоугольника
void my3Dscene::initRectangle()
{
    r_coord.x0=-150;
    r_coord.y0=50;

}

//Инициализация круга
void my3Dscene::initCircle()
{
    c_coord.x0=150;
    c_coord.y0=-50;
}

//Инициализация движения
void my3Dscene::moveAll(float r_x0, float r_y0,float c_x0, float c_y0,
                        float t_x1, float t_y1,float t_x2, float t_y2,float t_x3, float t_y3)
{
    //calcCircle();
   // calcSin();
   // calcWhirl();

    this->t_coord.x1=t_x1;
    this->t_coord.x2=t_x2;
    this->t_coord.x3=t_x3;
    this->t_coord.y1=t_y1;
    this->t_coord.y2=t_y2;
    this->t_coord.y3=t_y3;

    this->r_coord.x0=r_x0;
    this->r_coord.y0=r_y0;

    this->c_coord.x0=c_x0;
    this->c_coord.y0=c_y0;

    updateGL();
}
