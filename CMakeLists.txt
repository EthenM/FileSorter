cmake_minimum_required(VERSION 3.10)
project(FileSorter VERSION 0.1.0 LANGUAGES C CXX)

#this will store all of the files to add
#files being added to this variable might have to turn into a function,
#as I might have to deal with files being overridden
set(FILESSRCDIR "")

#This function will get the relative path to the subDirectories
#making it easier to add files, as the tree gets bigger
function(get_project_root_path PATH)
    set(temp_path ${PATH})
    file(RELATIVE_PATH temp_path ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
    message("At function " ${temp_path})
    set(${PATH} ${temp_path} PARENT_SCOPE)
endfunction()

#************ SUB DIRECTORIES ************# 
add_subdirectory(src)

message("The source code files: " ${FILESSRCDIR})

add_executable(FileSorter ${FILESSRCDIR})

#add flags for static linking of libraries
target_compile_options(FileSorter PRIVATE -static-libstdc++ -static-libgcc)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
