#include "QtWidgetsApplicationLMS.h"
#include "addDialog.h"
#include <QStandardItemModel>
#include <QStandardItem>
using namespace std;
QtWidgetsApplicationLMS::QtWidgetsApplicationLMS(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.listView->setModel(&model);
    ui.listView->show();
}

QtWidgetsApplicationLMS::~QtWidgetsApplicationLMS()
{}

void QtWidgetsApplicationLMS::on_addButton_clicked() {
    addDialog dialog(this);
    if (dialog.exec()) {
        QString title = dialog.titleLineEdit->text();
        QString author = dialog.authorLineEdit->text();

        if (!title.isEmpty() && !author.isEmpty()) {
            QStandardItem* item = new QStandardItem();
            item->setText(title);
            model.appendRow(item);
        }
    }
}