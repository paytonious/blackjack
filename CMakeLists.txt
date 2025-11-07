cmake_minimum_required(VERSION 3.10)
project(Blackjack)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files
file(GLOB SOURCES 
    "src/*.cpp"
    "src/card/*.cpp"
    "src/deck/*.cpp"
    "src/game/*.cpp"
)

# Create executable
add_executable(blackjack ${SOURCES})
