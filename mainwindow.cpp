#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsScene>


#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h_limit = 2000;
    v_limit = 1000;
    dt = 2;

    timer=new QTimer(this);
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);

     ui->graphicsView->setScene(scene);
     ui->centralwidget->adjustSize();

     timer->stop();
     connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    //cuerpograf(float x, float y, float vx, float vy, float m, float r);
     bars.append(new cuerpograf(0,0,0,0,50000,200));
     bars.append(new cuerpograf(-5000,0,0,-2,70,70)); // se agregan los cuerpos(planetas)
     bars.append(new cuerpograf(5000,0,0,2,70,70));
     bars.append(new cuerpograf(0,-5000,2,0,70,70));
     bars.append(new cuerpograf(0,5000,-2,0,70,70));
     for (int i = 0; i<bars.size();i++){
         bars.at(i)->actualizar(dt);
         scene->addItem(bars.at(i));

     }

}


MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{
    for (int i = 0;i<bars.size();i++) {
        for (int j = 0; i<bars.size();i++){
            if (i!=j){
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getX(),bars.at(j)->getEsf()->getY(),bars.at(j)->getEsf()->get_mass());
            }
        }

    }
    for (int i = 0; i<bars.size();i++){
        bars.at(i)->actualizar(dt);

    }


}


void MainWindow::on_pushButton_clicked()
{
    timer->start(dt);
}
