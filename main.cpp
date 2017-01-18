#include "grafica.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    grafica w;
    w.show();

    return a.exec();
}
