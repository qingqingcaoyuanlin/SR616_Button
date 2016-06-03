#ifndef SERIAL_H
#define SERIAL_H
#include <QThread>
#include <QtSerialPort/qserialport.h>
class Serial : public QThread
{
    Q_OBJECT
public:
    QSerialPort serialPort;
    QString PortName;
    QString BaudRate;
    QByteArray Data_Tx;
    QByteArray Data_Rx;
protected:
    void run();
signals:
    void signal_printf();
};

#endif // SERIAL_H
