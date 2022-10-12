#README

#Requirements
required OS: Windows 10, 11
required Compiler: Microsoft Visual C++ (MSVC) 14.34
required Visual Studio version: 2022

#How to compile
1. open IIKH.sln file in IIKH_src directory with Visual Studio2022
2. before run build, please make sure following things
    - build configuration is ISO C++17 Standard
    - set build options to “Release” and for “x64”
    - Windows SDK version 10.0.0(latest)
3. click “build” tab at left up side on your Visual Studio application window
4. click “solution build” option
5. check the successful build message on output window


#How to execute
1. go to “x64” directory in the “IIKH_src” directory
2. go to “Release” directory in “x64” directory
3. you will find execution file named “IIKH”
4. open that file.
    (If you don’t have txt files, IIKH will make one for you
    but if you want to use existing files, please locate the txt files in the same directory with IIKH.exe and name it as “DB_Recipe.txt” and “DB_Plans.txt”)
