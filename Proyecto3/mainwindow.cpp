#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    maximo=4;
    pintar(obj1.matriz);
    ui->cuadro->setLayout(layout);
    ui->label_2->setVisible(false);

}
void MainWindow:: mousePressEvent( QMouseEvent *e){

    int xp,yp,b,j;
    char gano[10];
    ui->label_2->setVisible(false);
     cout<<"x--- "<<e->x()<<"  y--- "<<e->y()<<endl;
     xp=(e->x()-130)/57;
     yp=(e->y()-110)/51;

    b=lobo_movimiento(xp,yp);

    if(obj1.lobo.g==12){

         b=5;
         ui->label_2->setText("GANA EL LOBO!!");
         ui->label_2->setVisible(true);

         for(int i=0; i<9; i++){
             for(int j=0; j<9; j++){
                if(obj1.matriz[i][j]==3){
                   obj1.matriz[i][j]=9;
               }
             }
        }
    }else {
        if(mov_lobo()==0){
            b=5;
            ui->label_2->setText("GANAN LAS GALLINAS!!");
            ui->label_2->setVisible(true);

        }
    }

    if(b==1){

         ui->label_2->setVisible(true);

    }else{
        if(b!=5){

          j=minimax();
          obj1.matriz[obj1.gallina[j].mjy][obj1.gallina[j].mjx]=1;
            obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;

            obj1.gallina[j].y=obj1.gallina[j].mjy;
            obj1.gallina[j].x=obj1.gallina[j].mjx;
        }

    }
    sprintf(gano, "%d", obj1.lobo.g);
    ui->label_4->setText(gano);
    pintar(obj1.matriz);
}
MainWindow::~MainWindow()
{
    delete ui;
}
