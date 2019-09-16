#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <QColor>

/*
 * Image class acts like QImage but with extra functions added editing
 */
class Image : public QImage{
public:
    /*-----Constructors-----*/


    /*
     * Default constructor passes construction to QImage default constructor.
     */
    Image();

    /*
     * Constructor creates an Image out of a QImage.
     *
     * @param img the QImage to be "copied"
     */
    Image(const QImage& img);

    /*
     * Constructor makes an Image with a specified height and width, passes to a QImage constructor of the same form.
     *
     * @param w the width
     * @param h the height
     * @param f the format
     */
    Image(int w, int h, const Format& f);



    /*-----Accessors-----*/


    /*
     * Give the width of the Image
     *
     * @return the width
     */
    int width();

    /*
     * Give the height of the Image
     *
     * @return the height
     */
    int height();



    /*-----Modifiers-----*/


    /*
     * Turn the Image to the Left
     */
    void rotateLeft();

    /*
     * Turn the Image to the right
     */
    void rotateRight();

    /*
     * Flip the Image over entirely
     */
    void rotate180();

    /*
     * Reflect the Image horizontally
     */
    void mirror();

    /*
     * Turn Image black and white
     */
    void blackAndWhite();

    /*
     * Convert Image to grayscale
     */
    void grayscale();

    /*
     * Make Image blue
     */
    void aqua();

    /*
     * Make Image green
     */
    void veridian();

    /*
     * Make Image red
     */
    void rouge();

    /*
     * Make Image sepia with specified depth and intensity
     *
     * @param depth the depth (how red/yellow/brown) 0-50
     * @param intensity the intensity (how dark of a contrast) 0-50
     */
    void sepia(int depth, int intensity);

    /*
     * Invert the color of each pixel
     */
    void negative();

    /*
     * Make Image brighter or darker with a specified level
     *
     * @param level how bright or dark -60-60
     */
    void brightness(int level);
};

#endif // IMAGE_H
