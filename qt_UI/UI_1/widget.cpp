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



    image << "C:/Users/Branton/Desktop/bg/1.png"
          << "C:/Users/Branton/Desktop/bg/2.png"
          << "C:/Users/Branton/Desktop/bg/3.png"
          << "C:/Users/Branton/Desktop/bg/4.png"
          << "C:/Users/Branton/Desktop/bg/5.png";


        positions[0]=QRect(-70, 60, 150, 180);
        positions[1]=QRect(50, 60, 150, 180);
        positions[2]=QRect(125, 50, 300, 200);
        positions[3]=QRect(350, 60, 150, 180);
        positions[4]=QRect(470, 60, 150, 180);

        label_list[0] = ui->label_1_picture;
        label_list[1] = ui->label_2_picture;
        label_list[2] = ui->label_3_picture;
        label_list[3] = ui->label_4_picture;
        label_list[4] = ui->label_5_picture;

    for(int i = 0; i < 5; ++i){
        label_list[i]->setGeometry(positions[i]);
        label_list[i]->setPixmap(image[i]);
        label_list[i]->setScaledContents(true);
    }


    connect(ui->pushButton_next_picture,&QPushButton::clicked,
            this,&Widget::clicked_next_picture);

    connect(ui->pushButton_last_picture,&QPushButton::clicked,
            this,&Widget::clicked_last_picture);
}


void Widget::update_picture(){

    int count = image.size();
    for(auto labels : label){
         if(effect){
             QPropertyAnimation* animation = new QPropertyAnimation(effect,"opacity");
             animation->setDuration(300);
             animation->setStartValue(0.3);
             animation->setEndValue(1.0);
             group->addAnimation(animation);
           }
       }

       group->start(QAbstractAnimation::DeleteWhenStopped);
}

void Widget::clicked_next_picture(){
    update_picture();
}

void Widget::clicked_last_picture(){

    update_picture();
}

Widget::~Widget()
{
    delete ui;
}

