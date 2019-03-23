完整填坑心得請參閱 <a href="https://omnixri.blogspot.com/2019/03/pi-3opencv-4-qt5.html" target="_blank">https://omnixri.blogspot.com/2019/03/pi-3opencv-4-qt5.html</a>

[百度](http://www.baidu.com){:target="_blank"}

opencv_install.sh 為完整安裝程序，下載到樹莓派，切換到根目錄(cd /home/pi或cd ~)後執行 ./opencv_install.sh 安裝過程需數小時，建議準備小風扇對著板子吹，以免CPU過熱造成速度變慢或當機。

\OpenCV4_Test 為完整QT專案檔及C++程式原碼，程式左半邊為一640x480的顯示窗，右側四個按鍵，分別為載入影像[Load...]、啟動及停止連續取像[Start/Stop]、影像模糊[Blue]及儲存影像[Save...]，更完整說明請參照程式內註解。
