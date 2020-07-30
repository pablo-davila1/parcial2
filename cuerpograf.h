#ifndef CUERPOGRAF_H
#define CUERPOGRAF_H


#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "cuerpo.h"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */

class cuerpograf: public QGraphicsItem
{
public:
    cuerpograf(float x, float y, float vx, float vy, float m, float r);
    ~cuerpograf();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    void actualizar(float dt);
    cuerpo* getEsf();

private:
    cuerpo* esf;
    float escala;
};

#endif // CUERPOGRAF_H
