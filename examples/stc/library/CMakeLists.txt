include_directories(include)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE includes src/*.h include/*.h)
add_library(stc_library ${sources} ${includes})

add_executable(stc_main main.cpp include/Library.h)
target_link_libraries(stc_main stc_library ${CMAKE_REQUIRED_LIBRARIES})

