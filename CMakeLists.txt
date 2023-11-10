cmake_minimum_required(VERSION 3.1)

project(
  Snake_Game
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(FTXUI)
add_executable(Snake_Game src/main.cpp)

target_link_libraries(Snake_Game 
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)