cmake_minimum_required(VERSION 3.28)
project(gcsll_src)

add_subdirectory(utils)

add_library(gcsll INTERFACE)
target_link_libraries(
    gcsll INTERFACE
    gcsll::utils
    gcsll::include_dir
)
add_library(gcsll::gcsll ALIAS gcsll)