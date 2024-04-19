cmake_minimum_required(VERSION 3.10)

project(Labyrinth)
set(CMAKE_OSX_ARCHITECTURES "arm64")
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/include ./inc)
message("system: ${CMAKE_SYSTEM_PREFIX_PATH}")
find_library(CAIRO_LIBRARY cairo)
message("cairo: ${CAIRO_LIBRARY}")


add_executable(playxxxx ./src/labyrinth.cpp ./src/lucca.cpp ./monk/main.cpp)
target_link_libraries( playxxxx ${CAIRO_LIBRARY} )
add_executable(playzzzz ./src/labyrinth.cpp ./src/lucca.cpp ./monk/mainfromfindall.cpp)
target_link_libraries( playzzzz ${CAIRO_LIBRARY} )
add_executable(labyrinth ./src/labyrinth.cpp ./labyrinth/main.cpp)
target_link_libraries( labyrinth ${CAIRO_LIBRARY} )
add_executable(lucca ./src/labyrinth.cpp ./src/lucca.cpp ./lucca/main.cpp)
target_link_libraries( lucca ${CAIRO_LIBRARY} )
add_executable(myth ./src/labyrinth.cpp ./src/lucca.cpp ./myth/main.cpp)
target_link_libraries( myth ${CAIRO_LIBRARY} )
add_executable(smyth ./src/labyrinth.cpp ./src/lucca.cpp ./smyth/main.cpp)
target_link_libraries( smyth ${CAIRO_LIBRARY} )