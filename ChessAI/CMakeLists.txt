cmake_minimum_required(VERSION 3.21)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess main.cpp Game.cpp Game.h Player.cpp Player.h Pieces.cpp Pieces.h Menu.cpp Menu.h BasicAI.cpp BasicAI.h MediumAi.cpp MediumAi.h Pawn.cpp Pawn.h Bishop.cpp Bishop.h Rook.cpp Rook.h King.cpp King.h Queen.cpp Queen.h Knight.cpp Knight.h Gamemenu.cpp Gamemenu.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Chess sfml-system sfml-window sfml-graphics sfml-audio)