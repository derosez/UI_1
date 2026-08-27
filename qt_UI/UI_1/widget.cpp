#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //绑页面
    connect(ui->pushButton_lunbo,&QPushButton::clicked,this,[=]{
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_zhuzhuang,&QPushButton::clicked,this,[=]{
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_jindutiao,&QPushButton::clicked,this,[=]{
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->pushButton_mianban,&QPushButton::clicked,this,[=]{
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->pushButton_liebiao,&QPushButton::clicked,this,[=]{
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->pushButton_biaoge,&QPushButton::clicked,this,[=]{
        ui->stackedWidget->setCurrentIndex(5);
    });



    image << ":/new/picture/C:/Users/Branton/Desktop/bg/1.png"
          << ":/new/picture/C:/Users/Branton/Desktop/bg/2.png"
          << ":/new/picture/C:/Users/Branton/Desktop/bg/3.png"
          << ":/new/picture/C:/Users/Branton/Desktop/bg/4.png"
          << ":/new/picture/C:/Users/Branton/Desktop/bg/5.png";
    _index_picture = 0;
    ui->label_pickture->setPixmap(image[_index_picture]);
    // 切换图片
    connect(ui->pushButton_last_picture,&QPushButton::clicked,this,[=]{
        _index_picture -= 1;
        if(_index_picture < 0){
            _index_picture = 4;
        }
        ui->label_pickture->setPixmap(image[_index_picture]);
    });
    connect(ui->pushButton_next_picture,&QPushButton::clicked,this,[=]{
        _index_picture += 1;
        if(_index_picture > 4){
            _index_picture = 0;
        }
        ui->label_pickture->setPixmap(image[_index_picture]);
    });

    //图片point
    connect(ui->pushButton_point_0,&QPushButton::clicked,this,[=]{
        ui->label_pickture->setPixmap(image[0]);
        _index_picture = 0;
    });
    connect(ui->pushButton_point_1,&QPushButton::clicked,this,[=]{
        ui->label_pickture->setPixmap(image[1]);
        _index_picture = 1;
    });
    connect(ui->pushButton_point_2,&QPushButton::clicked,this,[=]{
        ui->label_pickture->setPixmap(image[2]);
        _index_picture = 2;
    });
    connect(ui->pushButton_point_3,&QPushButton::clicked,this,[=]{
        ui->label_pickture->setPixmap(image[3]);
        _index_picture = 3;
    });
    connect(ui->pushButton_point_4,&QPushButton::clicked,this,[=]{
        ui->label_pickture->setPixmap(image[4]);
        _index_picture = 4;
    });
}

Widget::~Widget()
{
    delete ui;
}

