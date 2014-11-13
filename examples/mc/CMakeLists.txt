project(mc)

cmake_minimum_required (VERSION 2.6)

if (DEFINED CMAKE_BUILD_TYPE)
   set (CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
else ()
   set (CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build,options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
endif ()

set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")
set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")
set (CMAKE_MODULE_LINKER_FLAGS "${CMAKE_CXX_LINK_FLAGS} -Wl,--enable-auto-import")

add_subdirectory(naive)
add_subdirectory(clike)
add_subdirectory(oo_first)
