cmake_minimum_required(VERSION 3.28)
project(gcsll_utils_proj)

set(gcsll_exstd_lib src/exstd.cpp)
add_library(gcsll_utils_exstd OBJECT ${gcsll_exstd_lib})
list(APPEND gcsll_utils_objs gcsll_utils_exstd)
gcst_binary_prepare(gcsll_utils_exstd)

set(gcsll_launcher_lib src/launcher.cpp)
add_library(gcsll_utils_launcher OBJECT ${gcsll_launcher_lib})
list(APPEND gcsll_utils_objs gcsll_utils_launcher)
gcst_binary_prepare(gcsll_utils_launcher)

add_library(gcsll_utils STATIC)
gcst_export_prepare(gcsll_utils ${gcsll_utils_objs})
set(gcsll_utils_objs ${gcsll_utils_objs} PARENT_SCOPE)