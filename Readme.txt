Hướng dẫn biên dịch
Cách 1: Mở file EightQueen.pro bằng Qt Creator ( Hỗ trợ Qt framework 5.9 trở lên) và biên dịch trực tiếp bằng chương trình
Cách 2: Sử dụng MXE trên Linux cho Windows ( Xuất file .exe)
- Tải về: git clone https://github.com/mxe/mxe.git
- Cài đặt build dependencies: http://mxe.cc/#requirements
- Biên dịch Qt5 cho Windows: cd mxe && make qtbase
- Chuyển thư mục hiện hành trên terminal đến thư mục chứa mã nguồn chương trình
- Chạy Qt makefile: <mxe root>/usr/bin/i686-w64-mingw32.static-qmake-qt5
- Biên dịch chương trình: make
