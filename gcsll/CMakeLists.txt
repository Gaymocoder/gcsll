cmake_minimum_required(VERSION 3.28)
project(gcsll_src)

add_subdirectory(utils)
list(APPEND gcsll_objs ${gcsll_utils_objs})

add_subdirectory(labs)
list(APPEND gcsll_objs ${gcsll_labs_objs})

add_library(gcsll STATIC)
gcs_export_prepare(gcsll ${gcsll_objs})