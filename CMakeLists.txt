cmake_minimum_required(VERSION 3.0.0)
project(libeewin64 VERSION 0.1.0 LANGUAGES C CXX)


include_directories( "./" )
include_directories( "./win_forms" )

file(GLOB WIN_FORMS_SRC 
"win_forms/win_forms.cpp"
"win_forms/win_forms.h"
)


file(GLOB MAIN_SRC 
"libeewin64.cpp"
)

# SET( CMAKE_CXX_FLAGS_DEBUG  "")
# SET( CMAKE_CXX_FLAGS_RELEASE  "")
# SET( CMAKE_CXX_FLAGS  "-Ofast -DNDEBUG -std=c++20 -march=native -fpic -ftree-vectorize")


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 

set(RENDER_LIBS user32 gdiplus shlwapi msimg32)

# add_compile_options(
# "$<$<COMPILE_LANGUAGE:CXX>:--allow-undefined-file=src/libeewin64.syms>"
# )

# add_compile_options(
# "$<$<COMPILE_LANGUAGE:CXX>:-Wl,/DEF:libeewin64.def>"
# )

# add_compile_options(
# "$<$<COMPILE_LANGUAGE:CXX>:--extract-api-ignores=libeewin64.syms>"
# )

#add_compile_options(-S -emit-llvm)




#set (CMAKE_SHARED_LINKER_FLAGS "/exclude-symbols:__entryPoint__ /myflag")


add_library(libeewin64 STATIC ${WIN_FORMS_SRC} ${MAIN_SRC} )

#target_link_options(libeewin64 PRIVATE "LINKER:/force:unresolved")

target_link_libraries(libeewin64 STATIC ${RENDER_LIBS})

# message("BUILD_TYPE: ${BUILD_TYPE}")
# if (BUILD_TYPE AND BUILD_TYPE STREQUAL  "Debug")
# message("DBG is detected")
# set_property(TARGET libeewin64 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
# target_compile_definitions(libeewin64 PRIVATE  EF_IS_SUPER_USER_VER )   
# else()
# message("RELEASE is detected")
# set_property(TARGET libeewin64 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded")
# endif()

# if (MSVC)
#     # warning level 4
#     add_compile_options("-Wl,--export-all")
# else()
#     # additional warnings
#     add_compile_options("-Wl,--export-all")
# endif()

