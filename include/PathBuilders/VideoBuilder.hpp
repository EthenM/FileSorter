#pragma once

#include <tuple>
#include "PathBuilder.hpp"
#include "../Enums.hpp"

namespace FileSorterProgram::PathBuilders {
    class VideoBuilder : public PathBuilder { 
    private:
        /**
         * @brief The directory to store the sorted files in
         */
        std::string sortedDir;
        
    public:
        /**
         * @brief Construct a new Video Builder object
         * 
         * @param sortedDir The directory to store the sorted files in
         */
        VideoBuilder(std::string sortedDir);

        /**
         * @brief Destroy the Video Builder object
         */
        ~VideoBuilder();
    public:
        std::string buildPath(std::string file, SortType sortType);
        
    };
}

