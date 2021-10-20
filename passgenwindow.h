#ifndef PASSGENWINDOW_H
#define PASSGENWINDOW_H

#include <QMainWindow>

namespace Ui {
class Passgenwindow;
}

class Passgenwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Passgenwindow(QWidget *parent = nullptr);
    ~Passgenwindow();

signals:
    void firstWindow();

private slots:
    void on_Exitbutton_clicked();

    void on_genpass_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Passgenwindow *ui;
};

#endif // PASSGENWINDOW_H
