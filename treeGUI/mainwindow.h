#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binSTree.h"


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
    void changeEvent(QEvent *e);

private slots:
    void on_action_newTree_triggered();
    void on_action_triggered();
    void on_action_aboute_triggered();

    void on_pushButton_newTree_clicked();

    void on_pushButton_delTree_clicked();

    void on_action_delTree_triggered();

    void on_action_save_triggered();

private:
    Ui::MainWindow *ui;

    binSTree<int> *tree;

};

#endif // MAINWINDOW_H
