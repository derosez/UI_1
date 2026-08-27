#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_lunbo,&QPushButton::click,this,[=]{
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_zhuzhuang,&QPushButton::click,this,[=]{
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_jindutiao,&QPushButton::click,this,[=]{
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->pushButton_mianban,&QPushButton::click,this,[=]{
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->pushButton_liebiao,&QPushButton::click,this,[=]{
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->pushButton_biaoge,&QPushButton::click,this,[=]{
        ui->stackedWidget->setCurrentIndex(5);
    });

}

Widget::~Widget()
{
    delete ui;
}

