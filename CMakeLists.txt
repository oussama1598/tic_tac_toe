cmake_minimum_required(VERSION 3.7)

project(tic_tac_toe)

find_package(PkgConfig)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_INCLUDE_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

set(SRC_DIR ./src)
set(HEADERS_FOLDER headers)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Wall -Werror -fdump-rtl-expand")

include_directories(${SRC_DIR}/${HEADERS_FOLDER})
include_directories(${SRC_DIR}/pages/main)
include_directories(${SRC_DIR}/pages/signin)
include_directories(${SRC_DIR}/pages/signup)
include_directories(${SRC_DIR}/pages/game)
include_directories(${SRC_DIR}/pages/new_game)

set(SRCS
    ${SRC_DIR}/main.c
    ${SRC_DIR}/helpers/builder.c
    ${SRC_DIR}/helpers/tools.c
    ${SRC_DIR}/helpers/data_manager.c
    ${SRC_DIR}/pages/main/main_page.c
    ${SRC_DIR}/pages/signin/signin_page.c
    ${SRC_DIR}/pages/signup/signup_page.c
    ${SRC_DIR}/pages/new_game/new_game_page.c
    ${SRC_DIR}/pages/game/game.c
)

add_executable(tic_tac_toe ${SRCS})
target_link_libraries(tic_tac_toe ${GTK3_LIBRARIES})
