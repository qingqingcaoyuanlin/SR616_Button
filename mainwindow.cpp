#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "serial.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        ui->comboBox_Port->addItem(info.portName());
    ui->comboBox_Port->setCurrentIndex(0);

    QStringList Header;
    Header<<"9600"<<"12800"<<"115200";
    ui->comboBox_Baudrate->addItems(Header);
    ui->comboBox_Baudrate->setCurrentIndex(0);

    ui->pushButton_open->setText("打开");

    connect(&serialThread, SIGNAL(signal_printf()), this, SLOT(ui_printf()));

}

MainWindow::~MainWindow()
{
    serialThread.serialPort.close();
    delete ui;
}
void MainWindow::Serial_Send(Serial_Data *serialData)
{
    serialThread.serialPort.write((char*)serialData, sizeof(Serial_Data));
}
void MainWindow::on_pushButton_1_clicked()
{
    if(serialThread.serialPort.isOpen())
    {
        Serial_Data Data_Send;
        Data_Send.Start_Flag = 0x00;
        Data_Send.End_Flag = 0xFF;
        Data_Send.Value = 0x01;
        Serial_Send(&Data_Send);
        ui->textEdit->append("Button 1");
    }
    else
    {
        ui->textEdit->append("请先打开串口");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(serialThread.serialPort.isOpen())
    {
        Serial_Data Data_Send;
        Data_Send.Start_Flag = 0x00;
        Data_Send.End_Flag = 0xFF;
        Data_Send.Value = 0x02;
        Serial_Send(&Data_Send);
        ui->textEdit->append("Button 2");
    }
    else
    {
        ui->textEdit->append("请先打开串口");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(serialThread.serialPort.isOpen())
    {
        Serial_Data Data_Send;
        Data_Send.Start_Flag = 0x00;
        Data_Send.End_Flag = 0xFF;
        Data_Send.Value = 0x04;
        Serial_Send(&Data_Send);
        ui->textEdit->append("Button 3");
    }
    else
    {
        ui->textEdit->append("请先打开串口");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(serialThread.serialPort.isOpen())
    {
        Serial_Data Data_Send;
        Data_Send.Start_Flag = 0x00;
        Data_Send.End_Flag = 0xFF;
        Data_Send.Value = 0x08;
        Serial_Send(&Data_Send);
        ui->textEdit->append("Button 4");
    }
    else
    {
        ui->textEdit->append("请先打开串口");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(serialThread.serialPort.isOpen())
    {
        Serial_Data Data_Send;
        Data_Send.Start_Flag = 0x00;
        Data_Send.End_Flag = 0xFF;
        Data_Send.Value = 0x10;
        Serial_Send(&Data_Send);
        ui->textEdit->append("Button 5");
    }
    else
    {
        ui->textEdit->append("请先打开串口");
    }
}

void MainWindow::on_pushButton_open_clicked()
{
    if(serialThread.serialPort.isOpen())
    {
        ui->pushButton_open->setText("打开");
        serialThread.serialPort.close();
    }
    else
    {
        if(ui->comboBox_Port->currentText()!= NULL)
        {
            serialThread.serialPort.setBaudRate(ui->comboBox_Baudrate->currentText().toInt());
            serialThread.serialPort.setPortName(ui->comboBox_Port->currentText());

            if(serialThread.serialPort.open(QIODevice::ReadWrite))
            {
               ui->pushButton_open->setText("关闭");
               serialThread.start();
               ui->textEdit->append("open success\n");

            }
            else
            {
                ui->pushButton_open->setText("打开");
                ui->textEdit->append("open fail\n");
            }
        }
        else
        {
            ui->textEdit->append("please set serial\n");
        }


    }
}

void MainWindow::ui_printf()
{
    QScrollBar *scrollbar;
    QString string;
    string = QString(serialThread.Data_Rx);

    ui->textEdit->append(string);
    scrollbar = ui->textEdit->verticalScrollBar();
    scrollbar->setSliderPosition(scrollbar->maximum());
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
}
