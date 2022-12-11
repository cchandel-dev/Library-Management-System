#include "uilms.h"
#include "ui_uilms.h"

UILMS::UILMS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UILMS)
{
    ui->setupUi(this);
}

UILMS::~UILMS()
{
    delete ui;
}

