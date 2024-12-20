
#include "../include/FileSorter.hpp"
#include "../include/FileObtainer.hpp"
#include "../include/Enums.hpp"
#include "exceptions/DirectoryNotFoundException.cpp"
#include <iostream>
#include <vector>
#include <string>

namespace FileSorterProgram {

    FileSorter::FileSorter() {
        //send the program off to the initialized
        this->initProgramDetails();
    }

    int FileSorter::run() {
        //first up, get a list of the files within the directory that are needing to be sorted.
        
        //initialize the obtainer
        FileObtainer obtainer { NULL };

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

    void FileSorter::initProgramDetails() {

        //initializing the program. This needs three main things: the root path, the sort type
        //and the transfer type.
        
        //first up, read in the root path
        std::string rootPath;

        //ask the user for the root path
        std::cout << "Enter the root path (the folder to start in): ";
        std::cin >> rootPath;

        //next, ask the user for the sort type
        SortType sortType { handleSortType() };

        TranserType transferType { handleTransferType() };
        
        //add the two values to the fields in the object
        this->root = rootPath;
        this->sortType = sortType;
        this->transerType = transerType;
    }

    SortType handleSortType() {
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

    void displaySortTypeMenu() {
        std::cout << "How would you like the files to be sorted (placed in folders by):\n"
            << "1: Years\n"
            << "2: Months\n"
            << "Input the number for the desired sort type above and hit enter: ";
    }

    SortType getSortTypeChosen() {
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


    TranserType handleTransferType() {
        //start by displaying the menu
        displayTransferTypeMenu();

        //initialize the sort type
        TranserType transferType { getTransferTypeChosen() };
        
        //loop the question until the input is valid
        while (transferType == TranserType::Unknown) {
            std::cout << "Transfer type chosen was invalid. please try again.\n" << std::endl;

            //display the sort menu to the user
            displayTransferTypeMenu();

            //ask for the input, and convert it into the sort type
            transferType = getTransferTypeChosen();

        }
    }

    void displayTransferTypeMenu() {
        std::cout << "How would you like the files to be transferred:\n"
            << "1: Move\n"
            << "2: Copy\n"
            << "Input the number for the desired transfer type above and hit enter: ";
    }

    TranserType getTransferTypeChosen() {
        int userInput;
        std::cin >> userInput;

        TranserType transferType = static_cast<TranserType>(userInput);

        switch (transferType) {
        case TranserType::Move:
            return TranserType::Move;
            break;
        case TranserType::Copy:
            return TranserType::Copy;
            break;
        default:
            return TranserType::Unknown;
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
    }

}
