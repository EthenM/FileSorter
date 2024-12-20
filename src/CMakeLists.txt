set(DIRECTORY "")
get_project_root_path(DIRECTORY)

# Declare each of the sub directory variables here, to be loaded into the upper level variable
set (FILESPAGESDIR "")
set (FILESEXCEPTIONSDIR)

#************ SUB DIRECTORIES ************# 
# add_subdirectory()

set(FILESSRCDIR ${DIRECTORY}/main.cpp PARENT_SCOPE)
