@echo Compile programm...
@echo off
g++ Stuff.cpp Book.cpp Stationery.cpp Schoolbook.cpp Keeper.cpp main.cpp -o main.exe
if %errorlevel% == 0 (@echo Run application... && @echo off && .\main.exe)