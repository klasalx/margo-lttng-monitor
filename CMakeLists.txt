cmake_minimum_required(VERSION 3.16)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MARGO REQUIRED IMPORTED_TARGET GLOBAL margo)

find_package(LTTngUST)

add_library (lttng_monitor MODULE
    margo-lttng-monitoring.c
    margo-lttng-tp.c
)

set_target_properties(lttng_monitor PROPERTIES
    PREFIX ""
)

target_include_directories(lttng_monitor
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(lttng_monitor PRIVATE
        LTTng::UST
        dl
        PkgConfig::MARGO
)
