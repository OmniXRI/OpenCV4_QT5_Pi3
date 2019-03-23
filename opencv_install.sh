sudo apt-get update 
sudo apt-get upgrade
sudo apt-get install -y build-essential cmake unzip pkg-config
sudo apt-get install -y libjpeg-dev libtiff-dev libjasper-dev libpng12-dev
sudo apt-get install -y libavcodec-dev libavformat-dev libswscale-dev libv4l-dev
sudo apt-get install -y libxvidcore-dev libx264-dev
sudo apt-get install -y libgtk-3-dev
sudo apt-get install -y libcanberra-gtk*
sudo apt-get install -y libatlas-base-dev gfortran
sudo apt-get install -y python3-dev python3-pip
sudo pip3 install numpy scipy
sudo apt-get install -y python-dev python-pip
sudo pip install numpy scipy
sudo apt-get install -y qt5-default
sudo apt-get install -y qtcreator
cd ~
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.0.1.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.0.1.zip
sudo unzip opencv.zip
sudo unzip opencv_contrib.zip
sudo mv opencv-4.0.1 opencv
sudo mv opencv_contrib-4.0.1 opencv_contrib
cd ~/opencv
sudo mkdir build
cd build
sudo cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
    -D ENABLE_NEON=ON \
    -D ENABLE_VFPV3=ON \
    -D WITH_FFMPEG=ON \
    -D BUILD_TESTS=OFF \
    -D WITH_QT=ON \
    -D OPENCV_ENABLE_NONFREE=ON \
    -D INSTALL_PYTHON_EXAMPLES=OFF \
    -D INSTALL_C_EXAMPLES=OFF \
    -D BUILD_EXAMPLES=OFF ..
sudo make -j4
sudo make install
sudo ldconfig
sudo apt-get update

