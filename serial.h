#ifndef SERIAL_H
#define SERIAL_H
#include <QThread>
#include <QtSerialPort/qserialport.h>
class Serial : public QThread
{
public:
    Serial();
    ~Serial();
    QSerialPort serialPort;
    QString PortName;
    QString BaudRate;
    QByteArray Data_Tx;
protected:
    void run();
};

#endif // SERIAL_H
