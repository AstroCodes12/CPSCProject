if [ -f "CommandScheduler" ]; then
    rm CommandScheduler
fi

g++ -g src/*.cpp -o CommandScheduler

if [ $? -ne 0 ]; then
    echo ""
    echo "[ERROR] Compilation failed. Check your code for syntax errors."
    read -p "Press [Enter] to continue..."
    exit 1
fi

echo ""
echo "[SUCCESS] CommandScheduler.exe created!"
echo "Running..."
echo "---------------------------------------"
./CommandScheduler

read -p "Press [Enter] to continue..."