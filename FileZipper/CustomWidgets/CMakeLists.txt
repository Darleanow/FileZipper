# Add the source and header files for the Styles library
add_library(CustomWidgets STATIC
    CListView/CListView.cpp
    CListView/CListView.h
    CListView/CListViewDelegate.cpp
    CListView/CListViewDelegate.h
    CListView/CListViewModel.cpp
    CListView/CListViewModel.h
)

# Include the current directory for header file resolution
target_include_directories(CustomWidgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the Qt libraries to the CustomWidgets library
target_link_libraries(CustomWidgets PUBLIC Qt6::Widgets)
