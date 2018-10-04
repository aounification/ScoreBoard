mkdir build-dir
cd build-dir
cmake ..\.. -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 15 2017 Win64"
cd ..
