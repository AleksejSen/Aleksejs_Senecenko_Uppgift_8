#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"

#include "libcomponent.h"
#include "libpower.h"
#include "libresistance.h"


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

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_Calc_clicked()
{
    /* Read input */
   QString r0_in_raw = ui->lineEdit_R1->text();
   QString r1_in_raw = ui->lineEdit_R1->text();
   QString r2_in_raw = ui->lineEdit_R1->text();
   QString v_in_raw = ui->lineEdit_Volt->text();

   /*Conver to float*/
   /*R1*/
   if(r0_in_raw.toFloat() < 0)
       _r_in_arr[0] = 0;
   else
       _r_in_arr[0] = r0_in_raw.toFloat();
   /*R2*/
   if(r1_in_raw.toFloat() < 0)
       _r_in_arr[1] = 0;
   else
       _r_in_arr[1] = r1_in_raw.toFloat();
   /*R3*/
   if(r2_in_raw.toFloat() < 0)
        _r_in_arr[2] = 0;
   else
       _r_in_arr[2] = r2_in_raw.toFloat();
   /*Volt*/
   if(v_in_raw.toFloat() < 0)
       _v_in = 0;
   else
       _v_in = v_in_raw.toFloat();

   /*Chec for radiobuttons status*/
   if(!ui->radioButton_S->isChecked() && !ui->radioButton_P->isChecked())
   {
       QMessageBox *mBox = new QMessageBox(this);
       mBox->setText("Select Connection Type");
       mBox->show();
   }


   /*S connection*/
   if(ui->radioButton_S->isChecked())
   {
       /*calculate*/
        _r_total_f= 0;// calc_resistance(3, 'S', _r_in_arr);

       /*convert*/
       QString r_total = QString::number(_r_total_f);
       /*output*/
       ui->lineEdit_R_tot->setText(r_total);
   }

   /*P connection*/
   if(ui->radioButton_P->isChecked())
   {
       /*calculate*/
        _r_total_f=  0; //calc_resistance(3, 'P', _r_in_arr);
       /*convert*/
       QString r_total = QString::number(_r_total_f);
       /*output*/
       ui->lineEdit_R_tot->setText(r_total);
   }

   /*Powr Calc*/
   //_power = calc_power_r(_v_in, _r_total_f);
   QString power = QString::number(_power);
   ui->lineEdit_Pow->setText(power);


}

void MainWindow::on_pushButton_Clear_clicked()
{
    QString default_text = "";
    /*Reset values*/
    _r_in_arr[0] = 0;
    _r_in_arr[1] = 0;
    _r_in_arr[2] = 0;
    _v_in = 0;

    /*Reset lineEdit boxex*/
    ui->lineEdit_R1->setText(default_text);
    ui->lineEdit_R2->setText(default_text);
    ui->lineEdit_R3->setText(default_text);
    ui->lineEdit_Volt->setText(default_text);

    ui->lineEdit_R_tot->setText(default_text);
    ui->lineEdit_Pow->setText(default_text);
    ui->lineEdit_R1_E12->setText(default_text);
    ui->lineEdit_R2_E12->setText(default_text);
    ui->lineEdit_R3_E12->setText(default_text);
}
