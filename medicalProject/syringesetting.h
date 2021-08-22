#ifndef SYRINGESETTING_H
#define SYRINGESETTING_H

#include <QDialog>
#include <QPushButton>


namespace Ui {
class SyringeSetting;
}

class SyringeSetting : public QDialog
{
    Q_OBJECT

public:
    explicit SyringeSetting(QWidget *parent = nullptr);
    ~SyringeSetting();

private slots:
    void on_save_clicked();

private:
    Ui::SyringeSetting *ui;
};

#endif // SYRINGESETTING_H
