#include "welwind.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WelWind w;
    w.setStyleSheet("background-color: rgb(197, 230, 247);"); //set backgroud to light blue
    w.setWindowTitle("Welcome!");
    w.show();

    return a.exec();
}
