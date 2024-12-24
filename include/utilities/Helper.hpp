#pragma once

#include <string>
#include "../Enums.hpp"

namespace FileSorterProgram::utilities {
    
    /**
     * @brief Provides a list of static misc helper methods.
     * 
     */
    class Helper {
    public:
        /**
         * @brief Construct a new Helper object
         */
        Helper();

        /**
         * @brief Destroy the Helper object
         */
        ~Helper();

    public:

        /**
         * @brief Get the Corresponding month for the given enum (int, one based)
         * 
         * @param Month The one based month enum (1 = January)
         * @return std::string The string representation of the month given
         */
        static std::string getMonthString(Months month);

        /**
         * @brief Create a directory if it does not exist
         * 
         * @param directory The directory to create
         */
        static void createDirectoryIfNotExists(std::string directory);
    };
}

