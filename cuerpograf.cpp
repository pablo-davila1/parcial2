#include "cuerpograf.h"
#include "QDebug"
//#include <stdlib.h>     /* srand, rand, abs */
//#include <time.h>       /* time */


cuerpograf::cuerpograf(float x, float y, float vx, float vy, float m, float r) : escala(0.01)
{
    esf = new cuerpo(x,y,vx,vy,m,r);
}

cuerpograf::~cuerpograf()
{
    delete esf;
}

QRectF cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void cuerpograf::setEscala(float s)
{
    escala = s;
}

void cuerpograf::actualizar(float dt)
{
    esf->actualizar(dt);
    setPos(esf->getX()*escala,(-esf->getY())*escala);
}

cuerpo *cuerpograf::getEsf()
{
    return esf;
}


