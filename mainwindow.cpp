#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        ui->comboBox_Port->addItem(info.portName());
    ui->comboBox->setCurrentIndex(0);

    QStringList Header;
    Header<<"9600"<<"12800"<<"115200";
    ui->comboBox_rate->addItems(Header);
    ui->comboBox_rate->setCurrentIndex(0);

    ui->pushButton_open->setText("打开");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{

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
                ui->pushButton->setText("打开");
                ui->textEdit->append("open fail\n");
            }
        }
        else
        {
            ui->textEdit->append("please set serial\n");
        }


    }
}


