#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_elementTree->setValidator(new QRegExpValidator( QRegExp( "(-{0,1}\\d{1,5}[ ])+" ) ));
    ui->textEdit->setReadOnly(true);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_action_newTree_triggered()
{
    on_pushButton_newTree_clicked();
}

void MainWindow::on_action_triggered()
{
    QApplication::quit();
}

template <typename T>
void print_tree(treeNode<T> *n, int pos, QTextEdit *tE)
{
    if (n == nullptr)
    {
        for (int i = 0; i < pos; ++i)
             tE->setText(tE->toPlainText() + "      ");
        tE->setText(tE->toPlainText() + "#\n");
        return;
    }

    print_tree(n->left(), pos + 1, tE);

    for (int i = 0; i < pos; i++)
        tE->setText(tE->toPlainText() + "      ");
    tE->setText(tE->toPlainText() + QString::number(n->data) + "\n");

    print_tree(n->right(), pos + 1, tE);
}

void MainWindow::on_pushButton_newTree_clicked()
{
    if(ui->lineEdit_elementTree->text() != "")
    {
        ui->lineEdit_elementTree->setStyleSheet("border: 1px solid rgb(0, 170, 255)");
        QStringList sl = ui->lineEdit_elementTree->text().split(" ");

        tree = new binSTree<int>(sl[0].toInt());
        for(auto i = 1; i < sl.length(); ++i)
        {
            tree->Insert(sl[i].toInt());
        }

       ui->textEdit->setText("");
       print_tree(tree->getRoot(), 0, ui->textEdit);
    }
    else
    {
        ui->lineEdit_elementTree->setStyleSheet("border: 1px solid red");
    }
}

void MainWindow::on_pushButton_delTree_clicked()
{
    tree->ClearList();
    ui->lineEdit_elementTree->setText("");
    ui->textEdit->setText("");
}

void MainWindow::on_action_delTree_triggered()
{
    on_pushButton_delTree_clicked();
}


void MainWindow::on_action_save_triggered()
{

}
