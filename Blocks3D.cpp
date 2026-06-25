#include <windows.h>
#include <iostream>

// Экспортируем функцию для создания 2D блока
extern "C" __declspec(dllexport) void CreateBlock2D(float x, float y, float size) {
    std::cout << "Block2D создан в координатах: (" << x << ", " << y << ") размером " << size << std::endl;
}

// Точка входа в DLL
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
