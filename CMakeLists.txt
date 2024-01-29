cmake_minimum_required(VERSION 3.27)
project(don_t_make_me_laugh)

set(CMAKE_CXX_STANDARD 20)

add_executable(don_t_make_me_laugh main.cpp
        game.h
        game-logic.cpp
        player-header.h)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(don_t_make_me_laugh
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(don_t_make_me_laugh
        PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(don_t_make_me_laugh
        PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

find_package(sdl2-gfx CONFIG REQUIRED)
target_link_libraries(don_t_make_me_laugh PRIVATE SDL2::SDL2_gfx)