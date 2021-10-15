cmake_minimum_required (VERSION 2.8.11)

#project (fileManager)

#add_executable (fileManager main_fm.cpp filemanager.cpp filemanager.h)


set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



project(proyecto1Server LANGUAGES CXX)
add_executable(proyecto1Server 
		 serverMain.cpp
		 filemanager.h filemanager.cpp utils.h utils.cpp 
		 filemanager_imp.cpp filemanager_imp.h )
target_link_libraries(proyecto1Server pthread)


project(proyecto1Client LANGUAGES CXX)
add_executable(proyecto1Client 
	main_fm.cpp  
	utils.h utils.cpp filemanager_stub.cpp 
	filemanager_stub.h )
target_link_libraries(proyecto1Client pthread)
