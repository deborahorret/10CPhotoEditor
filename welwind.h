#ifndef WELWIND_H
#define WELWIND_H

#include <QDialog>
#include "mainwind.h"

namespace Ui {
class WelWind;
}

class WelWind : public QDialog
{
    Q_OBJECT

public:
    /*
     * Constructs a WelWind from a parent QWidget
     */
    explicit WelWind(QWidget *parent = 0);

    /*
     * deletes dynamically managed member fields
     */
    ~WelWind();

private slots:
    /*
     * When Continue Button is clicked, a new mainwind is created and displayed with an Image from the specified filepath.
     * WelWind is then hidden
     */
    void on_pushButton_clicked();

private:
    Ui::WelWind *ui;
    mainwind *mainwindow; //needs to be able to make a mainwind when Continue Button is clicked
};

#endif // WELWIND_H
