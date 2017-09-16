#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked,[=]{startEightQueen();});

}
void MainWindow::startEightQueen()
{
    int numQueen = ui->numQueenEdit->text().toInt();
    int delay = ui->delayTimeEdit->text().toInt();
    bool err = false;
    if (numQueen > 10 || numQueen <4 )
    {
        err =true;
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Số quân hậu phải thuôc [4, 10]]");
        msg->show();
    }
    if (delay < 0 || delay >2000)
    {
        err = true;
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Thời gian trễ thuôc [0, 2000]]");
        msg->show();
    }
    if (!err)
    {
        EightQueen* e = new EightQueen(nullptr,numQueen,delay);
        e->show();
        this->close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
