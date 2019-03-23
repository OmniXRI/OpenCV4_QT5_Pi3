![image](https://raw.githubusercontent.com/OmniXRI/OpenCV4_QT5_Pi3/master/20190324_OpenCV4_QT5_Fig01.png)

本範例使用OpenCV 4.0.1, QT 5.7.1, QT Creator 4.2.0, 適用樹莓派 Pi 3A+ / 3B+。

完整填坑心得請參閱 <a href="https://omnixri.blogspot.com/2019/03/pi-3opencv-4-qt5.html" target="_blank">https://omnixri.blogspot.com/2019/03/pi-3opencv-4-qt5.html</a>

opencv_install.sh 為完整安裝程序，下載到樹莓派根目錄(/home/pi)後執行 ./opencv_install.sh 安裝過程需數小時，建議準備小風扇對著板子吹，以免CPU過熱造成速度變慢或當機。

\OpenCV4_Test 為完整QT專案檔及C++程式原碼，程式左半邊為一640x480的顯示窗，右側四個按鍵，分別為載入影像[Load...]、啟動及停止連續取像[Start/Stop]、影像模糊[Blue]及儲存影像[Save...]，更完整說明請參照程式內註解。
