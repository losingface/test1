#include "maincontentsui.h"
#include "ui_maincontentsui.h"

#include <QDebug>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QFont>
#include <QIcon>
#include <QFrame>

MainContentsUI::MainContentsUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainContentsUI)
{
    ui->setupUi(this);
    //setStyleSheet("background-color: rgb(171, 171, 171)");
    ui->syringeSetting->setText("注射器设置");
    //ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->syringeSetting->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(84, 66, 104);color:white");
    ui->syringeSetting->setFont(QFont("微软雅黑", 14));

    ui->pressSetting->setText("压力设置");
    ui->pressSetting->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(84, 66, 104);color:white");
    ui->pressSetting->setFont(QFont("微软雅黑", 14));

    ui->otherSetting->setText("其他设置");
    ui->otherSetting->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(84, 66, 104);color:white");
    ui->otherSetting->setFont(QFont("微软雅黑", 14));

    ui->store1->setText("存储1");
    ui->store1->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store1->setFont(QFont("微软雅黑", 14));

    ui->store2->setText("存储2");
    ui->store2->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store2->setFont(QFont("微软雅黑", 14));

    ui->store3->setText("存储3");
    ui->store3->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store3->setFont(QFont("微软雅黑", 14));

    ui->store4->setText("存储4");
    ui->store4->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store4->setFont(QFont("微软雅黑", 14));

    ui->store5->setText("存储5");
    ui->store5->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store5->setFont(QFont("微软雅黑", 14));

    ui->store6->setText("存储6");
    ui->store6->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store6->setFont(QFont("微软雅黑", 14));

    ui->store7->setText("存储7");
    ui->store7->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store7->setFont(QFont("微软雅黑", 14));

    ui->store8->setText("存储8");
    ui->store8->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store8->setFont(QFont("微软雅黑", 14));

    ui->store9->setText("存储9");
    ui->store9->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store9->setFont(QFont("微软雅黑", 14));

    ui->store10->setText("存储10");
    ui->store10->setStyleSheet("border:4px solid white;border-radius:8px;padding:2px 4px;background-color: rgb(0, 0, 0);color:white;border-color: rgb(84, 66, 104);");
    ui->store10->setFont(QFont("微软雅黑", 14));

    ui->vacPrepare->setText("负压准备");
    ui->vacPrepare->setStyleSheet("border-radius:8px;padding:2px 4px;background-color: rgb(219, 71, 0);color:white");
    ui->vacPrepare->setFont(QFont("微软雅黑", 14));

    QIcon btn_icon;
   // btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/left-60.png");
    btn_icon.addFile(":/left-60.png");
    ui->mainUiLeft->setIcon(btn_icon);
    ui->mainUiLeft->setIconSize(QSize(60, 60));
    ui->mainUiLeft->setStyleSheet("border:none");

    //btn_icon.addFile("C:/Users/yurui/Desktop/projectContent/right-60.png");
    btn_icon.addFile(":/right-60.png");
    ui->mainUiRight->setIcon(btn_icon);
    ui->mainUiRight->setIconSize(QSize(60, 60));
    ui->mainUiRight->setStyleSheet("border:none");

    ui->frame->setStyleSheet("background-color: rgb(84, 66, 104);border:none;border-radius:10px;");
    ui->frame->installEventFilter(this);
  //  ui->frame->setStyleSheet("background-color: rgb(128, 128, 128);");
   // ui->frame->installEventFilter(this);


}

MainContentsUI::~MainContentsUI()
{
    delete ui;
}

void MainContentsUI::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //设置反锯齿
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::Qt4CompatiblePainting);
    painter.setPen(Qt::darkGray); //设置画笔颜色
   //画弦,该弦在QRect(10.0, 30.0, 80.0, 60.0)的内切椭圆上，并且起始角度为30(3点钟为0度，逆时针为正)，跨度为120

    // 给药量
    painter.drawChord(72, 20, 160, 160,30 * 16, -240 * 16);
    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawChord(72, 20, 160, 160,30 * 16, 120 * 16);

    QFont font("微软雅黑", 12);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(QPoint(118, 58),"给药量");

    QFont font2("微软雅黑", 20);
    painter.setFont(font2);
    painter.setPen(Qt::darkYellow);
    painter.drawText(QPoint(87, 125),"1ml/5ml");

    painter.setPen(Qt::darkGray); //设置画笔颜色
    painter.setBrush(QBrush(Qt::transparent));
    painter.drawChord(243, 20, 160, 160,30 * 16, -240 * 16);
    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawChord(243, 20, 160, 160,30 * 16, 120 * 16);

    // 给药次数
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(QPoint(285, 58),"给药次数");

    painter.setFont(font2);
    painter.setPen(Qt::darkYellow);
    painter.drawText(QPoint(267, 125),"120/20");

    painter.setPen(Qt::darkGray); //设置画笔颜色
    painter.setBrush(QBrush(Qt::transparent));
    painter.drawChord(423, 20, 160, 160,30 * 16, -240 * 16);
    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawChord(423, 20, 160, 160,30 * 16, 120 * 16);

    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(QPoint(460, 58),"给药速度");

    painter.setFont(font2);
    painter.setPen(Qt::darkYellow);
    painter.drawText(QPoint(480, 125),"50");

    // 负压强度
    painter.setPen(Qt::darkGray); //设置画笔颜色
    painter.setBrush(QBrush(Qt::transparent));
    painter.drawChord(603, 20, 160, 160,30 * 16, -240 * 16);
    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawChord(603, 20, 160, 160,30 * 16, 120 * 16);

    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(QPoint(642, 58),"负压强度");

    painter.setFont(font2);
    painter.setPen(Qt::darkYellow);
    painter.drawText(QPoint(665, 125),"50");


    // 治疗模式
    painter.setPen(Qt::darkGray); //设置画笔颜色
    painter.setBrush(QBrush(Qt::transparent));
    painter.drawChord(783, 20, 160, 160,30 * 16, -240 * 16);
    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawChord(783, 20, 160, 160,30 * 16, 120 * 16);

    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(QPoint(822, 58),"治疗模式");

    painter.setFont(font2);
    painter.setPen(Qt::darkYellow);
    painter.drawText(QPoint(845, 125),"50");


  //   painter.drawText(QPoint(50, 50),"xxxxxxx");

}

bool MainContentsUI::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->frame)
    {
        QPainter painter(ui->frame);
          //  ui->frame->setStyleSheet("background-color: rgb(84, 66, 104);border:none;border-radius:10px;");
        //设置反锯齿
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::Qt4CompatiblePainting);
        painter.setPen(Qt::darkGray); //设置画笔颜色

        // 手柄
        painter.setBrush(QBrush(Qt::darkYellow));
        painter.drawEllipse(105,0,135,135);
        painter.setBrush(QBrush(Qt::white));
        painter.drawEllipse(110,5,125,125);

        QFont font("微软雅黑", 16);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(QPoint(143, 60),"手柄");
        painter.drawText(QPoint(143, 90),"形状");
    }

    return QWidget::eventFilter(obj, e);
}

// 压力设置按钮
void MainContentsUI::on_pressSetting_clicked()
{

    emit pressSetting();
    this->hide();
}

// 注射设置按钮
void MainContentsUI::on_syringeSetting_clicked()
{
    qDebug() << "qqqqqqqqqqqqqqq";
    emit syringeSetting();
    this->hide();
}

// 其他设置按钮
void MainContentsUI::on_otherSetting_clicked()
{
    emit elseSetting();
    this->hide();
}
