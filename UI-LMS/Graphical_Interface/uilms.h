#ifndef UILMS_H
#define UILMS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class UILMS; }
QT_END_NAMESPACE

class UILMS : public QMainWindow
{
    Q_OBJECT

public:
    UILMS(QWidget *parent = nullptr);
    ~UILMS();

private:
    Ui::UILMS *ui;
};
#endif // UILMS_H
