#include <windows.h>
#include <winbase.h>
#include <iostream>
#include <conio.h>
using namespace std;


int main() {

    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    HANDLE Sthread;
    HANDLE Rthread;
    int a;
    DWORD S = CREATE_SUSPENDED;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(si);

    cout << "What is begin notepad(N) or calc(C)?";

    cin >> a;
    cout << a;

    if (a == 67 || a == 99) {
        BOOL res = CreateProcess(L"C:\Windows\System32\calc.exe", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi);


        if (!res) {
            cout << "ERROR: " << GetLastError() << endl;
            return -1;
        }

        cout << "ID - " << pi.dwProcessId << endl;

        for (bool t = 1; t == 1;) {

            cin >> a;

            if (a == 83 || a == 115) { cout << "S - "; SuspendThread(pi.hThread); }
            if (a == 83 || a == 115) {

            nRT:

                cin >> a;

                if (a == 84 || a == 116) {
                    cout << "T - ";
                    TerminateProcess(pi.hProcess, NO_ERROR);
                    t = 0;
                    break;
                }
                if (a == 82 || a == 114) { cout << "R - "; ResumeThread(pi.hThread); }
                else goto nRT;
            }
        }
    }

    if (CreateProcess(L"C:\Program Files (x86)\Notepad++", NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi) == TRUE) {
        cout << endl << "ID - " << pi.dwProcessId << endl;

        Sleep(10000);
        ResumeThread(pi.hThread);

        cout << GetThreadPriority(pi.hThread);
    }
}
