#ifndef EIGHTQUEEN_H
#define EIGHTQUEEN_H

#include <QMainWindow>
#include <QLabel>
#include <iostream>
#include <QPushButton>
#include <QLineEdit>
#include <QTime>
#include <stack>
#include <QMessageBox>
#include <chrono>

namespace Ui {
class EightQueen;
}

class EightQueen : public QMainWindow
{
    Q_OBJECT

public:
    explicit EightQueen(QWidget *parent = 0, int numQ = 4, int delayT = 300);
    ~EightQueen();
    void generateBoard(int);
    bool isSafe(int row, int col);
    bool putQueen(int row);
    void delay();
    void makeBoard(int num);
public slots:
    void printOneSolution();
private:
    Ui::EightQueen *ui;
    QLabel** label;
    char** board = nullptr;
    int* track = nullptr;
    int boardSize = 0;
    QLabel* moveCountLabel = nullptr;
    int moveCount =0;
    int backTrackCount = 0;
    int solutionCount = 0;
    QLabel* solutionCountLabel = nullptr;
    int delayTime = 0;
    QLabel* backTrackLabel = nullptr;
    QPushButton* nextButton;
};

#endif // EIGHTQUEEN_H
