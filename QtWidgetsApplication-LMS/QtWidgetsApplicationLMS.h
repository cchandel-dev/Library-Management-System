#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplicationLMS.h"
#include <QStandardItemModel>

class QtWidgetsApplicationLMS : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplicationLMS(QWidget *parent = nullptr);
    ~QtWidgetsApplicationLMS();

private slots:
    void on_addButton_clicked();
private:
    Ui::QtWidgetsApplicationLMSClass ui;
    int counterOfAddition;
    QStandardItemModel model;
};
