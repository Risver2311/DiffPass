#include <QMessageBox>
#include "mainwindow.h"
#include "passmanwindow.h"
#include "ui_logwindow.h"

Logwindow::Logwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logwindow)
{
    ui->setupUi(this);
}

Logwindow::~Logwindow()
{
    delete ui;
}

void Logwindow::on_Loginbutton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "test" && password == "test")
    {
        Passmanwindow *passmanwindow;
        passmanwindow = new Passmanwindow();
        connect(passmanwindow, &Passmanwindow::secWindow, this, &MainWindow::show);
        passmanwindow->show();
        this->close();
    }
    else
        QMessageBox::warning(this, "Login", "Username and password is not correct");
}

void Logwindow::on_Exitbutton_clicked()
{
        this->close();
}

void Logwindow::on_Registerbutton_clicked()
{
    Registerwindow registerwindow;
    registerwindow.setModal(true);
    registerwindow.exec();
}
