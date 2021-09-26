#include <iostream>
#include <QImage>
#include <fstream>
using namespace std;

int main()
{

    string filename="../parcial2-intentosinqapplication/recibir";
    QImage im( filename.c_str());
    int altomatrix,anchomatrix;
    int ancho=im.height(),alto=im.width(),R=0,G=0,B=0;
    cout<<"ingrese las dimensiones de la matriz: "<<endl;
    cout<<"altura de la matriz: "<<endl;
    cin>>altomatrix;
    cout<<"ancho de la matriz: "<<endl;
    cin>>anchomatrix;
    int matrixrojo[altomatrix][anchomatrix],matrixazul[altomatrix][anchomatrix],matrixverde[altomatrix][anchomatrix]; //matrix 16x16
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
            matrixrojo[z][w]=R/(recuentoancho*recuentoalto);
            matrixverde[z][w]=G/(recuentoancho*recuentoalto);
            matrixazul[z][w]=B/(recuentoancho*recuentoalto);
            R=0;
            G=0;
            B=0;
        }
    }
   for (int h=0;h<altomatrix;h++){
       for (int sopa=0;sopa<anchomatrix;sopa++){
           cout<<matrixazul[h][sopa];
       }
       cout<<endl;
   }

    return 0;
}

