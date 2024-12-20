#pragma once

#include <string>
#include <vector>

namespace FileSorterProgram {

    class FileObtainer {
    private:
        std::string root;

    //CONSTRUCTORS/DESTRUCTORS
    public:

        /**
         * @brief Construct a new File Obtainer object, with the root path given.
         * 
         * @param root The root path to get files from
         */
        FileObtainer(std::string root);

    public:

        /**
         * @brief Gets All files under the root path specified in the constructor
         * 
         * @return std::vector<std::string> A vector of all of the files found under the root path
         */
        std::vector<std::string> getFilesNotRecursive();
    };

}

