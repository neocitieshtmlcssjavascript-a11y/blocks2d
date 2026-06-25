#include <windows.h>
#include <iostream>

// Определяем тип функции, которая находится внутри DLL
// (например, функция принимает три float: x, y, size)
typedef void(*CreateBlockFunc)(float, float, float);

int main() {
    // 1. Загружаем DLL в память
    HMODULE hDll = LoadLibrary(TEXT("Blocks2D.dll"));
    
    if (hDll == NULL) {
        std::cout << "Ошибка: Не удалось загрузить Blocks2D.dll!" << std::endl;
        return 1;
    }

    // 2. Ищем адрес функции внутри DLL по её имени
    CreateBlockFunc CreateBlock2D = (CreateBlockFunc)GetProcAddress(hDll, "CreateBlock2D");

    if (CreateBlock2D == NULL) {
        std::cout << "Ошибка: Функция CreateBlock2D не найдена в DLL!" << std::endl;
        FreeLibrary(hDll);
        return 1;
    }

    // 3. Вызываем функцию из DLL
    std::cout << "Библиотека успешно подключена без Go!" << std::endl;
    CreateBlock2D(10.0f, 20.0f, 1.5f);

    // 4. Выгружаем библиотеку
    FreeLibrary(hDll);
    return 0;
}
