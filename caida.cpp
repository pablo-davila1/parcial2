#include "caida.h"
#include <QTimer>
#include <QGraphicsScene> // create a scene
#include <QGraphicsItem>
#include <QList>
#include <math.h>
#include <cmath>
#include <QDebug>



caida::caida(float pos2X_, float pos2Y_, float vel2X_, float vel2Y_, float masa_, float radio_, float K_, float e_)
{
    int random_number = rand() % 400;

    int random_numberVX = rand() % 38;




    PX2 = pos2X_;
    PY2 = pos2Y_;
    mass = masa_;
    R = radio_;
    VX2 = random_numberVX;
    VY2 = 0;
    AX2 = 0;
    AY2 = 0;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;

    //draw a bullet
    setRect(800,random_number,20,20);

    //conection
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move3()) );
    timer->start(50);
}

void caida::move3()
{
    if(pos().x() > 800 || pos().x() < 0){
        V = pow(((VX2*VX2*(-1*e))+(VY2*VY2)),1/2);
        angulo = atan2(VY2, VX2);
        AX2 = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY2 = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
        PX2 = -1*(PX2 + (VX2*dt) + ((AX2*(dt*dt))/2));
        PY2 = PY2 + (VY2*dt) + ((AY2*(dt*dt))/2);
        VX2 = -1*(VX2 + AX2*dt);
        VY2 = VY2 + AY2*dt;
        qDebug()<<"paso";
    }
    else{
        V = pow(((VX2*VX2)+(VY2*VY2)),1/2);
        angulo = atan2(VY2, VX2);
        AX2 = -((K*(V*V)*(R*R))/mass)*cos(angulo);
        AY2 = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
        PX2 = PX2 + (VX2*dt) + ((AX2*(dt*dt))/2);
        PY2 = PY2 + (VY2*dt) + ((AY2*(dt*dt))/2);
        VX2 = VX2 + AX2*dt;
        VY2 = VY2 + AY2*dt;}


    // move bullet2 in scene
    setPos(x()+VX2,y()-VY2);

    if (pos().y() < -rect().height()){
        scene()->removeItem(this);
        delete this;
    }
}
