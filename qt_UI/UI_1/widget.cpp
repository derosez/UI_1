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

        // 适配 681x341 的容器大小
        // 假设图片大小为 360x240，Y坐标居中：(341 - 240) / 2 ≈ 50
        // X坐标分配：
        // 中间(坑位2)居中：(681 - 360) / 2 ≈ 160
        // 左侧(坑位1)：露出左边一部分，比如 X = 20
        // 右侧(坑位3)：露出右边一部分，比如 X = 300
        // 最外侧(坑位0, 4)：移到容器边缘之外或边缘处
        positions[0]=QRect(-200, 50, 360, 240); // 最左侧，大部分在屏幕外
        positions[1]=QRect(20, 50, 360, 240);   // 左侧
        positions[2]=QRect(160, 50, 360, 240);  // 中间，完全展示
        positions[3]=QRect(300, 50, 360, 240);  // 右侧
        positions[4]=QRect(520, 50, 360, 240);  // 最右侧，大部分在屏幕外

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
    label_list[0]->raise();
    label_list[4]->raise();
    label_list[1]->raise();
    label_list[3]->raise();
    label_list[2]->raise();

    ui->pushButton_next_picture->raise();
    ui->pushButton_last_picture->raise();

    QParallelAnimationGroup* group = new QParallelAnimationGroup(this);
    for(int i = 0; i < 5; ++i){
        QPropertyAnimation* animation = new QPropertyAnimation(label_list[i],"geometry");
        animation->setDuration(300);
        animation->setStartValue(label_list[i]->geometry());
        animation->setEndValue(positions[i]);
        group->addAnimation(animation);
    }

    group->start(QAbstractAnimation::DeleteWhenStopped);
}

void Widget::clicked_next_picture(){
    QLabel* temp = label_list[image.size()-1];
    for(int i = 4; i > 0; i--){
        label_list[i] = label_list[i-1];
    }
    label_list[0] = temp;
    label_list[0]->setGeometry(positions[0]);
    update_picture();
}

void Widget::clicked_last_picture(){
    QLabel* temp = label_list[0];
    for(int i = 0; i < 4 ; ++i){
        label_list[i] = label_list[i+1];
    }
    label_list[4] = temp;
    label_list[4]->setGeometry(positions[4]);
    update_picture();
}

Widget::~Widget()
{
    delete ui;
}

