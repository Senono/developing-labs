#include <windows.h>
#include <process.h>
#include <iostream>

using namespace std;

DWORD dwCounter = 0;
int Inumber = 100, THREADS = 30;
HANDLE hStdOut;

CRITICAL_SECTION cs;

void Thread2(void* pParams) {
    EnterCriticalSection(&cs);
    cout << "2 thr " << endl;
}
void Thread(void* pParams) {
    InitializeCriticalSection(&cs);
    EnterCriticalSection(&cs);
    _beginthread(Thread2, 0, NULL);
    cout << "1 thr " << endl;
    LeaveCriticalSection(&cs);
}


int main() {
    for (int i = 0; i < 90; i++) {
        Sleep(100);
        _beginthread(Thread, 0, NULL);
    }

    cout << endl << "===========================================================================" << endl;
}