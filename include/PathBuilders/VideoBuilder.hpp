#pragma once

#include <tuple>
#include "PathBuilder.hpp"
#include "../Enums.hpp"

namespace FileSorterProgram::PathBuilders {
    class VideoBuilder : PathBuilder { 
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
        
    private:

        /**
         * @brief Get the Creation Date of the file given
         * 
         * @param file The file to get the creation date for
         * @return std::tuple<int, int> A tuple of the year and month the photo file was created
         */
        std::tuple<int, int> getCreationDate(std::string file);

    };
}

