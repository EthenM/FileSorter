set(DIRECTORY "")
get_project_root_path(DIRECTORY)

# Declare each of the sub directory variables here, to be loaded into the upper level variable
# set (FILESEXCEPTIONSDIR)

#************ SUB DIRECTORIES ************# 
# add_subdirectory()

set(FILESPATHBUILDERSDIR
    ${DIRECTORY}/JPGBuilder.cpp
    ${DIRECTORY}/PathBuilder.cpp
    ${DIRECTORY}/PNGBuilder.cpp
    ${DIRECTORY}/VideoBuilder.cpp
    PARENT_SCOPE
)
