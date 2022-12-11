#include "uilms.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UILMS w;
    w.show();
    return a.exec();
}
