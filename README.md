# 超市信息管理系统开发文档

## 一、环境及技术

1、环境

- Qt Creator 5.3
- ODBC Data Sources (32-bit)
- mysql-8.0.28-winx64
- Navicat 15 for MySQL

2、技术

- QT开发
- C++
- mysql

## 二、项目开发流程

1. 数据库设计
2. 界面UI设计
3. 代码逻辑编写
4. 开发文档编写

## 三、流程介绍

### 1、数据库设计

#### 1、1数据库代码

```mysql
/*
 Navicat MySQL Data Transfer

 Source Server         : localhost_3306
 Source Server Type    : MySQL
 Source Server Version : 80028
 Source Host           : localhost:3306
 Source Schema         : shop

 Target Server Type    : MySQL
 Target Server Version : 80028
 File Encoding         : 65001

 Date: 06/06/2022 20:30:21
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for goods
-- ----------------------------
DROP TABLE IF EXISTS `goods`;
CREATE TABLE `goods`  (
  `id` int NOT NULL COMMENT '商品编号',
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '商品名称',
  `num` int NOT NULL COMMENT '商品数量',
  `price` double(10, 2) NOT NULL COMMENT '商品价格',
  `kind` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '商品种类',
  `picture` blob NULL COMMENT '商品图片',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of goods
-- ----------------------------
INSERT INTO `goods` VALUES (1, '可乐', 300, 3.00, '饮料', NULL);
INSERT INTO `goods` VALUES (2, '上衣', 20, 99.00, '服装', NULL);
INSERT INTO `goods` VALUES (3, '大豆油', 300, 55.50, '食品', NULL);

-- ----------------------------
-- Table structure for worker
-- ----------------------------
DROP TABLE IF EXISTS `worker`;
CREATE TABLE `worker`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '职工编号',
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '职工姓名',
  `phone` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL COMMENT '职工电话',
  `usename` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '职工账号',
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL COMMENT '职工密码',
  `address` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NULL DEFAULT NULL COMMENT '职工联系地址',
  `picture` blob NULL COMMENT '职工照片',
  PRIMARY KEY (`id`) USING BTREE,
  CONSTRAINT `id` FOREIGN KEY (`id`) REFERENCES `goods` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_bin ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of worker
-- ----------------------------
INSERT INTO `worker` VALUES (1, '马师傅', '123', '123', '123', '陕西省西安市', NULL);
INSERT INTO `worker` VALUES (2, '石师傅', '1234', '1234', '1234', '陕西省西安市', NULL);
INSERT INTO `worker` VALUES (3, '野球帝', '12345', '12345', '12345', '陕西省西安市', NULL);

SET FOREIGN_KEY_CHECKS = 1;

```

#### 1、2 表设计

- goods表

![image-20220609152628020](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206091526151.png)

- worker表

![image-20220609152721943](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206091527988.png)

#### 1、3 视图

![image-20220609152927876](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206091529928.png)

### 2、界面UI设计

#### 2、1 登录界面

- 效果图

![](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206091531850.png)

- 结构说明

![image-20220609153543319](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206091535392.png)

#### 2、2 系统展示界面



### 3、代码逻辑编写

#### 3、1 登录逻辑

**login.h:**

```c++
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

```

**login.cpp:**

```c++
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

```

#### 3、2 系统功能逻辑

**mainwindow.h:**

