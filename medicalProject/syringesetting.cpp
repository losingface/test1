#include "syringesetting.h"
#include "ui_syringesetting.h"

#include <QImage>
#include <QIcon>
#include <QSize>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QMessageBox>


SyringeSetting::SyringeSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SyringeSetting)
{
    ui->setupUi(this);
    setStyleSheet("background-color: rgb(171, 171, 171)");

    QIcon btn_icon;

    // 注射规格
   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->injectionSizeLeft->setIcon(btn_icon);
    ui->injectionSizeLeft->setIconSize(QSize(60, 60));
    ui->injectionSizeLeft->setStyleSheet("border:none");

   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->injectionSizeRight->setIcon(btn_icon);
    ui->injectionSizeRight->setIconSize(QSize(60, 60));
    ui->injectionSizeRight->setStyleSheet("border:none");

    ui->injectionSize->setText("注射规格");
    ui->injectionSize->setFont(QFont("微软雅黑", 14));
    ui->injectionSize->setAlignment(Qt::AlignCenter);

    ui->injectionSizeValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->injectionSizeValue->setText("1ml/1ml");
    ui->injectionSizeValue->setFont(QFont("微软雅黑", 20));
    ui->injectionSizeValue->setAlignment(Qt::AlignCenter);

    // 给药次数
   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->doseTimeLeft->setIcon(btn_icon);
    ui->doseTimeLeft->setIconSize(QSize(60, 60));
    ui->doseTimeLeft->setStyleSheet("border:none");

    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->doseTimeRight->setIcon(btn_icon);
    ui->doseTimeRight->setIconSize(QSize(60, 60));
    ui->doseTimeRight->setStyleSheet("border:none");

    ui->doseTime->setText("给药次数");
    ui->doseTime->setFont(QFont("微软雅黑", 14));
    ui->doseTime->setAlignment(Qt::AlignCenter);

    ui->doseTimeValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->doseTimeValue->setText("10");
    ui->doseTimeValue->setFont(QFont("微软雅黑", 20));
    ui->doseTimeValue->setAlignment(Qt::AlignCenter);

    // 治疗模式
    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->cureModelLeft->setIcon(btn_icon);
    ui->cureModelLeft->setIconSize(QSize(60, 60));
    ui->cureModelLeft->setStyleSheet("border:none");

    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->cureModelRight->setIcon(btn_icon);
    ui->cureModelRight->setIconSize(QSize(60, 60));
    ui->cureModelRight->setStyleSheet("border:none");

    ui->cureModel->setText("治疗模式");
    ui->cureModel->setFont(QFont("微软雅黑", 14));
    ui->cureModel->setAlignment(Qt::AlignCenter);

    ui->cureModelValue->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(57, 46, 71);color:white");
    ui->cureModelValue->setText("10");
    ui->cureModelValue->setFont(QFont("微软雅黑", 20));
    ui->cureModelValue->setAlignment(Qt::AlignCenter);

    // 保存按钮
    ui->save->setText("保存");
    ui->save->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(219, 71, 0);color:white");
    ui->save->setFont(QFont("微软雅黑", 12));
}

SyringeSetting::~SyringeSetting()
{
    delete ui;
}

// 保存按钮槽函数
void SyringeSetting::on_save_clicked()
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

    msgBox.move(855,578);
    msgBox.setFixedSize(900, 500);
    int ret = msgBox.exec();

    if ( ret == QMessageBox::Ok )
     {
          qDebug() << "Yes clicked";
          // 注射规格
          QString injectionSizeValue = ui->injectionSizeValue->text();

          // 给药次数
          QString doseTimeValue = ui->doseTimeValue->text();

          // 治疗模式
          QString cureModelValue = ui->cureModelValue->text();

          qDebug() << "Yes clicked Value" << injectionSizeValue << doseTimeValue << doseTimeValue;
    }
     else if(ret == QMessageBox::Cancel)
     {
          qDebug() << "Cancel clicked  " ;
     }

}
