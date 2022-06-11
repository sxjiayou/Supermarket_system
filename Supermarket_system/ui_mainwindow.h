/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *showwidget;
    QWidget *task_bar;
    QHBoxLayout *horizontalLayout;
    QLabel *title;
    QPushButton *btn_reduce;
    QPushButton *btn_magnify;
    QPushButton *btn_close;
    QWidget *menu_bar;
    QPushButton *btn_goods;
    QPushButton *btn_workers;
    QStackedWidget *stackedWidget;
    QWidget *goodspage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *fungoods_btn;
    QPushButton *addgoods_btn;
    QPushButton *deletegoods_btn;
    QPushButton *changegoods_btn;
    QPushButton *selectgoods_btn;
    QPushButton *showgoods_btn;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *goods_id;
    QLabel *label_7;
    QLabel *goods_picture;
    QPushButton *goods_upload;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *goods_name;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *goods_num;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLineEdit *goods_price;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QLineEdit *goods_kind;
    QTableWidget *goods_tableWidget;
    QWidget *workerspage;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *addworkers_btn;
    QPushButton *deleteworkers_btn;
    QPushButton *changeworkers_btn;
    QPushButton *selectworkers_btn;
    QPushButton *showworkers_btn;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *workers_id;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QLineEdit *workers_name;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QLineEdit *workers_phone;
    QWidget *horizontalLayoutWidget_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QLineEdit *workers_usename;
    QWidget *horizontalLayoutWidget_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QLineEdit *workers_password;
    QWidget *horizontalLayoutWidget_15;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QLineEdit *workers_addres;
    QLabel *label_15;
    QLabel *workers_picture;
    QPushButton *workers_uoload;
    QTableWidget *workers_tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1637, 756);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ion/\350\266\205\345\270\202\345\225\206\345\223\201-\345\217\230.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        showwidget = new QWidget(centralWidget);
        showwidget->setObjectName(QStringLiteral("showwidget"));
        showwidget->setGeometry(QRect(20, 10, 1551, 741));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(128);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(showwidget->sizePolicy().hasHeightForWidth());
        showwidget->setSizePolicy(sizePolicy1);
        showwidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-bottom-left-radius: 30px;\n"
