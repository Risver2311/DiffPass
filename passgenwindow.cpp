/*#include "QMessageBox"
#include "iostream"
#include "string"
#include "QPixmap"
#include "QFile"
#include "QTextStream"*/

#include "mainwindow.h"
#include "ui_passgenwindow.h"

extern bool isLogged;

Passgenwindow::Passgenwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Passgenwindow)
{
    ui->setupUi(this);
}

Passgenwindow::~Passgenwindow()
{
    delete ui;
}

void Passgenwindow::on_Exitbutton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
        this->close();
}

void Passgenwindow::on_genpass_clicked()
{
    //QString password="";
    //QString alphabet_lower="abcdefghijklmnopqrstuvwxyz";
    //QString alphabet_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //QString symbols="!@#$%&";
    //QString number="0123456789";

    //ui->label_6->setText("select at least one option.");
}


void Passgenwindow::on_saveButton_clicked()
{

}



