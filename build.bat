@echo off
set GOOS=windows
set GOARCH=386
go build -ldflags="-s -w" -o Blocks2D.exe main.go
echo Сборка завершена! Нажмите любую клавишу.
pause
