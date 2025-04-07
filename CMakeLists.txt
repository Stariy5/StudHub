cmake_minimum_required(VERSION 3.22)
project(myapp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=thread -g1")

include(FetchContent)

find_package(Catch2 3 REQUIRED)

include_directories(${CATCH2_INCLUDE_DIRS})

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
)

FetchContent_MakeAvailable(Catch2)

add_subdirectory(dailybudget)
add_subdirectory(eveningbudget)
add_subdirectory(feepaying)
add_subdirectory(IStudHub)
add_subdirectory(myapp)
add_subdirectory(table)
#add_subdirectory(tests)

add_executable(studyhub main.cpp)

target_link_libraries(studyhub PRIVATE dailybudget eveningbudget fee-paying table IStudHub myapp)

add_compile_options(--coverage)
add_link_options(--coverage)

add_executable(testy ../tests/testing.cpp)

target_include_directories(testy PRIVATE ${CMAKE_SOURCE_DIR}/studyhub)

target_link_libraries(testy PRIVATE Catch2::Catch2WithMain)