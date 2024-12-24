
#include "../include/FileSorter.hpp"
#include "../include/FileObtainer.hpp"
#include "../include/Enums.hpp"
#include "../include/utilities/Helper.hpp"
#include "../include/PathBuilders/PathBuilder.hpp"
#include "exceptions/DirectoryNotFoundException.cpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <filesystem>
#include <windows.h>

namespace FileSorterProgram {

    FileSorter::FileSorter() {
        //send the program off to the initialized
        this->initProgramDetails("");
    }

    FileSorter::FileSorter(std::string rootPath) {
        this->initProgramDetails(rootPath);
    }

    int FileSorter::run() {
        //first up, get a list of the files within the directory that are needing to be sorted.
        
        //initialize the obtainer
        FileObtainer obtainer = FileObtainer();

        std::cout << this->root << std::endl;

        try {
            //attempt to make the initialization
            obtainer = FileObtainer(this->root);
        } catch (Exceptions::DirectoryNotFoundException ex) {
            //the directory was unable to be located. alert the user and exit the program.
            std::cerr << "ERROR: the root directory could not be found: " << ex.what() << std::endl;
            return 1;
        }

        //go and fetch the list of files to be sorted.
        //This is what is going to take the longest.
        std::vector<std::string> files { obtainer.getFilesNotRecursive() };

        //take the list of files and sort them.
        int success { this->sortFiles(&files) };

        return success;
    }

    #pragma region initProgramDetails

    void FileSorter::initProgramDetails(std::string root="") {

        //initializing the program. This needs three main things: the root path, the sort type
        //and the transfer type.
        
        //first up, read in the root path
        std::string rootPath { root };

        //only ask for the root path if it's not given.
        if (rootPath == "") {
            //ask the user for the root path
            std::cout << "Enter the root path (the folder to start in): ";
            std::cin >> rootPath;
        }

        //get the sorted directory name


        //next, ask the user for the sort type
        SortType sortType { handleSortType() };

        std::cout << std::endl;

        TransferType transferType { handleTransferType() };
        
        //add the two values to the fields in the object
        this->root = rootPath;
        this->sortType = sortType;
        this->transerType = transerType;
    }

    void FileSorter::getSortedDirName() {
        //pull out the parent directory to the root dir
        if (std::filesystem::path(this->root).has_parent_path()) {
            std::string parent = std::filesystem::path(this->root).parent_path().string();

            //get the sorted dir name. this will end up being a sibling to the root.
            std::string sortedDir = std::filesystem::path(this->root).stem().string() + "_" +
                SORTED_DIR;

            //create the sorted dir name, and store it
            this->sortedDirName = (std::filesystem::path(parent) / std::filesystem::path(sortedDir))
                .string();
        } else {
            //the sorted dir will just be under the root, rather than a sibling.
            std::string sortedDir = std::filesystem::path(this->root).stem().string() + "_" +
                SORTED_DIR;
            
            //create the sorted dir name, and store it
            this->sortedDirName = (std::filesystem::path(this->root) / 
                std::filesystem::path(sortedDir)).string();
        }

        utilities::Helper::createDirectoryIfNotExists(this->sortedDirName);
    }


    SortType FileSorter::handleSortType() {
        //start by displaying the menu
        displaySortTypeMenu();

        //initialize the sort type
        SortType sortType { getSortTypeChosen() };
        
        //loop the question until the input is valid
        while (sortType == SortType::Unknown) {
            std::cout << "Sort type chosen was invalid. please try again.\n" << std::endl;

            //display the sort menu to the user
            displaySortTypeMenu();

            //ask for the input, and convert it into the sort type
            sortType = getSortTypeChosen();
        }

        //return the sort type
        return sortType;
    }

    void FileSorter::displaySortTypeMenu() {
        std::cout << "How would you like the files to be sorted (placed in folders by):\n"
            << "1: Years\n"
            << "2: Months\n"
            << "Input the number for the desired sort type above and hit enter: ";
    }

    SortType FileSorter::getSortTypeChosen() {
        int userInput;
        std::cin >> userInput;

        SortType sortType = static_cast<SortType>(userInput);

        switch (sortType) {
        case SortType::Year:
            return SortType::Year;
            break;
        case SortType::Month:
            return SortType::Month;
            break;
        default:
            return SortType::Unknown;
            break;
        }
    }


