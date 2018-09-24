REM mkdir release
REM cd release
REM cmake ..\.. -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 15 2017 Win64"
REM cd ..

mkdir debug
cd debug
cmake ..\.. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DBUILD_SHARED_LIBS=TRUE -G "Visual Studio 15 2017 Win64"
cd ..
