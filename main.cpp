#include <QCoreApplication>
#include <iostream>
using namespace std;


void imprimirMatriz(int ** matriz,int longitud){
     for(int fila=0;fila<longitud;fila++){
         cout<<"\n";
         for(int columna=0;columna<longitud+1;columna++){
             cout<<matriz[fila][columna]<<" ";
         }
     }
}

void escalonarMatriz(int **matriz, int longitud ){
    for(int pivote=0;pivote<longitud;pivote++){
        for(int fila=0;fila<longitud;fila++){
            imprimirMatriz(matriz,longitud);
            if(fila>pivote){
                for(int columna=0;columna<longitud+1;columna++){
                    matriz[fila][columna]=matriz[fila][columna]*((matriz[pivote][pivote]))+(matriz[pivote][columna]*matriz[fila][pivote])*-1;
                }
            }
        }
    }
}



void rellenarMatriz(int ** matriz,int longitud){
    for(int fila=0;fila<longitud;fila++){
        for(int columna=0;columna<longitud+1;columna++){
            cin>>matriz[fila][columna];
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Creando la longitud de la matriz
    int x;
    cout<<"Diga la cantidad de variables"<<endl;cin>>x;


    //Creando la matriz
    int **matriz =new int*[x];
    for(int i=0;i<x;i++){
        matriz[i]=new int[x+1];
    }

    rellenarMatriz(matriz,x);
    cout<<"Mostrando matriz"<<endl;
    imprimirMatriz(matriz,x);
    cout<<"\n Matriz escalonada"<<endl;
    //escalonarMatriz(matriz,x);
escalonarMatriz(matriz,x);
imprimirMatriz(matriz,x);
    return a.exec();
}
