#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passgenwindow.h"
#include "logwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void mySignal(bool isLogged);

private slots:
    void on_quit_clicked();

    void on_passgen_clicked();

    void on_passman_clicked();

private:
    Ui::MainWindow *ui;

    Passgenwindow *passgenwindow;

    Logwindow *login;

};

#endif // MAINWINDOW_H
