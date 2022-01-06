#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    label = new QLabel;
    label->setMinimumWidth(150);
    label->setText("当前文件:");
    ui->statusbar->addWidget(label);

    pro = new QProgressBar;
    pro->setMinimum(5);
    pro->setMaximum(50);
    pro->setValue(25);
    //progressbar->setInvertedAppearance(true);// 反向
    double dProgress = (pro->value() - pro->minimum()) * 100.0
                    / (pro->maximum() - pro->minimum());
    pro->setFormat(QString::fromLocal8Bit("cur %1%").arg(QString::number(dProgress, 'f', 1)));
    ui->statusbar->addWidget(pro);

    fontcombobox = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel("字体"));
    ui->toolBar->addWidget(fontcombobox);


}


void MainWindow::on_action_2_triggered(bool checked)
{

}


void MainWindow::on_action_2_triggered()
{

}


void MainWindow::on_action_3_triggered(bool checked)
{
    QTextCharFormat fmt;
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

