cmake_minimum_required(VERSION 3.28)
project(gcsll_utils_proj)

add_library(gcsll_utils INTERFACE)
add_library(gcsll::utils ALIAS gcsll_utils)
target_link_libraries(gcsll_utils INTERFACE gcsll::include_dir)

set(gcsll_exstd_lib src/exstd.cpp)
add_library(gcsll_utils_exstd STATIC ${gcsll_exstd_lib})
add_library(gcsll::utils::exstd ALIAS gcsll_utils_exstd)
target_link_libraries(gcsll_utils_exstd PUBLIC gcsll::include_dir)
target_link_libraries(gcsll_utils INTERFACE gcsll::utils::exstd)

set(gcsll_launcher_lib src/launcher.cpp)
add_library(gcsll_utils_launcher STATIC ${gcsll_launcher_lib})
add_library(gcsll::utils::launcher ALIAS gcsll_utils_launcher)
target_link_libraries(gcsll_utils_launcher PUBLIC gcsll::include_dir)
target_link_libraries(gcsll_utils_launcher PRIVATE gcsll::utils::exstd)
target_link_libraries(gcsll_utils INTERFACE gcsll::utils::launcher)