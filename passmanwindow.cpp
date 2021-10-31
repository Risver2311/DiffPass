#include "mainwindow.h"
#include "ui_passmanwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

Passmanwindow::Passmanwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Passmanwindow)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("database");
}

Passmanwindow::~Passmanwindow()
{
    database.close();
    delete ui;
}

void Passmanwindow::recived(QString username)
{
    if(database.open())
    {
        QString sBuffer ="SELECT * FROM "+username;

        querymodel = new QSqlQueryModel();
        querymodel -> setQuery(sBuffer);
        ui -> tableView -> setModel(querymodel);
    }

    else
    {
        QMessageBox::about(this, "Failed", "Connection Failed");
    }

    Passmanwindow::show();
    base = username;
}

void Passmanwindow::on_AddButton_clicked()
{
    QString website = ui->lineEdit_website->text();
    QString user = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO "+base+"(website, username, password)" "VALUES(:website, :username, :password)");
    qry.bindValue(":website", website);
    qry.bindValue(":username", user);
    qry.bindValue(":password", password);

    if(qry.exec())
    {
        ui->lineEdit_website->clear();
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        QMessageBox::about(this, "Success", "Added");
    }

    else
    {
        qDebug() << qry.lastError();
        QMessageBox::about(this, "error", "error");
    }

     refresh();
}

void Passmanwindow::on_removeButton_clicked()
{
    QString website = ui->lineEdit_website->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery qry;
    qry.prepare("DELETE FROM "+base+" WHERE website =:website AND username =:username AND password =:password");
    qry.bindValue(":website", website);
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);

    if(qry.exec())
    {
        ui->lineEdit_website->clear();
        ui->lineEdit_username->clear();
        ui->lineEdit_password->clear();
        QMessageBox::about(this, "Success", "Removed");
    }

    else
    {
        qDebug() << qry.lastError();
        QMessageBox::about(this, "error", "error");
    }

    refresh();
}

void Passmanwindow::refresh()
{
    QString qBuffer ="SELECT * FROM "+base;
    querymodel = new QSqlQueryModel();
    querymodel -> setQuery(qBuffer);
    ui -> tableView -> setModel(querymodel);
}
