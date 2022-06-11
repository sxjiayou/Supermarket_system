/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *showwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *btn_login;
    QLabel *label_4;
    QLineEdit *Password;
    QLabel *label_3;
    QLineEdit *Username;
    QLabel *label_5;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(1158, 557);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ion/\347\224\250\346\210\267\347\231\273\345\275\225 .png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        showwidget = new QWidget(Login);
        showwidget->setObjectName(QStringLiteral("showwidget"));
        showwidget->setGeometry(QRect(10, 20, 1141, 521));
        label = new QLabel(showwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 351, 521));
        label->setStyleSheet(QLatin1String("border-image: url(:/image/login.png);\n"
"border-top-left-radius:30px;\n"
"border-bottom-left-radius:30px;"));
        label_2 = new QLabel(showwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 0, 791, 521));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(211, 211, 218);\n"
"border-top-right-radius:30px;\n"
"border-bottom-right-radius:30px;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pushButton = new QPushButton(showwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1040, 10, 51, 41));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/image/\345\205\263\351\227\255.png);"));
        btn_login = new QPushButton(showwidget);
        btn_login->setObjectName(QStringLiteral("btn_login"));
        btn_login->setGeometry(QRect(590, 420, 261, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        btn_login->setFont(font);
        btn_login->setStyleSheet(QLatin1String("#btn_login{\n"
"	\n"
"	background-color: rgb(0, 0, 0);\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	border:3px solid rgb(0,0,0);\n"
"	boder-radius:8px;\n"
"}\n"
"\n"
"#btn_login:hover{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"#btn_login:pressed{\n"
"	padding-top:5px;\n"
"	padding-left:5px;\n"
"}"));
        label_4 = new QLabel(showwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 270, 481, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_4->setFont(font1);
        Password = new QLineEdit(showwidget);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setGeometry(QRect(560, 300, 341, 51));
        Password->setFont(font);
        Password->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(showwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 180, 481, 101));
        label_3->setFont(font1);
        Username = new QLineEdit(showwidget);
        Username->setObjectName(QStringLiteral("Username"));
        Username->setGeometry(QRect(560, 200, 341, 51));
        Username->setFont(font);
        label_5 = new QLabel(showwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(600, 50, 271, 101));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(36);
        label_5->setFont(font2);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QString());
        btn_login->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        label_4->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", 0));
        Password->setText(QString());
        label_3->setText(QApplication::translate("Login", "\350\264\246\345\217\267\357\274\232", 0));
        Username->setText(QString());
        label_5->setText(QApplication::translate("Login", "\346\254\242\350\277\216\347\231\273\345\275\225\357\274\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
