#pragma once

#include <QDialog>
#include "ui_addDialog.h"

class addDialog : public QDialog, public Ui::Dialog
{
	Q_OBJECT

public:
	addDialog(QWidget* parent = nullptr);
	~addDialog();

private:

};
