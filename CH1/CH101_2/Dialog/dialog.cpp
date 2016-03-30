#include "dialog.h"
#include "ui_dialog.h"

#include <QMessageBox>

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
    this->calculateArea();
}

void Dialog::on_lineEditRadius_textChanged(const QString &arg1)
{
    this->calculateArea();
}

void Dialog::calculateArea()
{
    bool bOk;
    QString strTmp;
    QString strRadius = ui->lineEditRadius->text();
    int nRadius = strRadius.toInt(&bOk);
    if(bOk)
    {
        double area = nRadius * nRadius * PI;
        strTmp.setNum(area);

        ui->labelArea->setText(strTmp);
    }
    else
    {
        QMessageBox::warning(this, "warning", "请输入有效的半径。");
    }
}
