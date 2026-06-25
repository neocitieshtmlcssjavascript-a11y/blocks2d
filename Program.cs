using System;
using System.Runtime.InteropServices;

class Program
{
    // Импортируем функцию из DLL (Cdecl — стандартное соглашение вызовов для C++)
    [DllImport("Blocks2D.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void CreateBlock2D(float x, float y, float size);

    static void Main()
    {
        Console.WriteLine("Запуск Blocks2D через C#...");
        
        // Передаем параметры x, y и размер блока
        CreateBlock2D(12.0f, 24.5f, 1.0f);
        
        Console.WriteLine("Блок успешно создан в памяти движка!");
    }
}
