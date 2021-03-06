#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passgenwindow.h"
#include "passmanwindow.h"
#include "logwindow.h"
#include "registerwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quit_clicked();

    void on_passgen_clicked();

    void on_passman_clicked();

private:
    Ui::MainWindow *ui;

    Passgenwindow *passgenwindow;
    Passmanwindow *passmanwindow;
    Logwindow *logwindow;
};

#endif // MAINWINDOW_H