"border-top-left-radius: 30px;\n"
"border-top-right-radius: 30px;\n"
"border-bottom-right-radius: 0px;\n"
"border:none;\n"
""));
        task_bar = new QWidget(showwidget);
        task_bar->setObjectName(QStringLiteral("task_bar"));
        task_bar->setGeometry(QRect(0, 0, 1551, 101));
        task_bar->setStyleSheet(QLatin1String("\n"
"	border-top-left-radius: 30px;\n"
"	border-top-right-radius: 30px;\n"
"	border-bottom-left-radius: 0px;\n"
"	border-bottom-right-radius: 0px;	\n"
"background-color: rgb(86, 83, 93);"));
        horizontalLayout = new QHBoxLayout(task_bar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        title = new QLabel(task_bar);
        title->setObjectName(QStringLiteral("title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        title->setFont(font);
        title->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 255, 255);"));
        title->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(title);

        btn_reduce = new QPushButton(task_bar);
        btn_reduce->setObjectName(QStringLiteral("btn_reduce"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_reduce->sizePolicy().hasHeightForWidth());
        btn_reduce->setSizePolicy(sizePolicy2);
        btn_reduce->setMinimumSize(QSize(60, 60));
        btn_reduce->setMaximumSize(QSize(60, 60));
        btn_reduce->setStyleSheet(QStringLiteral("border-image: url(:/ion/minus-bold.png);"));

        horizontalLayout->addWidget(btn_reduce);

        btn_magnify = new QPushButton(task_bar);
        btn_magnify->setObjectName(QStringLiteral("btn_magnify"));
        sizePolicy2.setHeightForWidth(btn_magnify->sizePolicy().hasHeightForWidth());
        btn_magnify->setSizePolicy(sizePolicy2);
        btn_magnify->setMinimumSize(QSize(60, 60));
        btn_magnify->setMaximumSize(QSize(60, 60));
        btn_magnify->setStyleSheet(QStringLiteral("border-image: url(:/ion/add.png);"));

        horizontalLayout->addWidget(btn_magnify);

        btn_close = new QPushButton(task_bar);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        sizePolicy2.setHeightForWidth(btn_close->sizePolicy().hasHeightForWidth());
        btn_close->setSizePolicy(sizePolicy2);
        btn_close->setMinimumSize(QSize(60, 60));
        btn_close->setMaximumSize(QSize(60, 60));
        btn_close->setStyleSheet(QStringLiteral("border-image: url(:/ion/close.png);"));

        horizontalLayout->addWidget(btn_close);

        menu_bar = new QWidget(showwidget);
        menu_bar->setObjectName(QStringLiteral("menu_bar"));
        menu_bar->setGeometry(QRect(-1, 99, 191, 641));
        menu_bar->setStyleSheet(QLatin1String("border-bottom-left-radius: 30px;\n"
"border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-right-radius: 0px;	\n"
"background-color: rgb(81, 78, 85);\n"
"	"));
        btn_goods = new QPushButton(menu_bar);
        btn_goods->setObjectName(QStringLiteral("btn_goods"));
        btn_goods->setGeometry(QRect(10, 40, 171, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        btn_goods->setFont(font1);
        btn_goods->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(102,133,156,255), stop:1 rgba(117,255,201,255));\n"
"	border-radius: 7px;\n"
"    border:none;\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ion/\350\256\242\345\215\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_goods->setIcon(icon1);
        btn_goods->setIconSize(QSize(32, 32));
        btn_goods->setAutoRepeatInterval(95);
        btn_workers = new QPushButton(menu_bar);
        btn_workers->setObjectName(QStringLiteral("btn_workers"));
        btn_workers->setGeometry(QRect(10, 130, 171, 61));
        btn_workers->setFont(font1);
        btn_workers->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(102,133,156,255), stop:1 rgba(117,255,201,255));\n"
"	border-radius: 7px;\n"
"    border:none;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ion/\345\256\242\346\234\215.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_workers->setIcon(icon2);
        btn_workers->setIconSize(QSize(32, 32));
        stackedWidget = new QStackedWidget(showwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(189, 99, 1361, 641));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(55, 57, 67);\n"
"\n"
"	border-top-left-radius: 0px;\n"
"	border-top-right-radius: 0px;\n"
"	border-bottom-left-radius: 0px;\n"
"	border-bottom-right-radius: 0px;	\n"
"\n"
""));
        goodspage = new QWidget();
        goodspage->setObjectName(QStringLiteral("goodspage"));
        horizontalLayoutWidget = new QWidget(goodspage);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 550, 1361, 91));
        fungoods_btn = new QHBoxLayout(horizontalLayoutWidget);
        fungoods_btn->setSpacing(6);
        fungoods_btn->setContentsMargins(11, 11, 11, 11);
        fungoods_btn->setObjectName(QStringLiteral("fungoods_btn"));
        fungoods_btn->setContentsMargins(0, 0, 0, 0);
        addgoods_btn = new QPushButton(horizontalLayoutWidget);
        addgoods_btn->setObjectName(QStringLiteral("addgoods_btn"));
        addgoods_btn->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(50);
        sizePolicy3.setVerticalStretch(50);
        sizePolicy3.setHeightForWidth(addgoods_btn->sizePolicy().hasHeightForWidth());
        addgoods_btn->setSizePolicy(sizePolicy3);
        addgoods_btn->setMinimumSize(QSize(250, 70));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        addgoods_btn->setFont(font2);
        addgoods_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        fungoods_btn->addWidget(addgoods_btn);

        deletegoods_btn = new QPushButton(horizontalLayoutWidget);
        deletegoods_btn->setObjectName(QStringLiteral("deletegoods_btn"));
        deletegoods_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(deletegoods_btn->sizePolicy().hasHeightForWidth());
        deletegoods_btn->setSizePolicy(sizePolicy3);
        deletegoods_btn->setMinimumSize(QSize(250, 70));
        deletegoods_btn->setFont(font2);
        deletegoods_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        fungoods_btn->addWidget(deletegoods_btn);

        changegoods_btn = new QPushButton(horizontalLayoutWidget);
        changegoods_btn->setObjectName(QStringLiteral("changegoods_btn"));
        changegoods_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(changegoods_btn->sizePolicy().hasHeightForWidth());
        changegoods_btn->setSizePolicy(sizePolicy3);
        changegoods_btn->setMinimumSize(QSize(250, 70));
        changegoods_btn->setFont(font2);
        changegoods_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        fungoods_btn->addWidget(changegoods_btn);

        selectgoods_btn = new QPushButton(horizontalLayoutWidget);
        selectgoods_btn->setObjectName(QStringLiteral("selectgoods_btn"));
        selectgoods_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(selectgoods_btn->sizePolicy().hasHeightForWidth());
        selectgoods_btn->setSizePolicy(sizePolicy3);
        selectgoods_btn->setMinimumSize(QSize(250, 70));
        selectgoods_btn->setFont(font2);
        selectgoods_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        fungoods_btn->addWidget(selectgoods_btn);

        showgoods_btn = new QPushButton(horizontalLayoutWidget);
        showgoods_btn->setObjectName(QStringLiteral("showgoods_btn"));
        showgoods_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(showgoods_btn->sizePolicy().hasHeightForWidth());
        showgoods_btn->setSizePolicy(sizePolicy3);
        showgoods_btn->setMinimumSize(QSize(250, 70));
        showgoods_btn->setFont(font2);
        showgoods_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        fungoods_btn->addWidget(showgoods_btn);

        horizontalLayoutWidget_2 = new QWidget(goodspage);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 261, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(100, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label);

        goods_id = new QLineEdit(horizontalLayoutWidget_2);
        goods_id->setObjectName(QStringLiteral("goods_id"));
        sizePolicy2.setHeightForWidth(goods_id->sizePolicy().hasHeightForWidth());
        goods_id->setSizePolicy(sizePolicy2);
        goods_id->setMinimumSize(QSize(120, 50));
        goods_id->setMaximumSize(QSize(80, 16777215));
        goods_id->setFont(font3);
        goods_id->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_3->addWidget(goods_id);

        label_7 = new QLabel(goodspage);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 360, 100, 40));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(40, 40));
        label_7->setMaximumSize(QSize(100, 16777215));
        label_7->setFont(font3);
        label_7->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        goods_picture = new QLabel(goodspage);
        goods_picture->setObjectName(QStringLiteral("goods_picture"));
        goods_picture->setGeometry(QRect(131, 374, 141, 161));
        goods_picture->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));
        goods_upload = new QPushButton(goodspage);
        goods_upload->setObjectName(QStringLiteral("goods_upload"));
        goods_upload->setGeometry(QRect(30, 500, 93, 28));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        goods_upload->setFont(font4);
        goods_upload->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 10px;\n"
