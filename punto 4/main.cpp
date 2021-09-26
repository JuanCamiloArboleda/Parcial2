#include <iostream>
#include <QImage>
using namespace std;

int main()
{
    string filename="../parcial2-intentosinqapplication/recibir";
    QImage im( filename.c_str());
    int altomatrix,anchomatrix;
    int renglon=0,columna=0;
    int ancho=im.height(),alto=im.width(),R=0,G=0,B=0;
    cout<<"ingrese las dimensiones de la matriz: "<<endl;
    cout<<"altura de la matriz: "<<endl;
    cin>>altomatrix;
    cout<<"ancho de la matriz: "<<endl;
    cin>>anchomatrix;
    int matrix[altomatrix][anchomatrix]; //matrix 16x16
    int recuentoancho=0, recuentoalto=0;
    recuentoancho = ancho/anchomatrix;
    recuentoalto = alto/altomatrix;
    for (int z=0;z<altomatrix*anchomatrix;z++){
        for (int x=0;x<recuentoancho;x++){  //recorrer imagen
            for (int y=0;y<recuentoalto;y++){
                R=R+im.pixelColor(x+(columna*recuentoalto),y+(renglon*recuentoancho)).red();
                G=G+im.pixelColor(x+(columna*recuentoalto),y+(renglon*recuentoancho)).green();
                B=B+im.pixelColor(x+(columna*recuentoalto),y+(renglon*recuentoancho)).blue();

            }
        renglon+=1;
        }

     if (renglon==altomatrix){
             columna+=1;
             renglon=0;
     }
    }
    return 0;
}

//cout<<"intensidad del rojo: "<<im.pixelColor(x,y).red()<<endl;
//cout<<"intensidad del verde: "<<im.pixelColor(x,y).green()<<endl;
//cout<<"intensidad del azul: "<<im.pixelColor(x,y).blue()<<endl;
//a+=1;