```c++
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QFileDialog>
#include<QBuffer>
#include<QSqlDatabase>   //mysql数据库类
#include<QSqlTableModel>  //mysql表模型库
#include<QSqlQuery>       //mysql查询类库
#include<QSqlQueryModel>
#include<QTime>
#include<QPixmap>         //图形处理类库
#include <QWidget>
#include<QPoint>
#include <QTableView>
#include <QStandardItemModel>
#include<QString>
#include<QTableWidgetItem>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /*鼠标事件*/
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标点击
    void mousePressEvent(QMouseEvent *event);
    //鼠标拖动
    void mouseReleaseEvent(QMouseEvent *event);

    /*数据库事件*/
    //获取职工的数量
    void workers_num();
    //获取商品的数量
    void goods_num();
    //商品信息展示在列表
    void goods_show();
    //职工信息展示在列表
    void workers_show();

    //查询一条商品信息
    void querygoods(QString key,QString value);
    //查询一条职工信息
    void queryworkers(QString key,QString value);

    //清楚数据框中内容
    void goodsdata_claer();
    void workersdata_claer();





    //职工数量
    int workersnum;
    //商品数量
    int goodsnum;









private slots:
    //缩小窗口
    void on_btn_reduce_clicked();
    //放大窗口
    void on_btn_magnify_clicked();
    //关闭窗口
    void on_btn_close_clicked();
    //跳转商品信息管理页面
    void on_btn_goods_clicked();
    //跳转职工信息管理界面
    void on_btn_workers_clicked();
    //增加职工信息
    void on_addworkers_btn_clicked();
    //删除职工信息
    void on_deleteworkers_btn_clicked();
    //修改职工信息
    void on_changeworkers_btn_clicked();
    //查询职工信息
    void on_selectworkers_btn_clicked();
    //增加商品信息
    void on_addgoods_btn_clicked();
    //删除商品信息
    void on_deletegoods_btn_clicked();
    //修改商品信息
    void on_changegoods_btn_clicked();
    //查询商品信息
    void on_selectgoods_btn_clicked();
    //上传商品照片
    void on_goods_upload_clicked();
    //上传职工照片
    void on_workers_uoload_clicked();
    //显示全部职工信息
    void on_showworkers_btn_clicked();
    //显示全部商品信息
    void on_showgoods_btn_clicked();

    //列表点击事件
    void on_workers_tableWidget_cellDoubleClicked(int row, int column);
    void on_goods_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
     QPoint z;
     //图片上传
     QImage myPicImg1;
      QImage myPicImg2;

};

//访问Mysql数据库的静态方法
static bool createMySqlConn(){


  QSqlDatabase sqldb = QSqlDatabase::addDatabase("QODBC");
  sqldb.setHostName("127.0.0.1");
  sqldb.setPort(3306);
  sqldb.setDatabaseName("MySql");    //数据库名称
  sqldb.setUserName("root");
  sqldb.setPassword("123456");
  bool ok = sqldb.open();
  if(ok){

      return true;
  }else{
      QMessageBox::critical(0,QObject::tr("后台数据库连接失败！"),"无法创建连接！请检查排除故障后重启程序。",QMessageBox::Cancel);
      return false;
  }



}

#endif // MAINWINDOW_H

```

**mainwindow.cpp:**

