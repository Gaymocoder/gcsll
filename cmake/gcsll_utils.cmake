function(gcsll_link_labs TARGET)
    foreach(LAB IN LISTS ARGN)
        if(MSVC)
            target_link_libraries(${TARGET} PRIVATE /WHOLEARCHIVE:${LAB})
        else()
            target_link_libraries(${TARGET} PRIVATE
                -Wl,--whole-archive ${LAB} -Wl,--no-whole-archive
            )
        endif()
    endforeach()
endfunction()