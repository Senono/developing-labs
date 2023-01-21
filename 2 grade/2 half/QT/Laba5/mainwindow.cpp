#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

bool MainWindow::GetStringFromFile()
{
    QFile File;
    File.setFileName("File.txt");
    if (!File.open(QIODevice::ReadOnly))
        return false;
    else
    {
        char* String = new char[64];
        if (File.readLine(String, sizeof(char) * 64) <= 0)
        {
            File.close();
            return false;
        }
        else
        {
            ui->UserString->setText(QString::fromUtf8(String));
            return true;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_FileButton_clicked()
{
    if (!GetStringFromFile())
    {
        QMessageBox::critical(this, "File error", "Error: file couldn't be read");
    }
}

void MainWindow::on_CalculateButton_clicked()
{
    QString UserString = ui->UserString->text();

    if (!StackObj->CalculateString(UserString.toUtf8().data()))
    {
        QMessageBox::critical(this, "Calculating error", "Error: this string couldn't be calculated");
    }
    else
    {
        QString Result = "Результат: " + QString::number(StackObj->GetLastElement());
        ui->Result->setText(Result);
    }
}
