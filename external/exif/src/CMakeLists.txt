set(DIRECTORY "")
get_project_root_path(DIRECTORY)

# Declare each of the sub directory variables here, to be loaded into the upper level variable
# set (FILESEXCEPTIONSDIR)

#************ SUB DIRECTORIES ************# 
# add_subdirectory()

set(FILESEXIFDIR
    ${DIRECTORY}/exif.cpp
    PARENT_SCOPE
)
