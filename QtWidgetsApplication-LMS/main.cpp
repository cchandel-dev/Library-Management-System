#include "QtWidgetsApplicationLMS.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplicationLMS w;
    w.show();
    return a.exec();
}
