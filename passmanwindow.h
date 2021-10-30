#ifndef PASSMANWINDOW_H
#define PASSMANWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class Passmanwindow;
}

class Passmanwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Passmanwindow(QWidget *parent = nullptr);
    ~Passmanwindow();

public slots:
    void recived(QString username);

private slots:
    void on_AddButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::Passmanwindow *ui;

    QSqlDatabase database;
    QSqlQueryModel * querymodel;
    QString base;
};

#endif // PASSMANWINDOW_H
