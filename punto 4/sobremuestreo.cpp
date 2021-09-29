#include "sobremuestreo.h"
#include "iostream"
#include "fstream"
#include "QImage"

using namespace std;

sobremuestreo::sobremuestreo()
{

}

void sobremuestreo::sobremuestreo2()
{
    cout<<"ingrese direccion relativa del archivo: "<<endl;
    ofstream archivo;
    archivo.open("prueba.txt",ios::out);
    string filename="../parcial2-intentosinqapplication/recibir";
    cin>>filename;
    QImage im( filename.c_str());
    int altomatrix,anchomatrix;
    int R=0,G=0,B=0,contador=0;
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

}

void sobremuestreo::submuestro()
{
    int contador;
    cout<<"ingrese direccion relativa del archivo: "<<endl;
    ofstream archivo;
    archivo.open("prueba.txt",ios::out);
    string filename="../parcial2-intentosinqapplication/recibir";
    cin>>filename;
    QImage im( filename.c_str());
    int altomatrix=0,anchomatrix=0;
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
                    matrixrojo[x][y]=im.pixelColor(w,z).red();
                    matrixverde[x][y]=im.pixelColor(w,z).green();
                    matrixazul[x][y]=im.pixelColor(w,z).blue();
                    archivo<<"led.setPixelColor("<<contador<<","<<matrixrojo[x][y]<<","<<matrixverde[x][y]<<","<<matrixazul[x][y]<<");";
                    archivo<<"\n";
                    contador++;
                }
            }
        }
    }
}

int sobremuestreo::leeralto()
{
   string filename="../parcial2-intentosinqapplication/recibir";
   QImage im( filename.c_str());
   alto=im.width();
   return alto;

}

int sobremuestreo::leerancho()
{
    string filename="../parcial2-intentosinqapplication/recibir";
    QImage im( filename.c_str());
    ancho=im.height();
    return ancho;
}
