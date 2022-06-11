#include "login.h"
#include "ui_login.h"
#include<QWidget>
#include<QPoint>
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>



Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);
    //去掉系统无边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //阴影边框效果
    QGraphicsDropShadowEffect *shadow =new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);

    ui->showwidget->setGraphicsEffect(shadow);

    //设置父窗口为透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    //用户名焦点
    ui->Username->setFocus();
}

Login::~Login()
{
    delete ui;
}
//鼠标移动
void Login::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    //鼠标相对于桌面左上角的位置，鼠标的全局位置
    QPoint y = event->globalPos();
    QPoint x =y-this->z;
    this->move(x);
}
//鼠标点击
void Login::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    //鼠标相对于桌面左上角的位置，鼠标的全局位置
    QPoint y = event->globalPos();
    //窗口左上角相对于桌面左上角的位置
    QPoint x =this->geometry().topLeft();
    this->z = y-x; //定值
}
//鼠标释放
void Login::mouseReleaseEvent(QMouseEvent *event)
{

    QWidget::mouseReleaseEvent(event);
    //清空
    this->z=QPoint();

}

//关闭窗口
void Login::on_pushButton_clicked()
{
    this->close();
}

//登录事件
void Login::on_btn_login_clicked()
{
    if(!ui->Password->text().isEmpty()){
        QSqlQuery query;
        query.exec("select password from worker where usename='" + ui->Username->text()+"'");
        query.next();
        if(query.value(0).toString()==ui->Password->text()){
            //验证通过
            QDialog::accept();
        }else{
            //信息错误弹出警告
            QMessageBox::warning(this,tr("密码或账号错误！"),tr("请输入正确的信息"),QMessageBox::Ok);
            //清空输入框
            ui->Username->clear();
            ui->Password->clear();
        }
    }else{
        ui->Password->setFocus();
    }

}
