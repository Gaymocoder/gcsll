cmake_minimum_required(VERSION 3.28)
project(gcsll_src)

add_subdirectory(utils)
message("gcsll_utils_objs = ${gcsll_utils_objs}")
list(APPEND gcsll_objs ${gcsll_utils_objs})

add_library(gcsll STATIC)
message("${gcsll_objs}")
gcs_export_prepare(gcsll ${gcsll_objs})