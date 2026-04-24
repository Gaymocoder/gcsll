function(gcs_init_include target_name dir_path)
    if(TARGET "${target_name}")
        return()
    endif()

    add_library("${target_name}" INTERFACE)
    target_include_directories("${target_name}" INTERFACE
        $<BUILD_INTERFACE:${dir_path}>
        $<INSTALL_INTERFACE:include>
    )

    target_compile_features("${target_name}" INTERFACE cxx_std_23)
    if (MINGW)
        target_link_libraries("${target_name}" INTERFACE stdc++exp)
    endif()
endfunction()