#include "savewind.h"
#include "ui_savewind.h"
#include <QDateTime>
#include <QStandardPaths>

savewind::savewind(QWidget *_parent, Image* _img) :
    QDialog(_parent),
    ui(new Ui::savewind),
    img(_img)
{
    parent = _parent;
    ui->setupUi(this);

    //show img in middle of window
    QPixmap pic;
    pic.convertFromImage(*img);
    ui->picture->setPixmap(pic);
}

savewind::~savewind()
{
    //Clean up dynamically managed member fields
    delete ui;
}

void savewind::on_back_clicked()
{
    //go back to the editor and clean up memory
    parent->show();
    this->~savewind();
}

void savewind::on_save_clicked()
{
    QString name = ui->saveName->text(); //savename user types

    QString path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation); //path to user's Desktop
    QDateTime stamp = QDateTime::currentDateTime(); //timestamp

    if(name!=""){ //if user input a name to save under
        bool saved = img->save(path+"/"+name+".jpg", "JPG", 100);
        if(saved)
            QApplication::quit();
    }
    else{ //if no save name specified, use default
        bool saved = img->save(path+"/edited_"+ stamp.toString("M:d:yy hh.mm.ss") +".jpg", "JPG", 100);
        if(saved)
            QApplication::quit();
    }
}
