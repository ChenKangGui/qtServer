#include "smartserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmartServer w;
    w.show();

    return a.exec();
}
