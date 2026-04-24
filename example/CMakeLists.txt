cmake_minimum_required(VERSION 3.28)
project(gcsll_example)

block()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/examples)

    set(gcsll_sample0_lab_lib sample0/src/lab.cpp)
    add_library(gcsll_sample0_lab STATIC ${gcsll_sample0_lab_lib})
    target_link_libraries(gcsll_sample0_lab PUBLIC gcsll::gcsll)

    set(gcsll_sample0_exe sample0/src/main.cpp)
    add_executable(gcsll_sample0 ${gcsll_sample0_exe})
    gcsll_link_labs(gcsll_sample0 gcsll_sample0_lab)
endblock()