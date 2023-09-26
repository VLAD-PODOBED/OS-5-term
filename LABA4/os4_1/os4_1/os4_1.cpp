#include <iostream>
#include <windows.h>
#include <process.h>

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 10000; i++) {
        Sleep(1000);
        std::cout << "PID = " << pid << "\tTID = " << tid << "\n";
    }
}