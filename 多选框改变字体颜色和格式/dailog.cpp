#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    QObject::connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    QObject::connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_checkBox_1_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}


void Dialog::on_checkBox_2_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}


void Dialog::on_checkBox_3_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette palette = ui->textEdit->palette();
    if(ui->radioButton->isChecked())
        palette.setColor(QPalette::Text,Qt::red);
    else if(ui->radioButton_2->isChecked())
        palette.setColor(QPalette::Text,Qt::blue);
    else if(ui->radioButton_3->isChecked())
        palette.setColor(QPalette::Text,Qt::green);
    else
        palette.setColor(QPalette::Text,Qt::black);
    ui->textEdit->setPalette(palette);
}

