#ifndef PASSMANWINDOW_H
#define PASSMANWINDOW_H

#include <QMainWindow>

namespace Ui {
class Passmanwindow;
}

class Passmanwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Passmanwindow(QWidget *parent = nullptr);
    ~Passmanwindow();

signals:
    void secWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Passmanwindow *ui;
};

#endif // PASSMANWINDOW_H
