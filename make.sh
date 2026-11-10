if [ -f "lect29" ]; then
    rm lect29
fi

g++ -g src/*.cpp -o lect29

if [ $? -ne 0 ]; then
    echo ""
    echo "[ERROR] Compilation failed. Check your code for syntax errors."
    read -p "Press [Enter] to continue..."
    exit 1
fi

echo ""
echo "[SUCCESS] lect29.exe created!"
echo "Running..."
echo "---------------------------------------"
./lect29

read -p "Press [Enter] to continue..."