const koffi = require('koffi');

// 1. Загружаем библиотеку (файл должен лежать в той же папке)
const lib = koffi.load('./Blocks2D.dll');

// 2. Регистрируем функцию (имя, тип возвращаемого значения, типы аргументов)
// Пример для функции: void CreateBlock2D(float x, float y, float size)
const CreateBlock2D = lib.func('void CreateBlock2D(float x, float y, float size)');

// 3. Вызываем функцию
console.log("Запуск физики блоков через Node.js...");
CreateBlock2D(10.5, 20.0, 1.0);
console.log("Вызов успешно выполнен!");
