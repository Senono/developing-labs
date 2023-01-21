#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication.h"
#include <QString>
using namespace std;

class QtGuiApplication : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplicationClass ui;
public slots:
	void Main();
	QString Caesar_encryption(QString, int);
	QString Caesar_decryption(QString, int);
	QString Atbash_encryption(QString);
	QString Atbash_decryption(QString);
	void Output(QString);
	void Error();
};