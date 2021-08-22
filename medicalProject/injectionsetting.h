#ifndef INJECTIONSETTING_H
#define INJECTIONSETTING_H

#include <QDialog>

namespace Ui {
class InjectionSetting;
}

class InjectionSetting : public QDialog
{
    Q_OBJECT

public:
    explicit InjectionSetting(QWidget *parent = nullptr);
    ~InjectionSetting();

private:
    Ui::InjectionSetting *ui;
};

#endif // INJECTIONSETTING_H
