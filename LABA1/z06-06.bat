@chcp 65001 > nul
@echo off
echo -- строка параметров: %1 %2
echo -- режим: %1
echo -- имя файла: %2

if "%*" equ "" goto help
if "%2" equ "" echo ---+ отсутствует имя файла & goto exit

if /i "%1" equ "create" goto create
if /i "%1" equ "delete" goto delete
if /i "%1" neq "delete" goto errorRejim else if /i "%1" neq "create" goto errorRejim

:help
echo ---+ z03-06 режим файл
echo ---++ режим = {create, delete}
echo ---++ файл = имя файла
goto exit

:errorRejim
echo ---+ режим задан не корректно
goto exit

:create
if not exist %2 (echo. > %2 & echo ---+ файл %2 создан) else (echo ---+ файл %2 уже есть)
goto exit

:delete
if not exist %2 (echo ---+ файл %2 не найден) else (del %2 & echo ---+ файл %2 удален)
goto exit

:exit
pause