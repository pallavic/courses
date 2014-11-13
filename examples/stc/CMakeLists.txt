project(stc)

cmake_minimum_required (VERSION 2.6)

if (DEFINED CMAKE_BUILD_TYPE)
   set (CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
else ()
   set (CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build,options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
endif ()

if (MINGW)
   set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")
   set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")
   set (CMAKE_MODULE_LINKER_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")
endif ()

add_subdirectory(prototype)
add_subdirectory(procedural)
add_subdirectory(procedural_with_objects)
add_subdirectory(quick_and_dirty)
add_subdirectory(oo_first)
add_subdirectory(oo_second)
add_subdirectory(oo_third)
add_subdirectory(semantics)
add_subdirectory(ds_in_practice)
add_subdirectory(singleton)
add_subdirectory(library)


