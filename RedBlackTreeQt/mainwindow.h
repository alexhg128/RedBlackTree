#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <redblacktreeqt.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QRedBlackTree<int>* tree = new QRedBlackTree<int>();
    Ui::MainWindow *ui;

private slots:
    void insert();
    void remove();
    void print();
};

#endif // MAINWINDOW_H
