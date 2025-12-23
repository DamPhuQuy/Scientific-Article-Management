# Requirement:

Qt must be instaled in C:\Qt with mingw compiler

# Tạo thư mục build

mkdir build
cd build

# Setup

```
cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/<your_version>/mingw_64" -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1310_64/bin/g++.exe" -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1310_64/bin/gcc.exe"
```

# Build project

```cmake
cmake --build .
```

# Install dependencies

```
"C:/Qt/<your_version>/mingw_64/bin/windeployqt.exe" .\ArticleManage.exe
```
