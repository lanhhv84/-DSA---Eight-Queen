#include "eightqueen.h"
#include "ui_eightqueen.h"
#include <QPicture>
#include <QLabel>
#include <thread>

EightQueen::EightQueen(QWidget *parent, int numQ, int delayT) :
    QMainWindow(parent),
    ui(new Ui::EightQueen)
{
    ui->setupUi(this);
    makeBoard(numQ);
    delayTime = delayT;



}
void EightQueen::printOneSolution()
{
    bool solve = false;
    ++solutionCount;
    solutionCountLabel->setText("Cách " + QString::number(solutionCount));
    solutionCountLabel->adjustSize();
    nextButton->setDisabled(true);
    if (track[0] == 0)
        solve = putQueen(0);
    else
    {
        board[boardSize - 1][track[boardSize - 1] - 1] = '-';
        if ((boardSize - 2 + track[boardSize - 1]) % 2 == 1)
            label[boardSize - 1][track[boardSize - 1] - 1].setStyleSheet("background-image: url(:/Icon/black.jpg);");
        else
            label[boardSize - 1][track[boardSize - 1] - 1].setStyleSheet("background-image: url(:/Icon/white.jpg);");
        solve = putQueen(boardSize - 1);
    }
    nextButton->setDisabled(false);
    if (!solve)
    {
        nextButton->setDisabled(true);
        solutionCountLabel->setText("Cách " + QString::number(solutionCount - 1));
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Hết cách");
        msg->adjustSize();
        msg->show();
    }
}
void EightQueen::generateBoard(int size)
{
    boardSize = size;
    board = new char*[boardSize];
    for (int i = 0; i < boardSize; ++i)
        board[i] = new char[boardSize];
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardSize; ++j)
            board[i][j] = '-';
    track = new int[boardSize];
    for (int i = 0; i < boardSize; ++i)
        track[i] = 0;

}
bool EightQueen::isSafe(int row, int col)
{
    for (int i = 0; i < boardSize; ++i)
    {
        // Check column
        if (i != col)
            if (board[row][i] == '*')
                return false;
        // Check row
        if (i != row)
            if (board[i][col] == '*')
                return false;
        // Check hori
        for (int j = 0; j < boardSize; ++j)
        {
            if (i != col && j != row)
            {
                if ((i + j) == (col + row) || (i - j) == (col - row))
                    if (board[j][i] == '*')
                        return false;
            }
        }
    }
    return true;
}
bool EightQueen::putQueen(int row)
{
    bool found = false;		// Flag variable, if put queen in row "row" successful, this will be assigned to true
    int flag = -1;			// Index of column will put queen
    for (int i = track[row]; i < boardSize; ++i)	// Traverse all column of row "row"
    {
        if (isSafe(row, i))		// If can put queen in board[row][i]
        {
            found = true;		// Assigned flag to true
            flag = i;			// Store position to put queen
            track[row] = i + 1;		// Track
            break;
        }
    }

    if (found)
    {
        board[row][flag] = '*';
        ++moveCount;
        delay();
        moveCountLabel->setText("Tổng số lần duy chuyển: " + QString::number(moveCount));
        moveCountLabel->adjustSize();
        label[row][flag].setStyleSheet("background-image: url(:/Icon/queen2.jpg);");
        if (row < boardSize - 1)
            return putQueen(row + 1);
        else if ( row == boardSize - 1)
            return true;
    }
    else
    {
        if (row == 0)
            return false;
        delay();
        ++moveCount;
        moveCountLabel->setText("Tổng số lần duy chuyển: " + QString::number(moveCount));
        ++backTrackCount;
        backTrackLabel->setText("Số lần quay lui: " + QString::number(backTrackCount));
        moveCountLabel->adjustSize();
        if ((row - 2 + track[row - 1]) % 2 == 1)
            label[row - 1][track[row - 1] - 1].setStyleSheet("background-image: url(:/Icon/black.jpg);");
        else
            label[row - 1][track[row - 1] - 1].setStyleSheet("background-image: url(:/Icon/white.jpg);");
        board[row - 1][track[row - 1] - 1] = '-';

        track[row] = 0;
        return putQueen(row - 1);
    }
}
void EightQueen::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(delayTime);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void EightQueen::makeBoard(int num)
{
    nextButton = new QPushButton("Cách tiếp theo", this);
    int size = num;
    label = new QLabel*[size];
    this->resize(300+size*70, 150+size*70);
    for (int i = 0 ; i  < size ; ++i)
        label[i] = new QLabel[size];

    for (int i = 0 ; i < size ; ++i)
    {
        for (int j = 0 ; j < size ; ++j)
        {

            label[i][j].move(70+j*70,30+i*70);
            label[i][j].setText("");
            if (((i+j) %2) == 1)
            {
                label[i][j].setStyleSheet("background-image: url(:/Icon/black.jpg);");
            }
            else
            {
                label[i][j].setStyleSheet("background-image: url(:/Icon/white.jpg);");
            }
            label[i][j].setParent(this);
            label[i][j].setText("");
            label[i][j].show();
            label[i][j].setScaledContents( true );
            label[i][j].setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
            label[i][j].resize(70,70);

        }
    }
    nextButton->resize(80,20);
    nextButton->move(130 + size*70, 80 + 35*size);

    backTrackLabel = new QLabel("Số lần quay lui: 0", this);
    backTrackLabel->move(120 + size*70, 10 + 35*size );

    moveCountLabel = new QLabel("Tổng số lần duy chuyển: 0", this);
    moveCountLabel->adjustSize();
    moveCountLabel->move(120 + size*70, 35 + 35*size );

    solutionCountLabel = new QLabel("Cách 0", this);
    solutionCountLabel->adjustSize();
    solutionCountLabel->move(120 + size*70, 50 + 35*size );


    connect(nextButton,&QPushButton::clicked, [=]{printOneSolution();});
    generateBoard(size);

}

EightQueen::~EightQueen()
{
    delete ui;
}
