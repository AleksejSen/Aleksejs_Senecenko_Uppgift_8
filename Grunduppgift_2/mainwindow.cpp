#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonUp_clicked()
{
    QString val_raw = ui->lineEdit->text();
    int val = val_raw.toInt();

    if((ui->spinBox_Blue->value()>= 255)
       || (ui->spinBox_Green->value()>= 255)
       || (ui->spinBox_Red->value()>= 255))
    {
        QMessageBox *mBox = new QMessageBox(this);
        mBox->setText("MAX value!");
        mBox->show();
    }

    ui->spinBox_Blue->stepBy(val);
    ui->spinBox_Green->stepBy(val);
    ui->spinBox_Red->stepBy(val);
}

void MainWindow::on_pushButtonDown_clicked()
{
    QString val_raw = ui->lineEdit->text();
    int val = val_raw.toInt();

    if((ui->spinBox_Blue->value()<= 0)
       || (ui->spinBox_Green->value()<= 0)
       || (ui->spinBox_Red->value() <= 0))
    {
        QMessageBox *mBox = new QMessageBox(this);
        mBox->setText("MIN value!");
        mBox->show();
    }

    ui->spinBox_Blue->stepBy(-val);
    ui->spinBox_Green->stepBy(-val);
    ui->spinBox_Red->stepBy(-val);
}
