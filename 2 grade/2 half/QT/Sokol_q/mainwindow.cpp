#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QString UserString = ui->textEdit->toPlainText();
    if (!StackObj->CalculateString(UserString.toUtf8().data()))
    {
        QMessageBox::critical(this, "Calculating error", "Error: this string couldn't be calculated");
    }
    else
    {
        QString Result = "Результат: " + QString::number(StackObj->GetLastElement());
        ui->Result->setText(UserString);
}
