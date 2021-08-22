#include "presssetting.h"
#include "ui_presssetting.h"

#include <QImage>
#include <QIcon>
#include <QSize>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QMessageBox>

PressSetting::PressSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PressSetting)
{
    ui->setupUi(this);
    setStyleSheet("background-color: rgb(171, 171, 171)");
    // setStyleSheet ("border:2px;border-radius:10px;background-color: rgb(171, 171, 171)");
    //setStyleSheet ("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    // 设置窗口大小
    // this->setFixedSize(700,400);

    // 负压吸压
    QIcon btn_icon;
   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->pressSuctionLeft->setIcon(btn_icon);
    ui->pressSuctionLeft->setIconSize(QSize(60, 60));
    ui->pressSuctionLeft->setStyleSheet("border:none");

   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->pressSuctionRight->setIcon(btn_icon);
    ui->pressSuctionRight->setIconSize(QSize(60, 60));
    ui->pressSuctionRight->setStyleSheet("border:none");

    ui->pressSuctionValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->pressSuctionValue->setText("1");
    ui->pressSuctionValue->setFont(QFont("微软雅黑", 20));
    ui->pressSuctionValue->setAlignment(Qt::AlignCenter);

   // ui->pressSuction->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->pressSuction->setText("负压强度");
    ui->pressSuction->setFont(QFont("微软雅黑", 14));
    ui->pressSuction->setAlignment(Qt::AlignCenter);

    // 注射时间
    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->injectionTimeLeft->setIcon(btn_icon);
    ui->injectionTimeLeft->setIconSize(QSize(60, 60));
    ui->injectionTimeLeft->setStyleSheet("border:none");

   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->injectionTimeRight->setIcon(btn_icon);
    ui->injectionTimeRight->setIconSize(QSize(60, 60));
    ui->injectionTimeRight->setStyleSheet("border:none");

    ui->injectionTimeValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->injectionTimeValue->setText("1");
    ui->injectionTimeValue->setFont(QFont("微软雅黑", 20));
    ui->injectionTimeValue->setAlignment(Qt::AlignCenter);

   // ui->pressSuction->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->injectionTime->setText("注射时间间隔");
    ui->injectionTime->setFont(QFont("微软雅黑", 14));
    ui->injectionTime->setAlignment(Qt::AlignCenter);

    // 定量停顿时间
   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->rationPauseTimeLeft->setIcon(btn_icon);
    ui->rationPauseTimeLeft->setIconSize(QSize(60, 60));
    ui->rationPauseTimeLeft->setStyleSheet("border:none");

   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->rationPauseTimeRight->setIcon(btn_icon);
    ui->rationPauseTimeRight->setIconSize(QSize(60, 60));
    ui->rationPauseTimeRight->setStyleSheet("border:none");

    ui->rationPauseTimeValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->rationPauseTimeValue->setText("1");
    ui->rationPauseTimeValue->setFont(QFont("微软雅黑", 20));
    ui->rationPauseTimeValue->setAlignment(Qt::AlignCenter);

   // ui->pressSuction->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->rationPauseTime->setText("定量停顿时间");
    ui->rationPauseTime->setFont(QFont("微软雅黑", 14));
    ui->rationPauseTime->setAlignment(Qt::AlignCenter);

    // 半自动速度
    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->semiAutoSppedLeft->setIcon(btn_icon);
    ui->semiAutoSppedLeft->setIconSize(QSize(60, 60));
    ui->semiAutoSppedLeft->setStyleSheet("border:none");

    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->semiAutoSppedRight->setIcon(btn_icon);
    ui->semiAutoSppedRight->setIconSize(QSize(60, 60));
    ui->semiAutoSppedRight->setStyleSheet("border:none");

    ui->semiAutoSppedValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->semiAutoSppedValue->setText("1");
    ui->semiAutoSppedValue->setFont(QFont("微软雅黑", 20));
    ui->semiAutoSppedValue->setAlignment(Qt::AlignCenter);

   // ui->pressSuction->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->semiAutoSpped->setText("给药速度");
    ui->semiAutoSpped->setFont(QFont("微软雅黑", 14));
    ui->semiAutoSpped->setAlignment(Qt::AlignCenter);

    ui->save->setText("保存");
    ui->save->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(219, 71, 0);color:white");
    ui->save->setFont(QFont("微软雅黑", 12));

    // 获取压力设置参数
    getPressSettingParas();

}

PressSetting::~PressSetting()
{
    delete ui;
}

// 负压强度右侧按钮点击
void PressSetting::on_pressSuctionRight_clicked()
{
    QString pressStrengthString =  ui->pressSuctionValue->text();
    int index = m_pressStrength.indexOf(pressStrengthString);
    if(++index >= 10)
    {
        index = 0;
    }
    ui->pressSuctionValue->setText(m_pressStrength.at(index));
}

// 负压强度保存按钮点击
void PressSetting::on_pressSuctionSave_clicked()
{

    qDebug() << "on_pressSuctionSave_clicked on_pressSuctionSave_clicked";
}

// 负压强度左侧按钮点击
void PressSetting::on_pressSuctionLeft_clicked()
{
    QString pressStrengthString =  ui->pressSuctionValue->text();
    int index = m_pressStrength.indexOf(pressStrengthString);
    if(--index <= -1)
    {
        index = 9;
    }
    ui->pressSuctionValue->setText(m_pressStrength.at(index));
}