"    border:none;\n"
""));
        horizontalLayoutWidget_5 = new QWidget(goodspage);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 80, 261, 61));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(40, 40));
        label_3->setMaximumSize(QSize(100, 16777215));
        label_3->setFont(font3);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(label_3);

        goods_name = new QLineEdit(horizontalLayoutWidget_5);
        goods_name->setObjectName(QStringLiteral("goods_name"));
        sizePolicy2.setHeightForWidth(goods_name->sizePolicy().hasHeightForWidth());
        goods_name->setSizePolicy(sizePolicy2);
        goods_name->setMinimumSize(QSize(120, 50));
        goods_name->setMaximumSize(QSize(80, 16777215));
        goods_name->setFont(font3);
        goods_name->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_6->addWidget(goods_name);

        horizontalLayoutWidget_6 = new QWidget(goodspage);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 150, 261, 61));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(40, 40));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(label_4);

        goods_num = new QLineEdit(horizontalLayoutWidget_6);
        goods_num->setObjectName(QStringLiteral("goods_num"));
        sizePolicy2.setHeightForWidth(goods_num->sizePolicy().hasHeightForWidth());
        goods_num->setSizePolicy(sizePolicy2);
        goods_num->setMinimumSize(QSize(120, 50));
        goods_num->setMaximumSize(QSize(80, 16777215));
        goods_num->setFont(font3);
        goods_num->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_7->addWidget(goods_num);

        horizontalLayoutWidget_7 = new QWidget(goodspage);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 220, 261, 61));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMinimumSize(QSize(40, 40));
        label_5->setMaximumSize(QSize(100, 16777215));
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(label_5);

        goods_price = new QLineEdit(horizontalLayoutWidget_7);
        goods_price->setObjectName(QStringLiteral("goods_price"));
        sizePolicy2.setHeightForWidth(goods_price->sizePolicy().hasHeightForWidth());
        goods_price->setSizePolicy(sizePolicy2);
        goods_price->setMinimumSize(QSize(120, 50));
        goods_price->setMaximumSize(QSize(80, 16777215));
        goods_price->setFont(font3);
        goods_price->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_8->addWidget(goods_price);

        horizontalLayoutWidget_8 = new QWidget(goodspage);
        horizontalLayoutWidget_8->setObjectName(QStringLiteral("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(10, 290, 261, 61));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(40, 40));
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setFont(font3);
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_9->addWidget(label_6);

        goods_kind = new QLineEdit(horizontalLayoutWidget_8);
        goods_kind->setObjectName(QStringLiteral("goods_kind"));
        sizePolicy2.setHeightForWidth(goods_kind->sizePolicy().hasHeightForWidth());
        goods_kind->setSizePolicy(sizePolicy2);
        goods_kind->setMinimumSize(QSize(120, 50));
        goods_kind->setMaximumSize(QSize(80, 16777215));
        goods_kind->setFont(font3);
        goods_kind->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"    border:none;background-color: rgb(255, 255, 255);"));

        horizontalLayout_9->addWidget(goods_kind);

        goods_tableWidget = new QTableWidget(goodspage);
        goods_tableWidget->setObjectName(QStringLiteral("goods_tableWidget"));
        goods_tableWidget->setGeometry(QRect(285, 1, 1081, 551));
        goods_tableWidget->setStyleSheet(QLatin1String("QTableWidget{ color:black; \n"
"background-color:rgb(224,224,224);\n"
"selection-color:rgb(0, 0, 0); \n"
"selection-background-color:rgb(	100,149,237);\n"
"border:0px;\n"
"font: 8pt 'Microsoft YaHei' ;}"));
        stackedWidget->addWidget(goodspage);
        workerspage = new QWidget();
        workerspage->setObjectName(QStringLiteral("workerspage"));
        horizontalLayoutWidget_9 = new QWidget(workerspage);
        horizontalLayoutWidget_9->setObjectName(QStringLiteral("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(0, 550, 1361, 91));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        addworkers_btn = new QPushButton(horizontalLayoutWidget_9);
        addworkers_btn->setObjectName(QStringLiteral("addworkers_btn"));
        addworkers_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(addworkers_btn->sizePolicy().hasHeightForWidth());
        addworkers_btn->setSizePolicy(sizePolicy3);
        addworkers_btn->setMinimumSize(QSize(250, 70));
        addworkers_btn->setFont(font2);
        addworkers_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        horizontalLayout_10->addWidget(addworkers_btn);

        deleteworkers_btn = new QPushButton(horizontalLayoutWidget_9);
        deleteworkers_btn->setObjectName(QStringLiteral("deleteworkers_btn"));
        deleteworkers_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(deleteworkers_btn->sizePolicy().hasHeightForWidth());
        deleteworkers_btn->setSizePolicy(sizePolicy3);
        deleteworkers_btn->setMinimumSize(QSize(250, 70));
        deleteworkers_btn->setFont(font2);
        deleteworkers_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        horizontalLayout_10->addWidget(deleteworkers_btn);

        changeworkers_btn = new QPushButton(horizontalLayoutWidget_9);
        changeworkers_btn->setObjectName(QStringLiteral("changeworkers_btn"));
        changeworkers_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(changeworkers_btn->sizePolicy().hasHeightForWidth());
        changeworkers_btn->setSizePolicy(sizePolicy3);
        changeworkers_btn->setMinimumSize(QSize(250, 70));
        changeworkers_btn->setFont(font2);
        changeworkers_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        horizontalLayout_10->addWidget(changeworkers_btn);

        selectworkers_btn = new QPushButton(horizontalLayoutWidget_9);
        selectworkers_btn->setObjectName(QStringLiteral("selectworkers_btn"));
        selectworkers_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(selectworkers_btn->sizePolicy().hasHeightForWidth());
        selectworkers_btn->setSizePolicy(sizePolicy3);
        selectworkers_btn->setMinimumSize(QSize(250, 70));
        selectworkers_btn->setFont(font2);
        selectworkers_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        horizontalLayout_10->addWidget(selectworkers_btn);

        showworkers_btn = new QPushButton(horizontalLayoutWidget_9);
        showworkers_btn->setObjectName(QStringLiteral("showworkers_btn"));
        showworkers_btn->setEnabled(true);
        sizePolicy3.setHeightForWidth(showworkers_btn->sizePolicy().hasHeightForWidth());
        showworkers_btn->setSizePolicy(sizePolicy3);
        showworkers_btn->setMinimumSize(QSize(250, 70));
        showworkers_btn->setFont(font2);
        showworkers_btn->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 20px;\n"
"    border:none;\n"
""));

        horizontalLayout_10->addWidget(showworkers_btn);

        horizontalLayoutWidget_10 = new QWidget(workerspage);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 10, 261, 61));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget_10);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMinimumSize(QSize(40, 40));
        label_9->setMaximumSize(QSize(100, 16777215));
        label_9->setFont(font3);
        label_9->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_11->addWidget(label_9);

        workers_id = new QLineEdit(horizontalLayoutWidget_10);
        workers_id->setObjectName(QStringLiteral("workers_id"));
        sizePolicy2.setHeightForWidth(workers_id->sizePolicy().hasHeightForWidth());
        workers_id->setSizePolicy(sizePolicy2);
        workers_id->setMinimumSize(QSize(120, 50));
        workers_id->setMaximumSize(QSize(80, 16777215));
        workers_id->setFont(font3);
        workers_id->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_11->addWidget(workers_id);

        horizontalLayoutWidget_11 = new QWidget(workerspage);
        horizontalLayoutWidget_11->setObjectName(QStringLiteral("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(10, 80, 261, 61));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_11);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setMinimumSize(QSize(40, 40));
        label_10->setMaximumSize(QSize(100, 16777215));
        label_10->setFont(font3);
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_12->addWidget(label_10);

        workers_name = new QLineEdit(horizontalLayoutWidget_11);
        workers_name->setObjectName(QStringLiteral("workers_name"));
        sizePolicy2.setHeightForWidth(workers_name->sizePolicy().hasHeightForWidth());
        workers_name->setSizePolicy(sizePolicy2);
        workers_name->setMinimumSize(QSize(120, 50));
        workers_name->setMaximumSize(QSize(80, 16777215));
        workers_name->setFont(font3);
        workers_name->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_12->addWidget(workers_name);

        horizontalLayoutWidget_12 = new QWidget(workerspage);
        horizontalLayoutWidget_12->setObjectName(QStringLiteral("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(10, 150, 261, 61));
        horizontalLayout_13 = new QHBoxLayout(horizontalLayoutWidget_12);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(horizontalLayoutWidget_12);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setMinimumSize(QSize(40, 40));
        label_11->setMaximumSize(QSize(100, 16777215));
        label_11->setFont(font3);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_13->addWidget(label_11);

        workers_phone = new QLineEdit(horizontalLayoutWidget_12);
        workers_phone->setObjectName(QStringLiteral("workers_phone"));
        sizePolicy2.setHeightForWidth(workers_phone->sizePolicy().hasHeightForWidth());
        workers_phone->setSizePolicy(sizePolicy2);
        workers_phone->setMinimumSize(QSize(120, 50));
        workers_phone->setMaximumSize(QSize(80, 16777215));
        workers_phone->setFont(font3);
        workers_phone->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_13->addWidget(workers_phone);

        horizontalLayoutWidget_13 = new QWidget(workerspage);
        horizontalLayoutWidget_13->setObjectName(QStringLiteral("horizontalLayoutWidget_13"));
        horizontalLayoutWidget_13->setGeometry(QRect(10, 220, 261, 61));
        horizontalLayout_14 = new QHBoxLayout(horizontalLayoutWidget_13);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(horizontalLayoutWidget_13);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMinimumSize(QSize(40, 40));
        label_12->setMaximumSize(QSize(100, 16777215));
        label_12->setFont(font3);
        label_12->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_14->addWidget(label_12);

        workers_usename = new QLineEdit(horizontalLayoutWidget_13);
        workers_usename->setObjectName(QStringLiteral("workers_usename"));
        sizePolicy2.setHeightForWidth(workers_usename->sizePolicy().hasHeightForWidth());
        workers_usename->setSizePolicy(sizePolicy2);
        workers_usename->setMinimumSize(QSize(120, 50));
        workers_usename->setMaximumSize(QSize(80, 16777215));
        workers_usename->setFont(font3);
        workers_usename->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_14->addWidget(workers_usename);

        horizontalLayoutWidget_14 = new QWidget(workerspage);
        horizontalLayoutWidget_14->setObjectName(QStringLiteral("horizontalLayoutWidget_14"));
        horizontalLayoutWidget_14->setGeometry(QRect(10, 290, 261, 61));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_14);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(horizontalLayoutWidget_14);
        label_13->setObjectName(QStringLiteral("label_13"));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setMinimumSize(QSize(40, 40));
        label_13->setMaximumSize(QSize(100, 16777215));
        label_13->setFont(font3);
        label_13->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_15->addWidget(label_13);

        workers_password = new QLineEdit(horizontalLayoutWidget_14);
        workers_password->setObjectName(QStringLiteral("workers_password"));
        sizePolicy2.setHeightForWidth(workers_password->sizePolicy().hasHeightForWidth());
        workers_password->setSizePolicy(sizePolicy2);
        workers_password->setMinimumSize(QSize(120, 50));
        workers_password->setMaximumSize(QSize(80, 16777215));
        workers_password->setFont(font3);
        workers_password->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_15->addWidget(workers_password);

        horizontalLayoutWidget_15 = new QWidget(workerspage);
        horizontalLayoutWidget_15->setObjectName(QStringLiteral("horizontalLayoutWidget_15"));
        horizontalLayoutWidget_15->setGeometry(QRect(10, 360, 261, 61));
        horizontalLayout_16 = new QHBoxLayout(horizontalLayoutWidget_15);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_15);
        label_14->setObjectName(QStringLiteral("label_14"));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setMinimumSize(QSize(40, 40));
        label_14->setMaximumSize(QSize(100, 16777215));
        label_14->setFont(font3);
        label_14->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_16->addWidget(label_14);

        workers_addres = new QLineEdit(horizontalLayoutWidget_15);
        workers_addres->setObjectName(QStringLiteral("workers_addres"));
        sizePolicy2.setHeightForWidth(workers_addres->sizePolicy().hasHeightForWidth());
        workers_addres->setSizePolicy(sizePolicy2);
        workers_addres->setMinimumSize(QSize(120, 50));
        workers_addres->setMaximumSize(QSize(80, 16777215));
        workers_addres->setFont(font3);
        workers_addres->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));

        horizontalLayout_16->addWidget(workers_addres);

        label_15 = new QLabel(workerspage);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 430, 100, 40));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setMinimumSize(QSize(40, 40));
        label_15->setMaximumSize(QSize(100, 16777215));
        label_15->setFont(font3);
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        workers_picture = new QLabel(workerspage);
        workers_picture->setObjectName(QStringLiteral("workers_picture"));
        workers_picture->setGeometry(QRect(131, 424, 131, 121));
        workers_picture->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 10px;\n"
