cmake_minimum_required(VERSION 3.1)

project(TRPG)

## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

# set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

## In most cases better set in the CMake cache
set(SFML_DIR "/mingw32/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics system window REQUIRED)
find_package(ImGui-SFML REQUIRED)

add_executable(TRPG
    inc/role.h
    inc/obj.h
    inc/map.h
    inc/bag.h
    inc/log.h
    inc/definition.h
    inc/MapStartRoom.h
    inc/MapBookRoom.h
    inc/MapKitchen.h
    inc/MapSlaveRoom.h
    inc/MapAuditorium.h
    inc/gameloop.h
    src/role.cpp
    src/obj.cpp
    src/map.cpp
	src/main.cpp
)

target_include_directories(TRPG PRIVATE "inc")
target_link_libraries(TRPG 
	ImGui-SFML::ImGui-SFML
	sfml-graphics
	sfml-system
	sfml-audio
	sfml-window
)

# Copy files
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB BINARY_DEP_DLLS
    "${CMAKE_SOURCE_DIR}/bin/*.dll"
)
file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
