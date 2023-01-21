#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>
#include <QString>

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
    double start = -10.0;
    double end = 10.0;
    double step = 0.01;

    QString s1 = ui->lineEdit->text();
    QString s2 = ui->lineEdit_2->text();
    int k = s1.toInt();
    int b = s2.toInt();

    int N=(end-start)/step + 1;

    QVector<double> x(N), y(N);

    int i=0;
    for (double X=start; X<=end; X+=step)
    {
        if (k < 0.001 && k > -0.001) continue;
        x[i] = X;
        double tmp = (double) 1/k;
        if (X < -b && k % 2 != 0) y[i] = (-1) * qPow(qAbs(X + b), tmp);
        else if (X < -b && X + step > -b) y[i] = 0;
        else y[i] = qPow(X + b, tmp); // Функция
        i++;
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    double minY = -10, maxY = 10;
    ui->widget->xAxis->setRange(start, end); //Для оси Ox
    ui->widget->yAxis->setRange(minY, maxY); //Для оси Oy

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->replot();
}
