#ifndef LOADING_WINDOW_H
#define LOADING_WINDOW_H

#include <QWidget>
#include <QTimer>
#include "widget.h"

namespace Ui {
class loading_window;
}

class loading_window : public QWidget
{
    Q_OBJECT

public:
    explicit loading_window(QWidget *parent = nullptr);
    ~loading_window();

private:
    Ui::loading_window *ui;
    QTimer *timer = new QTimer(this);
};

#endif // LOADING_WINDOW_H
