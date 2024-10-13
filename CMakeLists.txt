cmake_minimum_required(VERSION 3.29)
project(LightYears
    VERSION 1.0.0
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# create light years variable
set(LIGHT_YEARS_TARGET_NAME LightYears)

add_subdirectory(LightYearsGame)