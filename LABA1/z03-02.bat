@chcp 65001 > nul
@echo off
echo -- имя этого bat-файла: %0
echo -- путь bat-файла: %~f0

setlocal enabledelayedexpansion
set FileName=D:\ос\LABA1\z03-02.bat
for %%a in ("%FileName%") do (
    set File=%%~fa
    for /f "tokens=1* delims=," %%a in ('wmic datafile where "name='!File:\=\\!'" get 'CreationDate' /format:csv ^| find /i "%ComputerName%"') do (set CreationDate=%%b)
    set cYear=!CreationDate:~0,4!
    set cMonth=!CreationDate:~4,2!
    set cDay=!CreationDate:~6,2!
    set cHour=!CreationDate:~8,2!
    set cMinutes=!CreationDate:~10,2!
    set TimeStamp=!cDay!.!cMonth!.!cYear! !cHour!:!cMinutes!
    ECHO -- файл создан !TimeStamp!
)

pause