#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QGridLayout>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <QMainWindow>
#include <QMouseEvent>
#define verde "verde.png"
#define gallina1 "gallina.png"
#define lobo1 "lobo.png"
#define casilla "casilla.png"
#define tablero "tablero.png"

using namespace std;

class figura{
public:
    int x;
    int y;
    int g;
    int g1;
    int mjx,mjy;

};


class principal{
  public:
    principal(){
        k=0;
        char linea[100];
        ifstream data("dato.txt");

        if(data.is_open()){
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                  fflush(stdin);
                  data.getline(linea,100);
                  matriz[i][j]=atoi(linea);
                  cout<<matriz[i][j];

                  if(matriz[i][j]==1){
                      gallina[k].x=j;
                      gallina[k].y=i;

                       //cout<<" VECTOR:  "<<gallina[k].x<<"   "<<gallina[k].y<<endl;
                 k++; }

                }
                cout<<endl;
             }
         }
        gm=-1;
        lobo.g=0;
        lobo.g1=0;
       lobo.x=4;
       lobo.y=5;
    }//constructor
    int matriz[9][9],k;
    figura gallina[17];
    figura lobo;
    int gm;
};







namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QList<QLabel*> etiqueta;
    QGridLayout *layout;
    QLabel *et;
    principal obj1;
    int maximo;
    ~MainWindow();
    void mousePressEvent( QMouseEvent *e);
public slots:

    int minimax(){
        int mejor_m=-1;
        int max, max_a, x,y;

        max= INT_MIN;

       /* cout<<"Matriz mini max"<<endl;
         for(int i=0; i<9; i++){
             for(int j=0; j<9; j++){


               cout<<obj1.matriz[i][j];
             }
             cout<<endl;
          }*/

        for(int j=0; j<17;j++){
            if(obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]==1){
          for(int k=0; k<3;k++){

                    if( obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x+1]==3 && k==0){
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x+1]=1;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;
                        x=obj1.gallina[j].x;
                        y=obj1.gallina[j].y;
                        obj1.gallina[j].x++;
                        obj1.gm=j;

                        max_a= valormin(0,INT_MIN,INT_MAX);
                        obj1.gm=-1;

                        obj1.gallina[j].x=x;
                        obj1.gallina[j].y=y;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x+1]=3;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=1;  //devuelvo

                        if(max_a>max){
                            max=max_a;

                            mejor_m=j;
                            obj1.gallina[j].mjy=obj1.gallina[j].y;
                            obj1.gallina[j].mjx=obj1.gallina[j].x +1;
                        }

                    }
                    if( obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x-1]==3 && k==1){
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x-1]=1;
                        x=obj1.gallina[j].x;
                        y=obj1.gallina[j].y;
                        obj1.gallina[j].x--;
                        obj1.gm=j;

                        max_a= valormin(0,INT_MIN,INT_MAX);
                        obj1.gm=-1;
                        obj1.gallina[j].x=x;
                        obj1.gallina[j].y=y;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x-1]=3;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=1;  //devuelvo


                        if(max_a>max){
                            max=max_a;

                            mejor_m=j;
                            obj1.gallina[j].mjy=obj1.gallina[j].y;
                            obj1.gallina[j].mjx=obj1.gallina[j].x -1;
                        }
                    }
                    if( obj1.matriz[obj1.gallina[j].y+1][obj1.gallina[j].x]==3 && k==2){
                        obj1.matriz[obj1.gallina[j].y+1][obj1.gallina[j].x]=1;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;
                        x=obj1.gallina[j].x;
                        y=obj1.gallina[j].y;
                        obj1.gallina[j].y++;
                        obj1.gm=j;


                        max_a= valormin(0,INT_MIN,INT_MAX);

                        obj1.gm=-1;
                        obj1.gallina[j].x=x;
                        obj1.gallina[j].y=y;
                        obj1.matriz[obj1.gallina[j].y+1][obj1.gallina[j].x]=3;
                        obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=1;  //devuelvo

                        if(max_a>max){

                            max=max_a;
                            mejor_m=j;
                            obj1.gallina[j].mjy=obj1.gallina[j].y+1;
                            obj1.gallina[j].mjx=obj1.gallina[j].x;
                        }
                    }
            }//for k
          }//if 1
        }

