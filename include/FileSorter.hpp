#pragma once

#include "Enums.hpp"

#include <vector>
#include <string>

namespace FileSorterProgram {

    class FileSorter {
    //FIELDS
    private:
        /**
         * @brief The root path to sort
         */
        std::string root;

        /**
         * @brief Whether to sort the files by years or by months
         */
        SortType sortType;

        /**
         * @brief Whether to move the files or copy the files. copying is the safer route, but
         * temporarily takes up more space
         */
        TranserType transerType;

        
    //CONSTRUCTORS
    public:
        /**
         * @brief Construct a new File Sorter object
         */
        FileSorter();

    //PUBLIC METHODS
    public:
        /**
         * @brief Runs the main logic of the program
         * 
         * @return int 0 if all good, 1 if not.
         */
        int run();

    //PRIVATE MEHTODS
    private:
        /**
         * @brief Initializes the program details, getting important information from the user that
         * will allow the program to run.
         */
        void initProgramDetails();

        /**
         * @brief Sorts the list of files found. Sorts them based on the sort type chosen by the
         * user
         * 
         * @param files A pointer to a vector of the files to be sorted.
         * 
         * @return int 0 if all good, 1 if not.
         */
        int sortFiles(std::vector<std::string>* files);

    };

}

