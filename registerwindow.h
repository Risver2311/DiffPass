#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Registerwindow;
}

class Registerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Registerwindow(QWidget *parent = nullptr);
    ~Registerwindow();

private slots:
    void on_Registerbutton_clicked();

private:
    Ui::Registerwindow *ui;

    QSqlDatabase database;
};

#endif // REGISTERWINDOW_H