```c++
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTreeWidgetItem>
#include<QWidget>
#include<QPoint>
#include<QMouseEvent>
#include<QGraphicsDropShadowEffect>
#include <QtCore>
#include <QtGui>
#include<QDebug>
#include<QPixmap>
#include<QSqlError>
#include<QList>
#include<QModelIndex>
#include<QComboBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*1、无边框效果*/
    ui->setupUi(this);
    //去掉系统无边框
    this->setWindowFlags(Qt::FramelessWindowHint);
    //阴影边框效果
    QGraphicsDropShadowEffect *shadow =new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setColor(Qt::black);
    shadow->setOffset(0);
    ui->centralWidget->setGraphicsEffect(shadow);
    //设置父窗口为透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    /*2、设置登录后的初始页面——商品信息管理页面*/
    ui->stackedWidget->setCurrentIndex(0);

    /*3、展示表格宽高设置*/
//    // 表格宽度随内容自动扩展
//    ui->workers_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->goods_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    // 表格高度随内容自动扩展
//    ui->workers_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->goods_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

   /*3、展示表格宽高设置，自动分配大小*/
    ui->workers_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配列宽
    ui->workers_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配行宽
    ui->goods_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配列宽
    ui->goods_tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//平均分配行宽

    /*4、设置单元格不可以被编辑*/
    ui->workers_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->goods_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //5、信息展示
    //职工信息展示
    workers_show();
    //商品信息展示
    goods_show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*1、鼠标事件*/
//鼠标移动
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    //鼠标相对于桌面左上角的位置，鼠标的全局位置
    QPoint y = event->globalPos();
    QPoint x =y-this->z;
    this->move(x);
}
//鼠标点击
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    //鼠标相对于桌面左上角的位置，鼠标的全局位置
    QPoint y = event->globalPos();
    //窗口左上角相对于桌面左上角的位置
    QPoint x =this->geometry().topLeft();
    this->z = y-x; //定值
}
//鼠标释放
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

    QWidget::mouseReleaseEvent(event);
    //清空
    this->z=QPoint();

}

/*2、获取列表的行数*/
//获取职工的数量
void MainWindow::workers_num()
{
     QSqlQuery query;
     //查询数据的所有行和列
     query.exec("SELECT * FROM worker");
     QSqlQueryModel *queryModel = new QSqlQueryModel();
     queryModel->setQuery(query);
     workersnum=queryModel->rowCount();
}
 //获取商品的数量
void MainWindow::goods_num()
{
    QSqlQuery query;
    //查询数据的所有行和列
    query.exec("SELECT * FROM goods");
    QSqlQueryModel *queryModel = new QSqlQueryModel();
    queryModel->setQuery(query);
    goodsnum=queryModel->rowCount();

}

/*3、信息展示*/
//3、1商品信息展示在列表
void MainWindow::goods_show()
{
    /*设置信息管理界面的标题*/
    goods_num();
    QStringList goods_headers;
    //列设置
    ui->goods_tableWidget->setColumnCount(6);
    //表头设置
    goods_headers << "商品编号" << "商品名称" << "商品数量" << "商品价格"<< "商品种类"<< "商品照片";
    ui->goods_tableWidget->setHorizontalHeaderLabels(goods_headers);
    //行设置
    ui->goods_tableWidget->setRowCount(goodsnum);
    //查询所有信息
    QString sql =QString("select * from goods ");
    QSqlQuery qry;
    //将信息展示在列表
    if(qry.exec(sql)){
        for(int i =0;qry.next();i++){
            ui->goods_tableWidget->setItem(i,0,new QTableWidgetItem(qry.value(0).toString()));
            ui->goods_tableWidget->setItem(i,1,new QTableWidgetItem(qry.value(1).toString()));
            ui->goods_tableWidget->setItem(i,2,new QTableWidgetItem(qry.value(2).toString()));
            ui->goods_tableWidget->setItem(i,3,new QTableWidgetItem(qry.value(3).toString()));
            ui->goods_tableWidget->setItem(i,4,new QTableWidgetItem(qry.value(4).toString()));
            //展示图片在列表
            QPixmap photo;
            QLabel *label = new QLabel;
            photo.loadFromData(qry.value(5).toByteArray(),"JPG");
            //图片自适应label大小
            photo.scaled(label->size(),Qt::KeepAspectRatio);
            label->setScaledContents(true);
            label->setPixmap(photo);
            ui->goods_tableWidget->setCellWidget(i,5,label);
        }
    }
}
//3、2职工信息展示在列表
void MainWindow::workers_show()
{
    /*设置信息管理界面的标题*/
    workers_num();
    QStringList worker_headers;
    //列设置
    ui->workers_tableWidget->setColumnCount(7);
    worker_headers << "职工编号" << "职工姓名" << "职工电话" << "职工账号"<< "职工密码"<< "职工地址"<<"职工照片";
    ui->workers_tableWidget->setHorizontalHeaderLabels(worker_headers);
    //行设置
    ui->workers_tableWidget->setRowCount(workersnum);
    //查询所有信息
    QString sql =QString("select * from worker ");
    QSqlQuery qry;

    if(qry.exec(sql)){

        for(int i =0;qry.next();i++){
            ui->workers_tableWidget->setItem(i,0,new QTableWidgetItem(qry.value(0).toString()));
            ui->workers_tableWidget->setItem(i,1,new QTableWidgetItem(qry.value(1).toString()));
            ui->workers_tableWidget->setItem(i,2,new QTableWidgetItem(qry.value(2).toString()));
            ui->workers_tableWidget->setItem(i,3,new QTableWidgetItem(qry.value(3).toString()));
            ui->workers_tableWidget->setItem(i,4,new QTableWidgetItem(qry.value(4).toString()));
            ui->workers_tableWidget->setItem(i,5,new QTableWidgetItem(qry.value(5).toString()));
            //展示图片在列表
            QPixmap photo;
            QLabel *label = new QLabel;
            photo.loadFromData(qry.value(6).toByteArray(),"JPG");
            //图片自适应label大小
            photo.scaled(label->size(),Qt::KeepAspectRatio);
            label->setScaledContents(true);
            label->setPixmap(photo);
            ui->workers_tableWidget->setCellWidget(i,6,label);
        }
    }
}

/*配合查询功能使用*/
//将查询的商品信息展示在列表
void MainWindow::querygoods(QString key,QString value)
{
//    //清空列表
//    for(int row = ui->goods_tableWidget->rowCount() - 1;row >= 0; row--)
//    {
//        ui->goods_tableWidget->removeRow(row);
//    }

    //清空列表
    ui->goods_tableWidget->clearContents();

    //查找总共有多少条信息
    QSqlQuery query;
    QString sql2 =QString("select * from goods where "+key+ "= '%1' ").arg(value);
    query.exec(sql2);
    QSqlQueryModel *queryModel = new QSqlQueryModel();
    queryModel->setQuery(query);
    int querygoodsnum=queryModel->rowCount();
    ui->goods_tableWidget->setRowCount(querygoodsnum);



    //查询所有信息
    QString sql =QString("select * from goods where "+key+ "= '%1' ").arg(value);
    QSqlQuery qry;
    //将信息展示在列表
    if(qry.exec(sql)){
        for(int i =0;qry.next();i++){
            ui->goods_tableWidget->setItem(i,0,new QTableWidgetItem(qry.value(0).toString()));
            ui->goods_tableWidget->setItem(i,1,new QTableWidgetItem(qry.value(1).toString()));
            ui->goods_tableWidget->setItem(i,2,new QTableWidgetItem(qry.value(2).toString()));
            ui->goods_tableWidget->setItem(i,3,new QTableWidgetItem(qry.value(3).toString()));
            ui->goods_tableWidget->setItem(i,4,new QTableWidgetItem(qry.value(4).toString()));
            //展示图片在列表
            QPixmap photo;
            QLabel *label = new QLabel;
            photo.loadFromData(qry.value(5).toByteArray(),"JPG");
            label->setPixmap(photo);
            ui->goods_tableWidget->setCellWidget(i,5,label);
        }
    }else{
         qDebug()<< qry.lastError();
    }
}

//将查询的职工信息展示在列表
void MainWindow::queryworkers(QString key,QString value)
{

    //方法1清空列表
//    for(int row = ui->workers_tableWidget->rowCount() - 1;row >= 0; row--)
//    {
//        ui->workers_tableWidget->removeRow(row);
//    }
    //方法2 清空列表
    ui->workers_tableWidget->clearContents();

    //查找总共有多少条信息
    QSqlQuery query;
    QString sql2 =QString("select * from worker where  "+key+ "= '%1' ").arg(value);
    query.exec(sql2);
    QSqlQueryModel *queryModel = new QSqlQueryModel();
    queryModel->setQuery(query);
    int queryworkersnum=queryModel->rowCount();
    ui->workers_tableWidget->setRowCount(queryworkersnum);



    //查询所有信息
    QString sql =QString("select * from worker where  "+key+ "= '%1'" ).arg(value);
    QSqlQuery qry;

    if(qry.exec(sql)){

        for(int i =0;qry.next();i++){
            ui->workers_tableWidget->setItem(i,0,new QTableWidgetItem(qry.value(0).toString()));
            ui->workers_tableWidget->setItem(i,1,new QTableWidgetItem(qry.value(1).toString()));
            ui->workers_tableWidget->setItem(i,2,new QTableWidgetItem(qry.value(2).toString()));
            ui->workers_tableWidget->setItem(i,3,new QTableWidgetItem(qry.value(3).toString()));
            ui->workers_tableWidget->setItem(i,4,new QTableWidgetItem(qry.value(4).toString()));
            ui->workers_tableWidget->setItem(i,5,new QTableWidgetItem(qry.value(5).toString()));
            //展示图片在列表
            QPixmap photo;
            QLabel *label = new QLabel;
            photo.loadFromData(qry.value(6).toByteArray(),"JPG");
            label->setPixmap(photo);
            ui->workers_tableWidget->setCellWidget(i,6,label);
        }
    }else{
        qDebug()<< qry.lastError();
    }

    //清楚输入的数据
    workersdata_claer();
}

/*清除输入框中的数据*/
void MainWindow::goodsdata_claer()
{
    ui->goods_id->clear();
    ui->goods_name->clear();
    ui->goods_num->clear();
    ui->goods_price->clear();
    ui->goods_kind->clear();
    ui->goods_picture->clear();
}

void MainWindow::workersdata_claer()
{
    ui->workers_id->clear();
    ui->workers_name->clear();
    ui->workers_phone->clear();
    ui->workers_usename->clear();
    ui->workers_password->clear();
    ui->workers_addres->clear();
    ui->workers_picture->clear();
}


/*3、窗口事件*/
//缩小按钮
void MainWindow::on_btn_reduce_clicked()
{
   this->showMinimized();
}
//放大按钮
void MainWindow::on_btn_magnify_clicked()
{
    //判断窗口所处在的大小状况
    if(this->isMaximized()){

        this->showNormal();
    }else{

        this->showMaximized();
    }
}
//关闭按钮
void MainWindow::on_btn_close_clicked()
{
    this->close();
}

/*4、跳转界面事件*/
//跳转商品信息管理页面
void MainWindow::on_btn_goods_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//跳转职工信息管理界面
void MainWindow::on_btn_workers_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*4、职工功能*/
//4、1增加职工信息
void MainWindow::on_addworkers_btn_clicked()
{ //插入一条职工信息
  QSqlQuery query;
  QString name =ui->workers_name->text();
  QString phone =ui->workers_phone->text();
  QString usename=ui->workers_usename->text();
  QString passworad=ui->workers_password->text();
  QString address=ui->workers_addres->text();
  query.prepare("insert into worker(name,phone,usename,password,address)"
                "values (?,?,?,?,?)");
  query.addBindValue(name);
  query.addBindValue(phone);
  query.addBindValue(usename);
  query.addBindValue(passworad);
  query.addBindValue(address);
  if(!query.exec()){
      //加入失败弹出警告
      QMessageBox::warning(this,tr("增加职工信息失败！"),tr("请完善信息,职工编号不用输入！"),QMessageBox::Ok);
      qDebug()<< query.lastError();
  }else{
      QMessageBox::information(0,QObject::tr("提示"),"成功增加职工信息");
  }

  //插入职工照片
  QByteArray picdata;
  QBuffer buffer(&picdata);
  buffer.open(QIODevice::WriteOnly);
  myPicImg2.save(&buffer,"JPG");
  QVariant var(picdata);
  QString sqlpic = "update worker set picture=? where name='"+name+"' ";
  query.prepare(sqlpic);
  query.addBindValue(var);
  if(!query.exec()){
      QMessageBox::information(0,QObject::tr("提示"),"照片写入失败！请缩小图片尺寸");
  }
  //清空图片
   myPicImg2=QImage();
  //刷新列表
  workers_show();

  //清楚输入的数据
  workersdata_claer();
}
//4、2删除职工信息
void MainWindow::on_deleteworkers_btn_clicked()
{
    QSqlQuery query;
   //按照编号或姓名删除
   if(!ui->workers_id->text().isEmpty()){
       int id = ui->workers_id->text().toInt();
       QString sql = QString("delete from worker where id='%1'").arg(id);
       if(query.exec(sql)){
           QMessageBox::information(0,QObject::tr("提示"),"删除成功");
       }else{
           QMessageBox::information(0,QObject::tr("提示"),"请输入正确的职工编号或姓名");
       }

   }else if(!ui->workers_name->text().isEmpty()){
        QString name = ui->workers_name->text();
        QString sql = QString("delete from worker where name='%1'").arg(name);
       if(query.exec(sql)){
           QMessageBox::information(0,QObject::tr("提示"),"删除成功");

       }else{
           QMessageBox::information(0,QObject::tr("提示"),"请输入正确的职工编号或姓名");
       }
   }else{
       QMessageBox::information(0,QObject::tr("提示"),"请输入职工编号或姓名");
   }

   //刷新页面
   workers_show();
   //清楚输入的数据
   workersdata_claer();
}
//4、3修改职工信息
void MainWindow::on_changeworkers_btn_clicked()
{
      //修改一条职工信息
      QSqlQuery query;
      QString id = ui->workers_id->text();
      QString name =ui->workers_name->text();
      QString phone =ui->workers_phone->text();
      QString usename=ui->workers_usename->text();
      QString passworad=ui->workers_password->text();
      QString address=ui->workers_addres->text();
      QString sql = QString("update worker set name='%1', phone='%2',usename='%3',password='%4', address='%5' where id ='%6'").arg(name).arg(phone).arg(usename).arg(passworad).arg(address).arg(id);
      if(!query.exec(sql)){
          //加入失败弹出警告
          QMessageBox::warning(this,tr("修改职工信息失败！"),tr("请完善信息,职工编号不用输入！"),QMessageBox::Ok);
          qDebug()<< query.lastError();
      }else{
          QMessageBox::information(0,QObject::tr("提示"),"成功修改职工信息");
      }

      if(myPicImg2.isNull()){
       qDebug()<<myPicImg2.isNull();}
      else{
      //修改图片
      //插入职工照片
      QByteArray picdata;
      QBuffer buffer(&picdata);
      buffer.open(QIODevice::WriteOnly);
      myPicImg2.save(&buffer,"JPG");
      QVariant var(picdata);
      QString sqlpic = "update worker set picture=? where name='"+name+"' ";
      query.prepare(sqlpic);
      query.addBindValue(var);
      if(!query.exec()){
          QMessageBox::information(0,QObject::tr("提示"),"照片写入失败！请缩小图片尺寸");
      }
      }
      //清空图片
       myPicImg2=QImage();
      //刷新列表
      workers_show();
      //清楚输入的数据
      workersdata_claer();
}
//4、4查询职工信息
void MainWindow::on_selectworkers_btn_clicked()
{
  if(!ui->workers_id->text().isEmpty()){
      QString key = "id";
      QString value=ui->workers_id->text();
      queryworkers(key,value);
  }else if(!ui->workers_name->text().isEmpty()){
      QString key = "name";
      QString value=ui->workers_name->text();
      queryworkers(key,value);
  }else if(!ui->workers_phone->text().isEmpty()){
      QString key = "phone";
      QString value=ui->workers_phone->text();
      queryworkers(key,value);
  }else if(!ui->workers_usename->text().isEmpty()){
      QString key = "usename";
      QString value=ui->workers_usename->text();
      queryworkers(key,value);
  }else if(!ui->workers_password->text().isEmpty()){
      QString key = "password";
      QString value=ui->workers_password->text();
      queryworkers(key,value);
  }else if(!ui->workers_addres->text().isEmpty()){
      QString key = "addres";
      QString value=ui->workers_addres->text();
      queryworkers(key,value);
  }else{
      QMessageBox::information(0,QObject::tr("提示"),"请输入信息!");
  }
}
//4、5显示全部职工信息
void MainWindow::on_showworkers_btn_clicked()
{
    workers_show();
}

/*5、商品功能*/
//5、1增加商品信息
void MainWindow::on_addgoods_btn_clicked()
{   //插入一条商品信息
    QSqlQuery query;
    QString name = ui->goods_name->text();
    int num = ui->goods_num->text().toInt();
    double price = ui->goods_price->text().toDouble();
    QString kind = ui->goods_kind->text();
    query.prepare("insert into goods(name,num,price,kind)"
                  "values(?,?,?,?)");
    query.addBindValue(name);
    query.addBindValue(num);
    query.addBindValue(price);
    query.addBindValue(kind);
    if(!query.exec()){
        //加入失败弹出警告
        QMessageBox::warning(this,tr("增加商品信息失败！"),tr("请完善信息,商品编号不用输入！"),QMessageBox::Ok);
        qDebug()<< query.lastError();
    }else{
        QMessageBox::information(0,QObject::tr("提示"),"成功增加商品信息");
    }

    //插入商品照片
    QByteArray picdata;
    QBuffer buffer(&picdata);
    buffer.open(QIODevice::WriteOnly);
    myPicImg1.save(&buffer,"JPG");
    QVariant var(picdata);
    QString sqlpic = "update goods set picture=? where name='"+name+"' ";
    query.prepare(sqlpic);
    query.addBindValue(var);
    if(!query.exec()){
        QMessageBox::information(0,QObject::tr("提示"),"照片写入失败！");
    }

    //清空图片
     myPicImg1=QImage();

    //刷新列表
    goods_show();
    //清楚输入的数据
    goodsdata_claer();
}
//5、2删除商品信息
void MainWindow::on_deletegoods_btn_clicked()
{
    QSqlQuery query;
   //按照编号或姓名删除
   if(!ui->goods_id->text().isEmpty()){
       int id = ui->goods_id->text().toInt();
       QString sql = QString("delete from goods where id='%1'").arg(id);
       if(query.exec(sql)){
           QMessageBox::information(0,QObject::tr("提示"),"删除成功");

       }else{
           QMessageBox::information(0,QObject::tr("提示"),"请输入正确的商品编号或名称");
           qDebug()<<query.lastError();
       }

   }else if(!ui->goods_name->text().isEmpty()){
        QString name = ui->goods_name->text();
        QString sql = QString("delete from goods where name='%1'").arg(name);
       if(query.exec(sql)){
           QMessageBox::information(0,QObject::tr("提示"),"删除成功");

       }else{
           QMessageBox::information(0,QObject::tr("提示"),"请输入正确的商品编号或名称");
           qDebug()<<query.lastError();
       }
   }else{
       QMessageBox::information(0,QObject::tr("提示"),"请输入商品编号或名称");
   }

   //刷新界面
   goods_show();
   //清楚输入的数据
   goodsdata_claer();
}
//5、3修改商品信息
void MainWindow::on_changegoods_btn_clicked()
{
    //修改一条商品信息
    QSqlQuery query;
    QString id = ui->goods_id->text();
    QString name =ui->goods_name->text();
    QString num =ui->goods_num->text();
    QString price=ui->goods_price->text();
    QString kind=ui->goods_kind->text();
    QString sql = QString("update goods set name='%1', num='%2',price='%3',kind='%4' where id ='%5'").arg(name).arg(num).arg(price).arg(kind).arg(id);
    if(!query.exec(sql)){
        //加入失败弹出警告
        QMessageBox::warning(this,tr("修改商品信息失败！"),tr("请完善信息,商品编号不用输入！"),QMessageBox::Ok);
        qDebug()<< query.lastError();
    }else{
        QMessageBox::information(0,QObject::tr("提示"),"成功修改商品信息");
    }


    if(myPicImg1.isNull()){
     qDebug()<<myPicImg1.isNull();}
    else{
    //插入商品照片
    QByteArray picdata;
    QBuffer buffer(&picdata);
    buffer.open(QIODevice::WriteOnly);
    myPicImg1.save(&buffer,"JPG");
    QVariant var(picdata);
    QString sqlpic = "update goods set picture=? where name='"+name+"' ";
    query.prepare(sqlpic);
    query.addBindValue(var);
    if(!query.exec()){
        QMessageBox::information(0,QObject::tr("提示"),"照片写入失败！");
    }
    }


    //清空图片
     myPicImg1=QImage();
    //刷新列表
    goods_show();
    //清楚输入的数据
    goodsdata_claer();
}
//5、4查询商品信息
void MainWindow::on_selectgoods_btn_clicked()
{
    if(!ui->goods_id->text().isEmpty()){
        QString key = "id";
        QString value=ui->goods_id->text();
        querygoods(key,value);
    }else if(!ui->goods_name->text().isEmpty()){
        QString key = "name";
        QString value=ui->goods_name->text();
        querygoods(key,value);
    }else if(!ui->goods_num->text().isEmpty()){
        QString key = "num";
        QString value=ui->goods_num->text();
        querygoods(key,value);
    }else if(!ui->goods_price->text().isEmpty()){
        QString key = "price";
        QString value=ui->goods_price->text();
        querygoods(key,value);
    }else if(!ui->goods_kind->text().isEmpty()){
        QString key = "kind";
        QString value=ui->goods_kind->text();
        querygoods(key,value);
    }else{
         QMessageBox::information(0,QObject::tr("提示"),"请输入信息！");
    }

    //清楚输入的数据
    goodsdata_claer();

}
//5、5显示全部商品信息
void MainWindow::on_showgoods_btn_clicked()
{
    goods_show();
}


/*6、图片上传事件*/
//6、1商品图片上传事件
void MainWindow::on_goods_upload_clicked()
{
    QString picturename = QFileDialog::getOpenFileName(this,"选择商品图片",".","Image File(*.png *.jpg *.jpeg *.bmp)");
    if(picturename.isEmpty()) return;
    myPicImg1.load(picturename);
    //图片自适应标签大小
    myPicImg1.scaled(ui->goods_picture->size(),Qt::KeepAspectRatio);
    ui->goods_picture->setScaledContents(true);
    ui->goods_picture->setPixmap(QPixmap::fromImage(myPicImg1));
}
//6、2职工照片上传事件
void MainWindow::on_workers_uoload_clicked()
{
    QString picturename = QFileDialog::getOpenFileName(this,"选择职工照片",".","Image File(*.png *.jpg *.jpeg *.bmp)");
    if(picturename.isEmpty()) return;
    myPicImg2.load(picturename);
    //图片自适应标签大小
    myPicImg2.scaled(ui->workers_picture->size(),Qt::KeepAspectRatio);
    ui->workers_picture->setScaledContents(true);
    ui->workers_picture->setPixmap(QPixmap::fromImage(myPicImg2));
}





/*7、职工列表点击事件*/
//获得该行的内容在输入框中展示，供用户编辑操作
void MainWindow::on_workers_tableWidget_cellDoubleClicked(int row, int column)
{
    QString workersvalue[6];
    //根据其行数获得其内容
    for(int i = 0 ;i <6;i++){
        QString value  = ui->workers_tableWidget->item(row,i)->text();
        workersvalue[i]=value;
    }
    ui->workers_id->setText(workersvalue[0]);
    ui->workers_name->setText(workersvalue[1]);
    ui->workers_phone->setText(workersvalue[2]);
    ui->workers_usename->setText(workersvalue[3]);
    ui->workers_password->setText(workersvalue[4]);
    ui->workers_addres->setText(workersvalue[5]);

}


/*8、商品列表点击事件*/
//获得该行的内容在输入框中展示，供用户编辑操作
void MainWindow::on_goods_tableWidget_cellDoubleClicked(int row, int column)
{
    QString goodvalue[5];
    //根据其行数获得其内容
    for(int i = 0 ;i <5;i++){
        QString value  = ui->goods_tableWidget->item(row,i)->text();
        goodvalue[i]=value;
    }
    ui->goods_id->setText(goodvalue[0]);
    ui->goods_name->setText(goodvalue[1]);
    ui->goods_num->setText(goodvalue[2]);
    ui->goods_price->setText(goodvalue[3]);
    ui->goods_kind->setText(goodvalue[4]);

}

```

