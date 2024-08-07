cmake_minimum_required(VERSION 3.22)
project(rpg)

add_executable(rpg main.cpp Entities/Entity.cpp Entities/Entity.h GameEngine/Game.cpp GameEngine/Game.h
        States/GameState.cpp States/GameState.h States/State.cpp States/State.h
        Settings/ISettings.h
        Settings/WindowSettings.cpp
        Settings/WindowSettings.h
        States/MainMenuState.cpp
        States/MainMenuState.h
        Input/Button.cpp
        Input/Button.h
)
include_directories(include)
set(EXECUTABLE_OUTPUT_PATH ${rpg_SOURCE_DIR}/bin)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

target_link_libraries(rpg PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(rpg PRIVATE cxx_std_17)

add_custom_command(
        TARGET rpg
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:rpg>
        VERBATIM)

install(TARGETS rpg)
