package main

import (
	"fmt"
	"syscall"
)

func main() {
	// 1. Загружаем библиотеку (файл должен лежать в той же папке)
	dll, err := syscall.LoadDLL("Blocks2D.dll")
	if err != nil {
		fmt.Println("Ошибка загрузки DLL:", err)
		return
	}
	defer dll.Release()

	// 2. Ищем функцию внутри DLL
	proc, err := dll.FindProc("CreateBlock2D")
	if err != nil {
		fmt.Println("Функция не найдена:", err)
		return
	}

	// 3. Передаем аргументы (в Go float32 передается через битовую маску)
	var x, y, size float32 = 10.5, 20.0, 1.0

	// Вызываем функцию из C++
	_, _, _ = proc.Call(
		uintptr(syscall.Float32bits(x)),
		uintptr(syscall.Float32bits(y)),
		uintptr(syscall.Float32bits(size)),
	)
}
