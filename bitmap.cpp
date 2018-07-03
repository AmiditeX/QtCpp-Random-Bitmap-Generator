#include "bitmap.h"

Bitmap::Bitmap(Generator &generator, const int &width, const int &heigth, const QVector<QVector<short int>> &colors)
    : gen_(generator), width_(width), height_(heigth), colors_(colors)
{
    genNumber_ = heigth * width; //Set how many numbers we will generate
}

QPixmap Bitmap::getBitmap()
{
    uchar pixmapColors[genNumber_ * 3]; //Colors in RGB888 for each number generated (3 int per color)
    int pixMapIterator = 0; //Iterator for pixmapColors

    //Generate random numbers and mod it with the number of colors passed as argument
    //Example : 2 colors set in vector means a generated number between 0 and 1
    int mod = colors_.size();
    for(int i = 0 ; i < genNumber_ ; i++)
    {
        unsigned long long g = gen_.generateNumber();
        short result = g % mod;
        QVector<short int> color = colors_[result]; //Get the color for each number in the color vector (defined as 255,255,255)
        pixmapColors[pixMapIterator] = color.at(0); //Set RGB888 first int (0-255)
        pixmapColors[pixMapIterator + 1] = color.at(1); //Second int (0-255)
        pixmapColors[pixMapIterator + 2] = color.at(2); //Third int (0-255)
        pixMapIterator += 3;
    }

    //We now got an array of RGB888 integer determining colors for each number generated
    QImage img(pixmapColors, width_, height_, width_ * 3, QImage::Format_RGB888); //Bytes per line = 3*numbers per line
    QPixmap pixmapResult = QPixmap::fromImage(img); //Create pixmap from image
    return pixmapResult;

}
