#masina
add_library(masina STATIC masina.cpp)
target_include_directories(masina PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#avion
add_library(avion STATIC avion.cpp)
target_include_directories(avion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#racheta
add_library(racheta STATIC racheta.cpp)
target_include_directories(racheta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#hovercraft
add_library(hovercraft STATIC hovercraft.cpp)
target_include_directories(hovercraft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
