#ifndef SMARTSERVER_H
#define SMARTSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class SmartServer;
}

class SmartServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit SmartServer(QWidget *parent = 0);
    ~SmartServer();

private slots:
    void newconnect();
    void recv_data();
//    void on_pushButton_clicked();

    void on_Send_clicked();

    void on_set_btn_clicked();

private:
    QTcpServer *server;
    QTcpSocket *socketfd;

    Ui::SmartServer *ui;
};

#endif // SMARTSERVER_H
