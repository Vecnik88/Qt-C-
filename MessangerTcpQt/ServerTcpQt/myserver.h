#pragma once

#include <QWidget>
#include <QtWidgets>
#include <QTcpServer>
#include <QTcpSocket>

class QTcpServer;
class QTextEdit;
class QTcpSocket;

class MyServer : public QWidget{
    Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit* m_ptxt;
    quint16 m_nNextBlockSize;

    void sendToClient(QTcpSocket* psocket, const QString& str);

public:
    MyServer(quint64 nPort, QWidget* wgt = 0);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};


