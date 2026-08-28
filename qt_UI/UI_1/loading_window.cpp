#include "loading_window.h"
#include "ui_loading_window.h"

loading_window::loading_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loading_window)
{
    ui->setupUi(this);
    ui->progressBar->setTextVisible(false);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);

    connect(timer,&QTimer::timeout,this,[=]{
       int value = ui->progressBar->value();

       if(value < 100){
           ui->progressBar->setValue(value + 1);
       }
       else{
           timer->stop();
           Widget* w = new Widget();
           w->show();
           this->hide();
       }

    });
    timer->start(5);
}

loading_window::~loading_window()
{
    delete ui;
}