**main.cpp:**

```c++
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
```

#### 3、3 各功能详解

##### 主函数

> 程序先调用mainwindow.cpp中连接数据库中的静态方法连接数据库，若初次连接失败，弹出提示框：请排查故障后连接；用户确认后，自行排查问题；同时程序自动打开mysql的服务进程；进行第二次连接，若失败则直接退出程序；反之，成功则直接进入登录界面。

```c++
//主函数
int main(int argc, char *argv[]){}

//访问Mysql数据库的静态方法
static bool createMySqlConn(){}
```

##### 登录功能

> 通过获取用户输入的账号和密码，点击登录按钮，触发登录点击事件，程序调用void Login::on_btn_login_clicked()函数连接数据库验证其正确性，若正确直接进去系统功能界面；反之，则弹出提示框：请输入正确的信息。

```c++
//登录事件
void Login::on_btn_login_clicked()
```



##### 增加信息功能

> 用户在输入框输入信息后，点击增加信息按钮，触发增加信息事件，程序调用 void on_addgoods_btn_clicked()函数，连接数据库，获得输入框中的信息，向数据库中插入信息；若输入框没有数据，则弹出提示框：请输入正确的信息。

```c++
   //增加商品信息
    void on_addgoods_btn_clicked();
     //增加职工信息
    void on_addworkers_btn_clicked();
```

