#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

using namespace std;

//С - 209(10) = D1(16) я - 255(10) = FF(16) т - 242(10) = F2(16)

// страница D1 = 209
// 209 * 4096 = 856064(10) = 0x000D1000(16) - добавить чтоб перейти на страницу
// смещение FFF(16)= 0x00000FFF(16) = 4095(10)
// короче к адресу начала arr + 0x000D1000 + 0x00000FFF

void saymem() {
    MEMORYSTATUS ms;
    GlobalMemoryStatus(&ms);
    std::cout << " -- Физическая память: " << ms.dwTotalPhys / KB << '\n';
    std::cout << " -- Доступно физ памяти: " << ms.dwAvailPhys / KB << '\n';
    std::cout << " -- Объем виртуальной памяти: " << ms.dwTotalVirtual / KB << '\n';
    std::cout << " -- Доступно виртуальной памяти: " << ms.dwAvailVirtual / KB << '\n';
}

int main() {
    setlocale(LOCALE_ALL, "rus");
    // заполнение структуры информацией о системе
    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);

    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    saymem();
    // выделение виртуальной памяти (без базового адреса, размер, выделение (при этом страницы заполняются нулями), типа доступа (чтение и запись))
    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    // возвращает LPVOID - дальний указатель на любой тип

    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }
    cout << endl ;

    saymem();

    // освобождение выделенной памяти (адрес памяти, размер (при MEM_RELEASE здесь NULL), операция (освобождена))
    VirtualFree(xmemaddr, NULL, MEM_RELEASE) ? cout << endl << "VirtualFree free\n" : cout << "Virtual false\n";
    saymem();

    system("pause");
}
