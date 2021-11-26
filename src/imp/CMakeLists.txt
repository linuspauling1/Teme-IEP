#pentru superclase
#aeronava
add_library(aeronava STATIC aeronava.cpp)
target_include_directories(aeronava PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#mijloc de transport
add_library(mijloc STATIC aeronava.cpp)
target_include_directories(mijloc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#pentru posibile subclase
#masina
add_library(masina STATIC masina.cpp)
target_include_directories(masina PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#avion
add_library(avion STATIC avion.cpp)
target_include_directories(avion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(avion aeronava)
#racheta
add_library(racheta STATIC racheta.cpp)
target_include_directories(racheta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(racheta aeronava)
#hovercraft
add_library(hovercraft STATIC hovercraft.cpp)
target_include_directories(hovercraft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
