#include <iostream>
#include <windows.h>
#include <process.h>

int main()
{
    for (int i = 0; i < 10000; i++) {
        Sleep(1);
        std::cout << "\t" << _getpid();
    }
}