##### 删除信息功能

> 用户通过输入框输入编号或者名称数据后点击删除信息按钮，触发删除西悉尼事件，程序通过一一检查编号、名称框的数据，获得其值，通过连接数据库，向数据库发送删除指令；若两个输入框都没有数据，则弹出提示框：请输入正确的信息。

```c++
   //删除职工信息
    void on_deleteworkers_btn_clicked();
    //删除商品信息
    void on_deletegoods_btn_clicked(); 
```

##### 修改信息功能

> 用户通过输入框输入要修改的数据后，点击修改信息按钮，触发修改信息事件，程序连接数据库，并根据获得输入框中的信息，向数据库中修改信息指令；若输入框没有数据，则弹出提示框：请输入正确的信息。

```c++
   //修改商品信息
    void on_changegoods_btn_clicked();
    //修改职工信息
    void on_changeworkers_btn_clicked();
```

##### 查询信息功能

> 用户通过输入在输入框输入要查询的数据，点击查询信息按钮，触发查询信息事件，程序通过一一排查输入框中的值，若全为空，则弹出提示框：请输入正确的信息；若有信息则获取其数据和查询的字段，传递给void querygoods(QString key,QString value)函数，该函数通过连接数据库，获得其信息，并将信息展示在表格中。

```c++
  //查询职工信息
    void on_selectworkers_btn_clicked();
  //查询商品信息
    void on_selectgoods_btn_clicked();
  //查询一条商品信息
    void querygoods(QString key,QString value);
    //查询一条职工信息
    void queryworkers(QString key,QString value);
```

