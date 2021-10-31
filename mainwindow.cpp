#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_passgen_clicked()
{
    Passgenwindow *passgenwindow = new Passgenwindow();
    passgenwindow->show();
    this->close();
}

void MainWindow::on_passman_clicked()
{
    Logwindow logwindow;
    logwindow.setModal(true);
    logwindow.exec();
}

void MainWindow::on_quit_clicked()
{
    QApplication::quit();
}
