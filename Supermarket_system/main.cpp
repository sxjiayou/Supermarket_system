#include "mainwindow.h"
#include"login.h"
#include <QApplication>
#include<QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!createMySqlConn()){
        //初次连接不成功，启动MYsql服务器进程
        QProcess process;
        process.start("C:/Users/Administrator/Desktop/启动服务/mysql.bat");
        //第二次连接
        if(!createMySqlConn()){
            return 1;
        }
    }
    //先进行登录，后进入系统
    Login login;
    if(login.exec()==QDialog::Accepted){
        MainWindow w;
        w.show();
        return a.exec();
    }else{
        return 0;
    }
}





