#ifndef SAVEWIND_H
#define SAVEWIND_H

#include "image.h"
#include <QDialog>
#include <QString>

namespace Ui {
class savewind;
}

class savewind : public QDialog
{
    Q_OBJECT

public:
    /*
     * Constructor makes a savewind from a parent Widget and sets img and filepath to be empty initially
     */
    explicit savewind(QWidget *_parent = 0, Image* _img = nullptr);

    /*
     * Cleans up dynamically allocated members
     */
    ~savewind();

private slots:
    /*
     * Goes back to editing window
     */
    void on_back_clicked();

    /*
     * Saves image to user's Desktop with name specified or a "edited_{timestamp}" if no input
     */
    void on_save_clicked();

private:
    Ui::savewind *ui;
    Image* img; //
    QString filepath;//
    QWidget* parent;
};

#endif // SAVEWIND_H
