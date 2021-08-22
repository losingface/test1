#include "elsesetting.h"
#include "ui_elsesetting.h"

#include <QString>
#include <QDebug>

#include <QDateTime>
#include <QThread>
#include <QTimer>

ElseSetting::ElseSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ElseSetting)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    //QThread *thread = new QThread();
    //timer->moveToThread(thread);
    //thread->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimerUpdate()));
   // timer->start(1000);

    ui->frame->setStyleSheet("background-color: rgb(171, 171, 171);border:none;border-radius:10px;");
    ui->frame_2->setStyleSheet("background-color: rgb(145, 145, 145);border:none;border-radius:10px;");

    // 保存按钮
    ui->save->setText("保存");
    ui->save->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(219, 71, 0);color:white");
    ui->save->setFont(QFont("微软雅黑", 12));

    ui->label->setText("时间设置");
    ui->label->setFont(QFont("微软雅黑", 14));
    //ui->label->setAlignment(Qt::AlignCenter);

    ui->yearLabel->setText("年");
    ui->yearLabel->setFont(QFont("微软雅黑", 14));
    ui->yearLabel->setAlignment(Qt::AlignCenter);

    ui->hourLabel->setText("时");
    ui->hourLabel->setFont(QFont("微软雅黑", 14));
    ui->hourLabel->setAlignment(Qt::AlignCenter);

    ui->monthLabel->setText("月");
    ui->monthLabel->setFont(QFont("微软雅黑", 14));
    ui->monthLabel->setAlignment(Qt::AlignCenter);

    ui->minLabel->setText("分");
    ui->minLabel->setFont(QFont("微软雅黑", 14));
    ui->minLabel->setAlignment(Qt::AlignCenter);

    ui->dayLabel->setText("日");
    ui->dayLabel->setFont(QFont("微软雅黑", 14));
    ui->dayLabel->setAlignment(Qt::AlignCenter);

    ui->secondLabel->setText("秒");
    ui->secondLabel->setFont(QFont("微软雅黑", 14));
    ui->secondLabel->setAlignment(Qt::AlignCenter);

   // ui->yearEdit->setText("时");
    ui->yearEdit->setFont(QFont("微软雅黑", 14));
    ui->yearEdit->setAlignment(Qt::AlignCenter);

    ui->hourEdit->setFont(QFont("微软雅黑", 14));
    ui->hourEdit->setAlignment(Qt::AlignCenter);

    ui->monthEdit->setFont(QFont("微软雅黑", 14));
    ui->monthEdit->setAlignment(Qt::AlignCenter);

    ui->minEdit->setFont(QFont("微软雅黑", 14));
    ui->minEdit->setAlignment(Qt::AlignCenter);

    ui->dayEdit->setFont(QFont("微软雅黑", 14));
    ui->dayEdit->setAlignment(Qt::AlignCenter);

    ui->secondEdit->setFont(QFont("微软雅黑", 14));
    ui->secondEdit->setAlignment(Qt::AlignCenter);
}

ElseSetting::~ElseSetting()
{
    delete ui;
}

void ElseSetting::init()
{
    setTimer();
}

void ElseSetting::setTimer()
{
    QDateTime time = QDateTime::currentDateTime();
    QString year = time.toString("yyyy");
    QString month = time.toString("MM");
    QString day = time.toString("dd");
    QString hour = time.toString("hh");
    QString min = time.toString("mm");
    QString second = time.toString("ss");

    ui->yearEdit->setText(year);
    ui->hourEdit->setText(hour);
    ui->monthEdit->setText(month);
    ui->minEdit->setText(min);
    ui->dayEdit->setText(day);
    ui->secondEdit->setText(second);
}

void ElseSetting::onTimerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString year = time.toString("yyyy");
    QString month = time.toString("MM");
    QString day = time.toString("dd");
    QString hour = time.toString("hh");
    QString min = time.toString("mm");
    QString second = time.toString("ss");

    ui->yearEdit->setText(year);
    ui->hourEdit->setText(hour);
    ui->monthEdit->setText(month);
    ui->minEdit->setText(min);
    ui->dayEdit->setText(day);
    ui->secondEdit->setText(second);
  //  ui->yearLabel->setText()

     qDebug() << " year year " << year << month << day << hour << min << second;
   // ui->labelDate->setText(str);
}

// 保存按钮槽函数
void ElseSetting::on_save_clicked()
{

}
