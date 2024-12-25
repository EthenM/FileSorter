#pragma once

#include "Enums.hpp"

#include <vector>
#include <tuple>
#include <string>
#include <regex>
#include <windows.h>

namespace FileSorterProgram {

    class FileSorter {
    public:
        /**
         * @brief Part of the name of the sorted directory. The first part is the name of the root
         * chosen by the user. this is then appended to the end, along with an underscore.
         */
        const std::string SORTED_DIR = "sorted";

        /**
         * @brief A regex pattern for grouping different file formats for building the path to the
         * needed sorted file.
         * 
         * @paragraph png files don't have a standard way of storing dates, so they are in their own
         * category. jpgs have a standard way of storing dates, so they are handled separately.
         * video files don't have a standard way of storing dates either, so they are all handled
         * together, similarly to how pngs are handled.
         */
        const std::string EXTENSION_PATTERN = "(png)|(jpg|jpeg)|(mov|mp4|gif)";

    //FIELDS
    private:
        /**
         * @brief The root path to sort
         */
        std::string root;

        /**
         * @brief The name of the directory to sort into
         * 
         */
        std::string sortedDirName;

        /**
         * @brief Whether to sort the files by years or by months
         */
        SortType sortType;

        /**
         * @brief Whether to move the files or copy the files. copying is the safer route, but
         * temporarily takes up more space
         */
        TransferType transferType;

        
    //CONSTRUCTORS
    public:
        /**
         * @brief Construct a new File Sorter object
         */
        FileSorter();

        /**
         * @brief Construct a new File Sorter object with the root path given
         * 
         * @param rootPath The root path to search through
         */
        FileSorter(std::string rootPath);

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
         * 
         * @param root The root path given. defaults to an empty string, and will be initialized
         * throughout the method execution.
         */
        void initProgramDetails(std::string root);

        /**
         * @brief gets the sorted directory name, and sets it in the field above.
         * 
         */
        void getSortedDirName();

        /**
         * @brief Handles retrieving the sort type from the user
         * 
         * @return SortType The Sort type chosen
         */
        SortType handleSortType();

        /**
         * @brief Displays the sort type menu, allowing the user to choose between the options
         * 
         */
        void displaySortTypeMenu();

        /**
         * @brief Get the SortType Chosen by the user 
         * 
         * @return SortType The SortType chosen by the user.
         */
        SortType getSortTypeChosen();


        /**
         * @brief Handles retrieving the transfer type from the user
         * 
         * @return TransferType The Transfer type chosen
         */
        TransferType handleTransferType();

        /**
         * @brief Displays the transfer type menu, allowing the user to choose between the options
         * 
         */
        void displayTransferTypeMenu();

        /**
         * @brief Get the TransferType Chosen by the user 
         * 
         * @return TransferType The TransferType chosen by the user.
         */
        TransferType getTransferTypeChosen();


        /**
         * @brief Sorts the list of files found. Sorts them based on the sort type chosen by the
         * user
         * 
         * @param files A pointer to a vector of the files to be sorted.
         * 
         * @return int 0 if all good, 1 if not.
         */
        int sortFiles(std::vector<std::string>* files);

        /**
         * @brief Tests to see if the filename already exists. if it does, it appends a number to
         * the end of the file name, and tries again
         * 
         * @param fileName The file name to validate
         */
        void getValidFileName(std::string &fileName);
    };

}

