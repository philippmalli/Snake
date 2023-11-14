cmake_minimum_required(VERSION 3.5)

project(
  Snake_Game
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(FTXUI)
add_executable(Snake_Game src/main.cpp
                      src/Boundary.h 
                      src/Constants.h 
                      src/Position.h 
                      src/KeyMapping.h 
                      src/KeyMapping.cpp
                      src/Player.h
                      src/Player.cpp
                      src/CanvasItem.h
                      src/CanvasItem.cpp
                      src/Canvas.h
                      src/Canvas.cpp
                      src/GameController.h
                      src/GameController.cpp
                      src/KeyMapping.h
                      src/KeyMapping.cpp
                      src/KeyboardInputHandler.h
                      src/KeyboardInputHandler.cpp)

target_link_libraries(Snake_Game 
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)

if(MSVC)
    target_compile_options(Snake_Game PRIVATE /W4)
else()
    target_compile_options(Snake_Game PRIVATE -O3 -Wall -Wextra -Weffc++ -Wpedantic -Wunused -Werror )
endif()

add_custom_target(cppcheck ALL COMMAND cppcheck --enable=all --suppress=missingInclude ../src)
add_custom_target(clang-format ALL COMMAND clang-format --style=file -i ../src/*
)
