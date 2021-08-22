#ifndef ELSESETTING_H
#define ELSESETTING_H

#include <QDialog>

namespace Ui {
class ElseSetting;
}

class ElseSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ElseSetting(QWidget *parent = nullptr);
    ~ElseSetting();

    void init();

    // 设置时间
    void setTimer();

public slots:

    // 定时器显示系统时间
    void onTimerUpdate(void);

private slots:
    void on_save_clicked();

private:
    Ui::ElseSetting *ui;
};

#endif // ELSESETTING_H