"    border:none;"));
        workers_uoload = new QPushButton(workerspage);
        workers_uoload->setObjectName(QStringLiteral("workers_uoload"));
        workers_uoload->setGeometry(QRect(30, 510, 93, 28));
        workers_uoload->setFont(font4);
        workers_uoload->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(67, 203, 255), stop:1 rgba(151, 8, 204));\n"
"	border-radius: 10px;\n"
"    border:none;\n"
""));
        workers_tableWidget = new QTableWidget(workerspage);
        workers_tableWidget->setObjectName(QStringLiteral("workers_tableWidget"));
        workers_tableWidget->setGeometry(QRect(280, 0, 1081, 551));
        workers_tableWidget->setStyleSheet(QLatin1String("QTableWidget{ color:black; \n"
"background-color:rgb(224,224,224);\n"
"selection-color:rgb(0, 0, 0); \n"
"selection-background-color:rgb(	100,149,237);\n"
"border:0px;\n"
"font: 8pt 'Microsoft YaHei' ;}"));
        stackedWidget->addWidget(workerspage);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\266\205\345\270\202\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        title->setText(QApplication::translate("MainWindow", "                       \350\266\205\345\270\202\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        btn_reduce->setText(QString());
        btn_magnify->setText(QString());
        btn_close->setText(QString());
        btn_goods->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\344\277\241\346\201\257\347\256\241\347\220\206", 0));
        btn_workers->setText(QApplication::translate("MainWindow", "\350\201\214\345\267\245\344\277\241\346\201\257\347\256\241\347\220\206", 0));
        addgoods_btn->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        deletegoods_btn->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        changegoods_btn->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        selectgoods_btn->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        showgoods_btn->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\205\250\351\203\250\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\347\274\226\345\217\267:", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\345\233\276\347\211\207:", 0));
        goods_picture->setText(QString());
        goods_upload->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\345\220\215\347\247\260:", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\346\225\260\351\207\217:", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\344\273\267\346\240\274:", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\347\247\215\347\261\273:", 0));
        addworkers_btn->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\350\201\214\345\267\245\344\277\241\346\201\257", 0));
        deleteworkers_btn->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\201\214\345\267\245\344\277\241\346\201\257", 0));
        changeworkers_btn->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\350\201\214\345\267\245\344\277\241\346\201\257", 0));
        selectworkers_btn->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\350\201\214\345\267\245\344\277\241\346\201\257", 0));
        showworkers_btn->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\205\250\351\203\250\350\201\214\345\267\245\344\277\241\346\201\257", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\201\214\345\267\245\347\274\226\345\217\267:", 0));
        label_10->setText(QApplication::translate("MainWindow", "\350\201\214\345\267\245\345\247\223\345\220\215:", 0));
        label_11->setText(QApplication::translate("MainWindow", "\350\201\214\345\267\245\347\224\265\350\257\235:", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\201\214\345\267\245\350\264\246\345\217\267:", 0));
        label_13->setText(QApplication::translate("MainWindow", "\350\201\214\345\267\245\345\257\206\347\240\201:", 0));
        label_14->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\345\234\260\345\235\200:", 0));
        label_15->setText(QApplication::translate("MainWindow", "\345\225\206\345\223\201\347\205\247\347\211\207:", 0));
        workers_picture->setText(QString());
        workers_uoload->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
