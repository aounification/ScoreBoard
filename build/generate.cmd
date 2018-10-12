REM mkdir Release
REM cd Release
REM cmake ..\.. -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 15 2017 Win64"
REM cd ..

mkdir Debug
cd Debug
cmake ..\.. -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 15 2017 Win64"
cd ..