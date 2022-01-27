#include "hwmon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hwmon w;
    w.show();
    return a.exec();
}
