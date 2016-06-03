#include "serial.h"
#include "mainwindow.h"
#include <QDebug>

void Serial::run()
{
    while(1)
    {
        while(serialPort.isOpen())
        {

            Data_Rx = serialPort.readAll();
            if(Data_Rx.length() > 0)
            {
                qDebug()<<"recv";
                emit signal_printf();
            }
            /*
            if(Data_Tx.length() > 0)
            {
                serialPort.write((char *)&Data_Tx, Data_Tx.length());
                Data_Tx.clear();
            }
            */
            usleep(1000);
        }
        sleep(1);
    }
}

