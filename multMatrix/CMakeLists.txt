cmake_minimum_required (VERSION 2.8.11)

project (multMatrixServer)

add_executable (multMatrixServer serverMain.cpp multmatrix.cpp multmatrix.h multmatrix_imp.cpp multmatrix_imp.h  utils.h utils.cpp)

target_link_libraries(multMatrixServer pthread)

project (multMatrixClient)

add_executable (multMatrixClient main_multMatrix.cpp multmatrix_stub.cpp multmatrix_stub.h utils.h utils.cpp)

target_link_libraries(multMatrixClient pthread)
