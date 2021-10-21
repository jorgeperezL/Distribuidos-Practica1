cmake_minimum_required (VERSION 2.8.11)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (multMatrixServer)

add_executable (multMatrixServer serverMain.cpp multmatrix.cpp multmatrix.h multmatrix_imp.cpp multmatrix_imp.h  utils.h utils.cpp)

target_link_libraries(multMatrixServer pthread)

project (multMatrixClient)

add_executable (multMatrixClient main_multMatrix.cpp multmatrix_stub.cpp multmatrix_stub.h utils.h utils.cpp multmatrix.cpp multmatrix.h filemanager.cpp filemanager.h)

target_link_libraries(multMatrixClient pthread)
