#ifndef PRESSSETTING_H
#define PRESSSETTING_H

#include <QDialog>

namespace Ui {
class PressSetting;
}

class PressSetting : public QDialog
{
    Q_OBJECT

public:
    explicit PressSetting(QWidget *parent = nullptr);
    ~PressSetting();

    // 获取压力设置参数
    void getPressSettingParas();

private slots:
    void on_pressSuctionRight_clicked();

    void on_pressSuctionSave_clicked();

    void on_pressSuctionLeft_clicked();

    void on_injectionTimeLeft_clicked();

    void on_injectionTimeRight_clicked();

    void on_injectionTimeSave_clicked();

    void on_rationPauseTimeLeft_clicked();

    void on_rationPauseTimeRight_clicked();

    void on_rationPauseTimeSave_clicked();

    void on_semiAutoSppedLeft_clicked();

    void on_semiAutoSppedRight_clicked();

    void on_semiAutoSppedSave_clicked();

    void on_save_clicked();

private:
    Ui::PressSetting *ui;

    // 负压强度
    QStringList m_pressStrength;

    // 注射时间间隔
    QStringList m_injectionTimegap;

    // 定量停顿时间
    QStringList m_rationPauseTime;

    // 给药速度
    QStringList m_medicineSpped;
};

#endif // PRESSSETTING_H
