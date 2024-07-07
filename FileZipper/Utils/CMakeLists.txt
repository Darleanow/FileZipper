# Add the source and header files for the Compressor library
add_library(Compressor STATIC
    Compressor.cpp
    Compressor.h
)

# Include the current directory for header file resolution
target_include_directories(Compressor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the Qt libraries to the Compressor library
target_link_libraries(Compressor PUBLIC Qt6::Widgets)
