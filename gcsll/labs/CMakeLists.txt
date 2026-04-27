cmake_minimum_required(VERSION 3.28)
project(gcsll_labs_proj)

set(gcsll_lab_lib src/lab.cpp)
add_library(gcsll_labs_lab OBJECT ${gcsll_lab_lib})
list(APPEND gcsll_labs_objs gcsll_labs_lab)
gcs_object_prepare(gcsll_labs_lab)

add_library(gcsll_labs STATIC)
gcs_export_prepare(gcsll_labs ${gcsll_labs_objs})
set(gcsll_labs_objs ${gcsll_labs_objs} PARENT_SCOPE)