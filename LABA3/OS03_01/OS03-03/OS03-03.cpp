#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <iomanip> 

int main()
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 peProcessEntry;
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    try
    {
        if (!Process32First(snap, &peProcessEntry))
            throw L"Process32First";
        do
        {
            std::wcout << L"Pid: " << peProcessEntry.th32ProcessID << "\t"
                << L"Name: " << peProcessEntry.szExeFile << "\n";
        } while (Process32Next(snap, &peProcessEntry));
    }
    catch (char* msg) {
        std::wcout << L"ERROR: " << msg << "\n";
    }
    system("pause");
    return 0;
}