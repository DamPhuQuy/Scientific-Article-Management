build

# Tạo thư mục build

mkdir build
cd build

# Cấu hình CMake với đường dẫn Qt6 và compiler đúng

cmake -G "MinGW Makefiles" `  -DCMAKE_PREFIX_PATH="C:/Qt/6.10.1/mingw_64"`
  -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1310_64/bin/g++.exe" `  -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1310_64/bin/gcc.exe"`
  ..

# Build project

cmake --build .
