#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <qevent.h>

#include <opencv.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent( QTimerEvent *event ); // 計時器事件處理函式
    int tIdCap;  // 計時器編號

private slots:
    bool eventFilter(QObject *obj,QEvent *event);//事件偵測(滑鼠)

    void on_btnLoad_clicked();
    void on_btnStart_clicked();
    void on_btnBlur_clicked();
    void on_btnSave_clicked();

private:
    void ShowFrame(cv::Mat imgS, QLabel *imgT);

    Ui::MainWindow *ui;

    QString fileName;
    Mat imgSrc;
    Mat imgFrame;
    VideoCapture cap;
};

#endif // MAINWINDOW_H
