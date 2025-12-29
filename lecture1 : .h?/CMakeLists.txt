PROJECT(WeatherApp)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)