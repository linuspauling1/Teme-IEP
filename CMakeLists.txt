cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(proiect VERSION 1.0)
##########################################################################################
#file(GLOB_RECURSE SRC_FILES src/*.cpp) # varianta nerecomandata dar,
#add_executable(exe main.cpp ${SRC_FILES}) # mai usor de implementat pentru proiecte mici
##########################################################################################
#add_library(exe STATIC src/fisier.cpp) # varianta recomandata, dar care poate fi
#target_include_directories(exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # imbunatatita
##########################################################################################
add_subdirectory(src/imp)
add_executable(exe src/main/main.cpp)
install(TARGETS exe DESTINATION bin)
#adaugam bibliotecile
target_link_libraries(exe PUBLIC masina)
target_link_libraries(exe PUBLIC avion)
target_link_libraries(exe PUBLIC racheta)
target_link_libraries(exe PUBLIC hovercraft)
target_link_libraries(exe PUBLIC aeronava)
target_link_libraries(exe PUBLIC mijloc)
