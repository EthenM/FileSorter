#include <iostream>
#include "../include/FileSorter.hpp"

/**
 * FileSorter:
 * 
 * This is meant to take in a root directory. for the sake of making this as easy as possible,
 * The file will be inputted during program execution, not from the command line.
 * 
 * This will then take the root directory, and find all the files within the directory.
 * 
 * It will then ask for the time span for the directories (either years or months)
 * 
 * Once the files have been found, it will move/copy them over to files split based on how the user
 * wishes (by year or month)
 * 
 */

/** */
int main(int argc, char* argv[]) {

    std::cout << "Running program on root: " << argv[1] << std::endl;

    //pass in the second argument. the first is the path to the command. The second will be the
    //root path.
    FileSorterProgram::FileSorter fs { std::string(argv[1]) };
    int success { fs.run() };

    //ensure the program doesn't close on the user.
    std::cout << "\n\nPress enter to continue...";
    std::cin.ignore().get();

    return success;
}
