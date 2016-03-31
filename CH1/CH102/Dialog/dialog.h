#ifndef DIALOG_H
#define DIALOG_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void calculateArea();

private:
    QLabel *label1,*labelArea;
    QLineEdit *lineEditRadius;
    QPushButton *button;
};

#endif // DIALOG_H
