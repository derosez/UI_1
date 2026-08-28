#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QStringList image;
    QRect  positions[5];
    QLabel* label_list[5];


private:
    void update_picture();
    void clicked_next_picture();
    void clicked_last_picture();
};



#endif // WIDGET_H


