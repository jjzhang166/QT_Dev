#include "dialog.h"
#include "ui_dialog.h"

const static double PI=3.1416;

Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    bool bOk;
    QString strTmp;
    QString strRadius = ui->lineEditRadius->text();
    int nRadius = strRadius.toInt(&bOk);
    double area = nRadius * nRadius * PI;
    strTmp.setNum(area);

    ui->labelArea->setText(strTmp);
}
