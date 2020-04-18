cmake_minimum_required(VERSION 3.16)
project(OpenGLTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenGLTest main.cpp rysowanie.cpp definicje.cpp interakcja.cpp konfiguracja.cpp)

target_link_libraries(OpenGLTest -lglut -lGL -lGLU)