﻿#include <iostream>
#include <Windows.h>
#include <iostream>

DWORD WINAPI OS04_05_T1() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 50; i++) {
        Sleep(1000);
        std::cout << "\nPID = " << pid << "\tTID = " << tid << "\tT1";
    }
    return 0;
}

DWORD WINAPI OS04_05_T2() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();

    for (int i = 0; i < 125; i++) {
        Sleep(1000);
        std::cout << "\nPID = " << pid << "\tTID = " << tid << "\tT2";
    }
    return 0;
}

int main() {
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();
    DWORD childId_T1, childId_T2 = NULL;

    HANDLE hChild1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_05_T1, NULL, 0, &childId_T1);
    HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OS04_05_T2, NULL, 0, &childId_T2);

    for (int i = 0; i < 100; i++) {
        Sleep(1000);
        std::cout << "\nPID = " << pid << "\tTID = " << tid;
        if (i == 40) {
            TerminateThread(hChild2, -1);
            std::cout << "\n-------Terminate  T2-------";
        }
    }

    WaitForSingleObject(hChild1, INFINITE);
    WaitForSingleObject(hChild2, INFINITE);
    CloseHandle(hChild1);
    CloseHandle(hChild2);
    return 0;
}