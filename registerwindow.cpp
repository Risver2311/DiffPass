#include "mainwindow.h"
#include "ui_registerwindow.h"

#include <QCryptographicHash>
#include <QMessageBox>

Registerwindow::Registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registerwindow)
{
    ui->setupUi(this);
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("database");
}

Registerwindow::~Registerwindow()
{
    delete ui;
    database.close();
}

void Registerwindow::on_Registerbutton_clicked()
{
    if(database.open())
    {
        QString username = ui -> lineEdit_username -> text();
        int username_length = ui ->lineEdit_username -> text().length();

        QByteArray password = ui -> lineEdit_password -> text().toUtf8();
        int password_length = ui ->lineEdit_username -> text().length();
        QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Md5);
        hash->addData(password);
        password = hash->result().toHex();

        QSqlQuery qry;

        qry.prepare("SELECT username FROM users WHERE username = :username");
        qry.bindValue(":username", username);

        bool check = true;

        if(qry.exec())
        {
            if(username_length >= 4 && password_length >= 4)
            {
                while(qry.next())
                {
                    QString usernameDB = qry.value("username").toString();

                    if(username == usernameDB)
                    {
                        QMessageBox::about(this, "Username", "Username Already Exist!");
                        check = false;
                        ui -> lineEdit_password ->clear();
                        ui -> lineEdit_username ->clear();
                        break;
                    }
                }
            }

            else
            {
                QMessageBox::about(this, "Username or Password", "Your username or password it too short(min. 4 letters)");
                ui -> lineEdit_password ->clear();
                ui -> lineEdit_username ->clear();
                check = false;
            }
        }

        if(check)
        {
            qry.prepare("CREATE TABLE "+ username +"(website VARCHAR(255), username VARCHAR(255), password VARCHAR(255))");
            qry.exec();

            qry.prepare("INSERT INTO users (username, password)" "VALUES (:username, :password)");
            qry.bindValue(":username", username);
            qry.bindValue(":password", password);

            if(qry.exec())
            {
                QMessageBox::about(this, "Registration", "Registration was successful");
                this->close();
            }

            else
            {
                QMessageBox::about(this, "Registration", "Registration was not successful");
            }

        }
    }

    else
    {
        qDebug() << "Not Connected";
    }
}
