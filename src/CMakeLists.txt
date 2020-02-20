
add_library(custom_shared_pointer INTERFACE)

target_include_directories(
    custom_shared_pointer
    INTERFACE
        ${CMAKE_SOURCE_DIR}/include
    )