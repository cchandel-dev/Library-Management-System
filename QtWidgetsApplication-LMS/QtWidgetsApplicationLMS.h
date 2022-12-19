#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplicationLMS.h"
#include <QStandardItemModel>
#include "Library.h"
class QtWidgetsApplicationLMS : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplicationLMS(QWidget *parent = nullptr);
    ~QtWidgetsApplicationLMS();
    template <typename T, typename Container = vector<T, std::allocator<T>>, typename Compare = less<T>>
    void data_to_model(std::priority_queue<T, Container, Compare> pq);
    void add_to_model(const std::string&);
private slots:
    void addButton_clicked();
    void on_deleteButton_clicked();
    void handleSelectionChanged(const QModelIndex&, const QModelIndex&);
    void groupButtonToggled(QAbstractButton* selectedButton);
    void searchByAuthor();
    void loadData();
    void clearAllData();
    void reportBug();
    void Instructions_and_Background();
private:
    Ui::QtWidgetsApplicationLMSClass ui;
    int counterOfAddition;
    QStandardItemModel model;
    Library test;
};