##### 显示全部信息功能

> 程序调用void goods_show()函数，将其信息展示在列表；
>
> 在void goods_show()函数中调用void workers_num()方法，连接数据库获取信息的总数量，设置int workersnum，即总数量；void goods_show()函数以此设置表格的行数；同时连接数据库，获得其信息，并将其信息展示在表格中。

```c++
   //商品信息展示在列表
    void goods_show();
    //职工信息展示在列表
    void workers_show();
//获取职工的数量
    void workers_num();
    //获取商品的数量
    void goods_num();
//职工数量
    int workersnum;
    //商品数量
    int goodsnum;
```

##### 双击表格内单元格获取信息功能

> 用户通过双击单元格，触发单元格点击事件，程序通过获得用户双击单元格所在的行数，从表格内获取数据，并展示在输入框内，供用户进行编辑，进行增加信息、删除信息等功能。

```c++
    //单元格点击事件
    void on_workers_tableWidget_cellDoubleClicked(int row, int column);
    void on_goods_tableWidget_cellDoubleClicked(int row, int column);
```

##### 图片上传功能

> 用户通过点击上传按钮，触发图片事件，程序打开文件管理器，供用户选择图片，系统以此获得图片，并展示在图片框内，并将其保存在全局变量内，供用户进行增加信息、删除信息等操作；若图片上传失败，则弹出提示框：图片尺寸太大，请缩小后上传。