// 注射时间间隔左侧按钮点击
void PressSetting::on_injectionTimeLeft_clicked()
{
    QString injectionTime =  ui->injectionTimeValue->text();
    int index = m_injectionTimegap.indexOf(injectionTime);
    if(--index <= -1)
    {
        index = 4;
    }
    ui->injectionTimeValue->setText(m_injectionTimegap.at(index));
}

// 注射时间间隔右侧按钮点击
void PressSetting::on_injectionTimeRight_clicked()
{
    QString injectionTime =  ui->injectionTimeValue->text();
    int index = m_injectionTimegap.indexOf(injectionTime);
    if(++index >= 5)
    {
        index = 0;
    }
    ui->injectionTimeValue->setText(m_injectionTimegap.at(index));
}

// 注射时间间隔保存按钮点击
void PressSetting::on_injectionTimeSave_clicked()
{

}

// 定量停顿时间左侧按钮点击
void PressSetting::on_rationPauseTimeLeft_clicked()
{
    QString rationPauseTime =  ui->rationPauseTimeValue->text();
    int index = m_rationPauseTime.indexOf(rationPauseTime);
    if(--index <= -1)
    {
        index = 4;
    }
    ui->rationPauseTimeValue->setText(m_rationPauseTime.at(index));
}

// 定量停顿时间右侧按钮点击
void PressSetting::on_rationPauseTimeRight_clicked()
{
    QString rationPauseTime =  ui->rationPauseTimeValue->text();
    int index = m_rationPauseTime.indexOf(rationPauseTime);
    if(++index >= 5)
    {
        index = 0;
    }
    ui->rationPauseTimeValue->setText(m_rationPauseTime.at(index));
}

// 定量停顿时间保存按钮点击
void PressSetting::on_rationPauseTimeSave_clicked()
{

}

// 给药速度左侧按钮点击
void PressSetting::on_semiAutoSppedLeft_clicked()
{
    QString medicineSpped =  ui->semiAutoSppedValue->text();
    int index = m_medicineSpped.indexOf(medicineSpped);
    if(--index <= -1)
    {
        index = 4;
    }
    ui->semiAutoSppedValue->setText(m_medicineSpped.at(index));
}

// 给药速度右侧按钮点击
void PressSetting::on_semiAutoSppedRight_clicked()
{
    QString medicineSpped =  ui->semiAutoSppedValue->text();
    int index = m_medicineSpped.indexOf(medicineSpped);
    if(++index >= 5)
    {
        index = 0;
    }
    ui->semiAutoSppedValue->setText(m_medicineSpped.at(index));
}

// 给药速度保存按钮点击
void PressSetting::on_semiAutoSppedSave_clicked()
{

}

// 获取压力设置参数
void PressSetting::getPressSettingParas()
{
    QString pressTest = "8";
    // 负压强度
    m_pressStrength << "1" << "2" << "3" << "4" << "5"
                  << "6" << "7" << "8" << "9" << "10";

    ui->pressSuctionValue->setText(pressTest);

    // 注射时间间隔
    m_injectionTimegap << "1" << "2" << "3" << "4" << "5";
    ui->injectionTimeValue->setText("3");

    // 定量停顿时间
    m_rationPauseTime << "1" << "2" << "3" << "4" << "5";
    ui->rationPauseTimeValue->setText("4");

    // 给药速度
    m_medicineSpped << "1" << "2" << "3" << "4" << "5";
    ui->semiAutoSppedValue->setText("2");
}

// 保存按钮槽函数
void PressSetting::on_save_clicked()
{
    QMessageBox msgBox;//定义提示框
   // msgBox.setWindowTitle("确认删除文件");
    msgBox.setText("是否保存？");
   // msgBox.setInformativeText("亲，删除之后不可恢复哦。。。");
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setButtonText(QMessageBox::Ok,"确定");
    msgBox.setButtonText(QMessageBox::Cancel,"取消");
    msgBox.setWindowFlags(Qt::FramelessWindowHint);//隐藏关闭按钮msgBox.setStyleSheet("background-color:white");//设置背景色msgBox.setIconPixmap(QPixmap(":/ico/ppt"));//设置图标
    msgBox.setStyleSheet("background-color: qlineargradient(x1: 0, y1: 1, x2: 0, y2: 0,stop: 0 rgba(255, 255, 255, 100%),stop: 1 rgba(10, 144, 255, 100%));");

    msgBox.move(830,578);
    msgBox.setFixedSize(900, 500);
    int ret = msgBox.exec();

    if ( ret == QMessageBox::Ok )
     {
          qDebug() << "Yes clicked";
          // 负压轻度
          QString pressSuctionValue = ui->pressSuctionValue->text();

          // 注射时间间隔
          QString injectionTimeValue = ui->injectionTimeValue->text();

          // 定量停顿时间
          QString rationPauseTimeValue = ui->rationPauseTimeValue->text();

          // 给药速度
          QString semiAutoSppedValue = ui->semiAutoSppedValue->text();

          qDebug() << "PressSetting save ok clicked Value" << pressSuctionValue << injectionTimeValue << rationPauseTimeValue << semiAutoSppedValue;
    }
     else if(ret == QMessageBox::Cancel)
     {
          qDebug() << "Cancel clicked  " ;
     }
}
