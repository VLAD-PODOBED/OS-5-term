#include <iostream>
#include <Windows.h>

int main()
{
	int id = GetCurrentProcessId();
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "Main process id: " << id << std::endl;
		Sleep(1000);
	}

	STARTUPINFO si1;
	PROCESS_INFORMATION pi1;
	ZeroMemory(&si1, sizeof(STARTUPINFO));
	si1.cb = sizeof(STARTUPINFO);

	STARTUPINFO si2;
	PROCESS_INFORMATION pi2 = {};
	ZeroMemory(&si2, sizeof(STARTUPINFO));
	si2.cb = sizeof(STARTUPINFO);

	if (CreateProcess(L"D:\\ос\\LABA3\\OS03_01\\x64\\Debug\\OS03_02_1.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
	{
		DWORD id1 = pi1.dwProcessId;
		std::cout << "Process created" << std::endl;
		for (size_t i = 0; i < 50; i++)
		{
			std::cout << "First child process id: " << id1 << std::endl;
			Sleep(1000);
		}
	}
	else
		std::cout << "Error: first process didn't createad" << std::endl;

	if (CreateProcess(L"D:\\ос\\LABA3\\OS03_01\\x64\\Debug\\OS03_02_2.exe", NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si1, &pi1))
	{
		DWORD id2 = pi1.dwProcessId;
		std::cout << "Process created" << std::endl;
		for (size_t i = 0; i < 125; i++)
		{
			std::cout << "Second child process id: " << id2 << std::endl;
			Sleep(1000);
		}
	}
	else
		std::cout << "Error: second process didn't createad" << std::endl;

	WaitForSingleObject(pi1.hProcess, INFINITE);
	WaitForSingleObject(pi2.hProcess, INFINITE);

	CloseHandle(pi1.hProcess);
	CloseHandle(pi2.hProcess);
}
