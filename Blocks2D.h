package main

/*
#cgo CFLAGS: -I./include
#cgo LDFLAGS: -L. -lBlocks2D
#include "blocks2d.h"
*/
import "C"

func main() {
    // Прямой вызов C++ функции через Cgo
    C.CreateBlock2D(C.float(10.5), C.float(20.0), C.float(1.0))
}
