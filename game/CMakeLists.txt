cmake_minimum_required(VERSION 3.1)

project(BirdGame)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

## In most cases better set in the CMake cache
set(SFML_DIR "/mingw32/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)
add_executable(BirdGame
	src/main.cpp
	src/game.cpp
	src/background.cpp
	src/button.cpp
	src/pillar.cpp
	src/role.cpp
	include/game.h
	include/background.h
	include/button.h
	include/pillar.h
	include/role.h
)
target_include_directories(BirdGame PRIVATE "include")
target_link_libraries(BirdGame sfml-graphics sfml-audio)

# Copy files
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB BINARY_DEP_DLLS
    "${CMAKE_SOURCE_DIR}/bin/*.dll"
)
file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
