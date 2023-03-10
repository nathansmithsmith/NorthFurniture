cmake_minimum_required(VERSION 3.11)

project(NorthFurniture VERSION 1.0)

set(C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add exe file.
file(GLOB SRC_FILES src/*.c src/states/*.c)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include src)
target_link_libraries(${PROJECT_NAME} raylib m)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
