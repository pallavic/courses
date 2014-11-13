file(GLOB_RECURSE sources *.cpp)
file(GLOB_RECURSE includes *.h)

add_executable(procedural_with_objects ${sources} ${includes})

