
#include <string>
#include <filesystem>
#include "../../include/PathBuilders/PNGBuilder.hpp"
#include "../../include/utilities/Helper.hpp"

namespace FileSorterProgram::PathBuilders {
    PNGBuilder::PNGBuilder(std::string sortedDir) {
        this->sortedDir = sortedDir;
    }

    PNGBuilder::~PNGBuilder() {  }

    std::string PNGBuilder::buildPath(std::string file) {
        //The PNG's aren't guaranteed a date tag anywhere. these will just be organized into a
        //PNG folder, where the user can organize them manually.

        //build the path to the PNG directory
        std::string dirPath = (std::filesystem::path(this->sortedDir) /
            std::filesystem::path(this->PNG_DIR)).string();

        //create the directory if it doesn't already exist
        utilities::Helper::createDirectoryIfNotExists(dirPath);

        //finally, return the path.
        return dirPath;
    }
}
