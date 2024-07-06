# Add the source and header files for the Styles library
add_library(Styles STATIC
    Styles.cpp
    Styles.h
)

# Include the current directory for header file resolution
target_include_directories(Styles PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the Qt libraries to the Styles library
target_link_libraries(Styles PUBLIC Qt6::Widgets)
