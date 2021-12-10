cmake_minimum_required(VERSION 3.21.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(dde VERSION 1.0)

find_library(X11 X11)
find_library(FREETYPE freetype)
find_library(Xft Xft)
find_package(Fontconfig)
find_library(XINERAMA Xinerama)

set(X11_INCLUDE_DIRS /usr/X11R6/include /usr/X11R6/include/Xft)
set(FREETYPE_INCLUDE_DIRS /usr/include/freetype2)

# dwm
add_executable(dwm ${CMAKE_CURRENT_SOURCE_DIR}/dwm/dwm.cpp ${CMAKE_CURRENT_SOURCE_DIR}/dwm/drw.cpp ${CMAKE_CURRENT_SOURCE_DIR}/dwm/util.cpp)
#add_executable(dwm++ ${CMAKE_CURRENT_SOURCE_DIR}/dwm++/src/dwm.cpp ${CMAKE_CURRENT_SOURCE_DIR}/dwm++/src/program.cpp)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/dwm/dwm.cpp PROPERTIES COMPILE_OPTIONS "-DXINERAMA")

target_include_directories(dwm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS} ${X11_INCLUDE_DIRS})
target_link_libraries(dwm PUBLIC ${X11} ${FREETYPE} ${Xft} Fontconfig::Fontconfig ${XINERAMA})

# dmenu
add_executable(dmenu ${CMAKE_CURRENT_SOURCE_DIR}/dmenu/dmenu.c ${CMAKE_CURRENT_SOURCE_DIR}/dmenu/drw.c ${CMAKE_CURRENT_SOURCE_DIR}/dmenu/util.c)
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/dmenu/dmenu.c PROPERTIES COMPILE_OPTIONS "-DXINERAMA")

target_include_directories(dmenu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${FREETYPE_INCLUDE_DIRS} ${X11_INCLUDE_DIRS})
target_link_libraries(dmenu PUBLIC ${X11} ${FREETYPE} ${Xft} Fontconfig::Fontconfig ${XINERAMA})

# stest
add_executable(stest ${CMAKE_CURRENT_SOURCE_DIR}/dmenu/stest.c)

install(TARGETS dwm dmenu stest DESTINATION bin)
install(PROGRAMS "${PROJECT_SOURCE_DIR}/dmenu/dmenu_run" "${PROJECT_SOURCE_DIR}/dmenu/dmenu_path" DESTINATION bin)
