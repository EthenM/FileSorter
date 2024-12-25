set(DIRECTORY "")
get_project_root_path(DIRECTORY)

# Declare each of the sub directory variables here, to be loaded into the upper level variable
set (FILESEXCEPTIONSDIR "")
set (FILESPATHBUILDERDIR "")
set (FILESUTILITIESDIR "")

#************ SUB DIRECTORIES ************# 
add_subdirectory(exceptions)
add_subdirectory(PathBuilders)
add_subdirectory(utilities)

set(FILESSRCDIR
    ${FILESEXCEPTIONSDIR}
    ${FILESPATHBUILDERSDIR}
    ${FILESUTILITIESDIR}
    ${DIRECTORY}/main.cpp
    ${DIRECTORY}/FileSorter.cpp
    ${DIRECTORY}/FileObtainer.cpp
    PARENT_SCOPE
)
