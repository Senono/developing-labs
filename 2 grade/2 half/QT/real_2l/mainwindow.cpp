#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QPainter>
#include <ctime>
#include <qmath.h>
#include <QLineF>

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

QString file_open;
QString file_save;
QColor color;

QString status;

void drawFig(QString path, QString pathSave, QColor clr) {
    QImage img;
    img.load(path);
    QPainter painter;

    if (!painter.begin(&img)) status = "Изображение не загружено. ";
    else status = "Картинка успешно загружена. ";

    painter.setPen(QPen(clr, 3));

    for (int i = 0; i < 3; i++) {
        int x0 = rand() % img.width();
        int y0 = rand() % img.height();
        int x1 = rand() % img.width();
        int y1 = rand() % img.height();

        int c = sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
        int b, a;

        int angleA, angleB, angleC;

        do {
            angleA = rand() % 180;
            angleB = rand() % 180;
        } while (angleA + angleB > 179);
        angleC = 180 - angleA - angleB;

        b = (c * sin(angleB))/sin(angleC);
        a = (c*sin(angleA))/sin(angleC);

        QLineF triangle;
        triangle.setP1(QPointF(x0,y0));
        triangle.setP2(QPointF(x1,y1));
        painter.drawLine(triangle);
        QLineF triangle2;
        triangle2.setP1(QPointF(triangle.x1(), triangle.y1()));
        triangle2.setAngle(angleB);
        triangle2.setLength(b);
        painter.drawLine(triangle2);
        QLineF triangle3;
        triangle3.setP1(QPointF(x1,y1));
        triangle3.setP2(QPointF(triangle2.x2(), triangle2.y2()));
        painter.drawLine(triangle3);
    }


    painter.end();
    if(img.save(pathSave)) status.append("Картинка успешно сохранена");
    else status.append("Картинка не сохранена");

}

void MainWindow::on_pushButton_2_clicked() // Открытие
{
    file_open = QFileDialog::getOpenFileName(this, "Выберите изображение", QDir::currentPath(), "*.jpg *.png *.jpeg");
}

void MainWindow::on_pushButton_3_clicked() // Цвет
{
    color = QColorDialog::getColor();
}

void MainWindow::on_pushButton_clicked() // Сохранение
{
    file_save = QFileDialog::getSaveFileName(this, "Выберите место для сохранения", QDir::currentPath(), "*.jpg *.png *.jpeg");
    drawFig(file_open, file_save, color);
    ui->label->setText(status);
}
