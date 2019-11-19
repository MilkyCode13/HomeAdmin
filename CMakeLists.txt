cmake_minimum_required(VERSION 3.0.0)
project(HomeAdmin VERSION 0.1.0)

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(HomeAdmin src/cApp.cpp src/cMainFrame.cpp)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
