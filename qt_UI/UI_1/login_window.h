#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QWidget>
#include "loading_window.h"

namespace Ui {
class login_window;
}

class login_window : public QWidget
{
    Q_OBJECT

public:
    explicit login_window(QWidget *parent = nullptr);
    ~login_window();

private:
    Ui::login_window *ui;
    void on_loginbutton_clicked();
};

#endif // LOGIN_WINDOW_H
