#ifndef UIDISPLAY_H
#define UIDISPLAY_H

#include <QMainWindow>
#include <QBitmap>
#include <generator.h>
#include <bitmap.h>

namespace Ui {
class UIDisplay;
}

class UIDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIDisplay(QWidget *parent = 0);
    ~UIDisplay();

public slots:
    void generateBitmap();
    void clearAll();

private:
    Ui::UIDisplay *ui;
};

#endif // UIDISPLAY_H
