#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;      // 創造一個主窗口物件

//    w.resize(800,480); // 窗口尺寸
//    w.move(0,-10);     // 窗口移動到距螢幕左上角(x,y)處
//    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // 無邊框視窗
//    int windowXPos = w.x(); // 取得窗口左上角x座標
//    int windowYPos = w.y(); // 取得窗口左上角y座標
//    QRect windowGeometry = w.frameGeometry(); // 返回的QRect可得窗口長、寬、位置等資訊。
//    w.setWindowTitle(QObject::tr("第一個主視窗")); // 設定窗口標題

    w.show();          //在螢幕上秀出窗口

    return a.exec();
}
