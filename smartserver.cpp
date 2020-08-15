#include "smartserver.h"
#include "ui_smartserver.h"
#include <string>
#include <QDebug>
#include <QHostAddress>

SmartServer::SmartServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SmartServer)
{
    ui->setupUi(this);

    server = new QTcpServer();
}

SmartServer::~SmartServer()
{
    delete ui;
}

void SmartServer::newconnect()
{
    qDebug() << "connect";
    socketfd = server->nextPendingConnection();
    QString ip = (socketfd->peerAddress()).toString();
    qDebug() << ip;

    connect(socketfd, SIGNAL(readyRead()), this, SLOT(recv_data()));
}

void SmartServer::recv_data()
{
    QByteArray buf = socketfd->readAll();
    qDebug() << buf;

    ui->recv_label->setText(buf);
}



void SmartServer::on_Send_clicked()
{
    char buf[1024] = {0};
    QString data = ui->send_label->toPlainText();
    if(!data.isEmpty())
    {
        strcpy_s(buf, data.toStdString().c_str());
        socketfd->write(buf, strlen(buf));
    }
}

void SmartServer::on_set_btn_clicked()
{
    int ip = ui->Port->text().toInt();
    server->listen(QHostAddress::Any, ip);

    connect(server, SIGNAL(newConnection()), this, SLOT(newconnect()));

    ui->set_btn->setVisible(false);
}
