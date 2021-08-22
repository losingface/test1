#include "widget.h"
#include "ui_widget.h"

#include <QString>
#include <QDebug>
#include <QFont>
#include <QIcon>
#include <QPushButton>
#include <QSize>
#include <QDateTime>
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    //QThread *thread = new QThread();
    //timer->moveToThread(thread);
    //thread->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerUpdate()));
    timer->start(1000);

    // 主界面控件显示
    mainContentsUI = new MainContentsUI(this);

    // 448 273
    mainContentsUI->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    mainContentsUI->move(448,273);
    mainContentsUI->show();

    // 压力设置界面显示 495 372
    pressSettingUi = new PressSetting(this);
    pressSettingUi->move(495,272);
    pressSettingUi->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // 注射设置
    syringeSettingUi = new SyringeSetting(this);
    syringeSettingUi->move(495,272);
    syringeSettingUi->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // 其他设置
    elseSettingUi = new ElseSetting(this);
    elseSettingUi->move(495,272);
    elseSettingUi->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    connect(mainContentsUI, SIGNAL(pressSetting()), this, SLOT(onShowPressSetting()), Qt::QueuedConnection);
    connect(mainContentsUI, SIGNAL(syringeSetting()), this, SLOT(onShowSyringeSetting()), Qt::QueuedConnection);
    connect(mainContentsUI, SIGNAL(elseSetting()), this, SLOT(onShowElseSetting()), Qt::QueuedConnection);
   // connect(mainContentsUI)

    // 设置窗口大小
  //  this->setFixedSize(800,600);

    ui->horizontalSlider->setRange(0,130);
    ui->horizontalSlider->setValue(24);
    ui->horizontalSlider->setStyleSheet(
                "QSlider::groove:horizontal {\
                  border: 0px solid #bbb;\
                }\
                QSlider::sub-page:horizontal {\
                  background: rgb(185,92,0);\
                  border-radius: 1px;\
                  border-background: rgb(0,0,0);\
                  margin-top: 8px;\
                  margin-bottom: 9px;\
                }\
                QSlider::add-page:horizontal {\
                  background: rgb(0,0,0);\
                  border: 0px solid #777;\
                  border-radius: 2px;\
                  margin-top: 8px;\
                  margin-bottom: 9px;\
                }\
                QSlider::handle:horizontal {\
                  background: rgb(0,0,0);\
                  border: 1px solid rgba(102,102,102,102);\
                  width: 8px;\
                  height: 8px;\
                  border-radius: 5px;\
                  margin-top: 2px;\
                  margin-bottom: 2px;\
                }\
                QSlider::handle:horizontal:hover {\
                  background: rgb(0,0,0);\
                  border: 1px solid rgba(102,102,102,102);\
                  border-radius: 5px;\
                }\
                }"
              );

    ui->volume->setText("");
    QImage image;
   // image.load("C:/Users/yurui/Desktop/projectContent/volume.png");
    image.load(":/volume.png");
    ui->volume->setPixmap(QPixmap::fromImage(image));
    ui->volume->resize(QSize(image.width(),image.height()));


    ui->deviceFault->setText("设备故障");
    //ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->deviceFault->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(84, 66, 104);color:white");
    ui->deviceFault->setFont(QFont("微软雅黑", 12));

    ui->deviceName->setText("设备名称");
    //ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->deviceName->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(84, 66, 104);color:white");
    ui->deviceName->setFont(QFont("微软雅黑", 12));

    ui->labelDate->setStyleSheet("border-radius:3px;padding:2px 4px;background-color: rgb(84, 66, 104);color:white");
    ui->labelDate->setFont(QFont("微软雅黑", 12));
    ui->labelDate->setAlignment(Qt::AlignCenter);
       // qDebug() << "yutest main " << QThread::currentThreadId();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onTimerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    QString str2 = time.toString("hh:mm:ss");
    ui->labelDate->setText(str);
   // qDebug() << "yutest ontimeout " << QThread::currentThreadId();
}

// 显示压力设置界面
void Widget::onShowPressSetting()
{
    pressSettingUi->show();
}

// 显示注射器设置界面
void Widget::onShowSyringeSetting()
{
    syringeSettingUi->show();
}

// 显示其他设置界面
void Widget::onShowElseSetting()
{
    elseSettingUi->show();
    elseSettingUi->init();
}

// 回到主界面槽函数
void Widget::on_mainUI_clicked()
{
    // 显示主界面
    mainContentsUI->show();

    // 压力设置界面隐藏
    pressSettingUi->hide();

    // 注射设置界面隐藏
    syringeSettingUi->hide();

    elseSettingUi->hide();
}
