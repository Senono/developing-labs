#include <iostream>
#include <Windows.h>
#include <cctype>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	char disk; // "A" - "Z"
	WCHAR d[4];

	WCHAR Name[100];
	WCHAR NameFileSystem[100];

	UINT disk_type;

	DWORD SerialNumber;
	DWORD TypeFileSystem;
	DWORD SizeTom;
	__int64 ByteAvailable, ByteMax, ByteFree;

	do {
		cout << "Введите желаемый диск: ";
		cin >> disk;
		if (disk > 96 && disk < 123) disk = toupper(disk);
	} while (disk > 90 || disk < 65);
	
	cout << "Введенный диск: " << disk << endl;

	DWORD mask = GetLogicalDrives();
	int index = disk - 'A';
	int bit = (mask >> index) & 1;

	if (!bit) {
		cout << "Запрашиваемый диск не существует" << endl;
	}
	else {
		d[0] = disk; d[1] = ':'; d[2] = '\\'; d[3] = '\0';
		disk_type = GetDriveType(d);
		
		switch (disk_type)
		{
		case DRIVE_UNKNOWN:
			cout << "Не известный тип диска" << endl;
			break;
		case DRIVE_NO_ROOT_DIR:
			cout << "Не правильный путь диска" << endl;
			break;
		case DRIVE_REMOVABLE:
			cout << "Съёмный диск" << endl;
			break;
		case DRIVE_FIXED:
			cout << "Фиксированный диск" << endl;
			break;
		case DRIVE_REMOTE:
			cout << "Удалённый диск" << endl;
			break;
		case DRIVE_CDROM:
			cout << "CD-ROM disk" << endl;
			break;
		case DRIVE_RAMDISK:
			cout << "RAM disk" << endl;
			break;
		default:
			cout << "Ошибка определения диска" << endl;
			break;
		}

		if (GetVolumeInformation(d, Name, 100, &SerialNumber, &SizeTom, &TypeFileSystem, NameFileSystem, 100))
		{
			wcout << Name << endl;
			wcout << NameFileSystem << endl;
			wcout << SerialNumber << endl;
		}
		else {
			cout << "Error" << endl;
		}

		if (GetDiskFreeSpaceEx(d, (PULARGE_INTEGER)&ByteAvailable, (PULARGE_INTEGER)&ByteMax, (PULARGE_INTEGER)&ByteFree)) {
			wcout << L"Доступно для использования: " <<ByteAvailable / 1024 / 1024 / 1024 << L"ГБ" << endl;
			wcout << L"Максимальный объём диска: " << ByteMax / 1024 / 1024 / 1024 << L"ГБ" << endl;
			wcout << L"Свободно на диске: " << ByteFree / 1024 / 1024 / 1024 << L"ГБ" << endl;
		}
		else {
			cout << "Error" << endl;
		}

	}
}


