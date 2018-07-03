#ifndef BITMAP_H
#define BITMAP_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include "generator.h"

class Bitmap
{

public:
    Bitmap(Generator &generator, const int &width, const int &heigth, const QVector<QVector<short int>> &colors);
    QPixmap getBitmap();

private:
    Generator &gen_; //Random number generator to use
    int width_; //Width of the pixmap
    int height_; //Height of the pixmap
    QVector<QVector<short int>> colors_; //Color in RGB888 for each value generated
    int genNumber_; //Number of random number to generate
};

#endif // BITMAP_H
