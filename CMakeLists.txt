cmake_minimum_required(VERSION 3.16)

project(FileZipperApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

# Enforce strict coding standards and best practices
if (MSVC)
    # MSVC specific flags
    add_compile_options(/W4 /permissive- /Zc:__cplusplus /WX)
else()
    # GCC/Clang specific flags
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wconversion -Wsign-conversion -Wshadow -Wnon-virtual-dtor)
endif()

# Suppress specific Qt warnings if needed
if (NOT MSVC)
    add_compile_options(-Wno-pragma-once-outside-header)
endif()

# Find Qt6 without forcing checks for Qt-specific configurations
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

# Add subdirectory for Styles and CustomWidgets
add_subdirectory(FileZipper/Styles)
add_subdirectory(FileZipper/CustomWidgets)


# Add source files
set(SOURCES
    FileZipper/FileZipperWindow.cpp
    FileZipper/main.cpp
    resources.qrc
)

# Add executable
qt_add_executable(FileZipperApp
    ${SOURCES}
)

# Link libraries
target_link_libraries(FileZipperApp PRIVATE Qt6::Widgets CustomWidgets Styles)

set_target_properties(FileZipperApp PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
