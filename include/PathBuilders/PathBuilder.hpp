#pragma once

#include <tuple>
#include <string>
#include "../Enums.hpp"

namespace FileSorterProgram::PathBuilders {
    
    /**
     * @brief An interface for the various path builders
     * 
     * @interface
     */
    class PathBuilder {
    public:
        /**
         * @brief Destroy the IPathBuilder object
         */
        virtual ~PathBuilder() = 0;

    public:
        /**
         * @brief Sorts a file into the needed folder
         */
        virtual std::string buildPath(std::string file, SortType sortType) = 0;
    };
}
