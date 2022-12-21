cmake_minimum_required(VERSION 3.18)
project(GameApp)

# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# file(GLOB CLASSES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# set(SOURCES ${CLASSES})

# add_executable(app
#     ${SOURCES}
# )

# target_include_directories(app PUBLIC Lib/include)

# file(GLOB SFML_LIBS Lib/lib/*)
# target_link_libraries(app ${SFML_LIBS})

add_subdirectory(src)