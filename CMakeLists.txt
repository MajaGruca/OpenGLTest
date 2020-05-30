cmake_minimum_required(VERSION 3.16)
project(OpenGLTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenGLTest main.cpp rysowanie.cpp definicje.cpp interakcja.cpp konfiguracja.cpp Terrain.cpp Terrain.h model3DS.cpp model3DS.h Vector.h textureBMP.cpp textureBMP.h windowsVal.h)

target_link_libraries(OpenGLTest -lglut -lGL -lGLU)