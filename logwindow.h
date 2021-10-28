#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

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

private slots:
    void on_Loginbutton_clicked();
    void on_Exitbutton_clicked();
    void on_Registerbutton_clicked();

private:
    Ui::Logwindow *ui;
    QSqlDatabase database;
};

#endif // LOGWINDOW_H
