#include "QtGuiApplication.h"
#include <QMessageBox>

QtGuiApplication::QtGuiApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(returnPressed()), this, SLOT(Main()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Main()));
}

void QtGuiApplication::Main()
{
	QString Text = ui.textEdit->toPlainText();
	int Type_cryption = ui.comboBox->currentIndex(); //0=Caesar, 1=Atbash
	int Encryption = ui.checkBox->checkState();
	int Decryption = ui.checkBox_2->checkState();
	int Shift = ui.lineEdit->text().toInt();
	/*ui.textBrowser->setPlainText(Text + QString::number(Text.size()) + QString::number(Type_cryption) + QString::number(Encryption) +
		QString::number(Decryption) + QString::number(Shift));*/
	if ((Text != 0) && (Text.size() > 0) && (Type_cryption == 0) && (Shift > 0) && (Shift < 27) && (Encryption == 2) && (Decryption == 0))
		Output (Caesar_encryption(Text, Shift));
	else if ((Text != 0) && (Text.size() > 0) && (Type_cryption == 0) && (Shift > 0) && (Shift < 27) && (Encryption == 0) && (Decryption == 2))
		Output(Caesar_decryption(Text, Shift));
	else if ((Text != 0) && (Text.size() > 0) && (Type_cryption == 1) && (Encryption == 2) && (Decryption == 0))
		Output(Atbash_encryption(Text));
	else if ((Text != 0) && (Text.size() > 0) && (Type_cryption == 1) && (Encryption == 0) && (Decryption == 2))
		Output(Atbash_decryption(Text));
	else Error();
}

QString QtGuiApplication::Caesar_encryption(QString Text, int shift)
{
	string str = Text.toLocal8Bit().constData();
	for (int i = 0; i < Text.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = ('a' + (str[i] - 'a' + shift) % 26);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = ('A' + (str[i] - 'A' + shift) % 26);
		}
	}
	return QString::fromStdString(str);
}

QString QtGuiApplication::Caesar_decryption(QString Text, int shift)
{
	string str = Text.toLocal8Bit().constData();
	for (int i = 0; i < Text.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = ('z' - ('z' - str[i] + shift) % 26);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = ('Z' - ('Z' - str[i] + shift) % 26);
		}
	}
	return QString::fromStdString(str);
}

QString QtGuiApplication::Atbash_encryption(QString Text)
{
	string str = Text.toLocal8Bit().constData();
	for (int i = 0; i < Text.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - str[i] + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' - str[i] + 'A';
	}
	return QString::fromStdString(str);
}

QString QtGuiApplication::Atbash_decryption(QString Text)
{
	string str = Text.toLocal8Bit().constData();
	for (int i = 0; i < Text.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'a' - str[i] + 'z';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'A' - str[i] + 'Z';
	}
	return QString::fromStdString(str);
}

void QtGuiApplication::Output(QString Text)
{
	ui.textBrowser->setPlainText(Text);
}

void QtGuiApplication::Error()
{
	ui.textBrowser->setPlainText("");
	QMessageBox msgbox;
	msgbox.setWindowTitle("Error");
	msgbox.setText("Check the accuracy of the data entered!");
	msgbox.exec();
}