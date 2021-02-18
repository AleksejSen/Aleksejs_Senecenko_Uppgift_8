#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Calc_clicked();

    void on_pushButton_Clear_clicked();

private:
    Ui::MainWindow *ui;

private:
 /*variables*/
  float _v_in = 0;

  float _r_in_arr[3] ={0};
  float _r_total_f= 0;
  float _power = 0;

  float _r_E12_arr[3] = {0};


};
#endif // MAINWINDOW_H
