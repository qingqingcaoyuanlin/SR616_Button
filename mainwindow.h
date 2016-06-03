#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serial.h"
namespace Ui {
class MainWindow;
}
typedef struct Serial_Data_
{
    uchar Start_Flag;    //开始标志，0x00
    uchar Value;        //值
    uchar End_Flag;    //结束标志，0xFF
}Serial_Data;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
    Serial serialThread;
    void Serial_Send(Serial_Data *serialData);
private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_clicked();

protected slots:
    void ui_printf();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
