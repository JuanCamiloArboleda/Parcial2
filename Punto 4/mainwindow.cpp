#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_imagenbtn_clicked()
{
    QString archivo = QFileDialog::getOpenFileName(this, tr("elije"),"", tr("images(*.png *.jpg *.jpeg *.bmp *.gif)"));
    
    if (QString::compare(archivo, QString()) != 0 ){
        QImage image;
        bool valido=image.load(archivo);
        if  (valido){
            image=image.scaledToWidth(ui->labelimage->width(),Qt::SmoothTransformation);
            ui->labelimage->setPixmap(QPixmap::fromImage(image));
        }
    }
}