cout<<"---MAX:--"<<max<<endl;
cout<<"mejor mov "<<mejor_m<<endl;

        return mejor_m;
    }//MIN MAX

    int valormax(int prof, int alfa, int beta){
        int fin= ganador();
        int x,y;

        if(fin==2){
            return heuristica();
        }else{
            if(prof>maximo){
                return heuristica();
            }else{
                for(int j=0; j<17;j++){
                    if(obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]==1){
                  for(int k=0; k<3;k++){

                            if( obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x+1]==3 && k==0){
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x+1]=1;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;
                                x=obj1.gallina[j].x;
                                y=obj1.gallina[j].y;
                                obj1.gallina[j].x++;
                                obj1.gm=j;

                               alfa=max(alfa,valormin(prof+1,alfa,beta));

                              obj1.gm=-1;
                              obj1.gallina[j].x=x;
                                obj1.gallina[j].y=y;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x+1]=3;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=1;  //devuelvo

                                if(alfa>=beta){
                                    return beta;
                                }

                            }
                            if( obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x-1]==3 && k==1){
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x-1]=1;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;
                                x=obj1.gallina[j].x;
                                y=obj1.gallina[j].y;
                                obj1.gallina[j].x--;
                                obj1.gm=j;

                                alfa=max(alfa,valormin(prof+1,alfa,beta));
                                obj1.gm=-1;
                               obj1.gallina[j].x=x;
                                obj1.gallina[j].y=y;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x-1]=3;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=1;  //devuelvo

                                if(alfa>=beta){
                                    return beta;
                                }
                            }
                            if( obj1.matriz[obj1.gallina[j].y+1][obj1.gallina[j].x]==3 && k==2){
                                obj1.matriz[obj1.gallina[j].y+1][obj1.gallina[j].x]=1;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=3;
                                x=obj1.gallina[j].x;
                                y=obj1.gallina[j].y;
                                obj1.gallina[j].y++;
                                obj1.gm=j;

                                alfa=max(alfa,valormin(prof+1,alfa,beta));
                                obj1.gm=-1;

                               obj1.gallina[j].x=x;
                                obj1.gallina[j].y=y;
                                obj1.matriz[obj1.gallina[j].y+1][obj1.gallina[j].x]=3;
                                obj1.matriz[obj1.gallina[j].y][obj1.gallina[j].x]=1;  //devuelvo

                                if(alfa>=beta){
                                    return beta;
                                }
                            }
                        }//for k
                  }
                } return alfa;

            }
        }

    }// ValoMax

    int valormin(int prof, int alfa, int beta){
        int fin= ganador();
        int x,y;


        if(fin==1){
            return heuristica();
        }else{
            if(prof>maximo){
                return heuristica();
            }else{
                for(int j=0; j<8;j++){
                    if( (obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]==1)&&(obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+2]==3) && j==0){
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x+2]=2;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                        obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]=3;
                        x=obj1.lobo.x;
                        obj1.lobo.g1++;
                        obj1.lobo.x=obj1.lobo.x+2;

                        beta=min(beta,valormax(prof+1,alfa,beta));
                         obj1.lobo.g1--;
                       obj1.lobo.x=x;
                         obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x+2]=3;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo

                        if(alfa>=beta){
                            return alfa;
                        }
                    }else{
                        if( (obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]==3) && j==0){
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x+1]=2;
                             obj1.matriz[obj1.lobo.y][(obj1.lobo.x)]=3;
                            x=obj1.lobo.x;

                            obj1.lobo.x=obj1.lobo.x+1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                           obj1.lobo.x=x;

                            obj1.matriz[obj1.lobo.y][obj1.lobo.x+1]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo

                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }
               //------------------------------------------------------------------------------------------------

                    if((obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]==1)&&(obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-2]==3) && j==1 ){
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x-2]=2;
                         obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]=3;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                        x=obj1.lobo.x;
                        obj1.lobo.g1++;
                        obj1.lobo.x=obj1.lobo.x-2;

                        beta=min(beta,valormax(prof+1,alfa,beta));

                       obj1.lobo.x=x;
                        obj1.lobo.g1--;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x-2]=3;
                         obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }

                    }else{
                        if( (obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]==3)&& j==1){
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x-1]=2;
                             obj1.matriz[obj1.lobo.y][(obj1.lobo.x)]=3;
                            x=obj1.lobo.x;

                            obj1.lobo.x=obj1.lobo.x-1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                           obj1.lobo.x=x;

                            obj1.matriz[obj1.lobo.y][obj1.lobo.x-1]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }

              //---------------------------------------------------------------------------------------------------------

                    if((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]==1)&&(obj1.matriz[obj1.lobo.y-2][(obj1.lobo.x)]==3) && j==2){
                        obj1.matriz[obj1.lobo.y-2][obj1.lobo.x]=2;
                         obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]=3;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                        obj1.lobo.g1++;
                        y=obj1.lobo.y;
                        obj1.lobo.y=obj1.lobo.y-2;

                        beta=min(beta,valormax(prof+1,alfa,beta));

                        obj1.lobo.g1--;
                        obj1.lobo.y=y;
                        obj1.matriz[obj1.lobo.y-2][obj1.lobo.x]=3;
                         obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }

                    }else{
                        if( (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]==3)&& j==2){
                            obj1.matriz[obj1.lobo.y-1][obj1.lobo.x]=2;
                             obj1.matriz[obj1.lobo.y][(obj1.lobo.x)]=3;
                            y=obj1.lobo.y;
                            obj1.lobo.y=obj1.lobo.y-1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                            obj1.lobo.y=y;
                            obj1.matriz[obj1.lobo.y-1][obj1.lobo.x]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }

              //---------------------------------------------------------------------------------------------
                    if((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]==1)&&(obj1.matriz[obj1.lobo.y+2][(obj1.lobo.x)]==3)&& j==3){
                        obj1.matriz[obj1.lobo.y+2][obj1.lobo.x]=2;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                         obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]=3;
                        obj1.lobo.g1++;
                        y=obj1.lobo.y;
                        obj1.lobo.y=obj1.lobo.y+2;

                        beta=min(beta,valormax(prof+1,alfa,beta));
                            obj1.lobo.g1--;
                        obj1.lobo.y=y;
                        obj1.matriz[obj1.lobo.y+2][obj1.lobo.x]=3;
                         obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }

                    }else{
                        if( (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]==3)&& j==3){
                            obj1.matriz[obj1.lobo.y+1][obj1.lobo.x]=2;
                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                            y=obj1.lobo.y;
                            obj1.lobo.y=obj1.lobo.y+1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                            obj1.lobo.y=y;
                            obj1.matriz[obj1.lobo.y+1][obj1.lobo.x]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }
            //-------------------------------------------------------------------------------------------------------
                    if( (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)+1]==1)&& (obj1.matriz[obj1.lobo.y+2][(obj1.lobo.x)+2]==3) && j==4){
                        obj1.matriz[obj1.lobo.y+2][obj1.lobo.x+2]=2;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                          obj1.matriz[obj1.lobo.y+1][obj1.lobo.x+1]=3;
                        x=obj1.lobo.x;
                        y=obj1.lobo.y;
                        obj1.lobo.y=obj1.lobo.y+2;
                        obj1.lobo.x=obj1.lobo.x+2;
                        obj1.lobo.g1++;
                        beta=min(beta,valormax(prof+1,alfa,beta));
                        obj1.lobo.g1--;
                        obj1.lobo.y=y;
                        obj1.lobo.x=x;
                        obj1.matriz[obj1.lobo.y+2][obj1.lobo.x+2]=3;
                         obj1.matriz[obj1.lobo.y+1][obj1.lobo.x+1]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }
                    }else{
                        if( (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)+1]==3)&& j==4){
                            obj1.matriz[obj1.lobo.y+1][obj1.lobo.x+1]=2;
                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                            x=obj1.lobo.x;
                            y=obj1.lobo.y;
                            obj1.lobo.y=obj1.lobo.y+1;
                            obj1.lobo.x=obj1.lobo.x+1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                            obj1.lobo.y=y;
                            obj1.lobo.x=x;
                            obj1.matriz[obj1.lobo.y+1][obj1.lobo.x+1]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }
            //----------------------------------------------------------------------------------------------------------------
                    if( (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)-1]==1)&& (obj1.matriz[obj1.lobo.y-2][(obj1.lobo.x)-2]==3) && j==5){
                        obj1.matriz[obj1.lobo.y-2][obj1.lobo.x-2]=2;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                          obj1.matriz[obj1.lobo.y-1][obj1.lobo.x-1]=3;
                        x=obj1.lobo.x;
                        y=obj1.lobo.y;
                        obj1.lobo.y=obj1.lobo.y-2;
                        obj1.lobo.x=obj1.lobo.x-2;
                        obj1.lobo.g1++;
                        beta=min(beta,valormax(prof+1,alfa,beta));
                        obj1.lobo.g1--;
                        obj1.lobo.y=y;
                        obj1.lobo.x=x;
                        obj1.matriz[obj1.lobo.y-2][obj1.lobo.x-2]=3;
                         obj1.matriz[obj1.lobo.y-1][obj1.lobo.x-1]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }
                    }else{
                        if( (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)-1]==3)&& j==5){
                            obj1.matriz[obj1.lobo.y-1][obj1.lobo.x-1]=2;
                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                            x=obj1.lobo.x;
                            y=obj1.lobo.y;
                            obj1.lobo.y=obj1.lobo.y-1;
                            obj1.lobo.x=obj1.lobo.x-1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                            obj1.lobo.y=y;
                            obj1.lobo.x=x;
                            obj1.matriz[obj1.lobo.y-1][obj1.lobo.x-1]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }

            //--------------------------------------------------------------------------------------------------------------------
                    if( (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)-1]==1)&& (obj1.matriz[obj1.lobo.y+2][(obj1.lobo.x)-2]==3)&& j==6 ){
                        obj1.matriz[obj1.lobo.y+2][obj1.lobo.x-2]=2;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                          obj1.matriz[obj1.lobo.y+1][obj1.lobo.x-1]=3;
                        x=obj1.lobo.x;
                        y=obj1.lobo.y;
                        obj1.lobo.y=obj1.lobo.y+2;
                        obj1.lobo.x=obj1.lobo.x-2;
                        obj1.lobo.g1++;
                        beta=min(beta,valormax(prof+1,alfa,beta));
                        obj1.lobo.g1--;
                        obj1.lobo.y=y;
                        obj1.lobo.x=x;
                        obj1.matriz[obj1.lobo.y+2][obj1.lobo.x-2]=3;
                         obj1.matriz[obj1.lobo.y+1][obj1.lobo.x-1]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }
                    }else{
                        if( (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)-1]==3)&& j==6){
                            obj1.matriz[obj1.lobo.y+1][obj1.lobo.x-1]=2;
                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                            x=obj1.lobo.x;
                            y=obj1.lobo.y;
                            obj1.lobo.y=obj1.lobo.y+1;
                            obj1.lobo.x=obj1.lobo.x-1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                            obj1.lobo.y=y;
                            obj1.lobo.x=x;
                            obj1.matriz[obj1.lobo.y+1][obj1.lobo.x-1]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }

             //-----------------------------------------------------------------------------------------------------------
                    if( (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)+1]==1)&& (obj1.matriz[obj1.lobo.y-2][(obj1.lobo.x)+2]==3)&& j==7 ){
                        obj1.matriz[obj1.lobo.y-2][obj1.lobo.x+2]=2;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                          obj1.matriz[obj1.lobo.y-1][obj1.lobo.x+1]=3;
                        x=obj1.lobo.x;
                        y=obj1.lobo.y;
                        obj1.lobo.y=obj1.lobo.y-2;
                        obj1.lobo.x=obj1.lobo.x+2;
                        obj1.lobo.g1++;
                        beta=min(beta,valormax(prof+1,alfa,beta));
                        obj1.lobo.g1--;
                        obj1.lobo.y=y;
                        obj1.lobo.x=x;
                        obj1.matriz[obj1.lobo.y-2][obj1.lobo.x+2]=3;
                         obj1.matriz[obj1.lobo.y-1][obj1.lobo.x+1]=1;
                        obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                        if(alfa>=beta){
                            return alfa;
                        }
                    }else{
                        if( (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)+1]==3)&& j==7){
                            obj1.matriz[obj1.lobo.y-1][obj1.lobo.x+1]=2;
                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                            x=obj1.lobo.x;
                            y=obj1.lobo.y;
                            obj1.lobo.y=obj1.lobo.y-1;
                            obj1.lobo.x=obj1.lobo.x+1;

                            beta=min(beta,valormax(prof+1,alfa,beta));

                            obj1.lobo.y=y;
                            obj1.lobo.x=x;
                            obj1.matriz[obj1.lobo.y-1][obj1.lobo.x+1]=3;
                            obj1.matriz[obj1.lobo.y][obj1.lobo.x]=2;  //devuelvo
                            if(alfa>=beta){
                                return alfa;
                            }
                        }
                    }

                }return beta;

            }
        }

    }// ValoMax

    int min(int a,int b){
        if(a<b){
            return a;
        }else{
            return b;
        }
    }
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }

    int heuristica(){
        int cost;
        int fin= ganador();

        if(fin==1){
            return -1000;
        }else{
            if(fin==2)
                return 1000;
        }
        cost= (costoG()+radar()+bajar())-costoL();
       // cout<<"costo g"<<costoG()+radar()+bajar()<<"  costoL: "<<costoL()<<"  Costo t:"<<cost<<endl;
        return cost;

    }
    int costoL(){
        int c;
        if(obj1.lobo.g1>obj1.lobo.g){
            c=((obj1.lobo.g1-obj1.lobo.g)*100);
            //cout<<"C: comida "<<c<<endl;
            return c;
        }else{
            c=mov_lobo()*10;
            //cout<<"C: movimiento "<<c<<endl;
            return c;
        }
    }
    int costoG(){
        int c=mov_lobo();

        if(c==8){
            return 0;
        }else{
            return ((8-c)*10);
        }
    }

    int ganador(){
        if((obj1.lobo.g1)==12){
            return 1;
        }else{
            if(mov_lobo()==0){
                return 2;
            }else{
                return 0;
            }
        }
    }//GANADOR
    int bajar(){
        if(obj1.matriz[obj1.gallina[obj1.gm].y+1][obj1.gallina[obj1.gm].x]==3){
            return 50;
        }else{
          /* if(( obj1.gallina[obj1.gm].x<4 && obj1.matriz[obj1.gallina[obj1.gm].y][obj1.gallina[obj1.gm].x+1]==3) || (obj1.gallina[obj1.gm].x>=4 && obj1.matriz[obj1.gallina[obj1.gm].y][obj1.gallina[obj1.gm].x-1]==3)){
                return 10;
            }else{

        }*/
        return 0;
        }
    }

    int radar(){

        if(( (obj1.matriz[obj1.gallina[obj1.gm].y][(obj1.gallina[obj1.gm].x)+1]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y][(obj1.gallina[obj1.gm].x)-1]==1)|| (obj1.matriz[obj1.gallina[obj1.gm].y][(obj1.gallina[obj1.gm].x)-1]==0) )) ){

            return 80;

        }
        if(((obj1.matriz[obj1.gallina[obj1.gm].y][(obj1.gallina[obj1.gm].x)-1]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y][(obj1.gallina[obj1.gm].x)+1]==1)|| (obj1.matriz[obj1.gallina[obj1.gm].y][(obj1.gallina[obj1.gm].x)+1]==0)))){

            return 80;
        }
        if(((obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)]==1)||(obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)]==0)))){

            return 80;
        }
        if(((obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y+2][(obj1.gallina[obj1.gm].x)]==1)||(obj1.matriz[obj1.gallina[obj1.gm].y+2][(obj1.gallina[obj1.gm].x)]==0)))){
            return 80;
        }

        if( ((obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)+1]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)-1]==1)||(obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)-1]==0)))){

            return 80;
        }

        if( ((obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)-1]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)+1]==1)||(obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)+1]==0)))){

            return 80;
        }
        if( ((obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)-1]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)+1]==1)|| (obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)+1]==0)))){

            return 80;
        }
        if( ((obj1.matriz[obj1.gallina[obj1.gm].y-1][(obj1.gallina[obj1.gm].x)+1]==2)&& ((obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)-1]==1)||(obj1.matriz[obj1.gallina[obj1.gm].y+1][(obj1.gallina[obj1.gm].x)-1]==0)))){
            return 80;
        }
        return 0;

    }

    int mov_lobo(){
        int c=0;
        if(( (obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]==1)&&(obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+2]==3)) || (obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]==3)  ){
           c++;
        }
        if(((obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]==1)&&(obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-2]==3))||(obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]==3)){
            c++;
        }
        if(((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]==1)&&(obj1.matriz[obj1.lobo.y-2][(obj1.lobo.x)]==3))|| (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]==3)){
            c++;
        }
        if(((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]==1)&&(obj1.matriz[obj1.lobo.y+2][(obj1.lobo.x)]==3))|| (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]==3)){
            c++;
        }

        if( ((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)+1]==1)&& (obj1.matriz[obj1.lobo.y+2][(obj1.lobo.x)+2]==3))|| (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)+1]==3) ){
           c++;
        }

        if( ((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)-1]==1)&& (obj1.matriz[obj1.lobo.y-2][(obj1.lobo.x)-2]==3))|| (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)-1]==3) ){
           c++;
        }
        if(((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)-1]==1)&& (obj1.matriz[obj1.lobo.y+2][(obj1.lobo.x)-2]==3))|| (obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)-1]==3) ){
            c++;
        }
        if(((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)+1]==1)&& (obj1.matriz[obj1.lobo.y-2][(obj1.lobo.x)+2]==3))|| (obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)+1]==3) ){
           c++;
        }

        if(c==0){
            return 0;
        }else{
            return c;
        }

    }//Movimiento Lobo


    int lobo_movimiento(int xp, int yp ){
        int antes,con=0;
        antes= obj1.lobo.g;

         if(obj1.matriz[yp][xp]==3){

             if( ((((obj1.lobo.x)+1==xp) || ((obj1.lobo.x)-1==xp)) && ((obj1.lobo.y)==yp) ) || ((((obj1.lobo.y)+1==yp) || ((obj1.lobo.y)-1==yp))&& ((obj1.lobo.x)==xp)) || (((obj1.lobo.y)-1==yp)&& ((obj1.lobo.x)-1==xp)) || (((obj1.lobo.y)+1==yp)&& ((obj1.lobo.x)+1==xp)) || (((obj1.lobo.y)-1==yp)&& ((obj1.lobo.x)+1==xp)) || (((obj1.lobo.y)+1==yp)&& ((obj1.lobo.x)-1==xp)) ){
                 obj1.matriz[yp][xp]=2;

                 obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;

                 obj1.lobo.x=xp;
                 obj1.lobo.y=yp;
                    con++;

             }else{
                 if( ((obj1.matriz[obj1.lobo.y][(obj1.lobo.x)+1]==1)&&(((obj1.lobo.x)+2==xp && obj1.lobo.y==yp))) ){
                     obj1.lobo.g++;

                     obj1.matriz[yp][xp]=2;
                     obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                     obj1.matriz[obj1.lobo.y][obj1.lobo.x+1]=3;
                     obj1.lobo.x=xp;
                     obj1.lobo.y=yp;
                     con++;
                 }else{
                     if(((obj1.matriz[obj1.lobo.y][(obj1.lobo.x)-1]==1)&&(((obj1.lobo.x)-2==xp && obj1.lobo.y==yp)))){
                         obj1.lobo.g++;

                         obj1.matriz[yp][xp]=2;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                         obj1.matriz[obj1.lobo.y][obj1.lobo.x-1]=3;
                         obj1.lobo.x=xp;
                         obj1.lobo.y=yp;
                         con++;
                     }else{
                         if(((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)]==1)&&(((obj1.lobo.y)-2==yp  && obj1.lobo.x==xp)))){
                             obj1.lobo.g++;

                             obj1.matriz[yp][xp]=2;
                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                             obj1.matriz[obj1.lobo.y-1][obj1.lobo.x]=3;
                             obj1.lobo.x=xp;
                             obj1.lobo.y=yp;
                             con++;
                         }else{
                             if(((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)]==1)&&(((obj1.lobo.y)+2==yp  && obj1.lobo.x==xp)))){
                                 obj1.lobo.g++;

                                 obj1.matriz[yp][xp]=2;
                                 obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                                 obj1.matriz[obj1.lobo.y+1][obj1.lobo.x]=3;
                                 obj1.lobo.x=xp;
                                 obj1.lobo.y=yp;
                                 con++;

                             }
                             else{

                                 if( ((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)+1]==1)&& ((obj1.lobo.x)+2==xp && (obj1.lobo.y)+2==yp)) ){
                                     obj1.lobo.g++;

                                     obj1.matriz[yp][xp]=2;
                                     obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                                     obj1.matriz[obj1.lobo.y+1][obj1.lobo.x+1]=3;
                                     obj1.lobo.x=xp;
                                     obj1.lobo.y=yp;
                                     con++;

                                 }
                                 else{
                                     if( ((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)-1]==1)&& ((obj1.lobo.x)-2==xp && (obj1.lobo.y)-2==yp)) ){
                                         obj1.lobo.g++;

                                         obj1.matriz[yp][xp]=2;
                                         obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                                         obj1.matriz[obj1.lobo.y-1][obj1.lobo.x-1]=3;
                                         obj1.lobo.x=xp;
                                         obj1.lobo.y=yp;
                                         con++;
                                     }else{
                                         if( ((obj1.matriz[obj1.lobo.y+1][(obj1.lobo.x)-1]==1)&& ((obj1.lobo.x)-2==xp && (obj1.lobo.y)+2==yp)) ){
                                             obj1.lobo.g++;

                                             obj1.matriz[yp][xp]=2;
                                             obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                                             obj1.matriz[obj1.lobo.y+1][obj1.lobo.x-1]=3;
                                             obj1.lobo.x=xp;
                                             obj1.lobo.y=yp;
                                             con++;
                                         }else{
                                             if( ((obj1.matriz[obj1.lobo.y-1][(obj1.lobo.x)+1]==1)&& ((obj1.lobo.x)+2==xp && (obj1.lobo.y)-2==yp)) ){
                                                 obj1.lobo.g++;

                                                 obj1.matriz[yp][xp]=2;
                                                 obj1.matriz[obj1.lobo.y][obj1.lobo.x]=3;
                                                 obj1.matriz[obj1.lobo.y-1][obj1.lobo.x+1]=3;
                                                 obj1.lobo.x=xp;
                                                 obj1.lobo.y=yp;
                                                 con++;
                                             }
                                         }
                                     }
                                 }

                             }

                         }
                     }

                 }
             }
         }else{
             return 5;
         }

         if(con==0){
             return 5;
         }

         cout<<obj1.lobo.x<<"   "<<obj1.lobo.y<<endl;
            int ban=0;
         if(antes<obj1.lobo.g){
             if(obj1.matriz[obj1.lobo.y+1][obj1.lobo.x+1]==1 && obj1.matriz[obj1.lobo.y+2][obj1.lobo.x+2]==3){
                 ban++;


             }else{
                 if(obj1.matriz[obj1.lobo.y][obj1.lobo.x+1]==1 && obj1.matriz[obj1.lobo.y][obj1.lobo.x+2]==3){
                     ban++;


                 }else{
                     if(obj1.matriz[obj1.lobo.y-1][obj1.lobo.x+1]==1 && obj1.matriz[obj1.lobo.y-2][obj1.lobo.x+2]==3){
                         ban++;

                     }else{
                         if(obj1.matriz[obj1.lobo.y][obj1.lobo.x-1]==1 && obj1.matriz[obj1.lobo.y][obj1.lobo.x-2]==3){
                             ban++;

                         }else{
                             if(obj1.matriz[obj1.lobo.y-1][obj1.lobo.x-1]==1 && obj1.matriz[obj1.lobo.y-2][obj1.lobo.x-2]==3){
                                ban++;

                             }else{
                                 if(obj1.matriz[obj1.lobo.y+1][obj1.lobo.x-1]==1 && obj1.matriz[obj1.lobo.y+2][obj1.lobo.x-2]==3){
                                     ban++;

                             }else{
                                 if(obj1.matriz[obj1.lobo.y-1][obj1.lobo.x]==1 && obj1.matriz[obj1.lobo.y-2][obj1.lobo.x]==3){
                                     ban++;

                                 }else{
                                     if(obj1.matriz[obj1.lobo.y+1][obj1.lobo.x]==1 && obj1.matriz[obj1.lobo.y+2][obj1.lobo.x]==3){
                                         ban++;

                                     }
                                 }
                             }
                         }
                     }
                 }

          }
         }

        }//doble salto
        cout<<"Matriz movi lobo"<<endl;
         for(int i=0; i<9; i++){
             for(int j=0; j<9; j++){


               cout<<obj1.matriz[i][j];
             }
             cout<<endl;
          }
         //cout<<obj1.lobo.x<<"   "<<obj1.lobo.y<<endl;

         obj1.lobo.g1=obj1.lobo.g;
         if(ban!=0){
            return 1;
         }else{
             return 0;
         }


    }//lobo
    void pintar(int matriz[9][9]){

        int i=0;
        for(int j=0;j<(81);j++){
            etiqueta<< new QLabel(this);
        }


        for(int j=0;j<9;j++){
             for(int k=0;k<9;k++){

        if(matriz[j][k]==0){
            etiqueta.at(i)->setPixmap(QPixmap(verde));

        }else{
            if(matriz[j][k]==1){
                etiqueta.at(i)->setPixmap(QPixmap(gallina1));

            }else{
                if(matriz[j][k]==2){
                    etiqueta.at(i)->setPixmap(QPixmap(lobo1));

                }else{
                    if(matriz[j][k]==3 || matriz[j][k]==9){
                        etiqueta.at(i)->setPixmap(QPixmap(casilla));

                    }
                }}}i++;}}

        layout = new QGridLayout();
        int x=0, y=0,z=0;

        for(int i=0;i<9;i++){
             for(int j=0;j<9;j++){
                layout->addWidget(etiqueta[z],y,x);
                z++;
                x++;
             }
             x=0;
             y++;
         }


    }//pintar

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
