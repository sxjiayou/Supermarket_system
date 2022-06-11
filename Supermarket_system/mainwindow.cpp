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
