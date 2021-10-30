#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "passmanwindow.h"

namespace Ui {
class Logwindow;
}

class Logwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Logwindow(QWidget *parent = nullptr);
    ~Logwindow();

signals:
    void logWindow();
    void trasmit_to_passman(QString username);

private slots:
    void on_Loginbutton_clicked();
    void on_Exitbutton_clicked();
    void on_Registerbutton_clicked();

private:
    Ui::Logwindow *ui;

    Passmanwindow passmanwindow;
    QSqlDatabase database;
};

#endif // LOGWINDOW_H
