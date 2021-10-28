#include <QMessageBox>
#include <QCryptographicHash>

#include "mainwindow.h"
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
    database = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("database");

    QString username = ui->lineEdit_username->text();
    QByteArray password = ui -> lineEdit_password -> text().toUtf8();

    QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Md5);
    hash->addData(password);

    password = hash->result().toHex();

    if(database.open())
    {
        QSqlQuery qry(QSqlDatabase::database("MyConnect"));

        qry.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));
        qry.bindValue(":username", username);
        qry.bindValue(":password", password);

        if(!qry.exec())
        {
            QMessageBox::about(this, "Failed", "Query Failed To Execute");
        }

        else
        {
            while(qry.next())
            {
                QString usernameDB = qry.value(1).toString();
                QString passwordDB = qry.value(2).toString();

                if(usernameDB == username && passwordDB == password)
                {
                    QMessageBox::about(this, "Success", "Login Success");
                    this -> close();
                    Passmanwindow *passmanwindow = new Passmanwindow();
                    passmanwindow -> show();

                }

                else
                {
                    QMessageBox::about(this, "Failed", "Login Failed");
                }
            }
        }
    }

    else
    {
        QMessageBox::about(this, "Database Failed", "Database Connection Failed");
    }
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
