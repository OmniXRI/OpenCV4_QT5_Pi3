#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    qApp->installEventFilter(this);

    tIdCap = 0;  // 計時器編號

    ui->pbxS->setScaledContents(true); // 影像自動縮放至QLabel尺寸
}

MainWindow::~MainWindow()
{
    if ( tIdCap != 0 )
        killTimer(tIdCap);

    delete ui;
}

// 計時器事件處理函式
void MainWindow::timerEvent( QTimerEvent *event )
{
    cap >> imgFrame;  // 從攝像頭取入一張影像

    if(imgFrame.empty()){  // 若取不到影像則結束程式
        QMessageBox::about(NULL, "Error", "No Camera!");
        killTimer(tIdCap); // 刪除計時器
        return;
    }

    ShowFrame(imgFrame, ui->pbxS);  // 顯示cv::Mat到QLabel(等同picture box)上
}

// 事件過濾器
bool MainWindow::eventFilter(QObject *obj, QEvent* event)
{
  QString str;
  QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event); // 建立滑鼠事件
  QPoint pt = mouseEvent->pos();  // 記錄滑鼠座標

  // 取得之滑鼠座標為原始座標，非讀入圖之座標，因為圖讀入時會強迫縮放到QLabel尺寸
  if (obj==ui->pbxS && event->type() == QEvent::MouseMove)  // 若滑鼠在圖像上移動
  {
       str = "Pos : (" + QString::number(pt.x()) +", " + QString::number(pt.y()) + ")";
       ui->labMousePos->setText(str);                  // 顯示座標
  }else if(obj==ui->pbxS && event->type() == QEvent::MouseButtonPress){ // 若滑鼠在圖上按下
       str = "Press : (" + QString::number(pt.x()) +", " + QString::number(pt.y()) +")";
       ui->labMousePos->setText(str);                  // 顯示座標
  }else if(obj==ui->pbxS && event->type() == QEvent::MouseButtonRelease){ // 若滑鼠在圖上放開
      str = "Release : (" + QString::number(pt.x()) +", " + QString::number(pt.y()) +")";
      ui->labMousePos->setText(str);                  // 顯示座標
 }

  return false;
}

// 顯示cv::Mat到QLabel(等同picture box)上
void MainWindow::ShowFrame(cv::Mat imgS, QLabel *imgT)
{
    Mat imgC;

    cvtColor(imgS,imgC,cv::COLOR_BGR2RGB);  // 把影像色彩格式從BGR888轉成RGB888

    QImage tmp(imgC.data, imgC.cols, imgC.rows, imgC.step,
               QImage::Format_RGB888);  // 從cv::Mat格式轉換成QImage格式

    imgT->setPixmap(QPixmap::fromImage(tmp));  // 顯示影像到QLabel
}

// [Load...] 載入圖像按鍵處理函式
void MainWindow::on_btnLoad_clicked()
{
    // 打開QT開啟檔案對話盒並取得檔案名稱
    fileName = QFileDialog::getOpenFileName(this,tr("Open File"));
    QWidget::setWindowTitle (fileName);

    // 將QT String格式轉成標準字串並讀入檔案到指定cv::Mat
    imgSrc = cv::imread(fileName.toStdString(),IMREAD_COLOR);

     //Check if the mat gets the image data.
     if(!imgSrc.empty()) {
         ShowFrame(imgSrc, ui->pbxS);  // 顯示imgSrc到pbxS上
     }
     else{  // 若取不到影像則結束程式
         QMessageBox::about(NULL, "Error", "File not exist!");
         killTimer(tIdCap);   // 刪除計時器
         return;
     }
}

// [Start] 啟動及結束連續取像按鍵處理函式
void MainWindow::on_btnStart_clicked()
{
    if(cap.isOpened())  // 若攝像頭已開啟，則先釋放掉再重新設定
        cap.release();

    if(ui->btnStart->text().compare(QString("Start")) == 0){ // 若按鍵顯示[Start]
        cap = VideoCapture(0);  // 建立VideoCapture, /dev/video0

        if(!cap.isOpened()){  // 若開啟失敗則結束
            QMessageBox::about(NULL, "Error", "Can not find camera!");
        }
        else{  // 若開啟成功
            cap.set(CAP_PROP_FRAME_WIDTH, 640);  // 設定取像寬度
            cap.set(CAP_PROP_FRAME_HEIGHT, 480); // 設定取像高度
            tIdCap = startTimer(33);  // 設定取像間隔時間(計時器事件)為33ms(30FPS)
            ui->btnStart->setText("Stop");  // 設定按鍵文字變成[Stop]
        }
    }
    else{   // 若按鍵顯示[Stop]
        killTimer(tIdCap);  // 刪除計時器
        tIdCap = 0;  // 刪除計時器編號
        ui->btnStart->setText("Start");  // 設定按鍵文字變成[Start]
        if(!imgFrame.empty()){
            imgFrame.copyTo(imgSrc); // 將攝像頭影像複製到影像來源
            ShowFrame(imgSrc, ui->pbxS);  // 顯示imgSrc到pbxS上
        }
    }
}

// [Blur] 模糊影像按鍵處理函式
void MainWindow::on_btnBlur_clicked()
{
   blur(imgSrc,imgSrc,Size(9,9)); // 以9x9遮罩進行影像模糊化
   ShowFrame(imgSrc, ui->pbxS);  // 顯示imgSrc到pbxS上
}

// [Save...] 儲存影像按鍵處理函式
void MainWindow::on_btnSave_clicked()
{
    if(!imgSrc.empty()){
        imwrite("./test.png",imgSrc); // 將cv::Mat影像寫入指定檔案中(bmp, jpg, png...格式皆可)
        QMessageBox::about(NULL, "Save", "File Save OK!");
    }
    else{
        QMessageBox::about(NULL, "Error", "Image is empty!");
    }
}

