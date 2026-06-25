import ctypes
import os

# Получаем абсолютный путь к вашей DLL
dll_path = os.path.abspath("Blocks2D.dll")

try:
    # Загружаем библиотеку
    blocks_dll = ctypes.CDLL(dll_path)
    
    # Задаем типы входных аргументов для стабильности (3 числа float)
    blocks_dll.CreateBlock2D.argtypes = [ctypes.c_float, ctypes.c_float, ctypes.c_float]
    
    # Прямой вызов функции симуляции
    blocks_dll.CreateBlock2D(10.5, 20.0, 1.0)
    print("Физический движок блоков успешно запущен через Python!")

except Exception as e:
    print(f"Ошибка вызова DLL: {e}")
