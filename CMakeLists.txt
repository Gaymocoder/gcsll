cmake_minimum_required(VERSION 3.28)
project(gcsll VERSION 1.0.0)

block()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    
    include(${CMAKE_CURRENT_LIST_DIR}/cmake/gcs_utils.cmake)
    include(${CMAKE_CURRENT_LIST_DIR}/cmake/gcsll_utils.cmake)

    if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        set(CMAKE_CXX_STANDARD 23)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
        add_compile_options(-Wall -Wextra -pedantic -O0 -g)
    endif()

    gcs_init_include(gcsll_include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")
    add_library(gcsll::include_dir ALIAS gcsll_include_dir)
    
    add_subdirectory(gcsll)
    if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        add_subdirectory(example)
    endif()

endblock()