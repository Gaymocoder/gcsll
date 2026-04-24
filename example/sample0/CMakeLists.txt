cmake_minimum_required(VERSION 3.28)
project(gcsll_sample0)

find_package(gcsll QUIET)
if (NOT gcsll_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        gcsll
        GIT_REPOSITORY https://github.com/Gaymocoder/gcsll.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(gcsll)
endif()

set(gcsll_sample_lab_lib src/lab.cpp)
add_library(gcsll_sample_lab STATIC ${gcsll_sample_lab_lib})
target_link_libraries(gcsll_sample_lab PUBLIC gcsll::gcsll)

set(MAIN_EXE src/main.cpp)
add_executable(gcsll_sample ${MAIN_EXE})
gcsll_link_labs(gcsll_sample gcsll_sample_lab)