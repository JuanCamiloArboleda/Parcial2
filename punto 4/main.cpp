#include <iostream>
#include <QImage>
#include <fstream>
#include "sobremuestreo.h"
using namespace std;

int main()
{
    cout<<"ingrese que opcion desea: "<<endl;
    cout<<"1. submuestreo de la imagen. (imagen de mayor tamanio a menor. "<<endl;
    cout<<"2. sobremuestreo de la imagen. (imagen de menor tamanio a mayor. )"<<endl;
    cout<<"3. salir del programa."<<endl;
    cout<<"( al utilizar cualquiera de las dos primeras opciones deberia terminar el programa. )"<<endl;
    sobremuestreo imagen;
    int opcion=9;
    cin>>opcion;
    switch (opcion) {
    case 1:{
        imagen.sobremuestreo2();
        break;
    }
    case 2:{
            imagen.submuestro();
            break;
    }
    case 3:{
        cout<<"el trabajo se ha cerrado exitosamente.";
        break;
    }

    }

    /*
    //cout<<"ingrese direccion relativa de la imagen: "<<endl;
    ofstream archivo;
    archivo.open("prueba.txt",ios::out);
    string filename="../parcial2-intentosinqapplication/recibir";
   // cin>>filename;
    QImage im( filename.c_str());
    int altomatrix,anchomatrix;
    int ancho=im.height(),alto=im.width(),R=0,G=0,B=0,contador=0,contador2=0;
    int opcion=9;
    cout<<"--ingrese que opcion desea: "<<endl;
    cout<<"->1. submuestreo de la imagen. (imagen de mayor tamanio a menor. "<<endl;
    cout<<"->2. sobremuestreo de la imagen. (imagen de menor tamanio a mayor. )"<<endl;
    cout<<"->3. salir del programa."<<endl;
    cout<<"( al utilizar cualquiera de las dos primeras opciones deberia terminar el programa. )"<<endl;
    while (true){
        cin>>opcion;
        if (opcion==1){
            cout<<"ingrese las dimensiones de la matriz: "<<endl;
            cout<<"altura de la matriz: "<<endl;
            cin>>altomatrix;
            cout<<"ancho de la matriz: "<<endl;
            cin>>anchomatrix;
            int matrixrojo[altomatrix][anchomatrix],matrixazul[altomatrix][anchomatrix],matrixverde[altomatrix][anchomatrix]; //matrix 16x16

            if (archivo.fail()){

                exit(1);
            }

            int recuentoancho=0, recuentoalto=0;
            recuentoancho = ancho/anchomatrix;
            recuentoalto = alto/altomatrix;
            for(int z=0; z<anchomatrix;z++){
                for(int w=0; w<altomatrix; w++){
                    for(int x=0+(z*recuentoalto); x<recuentoalto+(z*recuentoalto);x++){
                        for(int y=0+(w*recuentoancho);y<recuentoancho+(w*recuentoancho);y++){
                            R=R+im.pixelColor(x,y).red();
                            G=G+im.pixelColor(x,y).green();
                            B=B+im.pixelColor(x,y).blue();
                        }
                    }
                    matrixrojo[w][z]=R/(recuentoancho*recuentoalto);
                    matrixverde[w][z]=G/(recuentoancho*recuentoalto);
                    matrixazul[w][z]=B/(recuentoancho*recuentoalto);
                    R=0;
                    G=0;
                    B=0;
                }
            }
           for (int h=0;h<anchomatrix;h++){
               for (int sopa=0;sopa<altomatrix;sopa++){
                   archivo<<"led.setPixelColor("<<contador<<","<<matrixrojo[h][sopa]<<","<<matrixverde[h][sopa]<<","<<matrixazul[h][sopa]<<");";
                   archivo<<"\n";
                   contador++;
               }
           }
           break;
        }else if (opcion == 2){
            cout<<"ingrese las dimensiones de la matriz: "<<endl;
            cout<<"altura de la matriz: "<<endl;
            cin>>altomatrix;
            cout<<"ancho de la matriz: "<<endl;
            cin>>anchomatrix;
            int matrixrojo[altomatrix][anchomatrix],matrixazul[altomatrix][anchomatrix],matrixverde[altomatrix][anchomatrix]; //matrix 16x16
            int recuentoalto2=anchomatrix/ancho;
            int recuentoancho2=altomatrix/alto;
            for(int z=0; z<alto;z++){
                for(int w=0; w<ancho; w++){
                    for(int x=0+(w*recuentoancho2);x<recuentoancho2+(w*recuentoancho2);x++){
                        for(int y=0+(z*recuentoalto2); y<recuentoalto2+(z*recuentoalto2);y++){
                            matrixrojo[x][y]=im.pixelColor(z,w).red();
                            matrixverde[x][y]=im.pixelColor(z,w).green();
                            matrixazul[x][y]=im.pixelColor(z,w).blue();
                            cout<<matrixrojo[x][y]<<","<<matrixverde[x][y]<<","<<matrixazul[x][y];
                            cout<<endl;
                            archivo<<"led.setPixelColor("<<contador<<","<<matrixrojo[x][y]<<","<<matrixverde[x][y]<<","<<matrixazul[x][y]<<");";
                            archivo<<"\n";
                            contador++;
                            if (contador%16==0){

                                contador2++;
                            }else if(contador%16==0 && contador2==2){

                                contador2=0;
                            }
                        }
                    }
                }
            }            break;
        }else if (opcion == 3){
            cout<<"se ha finalizado el programa satisfactoriamente."<<endl;
            break;
        }
    }
    */
    return 0;
}

