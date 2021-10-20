#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logwindow = new Logwindow();
    connect(logwindow, &Logwindow::logWindow, this, &MainWindow::show);

    passgenwindow = new Passgenwindow();
    connect(passgenwindow, &Passgenwindow::firstWindow, this, &MainWindow::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_passgen_clicked()
{
    passgenwindow->show();
        this->close();
}

void MainWindow::on_passman_clicked()
{
    logwindow->show();
        this->close();
}

void MainWindow::on_quit_clicked()
{
    QApplication::quit();
}


