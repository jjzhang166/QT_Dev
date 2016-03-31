#include "dialog.h"
#include <QGridLayout>
#include <QMessageBox>

#include "cmath.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->label1 = new QLabel(this);
    label1->setText(tr("请输入圆的半径："));
    this->labelArea = new QLabel(this);
    this->lineEditRadius = new QLineEdit(this);
    this->button = new QPushButton(this);
    this->button->setText(tr("显示对应圆的面积"));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(this->label1, 0, 0);
    mainLayout->addWidget(this->lineEditRadius, 0, 1);
    mainLayout->addWidget(this->labelArea, 1, 0);
    mainLayout->addWidget(this->button, 1, 1);

    connect(this->button, SIGNAL(clicked()), this, SLOT(calculateArea()));
    connect(this->lineEditRadius, SIGNAL(textChanged(QString)), this, SLOT(calculateArea()));
}

Dialog::~Dialog()
{

}

void Dialog::calculateArea()
{
    bool bOk;
    QString strRadius = this->lineEditRadius->text();
    double dRadius = strRadius.toDouble(&bOk);
    if(bOk)
    {
        QString strTmp;
        double dArea = dvcs::CMath::calCirclecArea(dRadius);
        strTmp.setNum(dArea);

        this->labelArea->setText(strTmp);
    }
    else
    {
        QMessageBox::warning(this, "warning", "请输入有效的半径。");
    }
}
