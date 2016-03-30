#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_lineEditRadius_textChanged(const QString &arg1);

private:
    void calculateArea();

    Ui::Dialog *ui;
};

#endif // DIALOG_H
