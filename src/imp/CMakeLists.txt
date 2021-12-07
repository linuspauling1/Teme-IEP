#pentru superclase
#aeronava
add_library(aeronava STATIC aeronava.cpp)
target_include_directories(aeronava PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#pentru posibile subclase
#avion
add_library(avion STATIC avion.cpp)
target_include_directories(avion PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(avion aeronava)
#racheta
add_library(racheta STATIC racheta.cpp)
target_include_directories(racheta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(racheta aeronava)
#pentru alte clase
#lacat
add_library(lacat STATIC lacat.cpp)
target_include_directories(lacat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#siruri
add_library(siruri STATIC siruri.cpp)
target_include_directories(siruri PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#ciclu
add_library(ciclu STATIC ciclu.cpp)
target_include_directories(ciclu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
