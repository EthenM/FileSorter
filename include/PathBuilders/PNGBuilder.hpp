#pragma once

#include "PathBuilder.hpp"
#include <string>

namespace FileSorterProgram::PathBuilders {
    class PNGBuilder : public PathBuilder {        
    private:
        /**
         * @brief The directory to store the sorted files in
         */
        std::string sortedDir;
    
    public:

        /**
         * @brief Construct a new PNGBuilder object
         * 
         * @param sortedDir The directory to store the sorted files in
         */
        PNGBuilder(std::string sortedDir);

        /**
         * @brief Destroy the PNGBuilder object
         */
        ~PNGBuilder();

    public:
        std::string buildPath(std::string file, SortType sortType);
    };
}
