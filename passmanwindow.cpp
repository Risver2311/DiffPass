#include "passmanwindow.h"
#include "mainwindow.h"
#include "ui_passmanwindow.h"

Passmanwindow::Passmanwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Passmanwindow)
{
    ui->setupUi(this);
}

Passmanwindow::~Passmanwindow()
{
    delete ui;
}

