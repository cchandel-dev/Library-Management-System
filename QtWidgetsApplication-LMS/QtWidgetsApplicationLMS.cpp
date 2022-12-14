#include "QtWidgetsApplicationLMS.h"
#include "addDialog.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include "Library.h"
using namespace std;
QtWidgetsApplicationLMS::QtWidgetsApplicationLMS(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.listView->setModel(&model);
    ui.listView->setSelectionMode(QAbstractItemView::SingleSelection); 
    // connect the selectionChanged signal to the handleSelectionChanged slot
    QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButton_clicked()));
    QObject::connect(ui.buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(groupButtonToggled(QAbstractButton*)));
    QObject::connect(ui.listView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(handleSelectionChanged(const QModelIndex &, const QModelIndex &)));
    ui.listView->show();//not sure this line is even necessary
}

QtWidgetsApplicationLMS::~QtWidgetsApplicationLMS()
{}

void QtWidgetsApplicationLMS::addButton_clicked() {
    addDialog dialog(this);
    if (dialog.exec()) {
        QString title = dialog.titleLineEdit->text();
        QString author = dialog.authorLineEdit->text();
        QString bookSize = dialog.sizeLineEdit->text();
        QDate date = dialog.publishCalender->selectedDate();
        if (!title.isEmpty() && !author.isEmpty() && !bookSize.isEmpty() && date.isValid()) {
            test.addBook(title.toStdString(), author.toStdString(), bookSize.toInt(), date.day(), date.month(), date.year());
            QStandardItem* item = new QStandardItem();
            item->setText(title);
            model.appendRow(item);
        }
    }
}
void QtWidgetsApplicationLMS::on_deleteButton_clicked() {
    QItemSelectionModel* select = ui.listView->selectionModel();
    if (select->hasSelection()) { //check if has selectionbuttonClicked
        QModelIndexList rows = select->selectedRows(); // return selected row(s)
        for (const QModelIndex& row : rows)
            model.removeRow(row.row());
    }
}
void QtWidgetsApplicationLMS::handleSelectionChanged(const QModelIndex& old_idx, const QModelIndex& new_idx) {
    QVariant data = model.data(old_idx, Qt::DisplayRole);
    ui.bookTitleLabel->setText(data.toString());
}
void QtWidgetsApplicationLMS::groupButtonToggled(QAbstractButton* selectedButton) {
    /*if (selectedButton == ui.sortTitleButton) {
        model.clear(); 

        QStandardItem* item = new QStandardItem();
        item->setText(title);
        model.appendRow(item);
    }*/
}