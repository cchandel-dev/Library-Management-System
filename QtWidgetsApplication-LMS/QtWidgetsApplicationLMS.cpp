#include "QtWidgetsApplicationLMS.h"
#include "addDialog.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStringListModel>
#include "Library.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace std;
QtWidgetsApplicationLMS::QtWidgetsApplicationLMS(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.listView->setModel(&model);
    ui.listView->setSelectionMode(QAbstractItemView::SingleSelection);
    // connect the selectionChanged signal to the handleSelectionChanged slot
    QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addButton_clicked()));
    QObject::connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchByAuthor()));
    QObject::connect(ui.actionLoad_Data, SIGNAL(triggered()), this, SLOT(loadData()));
    QObject::connect(ui.actionClear_Data, SIGNAL(triggered()), this, SLOT(clearAllData()));
    QObject::connect(ui.buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(groupButtonToggled(QAbstractButton*)));
    QObject::connect(ui.listView->selectionModel(), SIGNAL(currentChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(handleSelectionChanged(const QModelIndex &, const QModelIndex &)));
    ui.listView->show();//not sure this line is even necessary
    ui.sortTitleButton->click();
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
        for (const QModelIndex& row : rows) {
            QVariant source = model.data(row, Qt::DisplayRole);
            std::string temp = source.toString().toStdString();
            test.deleteBook(temp);
            model.removeRow(row.row());
        }
    }
}
void QtWidgetsApplicationLMS::handleSelectionChanged(const QModelIndex& old_idx, const QModelIndex& new_idx) {
    QVariant data = model.data(old_idx, Qt::DisplayRole);
    ui.bookTitleLabel->setText(data.toString());
}
void QtWidgetsApplicationLMS::groupButtonToggled(QAbstractButton* selectedButton) {
    if (selectedButton == ui.sortTitleButton) {
        model.clear();
        auto tempQueue = test.getNamesSorted();
        while (tempQueue.size()) {
            QStandardItem* item = new QStandardItem();
            item->setText(QString::fromStdString(tempQueue.top()));
            model.appendRow(item);
            tempQueue.pop();
        }
    }
    if (selectedButton == ui.sortSizeButton) {
        model.clear();
        auto tempQueue = test.getSizesSorted();
        while (tempQueue.size()) {
            QStandardItem* item = new QStandardItem();
            item->setText(QString::fromStdString(tempQueue.top().name));
            model.appendRow(item);
            tempQueue.pop();
        }
    }
    if (selectedButton == ui.sortDateButton) {
        model.clear();
        auto tempQueue = test.getDatesSorted();
        while (tempQueue.size()) {
            QStandardItem* item = new QStandardItem();
            item->setText(QString::fromStdString(tempQueue.top().name));
            model.appendRow(item);
            tempQueue.pop();
        }
    }
}
void QtWidgetsApplicationLMS::searchByAuthor() {
    QString author = ui.searchLine->text();
    unordered_set<std::string> titles = test.getBooksByAuthor(author.toStdString());
    std::vector<std::string> list;
    if(ui.buttonGroup->checkedButton() == ui.sortTitleButton){
        auto temp = test.getNamesSorted();
        while (temp.size()) {
            list.push_back(temp.top());
            temp.pop();
        }
    }
    if (ui.buttonGroup->checkedButton() == ui.sortSizeButton) {
        auto temp2 = test.getSizesSorted();
        while (temp2.size()) {
            list.push_back(temp2.top().name);
            temp2.pop();
        }
    }
    if (ui.buttonGroup->checkedButton() == ui.sortDateButton) {
        auto temp3 = test.getDatesSorted();
        while (temp3.size()) {
            list.push_back(temp3.top().name);
            temp3.pop();
        }
    }
    model.clear();
    for (const string& qstr : list) {
        if (titles.find(qstr) != titles.end() && author.toStdString() != "") {
            QStandardItem* item = new QStandardItem();
            item->setText(QString::fromStdString(qstr));
            model.appendRow(item);
        }
        else if (author.toStdString() == "") {
            QStandardItem* item = new QStandardItem();
            item->setText(QString::fromStdString(qstr));
            model.appendRow(item);
        }
    }
}
void QtWidgetsApplicationLMS::loadData() {
        // read in the json file
        std::ifstream f("GenericBookData.txt", std::ifstream::in);

        json j; //create unitiialized json object

        f >> j; // initialize json object with what was read from file

        std::cout << j << std::endl; // prints json object to screen

        for (auto obj : j) {
           test.addBook(obj["title"], obj["author"], obj["number_of_pages"], obj["publishing_date"]["publishing_day"], obj["publishing_date"]["publishing_month"], obj["publishing_date"]["publishing_year"]);
            QStandardItem* item = new QStandardItem();
            item->setText(QString::fromStdString(obj["title"].get<std::string>()));
            model.appendRow(item);
        }
        ui.buttonGroup->checkedButton()->click();

}
void QtWidgetsApplicationLMS::clearAllData() {
    auto temp = test.getNamesSorted();
    while (temp.size()) {
        test.deleteBook(temp.top());
        temp.pop();
    }
    ui.buttonGroup->checkedButton()->click();
}