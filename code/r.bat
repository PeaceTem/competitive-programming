@echo off
set SRC=%1

if "%SRC%"=="" (
    echo Usage: r file OR r file.cpp
    exit /b
)

:: Add .cpp if not provided
if /i not "%SRC:~-4%"==".cpp" (
    set SRC=%SRC%.cpp
)

:: Check if source file exists
if not exist "%SRC%" (
    echo Source file "%SRC%" not found.
    exit /b
)

:: Check input.txt
if not exist "input.txt" (
    echo input.txt not found.
    exit /b
)

echo Compiling %SRC% ...
g++ -std=gnu++17 "%SRC%" -O2 -Wall -o a.exe
if errorlevel 1 (
    echo Compilation failed.
    exit /b
)

echo Running a.exe with input.txt ...
a.exe < input.txt
