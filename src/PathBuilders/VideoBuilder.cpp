
#include <iostream>
#include <windows.h>
#include <filesystem>
#include <string>
#include <sstream>
#include <tuple>
#include <chrono>
#include <iomanip>
#include "../../include/PathBuilders/VideoBuilder.hpp"
#include "../../include/Enums.hpp"
#include "../../include/utilities/Helper.hpp"

namespace FileSorterProgram::PathBuilders {
    VideoBuilder::VideoBuilder(std::string sortedDir) {
        this->sortedDir = sortedDir;
    }

    VideoBuilder::~VideoBuilder() {  }

    std::string VideoBuilder::buildPath(std::string file, SortType sortType) {
        //video creation dates aren't guaranteed to be stored. put it in the unsortable directory,
        //and let the user handle it.
        
        //build the path to the unsortable directory
        std::string dirPath = (std::filesystem::path(this->sortedDir) /
            std::filesystem::path(utilities::Helper::UNSORTABLE_DIR)).string();

        //create the directory if it doesn't already exist
        utilities::Helper::createDirectoryIfNotExists(dirPath);

        //finally, return the path.
        return dirPath;
    }
}
