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

private slots:
    void addButton_clicked();
    void on_deleteButton_clicked();
    void handleSelectionChanged(const QModelIndex&, const QModelIndex&);
    void groupButtonToggled(QAbstractButton* selectedButton);
    void searchByAuthor();
private:
    Ui::QtWidgetsApplicationLMSClass ui;
    int counterOfAddition;
    QStandardItemModel model;
    Library test;
};
