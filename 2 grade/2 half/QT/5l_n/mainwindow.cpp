#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QTextBrowser>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str = ui->textEdit->toPlainText();
    int strSize = str.size();
    QString result = "";
    QString check = "";
    for (int i = 0; i < strSize; i++) {
        if (!check.contains(str[i], Qt::CaseInsensitive) && str[i] != " ") {
            QString tmp = "";
            check.append(str[i]);
            result.append(str[i] + " = ");
            int count = str.count(str[i]);
            tmp.setNum(count);
            result.append(tmp + "\n");
        }
    }
    ui->textBrowser->setText(result);
}
