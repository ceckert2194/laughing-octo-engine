cmake_minimum_required(VERSION 3.16)
project(laughing-octo-engine)

# Configure Qt and C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set Qt paths
set(Qt6_DIR "C:/Qt/6.8.2/mingw_64/lib/cmake/Qt6")
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64")

# Find Qt packages
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Set up executable
add_executable(laughing-octo-engine WIN32
    src/main.cpp
    src/MainWindow.cpp
    include/MainWindow.hpp
)

# Configure include directories
target_include_directories(laughing-octo-engine PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link Qt libraries
target_link_libraries(laughing-octo-engine PRIVATE Qt6::Widgets)