#ifndef MAINWIND_H
#define MAINWIND_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QVector>
#include "image.h"
#include "savewind.h"


namespace Ui {
class mainwind;
}

class mainwind : public QMainWindow
{
    Q_OBJECT


public:
    /*
     * Constructor creates a mainwind object from a parent QWidget (welwind) and a filepath (specified in welwind)
     */
    explicit mainwind(QWidget *_parent = 0, const QString& path = "");

    /*
     * Destructor deletes all dynamically allocated members
     */
    ~mainwind();

    /*
     * Give the path to the image file we're working with
     *
     * @return filepath as a copy
     */
    QString getFilePath();

private slots:
    /* -----------TOP TOOLBAR---------- */

    /*
     * Program exits when Quit is clicked
     */
    void on_actionQuit_triggered();

    /*
     * About description box is displayed on click
     */
    void on_actionAbout_Photo_Editor_triggered();

    /*
     * Filter Widget appears when filter button clicked
     */
    void on_actionFilters_3_triggered();

    /*
     * ToolBars Widget appears when filter button clicked
     */
    void on_actionTools_triggered();

    /*
     * Undo the most recent step
     */
    void on_actionUndo_triggered();

    /*
     * Set the current image to the base image
     */
    void on_actionRevert_triggered();

    /*
     * Image displayed rotated right when button clicked
     */
    void on_actionRotateRight_triggered();

    /*
     * Image displayed rotated left when button clicked
     */
    void on_actionRotateLeft_triggered();

    /*
     * Image displayed turned over when button clicked
     */
    void on_actionRotate_180_triggered();

    /*
     * Image displayed mirrored when button clicked
     */
    void on_actionFlip_2_triggered();

    /* -----------FILTERS---------- */

    /*
     * Image displayed turned black and white when button clicked
     */
    void on_blackAndWhite_clicked();

    /*
     * Image displayed turned grayscale when button clicked
     */
    void on_grayscale_clicked();

    /*
     * Image displayed turned blue when button clicked
     */
    void on_aqua_clicked();

    /*
     * Image displayed turned red when button clicked
     */
    void on_rouge_clicked();

    /*
     * Image displayed turned green when button clicked
     */
    void on_veridian_clicked();

    /*
     * Image displayed converted to negative when button clicked
     */
    void on_negative_clicked();

    /*
     * When clicked, brightness slider appears to modify the image
     */
    void on_brightness_clicked();

    /*
     * When slider is moved, the image displayed gets brighter or darker depending on position
     */
    void on_brightSlider_sliderMoved(int position);

    /*
     * When user clicks "Commit", image brightness is set to current level
     */
    void on_brightSave_clicked();

    /*
     * When "Sepia" clicked, sepia sliders appear to modify the image
     */
    void on_sepia_clicked();

    /*
     * When depth slider is moved, sepia image displayed has its depth updated
     */
    void on_depthSlider_sliderMoved(int position);

    /*
     * When intensity slider is moved, sepia image displayed has its intensity updated
     */
    void on_intensitySlider_sliderMoved(int position);

    /*
     * When user clicks "Commit", image is set to have sepia filter with current depth and intensity
     */
    void on_sepiaSave_clicked();

    /*
     * Restart the whole process
     */
    void on_actionNew_triggered();

    /*
     * Display save window
     */
    void on_actionSave_triggered();

    /* -----------SIDE TOOLBAR---------- */

    /*
     * Image displayed mirrored when button clicked
     */
    void on_flip_clicked();

    /*
     * Set the current image to the base image
     */
    void on_revert_clicked();

    /*
     * Undo the most recent step
     */
    void on_undo_clicked();

    /*
     * Image displayed rotated left when button clicked
     */
    void on_rotate_left_clicked();

    /*
     * Image displayed rotated right when button clicked
     */
    void on_rotate_right_clicked();

    /*
     * Image displayed rotated 180 degrees when button clicked
     */
    void on_rotate180_clicked();


private:
    Ui::mainwind *ui;
    Image* currImg; //Image to be displayed
    Image* baseImg; //original loaded Image
    QVector<Image> history; //keeps all steps
    QString filepath; //path to the image in the qrc to be edited

    savewind* save; //the savewindow created when save is clicked
    QWidget* parent; //the WelWind that started the editor
};

#endif // MAINWIND_H
