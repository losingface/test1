#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

#include "maincontentsui.h"
#include "presssetting.h"
#include "syringesetting.h"
#include "elsesetting.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    //主界面
    MainContentsUI *mainContentsUI;

    // 压力设置界面
    PressSetting *pressSettingUi;

    //注射设置界面
    SyringeSetting *syringeSettingUi;

    // 其他设置界面
    ElseSetting *elseSettingUi;

public slots:

    // 定时器显示系统时间
    void onTimerUpdate(void);

    // 显示压力设置界面
    void onShowPressSetting();

    // 显示注射器设置界面
    void onShowSyringeSetting();

    // 显示其他设置界面
    void onShowElseSetting();

private slots:

    void on_mainUI_clicked();

};

#endif // WIDGET_H