```c++
    //上传商品照片
    void on_goods_upload_clicked();
    //上传职工照片
    void on_workers_uoload_clicked();
   //图片上传
     QImage myPicImg1;
     QImage myPicImg2;
```

##### 输入框清除功能

> 用户每进行一次增删改查等操作后，程序都会自动清楚输入框中的内容

```c++
   //清楚数据框中内容
    void goodsdata_claer();
    void workersdata_claer();  
```

##### 跳转界面功能

> 用户点击信息管理按钮后，触发跳转界面事件，程序根据用户单击的按钮信息，跳转到相应的界面

```c++
   //跳转商品信息管理页面
    void on_btn_goods_clicked();
    //跳转职工信息管理界面
    void on_btn_workers_clicked();  
```

#### 3、4 .pro工程文件

```c++
#-------------------------------------------------
#
# Project created by QtCreator 2022-06-06T11:05:27
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Supermarket_system
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    login.h

FORMS    += mainwindow.ui \
    login.ui

RESOURCES += \
    res.qrc

CONFIG += C++11

```



## 四、程序发布

> 在编写 Qt 程序的时候，不管我们使用的什么样的 IDE 都可以进行编译版本的切换，如果要发布程序需要切换为 Release 版本（Debug 为调试版本），编译器会对生成的 Release 版可执行程序进行优化，生成的可执行程序会更小。这里以 QtCreator 为例，截图如下：

![image-20220611181400415](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206111814481.png)

**模式选择完毕之后开始构建当前项目，最后找到生成的带 Release 后缀的构建目录，如下图所示：**

![image-20220611181506305](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206111815390.png)

**将 Release 放在一个单独的文件内**

**打开 Powershell窗口执行命令：**

**输入windeployqt.exe 可执行程序的命名+.exe**

![image-20220611181307561](https://sx-image799.oss-cn-hangzhou.aliyuncs.com/image/202206111813712.png)

