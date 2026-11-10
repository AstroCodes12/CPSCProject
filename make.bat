@echo off

if exist lect29.exe del lect29.exe

g++ -g src/*.cpp -o lect29.exe

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Compilation failed. Check your code for syntax errors.
    pause
    exit /b %errorlevel%
)

echo.
echo [SUCCESS] lect29.exe created!
echo Running...
echo ---------------------------------------
.\lect29.exe
pause