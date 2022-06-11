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
