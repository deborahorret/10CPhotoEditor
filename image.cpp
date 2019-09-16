#include "image.h"

Image::Image() : QImage(){} //pass construction to QImage

Image::Image(const QImage& img) : QImage(img){} //pass construction to QImage

Image::Image(int w, int h, const Format& f=Format_RGB32) : QImage(w,h,f){} //let QImage do the work, default format is RGB32 if none specified

int Image::width(){
    return QImage::width();
}

int Image::height(){
    return QImage::height();
}

void Image::rotateRight(){
    int cols = this->height();
    int rows = this->width();
    //make an image with a length and width swapped from current image
    Image temp(cols, rows);
    //map each pixel from the original image into the new image
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            temp.setPixel(cols-1-c, r, this->pixel(r,c));
        }
    }
    //commit the changes
    *this = temp;
}

void Image::rotateLeft(){
    int cols = this->height();
    int rows = this->width();
    //make an image with a length and width swapped from current image
    Image temp(cols, rows);
    //map each pixel from the original image into the new image
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            temp.setPixel(c, rows-1-r, this->pixel(r,c));
        }
    }
    //commit the changes
    *this = temp;
}

void Image::rotate180(){
    //use the function we already created
    rotateRight();
    rotateRight();
}

void Image::mirror(){
    int cols = this->height();
    int rows = this->width();
    //Go through the first half of the image
    for(int r=0; r<rows/2; r++){
        for(int c=0; c<cols; c++){
            //swap the pixels from the left side of the image to the right side it mirror it
            QRgb temp = pixel(r, c);
            this->setPixel(r, c, this->pixel(rows-1-r, c));
            this->setPixel(rows-1-r, c, temp);
        }
    }
}


void Image::blackAndWhite(){
    int cols = this->height();
    int rows = this->width();
    //go through the Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            //extract RGB of each pixel
            int blue = pixelColor(r,c).blue();
            int green = pixelColor(r,c).green();
            int red = pixelColor(r,c).red();
            int avg = (blue+green+red)/3; //average them up
            if(255-avg > 128) //if the average is closer to black
                setPixelColor(r, c, Qt::black); //make it black
            else //if it's closer to white
                setPixelColor(r, c, Qt::white); //make it white
        }
    }
}

void Image::grayscale(){
    int cols = this->height();
    int rows = this->width();
    //go through the Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            //take RGB values at adjusted levels (we found these levels online)
            int blue = pixelColor(r,c).blue() * 0.11 + 0.5;
            int green = pixelColor(r,c).green() * 0.59 + 0.5;
            int red = pixelColor(r,c).red() * 0.3 + 0.5;
            int gray = blue+green+red; //add them all up
            setPixelColor(r, c, QColor(gray,gray,gray)); //make the pixel the new gray color
        }
    }
}

void Image::aqua(){
    int cols = this->height();
    int rows = this->width();
    //go through the Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            //only let the blue value of that pixel be represented
            setPixelColor(r, c, QColor(0, 0, pixelColor(r,c).blue()));
        }
    }
}

void Image::veridian(){
    int cols = this->height();
    int rows = this->width();
    //go through the Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            //only let the green value of that pixel be represented
            setPixelColor(r, c, QColor(0, pixelColor(r,c).green(), 0));
        }
    }
}

void Image::rouge(){
    int cols = this->height();
    int rows = this->width();
    //go through the Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            //only let the red value of that pixel be represented
            setPixelColor(r, c, QColor(pixelColor(r,c).red(), 0, 0));
        }
    }
}

void Image::sepia(int depth, int intensity){
    int cols = this->height();
    int rows = this->width();
    //go through the Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            int blue = pixelColor(r,c).blue();
            int green = pixelColor(r,c).green();
            int red = pixelColor(r,c).red();
            int avg = (red+blue+green)/3; //average the RGB values similar to grayscale
            blue = green = red = avg;
            red += depth*2; //make the reds lighter
            green += depth; //and the greens (yellows) lighter
            //but make sure they don't go above 255 (white)
            if(red>255)
                red = 255;
            if(green>255)
                green = 255;

            blue -= intensity; //make the blues darker
            //but make sure they dont go out of bounds (0-255)
            if(blue<0)
                blue = 0;
            if(blue>255)
                blue = 255;
            //set pixel to adjusted colors
            setPixelColor(r, c, QColor(red, green, blue));
        }
    }
}

void Image::negative(){
    int cols = this->height();
    int rows = this->width();
    //go through the image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            int blue = pixelColor(r,c).blue();
            int green = pixelColor(r,c).green();
            int red = pixelColor(r,c).red();
            //invert the color of each pixel
            setPixelColor(r, c, QColor(255-red, 255-green, 255-blue));
        }
    }
}

void Image::brightness(int level){
    int brightness = 255*level/60; //we will use this to adjust RGB values
    int cols = this->height();
    int rows = this->width();
    //go through Image pixel by pixel
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            int blue = pixelColor(r,c).blue();
            int green = pixelColor(r,c).green();
            int red = pixelColor(r,c).red();

            //adjust all RGB values, but keep them in bounds
            int newblue = blue+brightness;
            if(newblue>255)
                newblue = 255;
            if(newblue<0)
                newblue = 0;

            int newgreen = green+brightness;
            if(newgreen>255)
                newgreen = 255;
            if(newgreen<0)
                newgreen = 0;

            int newred = red+brightness;
            if(newred>255)
                newred = 255;
            if(newred<0)
                newred = 0;

            setPixelColor(r, c, QColor(newred, newgreen, newblue)); //update the pixel color
        }
    }
}
