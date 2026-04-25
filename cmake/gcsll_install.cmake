install(TARGETS gcsll gcsll_utils
    EXPORT gcsll_targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/
    DESTINATION include
)

install(EXPORT gcsll_targets
    FILE gcsllTargets.cmake
    NAMESPACE gcsll::
    DESTINATION lib/cmake/gcsll
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    cmake/gcsllConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/gcsllConfig.cmake
    INSTALL_DESTINATION lib/cmake/gcsll
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/gcsllConfig.cmake
    ${CMAKE_CURRENT_LIST_DIR}/gcsll_utils.cmake
    DESTINATION lib/cmake/gcsll
)
