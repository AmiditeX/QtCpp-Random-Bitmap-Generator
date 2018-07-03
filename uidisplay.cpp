#include "uidisplay.h"
#include "ui_uidisplay.h"

#include <iostream>

UIDisplay::UIDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIDisplay)
{
    ui->setupUi(this);
    connect(ui->generate, SIGNAL(clicked(bool)), this, SLOT(generateBitmap()));
    connect(ui->clear, SIGNAL(clicked(bool)), this, SLOT(clearAll()));
}

void UIDisplay::generateBitmap()
{
    unsigned long long seed, a, c, m, bitshift;
    seed = ui->seed->text().toULongLong();
    a = ui->multiplier->text().toULongLong();
    c = ui->increment->text().toULongLong();
    m = ui->modulus->text().toULongLong();
    bitshift = ui->bitshifting->text().toULongLong();
    Type t = static_cast<Type>(ui->genType->currentIndex());

    QVector<QVector<short int>> v;
    QVector<short int> color1; //RED
    color1.append(255); color1.append(0); color1.append(0);
    QVector<short int> color2; //BLUE
    color2.append(0); color2.append(0); color2.append(255);
    QVector<short int> color3; //BLACK
    color3.append(0); color3.append(0); color3.append(0);
    QVector<short int> color4; //WHITE
    color4.append(255); color4.append(255); color4.append(255);

    short int nbColor = 0;
    if(ui->red->isChecked())
    {
        v.append(color1);
        nbColor++;
    }
    if(ui->blue->isChecked())
    {
        v.append(color2);
        nbColor++;
    }
    if(ui->black->isChecked())
    {
        v.append(color3);
        nbColor++;
    }
    if(ui->white->isChecked())
    {
        v.append(color4);
        nbColor++;
    }

    if(v.isEmpty())
        return;

    Generator gen(a, c, m, seed, t, bitshift);
    Bitmap bitmap(gen, ui->width->value(), ui->heigth->value(), v);
    QPixmap pix = bitmap.getBitmap();
    QString currentAlgorithm;
    currentAlgorithm = QString("(result = (%0 * %1 + %2) % %3) % %4").arg(a).arg(seed).arg(c).arg(m).arg(nbColor);
    ui->current->setText(currentAlgorithm);
    ui->label->setPixmap(pix);
}

void UIDisplay::clearAll()
{
    ui->seed->clear();
    ui->multiplier->clear();
    ui->increment->clear();
    ui->modulus->clear();
    ui->bitshifting->clear();
    ui->genType->setCurrentIndex(0);
}

UIDisplay::~UIDisplay()
{
    delete ui;
}
