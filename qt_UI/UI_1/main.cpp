#include "widget.h"
#include "login_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    login_window login;
    login.show();

    return a.exec();
}
