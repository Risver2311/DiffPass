#include "QMessageBox"
#include "iostream"
#include "string"
#include "QPixmap"
#include "QFile"
#include "QTextStream"

#include "passgenwindow.h"
#include "mainwindow.h"
#include "ui_passgenwindow.h"

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
    QString password="";
    QString alphabet_lower="abcdefghijklmnopqrstuvwxyz";
    QString alphabet_upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString symbols="!@#$%&";
    QString number="0123456789";

    int len = ui->spinBox->value();
    int key,count_alpha_lwr=0,count_alpha_uppr=0,count_symbols=0,count_number=0;
    int c=0;

    if(ui->numbers->isChecked() && ui->symbols->isChecked() && ui->lowcase->isChecked() && ui->uppcase->isChecked())
    {
        while(c<len){
            int k=rand()%4+1;   //Generates a Random Number between 1 to 4

            if(c==0){
                k%=3;
                if(k==0)
                    ++k;
            }
            switch(k){
                case 1:/*This block will help to add lowercase alphabets in the password*/{
                    if((count_alpha_lwr==2)&&(count_number==0||count_alpha_uppr==0||count_alpha_uppr==1||count_symbols==0))
                        break;
                    int key=rand()%26;
                    password=password+alphabet_lower[key];
                    count_alpha_lwr++;
                    c++;
                    break;
            }

            case 2:/*This block will help to add uppercase alphabets in the password*/{
                    if((count_alpha_uppr==2)&&(count_number==0||count_alpha_lwr==0||count_alpha_lwr==1||count_symbols==0))
                        break;
                    key=rand()%26;
                    password=password+alphabet_upper[key];
                    count_alpha_uppr++;
                    c++;
                    break;
            }
            case 3:/*This block will help to add digits in the password*/{
                    if((count_number==1)&&(count_alpha_lwr==0||count_alpha_lwr==1||count_alpha_uppr==1||count_alpha_uppr==0||count_symbols==0))
                        break;
                    key=rand()%10;
                    password=password+number[key];
                    count_number++;
                    c++;
                    break;
            }
            case 4:/*This block will help to symbols in the password*/{
                    if((count_symbols==1)&&(count_alpha_lwr==0||count_alpha_lwr==0||count_alpha_lwr==1||count_alpha_uppr==0||count_alpha_uppr==1||count_number==0))
                        break;
                    key=rand()%6;
                    password=password+symbols[key];
                    count_symbols++;
                    c++;
                    break;
            }
            }

        }
    }
    else
        ui->label_6->setText("select at least one option.");

    ui->lineEdit->setText(password);
}

