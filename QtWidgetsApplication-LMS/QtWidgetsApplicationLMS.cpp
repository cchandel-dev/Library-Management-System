#include "QtWidgetsApplicationLMS.h"
#include <QStandardItemModel>
#include <QStandardItem>
using namespace std;
QtWidgetsApplicationLMS::QtWidgetsApplicationLMS(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.DataView->setModel(&model);
    ui.DataView->show();
}

QtWidgetsApplicationLMS::~QtWidgetsApplicationLMS()
{}

void QtWidgetsApplicationLMS::on_addButton_clicked() {
    QStandardItem* item = new QStandardItem();
    item->setEditable(false);
    item->setText("This is a test run!");
    model.appendRow(item);
}