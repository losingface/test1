#ifndef MAINCONTENTSUI_H
#define MAINCONTENTSUI_H

#include <QDialog>

namespace Ui {
class MainContentsUI;
}

class MainContentsUI : public QDialog
{
    Q_OBJECT

public:
    explicit MainContentsUI(QWidget *parent = nullptr);
    ~MainContentsUI();

    //bool eventFilter(QObject *obj, QEvent *e);

protected:

    void paintEvent(QPaintEvent *event);

    bool eventFilter(QObject *obj, QEvent *e);

signals:

    //压力设置信号
    void pressSetting();

    // 注射设置信号
    void syringeSetting();

    // 其他设置信号
    void elseSetting();

private slots:

    // 压力设置槽函数
    void on_pressSetting_clicked();

    // 注射设置槽函数

    void on_syringeSetting_clicked();

    void on_otherSetting_clicked();

private:
    Ui::MainContentsUI *ui;
};

#endif // MAINCONTENTSUI_H
