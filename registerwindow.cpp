#include "registerwindow.h"
#include "ui_registerwindow.h"

#include <QCryptographicHash>
#include <QMessageBox>

Registerwindow::Registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registerwindow)
{
    ui->setupUi(this);
}

Registerwindow::~Registerwindow()
{
    delete ui;
}

void Registerwindow::on_Registerbutton_clicked()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("database");

    if(database.open())
    {
        QString username = ui -> lineEdit_username -> text();

        QByteArray password = ui -> lineEdit_password -> text().toUtf8();
        QCryptographicHash *hash = new QCryptographicHash(QCryptographicHash::Md5);
        hash->addData(password);
        password = hash->result().toHex();

        QSqlQuery qry;

        qry.prepare("SELECT username FROM users WHERE username = :username");
        qry.bindValue(":username", username);

        bool check = true;

        if(qry.exec())
        {
            while(qry.next())
            {
                QString usernameDB = qry.value("username").toString();

                if(username == usernameDB)
                {
                    QMessageBox::about(this, "Username", "Username Already Exist!");
                    check = false;
                    break;
                }
            }
        }

        if(check)
        {
            qry.prepare("INSERT INTO users(username, password)" "VALUES (:username, :password)");
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

