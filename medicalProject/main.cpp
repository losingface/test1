#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 编码格式支持命令行录入
    const char* codecName = "System";

    #ifndef Q_OS_LINUX
    codecName = "System";
    #else
    codecName = "GBK";
    #endif


    // 设置编码格式，可支持特殊字符显示
    QTextCodec *codec = NULL;
    codec = QTextCodec::codecForName(codecName);
    if (NULL == codec)
    {
        qDebug() << "-IPU- main() - codec is null, new by system or gb2312" ;

        #ifndef Q_OS_LINUX
        codecName = "System";
        #elif defined (Q_OS_LINUX)
        codecName = "GBK";
        #endif

        codec = QTextCodec::codecForName(codecName);
    }
    QTextCodec::setCodecForLocale(codec);
  //  QTextCodec::setCodecForCStrings(codec);
   // QTextCodec::setCodecForTr(codec);

    Widget w;
    w.show();

    return a.exec();
}