    TransferType FileSorter::handleTransferType() {
        //start by displaying the menu
        displayTransferTypeMenu();

        //initialize the sort type
        TransferType transferType { getTransferTypeChosen() };
        
        //loop the question until the input is valid
        while (transferType == TransferType::Unknown) {
            std::cout << "Transfer type chosen was invalid. please try again.\n" << std::endl;

            //display the sort menu to the user
            displayTransferTypeMenu();

            //ask for the input, and convert it into the sort type
            transferType = getTransferTypeChosen();

        }

        return transferType;
    }

    void FileSorter::displayTransferTypeMenu() {
        std::cout << "How would you like the files to be transferred:\n"
            << "1: Move\n"
            << "2: Copy\n"
            << "Input the number for the desired transfer type above and hit enter: ";
    }

    TransferType FileSorter::getTransferTypeChosen() {
        int userInput;
        std::cin >> userInput;

        TransferType transferType = static_cast<TransferType>(userInput);

        switch (transferType) {
        case TransferType::Move:
            return TransferType::Move;
            break;
        case TransferType::Copy:
            return TransferType::Copy;
            break;
        default:
            return TransferType::Unknown;
            break;
        }
    }

    #pragma endregion

    int FileSorter::sortFiles(std::vector<std::string>* files) {
        //file sorting will happen here. this is the last part to the application. We take the files
        //from in the pointer, and add them to a directory, based on their creation time,
        //and the sort type chosen.

        //If the user wanted it sorted by year, just throw it into the directory of the
        //corresponding year.

        //If the user wanted it sorted by month, then throw it into the directory of the month, of
        //the corresponding year.

        //check if the sorted folder is already created in the 

        for (int i = 0; i < files->size(); i++) {
            std::string file { (*files)[i] };

            //check if the file exists and it is not a directory
            if (std::filesystem::exists(file) && !std::filesystem::is_directory(file)) {
                
                //build the dir path, depending on the extension of the file.
                std::string dirPath { "" };

                //run the extension of the file on a regex function, to get the path builder needed
                PathBuilders::PathBuilder* pathBuilder;

                //here, determine the type of PathBuilder needed.

                dirPath = pathBuilder->buildPath(file, this->sortType);

                //here, move or copy the file to the dirPath
                
                //add the filename to the path
                std::filesystem::path filePath = file;
                std::string fileName = filePath.filename().string();
                dirPath = (std::filesystem::path(dirPath) / std::filesystem::path(fileName))
                    .string();

                //get a valid file path (ensure no duplicate files)
                getValidFileName(dirPath);

                std::cout << dirPath << std::endl;

                // switch (this->transerType) {
                // case TransferType::Move:

                //     //attempt to move the file.
                //     try {
                //         std::filesystem::rename(file, dirPath);
                //         std::cout << file + " Has been moved successfully!" << std::endl;
                //     } catch (const std::filesystem::filesystem_error& ex) {
                //         std::cerr << "Error moving file: " << ex.what() << std::endl;
                //     }

                //     break;
                // case TransferType::Copy:
                    
                //     //attempt to copy the file.
                //     try {
                //         std::filesystem::copy(file, dirPath,
                //             std::filesystem::copy_options::overwrite_existing);    
                //         std::cout << file << " successfully copied to " + dirPath << std::endl;
                //     } catch (const std::filesystem::filesystem_error& ex) {
                //         std::cerr << "Error copying file: " << ex.what() << std::endl;
                //     }
                    
                //     break;
                // }
            }
        }

        return 1;
    }

    void FileSorter::getValidFileName(std::string &fileName) {
        if (!std::filesystem::exists(fileName)) {
            //file name is good, return from the function
            return;
        }

        //file name already exists. go ahead and append a number to it and try again.
        int i = 1;

        std::filesystem::path filePath = fileName;

        //build the new file name
        std::string fileNameNoExtension = filePath.stem().string();
        fileNameNoExtension += "_" + std::to_string(i);
        fileNameNoExtension += filePath.extension().string();

        //loop through, increasing the number appended by one, until a valid name is found.
        while (std::filesystem::exists(fileNameNoExtension)) {
            //increment the counter
            i++;

            //rebuild the file name
            fileNameNoExtension = filePath.stem().string();
            fileNameNoExtension += "_" + std::to_string(i);
            fileNameNoExtension += filePath.extension().string();
        }

        fileName = filePath.parent_path().string() + "\\" + fileNameNoExtension;
    }
}
