#include "injectionsetting.h"
#include "ui_injectionsetting.h"

InjectionSetting::InjectionSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InjectionSetting)
{
    ui->setupUi(this);

    setStyleSheet("background-color: rgb(171, 171, 171)");


}

InjectionSetting::~InjectionSetting()
{
    delete ui;
}
