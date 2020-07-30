#ifndef CAIDA_H
#define CAIDA_H

#include <QGraphicsRectItem>

class caida : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    caida(float pos2X_, float pos2Y_, float vel2X_, float vel2Y_, float masa_, float radio_, float K_, float e_);

private slots:
    void move3();

private:
    float PX2;//posicion en x
    float PY2;//posicion en y
    float mass;//masa del cuerpo
    float R;//radio del cuerpo
    float VX2;//velocidad en x
    float VY2;//velocidad en y
    float angulo;//angulo en el que va el cuerpo.
    float AX2;//aceleracion en x
    float AY2;//aceleracion en y
    float G;//gravedad
    float K;//resistencia del aire
    float e;//coeficiente de restitucion.
    float V;//vector velocidad.
    float dt;//delta de tiempo.


};

#endif // CAIDA_H
