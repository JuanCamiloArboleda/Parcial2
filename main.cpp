#include <iostream>
#include <QImage>
using namespace std;

int main()
{
    string filename="../parcial2-intentosinqapplication/recibir";
    QImage im( filename.c_str());
    unsigned int pixelX=1023;
    unsigned int pixelY=767;
    int alto,ancho,a=0;
    cout<<"ingrese las dimensiones de la matriz: "<<endl;
    cout<<"altura de la matriz: "<<endl;
    cin>>alto;
    cout<<"ancho de la matriz: "<<endl;
    cin>>ancho;
    int R[alto][ancho],G[alto][ancho],B[alto][ancho];
    for (int x=0;x<=alto;x++){
        for (int y=0;y<=ancho;y++){
            R[x][y]=im.pixelColor(x,y).red();
            G[x][y]=im.pixelColor(x,y).green();
            B[x][y]=im.pixelColor(x,y).blue();
            cout<<R[x][y]<<G[x][y]<<B[x][y]<<endl;
            a=a+1;
            cout<<a<<endl;
        }
    }
    cout<<"intensidad del rojo: "<<im.pixelColor(pixelX,pixelY).red()<<endl;
    cout<<"intensidad del verde: "<<im.pixelColor(pixelX,pixelY).green()<<endl;
    cout<<"intensidad del azul: "<<im.pixelColor(pixelX,pixelY).blue()<<endl;
    return 0;
}
