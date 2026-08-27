#include "login_window.h"
#include "ui_login_window.h"

login_window::login_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_window)
{
    ui->setupUi(this);
    ui->lineEdit_1->setText("123123");
    ui->lineEdit_2->setText("123123");

    connect(ui->pushButton,&QPushButton::clicked,this,&login_window::on_loginbutton_clicked);

}

login_window::~login_window()
{
    delete ui;
}

void login_window::on_loginbutton_clicked(){
    QString username = ui->lineEdit_1->text();
    QString password = ui->lineEdit_2->text();

    if(username == "123123" && password == "123123"){
        this->hide();

        loading_window* w = new loading_window();
        w->show();

    }

}
