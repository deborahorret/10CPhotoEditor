#include "welwind.h"
#include "ui_welwind.h"
#include "mainwind.h"
#include <QImage>

WelWind::WelWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelWind)
{
    ui->setupUi(this);
    //don't show error message unless necessary
    ui->badLoad->hide();
}

WelWind::~WelWind()
{
    //Clean up dynamically managed member fields
    delete ui;
    delete mainwindow;
}

void WelWind::on_pushButton_clicked()
{
    QString path = ui->fileInput->text(); //extract the image filepath that the user typed in (default is royce.jpg)

    QImage test;
    bool loaded = test.load(path);
    if(!loaded){
        ui->badLoad->show();
    }
    else{ //if path is valid

        ui->badLoad->hide();
        mainwindow = new mainwind(this, path);
        mainwindow->setWindowTitle("Photo Editor");
        mainwindow->show();

        //only want mainwindow visible
        this->hide();
    }
}

