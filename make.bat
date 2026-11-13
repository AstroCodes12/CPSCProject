@echo off

if exist CommandScheduler.exe del CommandScheduler.exe

g++ -g src/*.cpp -o CommandScheduler.exe

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Compilation failed. Check your code for syntax errors.
    pause
    exit /b %errorlevel%
)

echo.
echo [SUCCESS] CommandScheduler.exe created!
echo Running...
echo ---------------------------------------
.\CommandScheduler.exe
pause