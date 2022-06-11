#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<QSqlQuery>  //查询mysql数据库
#include<QMessageBox>
#include<QCryptographicHash>  //包含MD5算法库
#include <QWidget>
#include<QPoint>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标点击
    void mousePressEvent(QMouseEvent *event);
    //鼠标拖动
    void mouseReleaseEvent(QMouseEvent *event);


private slots:
    //关闭窗口
    void on_pushButton_clicked();
    //登录事件
    void on_btn_login_clicked();

private:
    Ui::Login *ui;
     QPoint z;

};

#endif // LOGIN_H
