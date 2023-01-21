#include <iostream>
#include <Windows.h>
using namespace std;

#define FILE_NAME_LENGTH 100
#define MAX_FILE_LENGTH 500
#define FILE_READ "ReadFile.txt"
#define FILE_WRITE "WriteFile.txt"

int main()
{
	setlocale(LC_ALL, "");

	char readFileName[FILE_NAME_LENGTH];
	char writeFileName[FILE_NAME_LENGTH];
	char buffer[MAX_FILE_LENGTH];
	long pointer; // Указатель на начальную точку

	BOOL isFileRead;
	BOOL isFileDelete;
	BOOL isFileWrite;

	HANDLE firstFile;
	HANDLE secondFile;
	int readBytes; // Прочтенные байты
	int writeBytes; // Записанные байты

	cout << "Введите название первого файла: ";
	cin >> readFileName;
	do {
		cout << "Введите номер символа для чтения: ";
		cin >> pointer;
	} while (pointer <= 0);

	cout << "Введите название второго файла: ";
	cin >> writeFileName;

	firstFile = CreateFile(TEXT(FILE_READ), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (firstFile == INVALID_HANDLE_VALUE) {
		cout << endl << "Ошибка №" << GetLastError();
		char *buf;
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR) &buf, 0, NULL);
		return -1;
	}
	else {
		cout << endl << "Success for first file ^_^";
	}

	SetFilePointer(firstFile, pointer, 0, FILE_BEGIN);
	isFileRead = ReadFile(firstFile, buffer, sizeof(buffer), (DWORD*)& readBytes, NULL);
	if (isFileRead == false) {
		cout << endl << "Невозможно прочитать файл. Ошибка №" << GetLastError();
		wchar_t buf[256];
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			buf, (sizeof(buf) / sizeof(wchar_t)), NULL);
		return -1;
	}
	else {
		cout << endl << "Файл успешно прочитан";
	}

	CloseHandle(firstFile);
	secondFile = CreateFile(TEXT(FILE_WRITE), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (secondFile == INVALID_HANDLE_VALUE) {
		cout << endl << "Ошибка №" << GetLastError();
		wchar_t buf[256];
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			buf, (sizeof(buf) / sizeof(wchar_t)), NULL);
		return -1;
	}
	else {
		cout << endl << "Success for second file ^_^";
	}

	isFileWrite = WriteFile(secondFile, buffer, (DWORD)readBytes, (PDWORD)& writeBytes, NULL);
	if (isFileWrite == false) {
		cout << endl << "Неудалось записать в файл. Ошибка №" << GetLastError();
		wchar_t buf[256];
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			buf, (sizeof(buf) / sizeof(wchar_t)), NULL);
		return -1;
	}
	else {
		cout << endl << "Запись во второй файл успешна";
	}

	CloseHandle(secondFile);
	isFileDelete = DeleteFileA(FILE_READ);

	if (isFileDelete == false) {
		cout << endl << "Не удалось удалить файл. Ошибка №" << GetLastError();
		return -1;
	}
	else {
		cout << endl << "Файл для чтения успешно удалён";



	}

	return 0;
}