#include "../include/FileObtainer.hpp"
#include "exceptions/DirectoryNotFoundException.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <filesystem>

namespace FileSorterProgram {

    FileObtainer::FileObtainer() {
        this->root = "";
    }

    FileObtainer::FileObtainer(std::string root) {
        if (!std::filesystem::exists(root) && !std::filesystem::is_directory(root)) {
            //root path passed in was not a directory that exists. throw an error, and alert the user
            //to try again.
            throw new Exceptions::DirectoryNotFoundException(root);
        }
        
        //all is good, set the root and move on.

        //set the root field to the value passed in
        this->root = root;
    }

    std::vector<std::string> FileObtainer::getFilesNotRecursive() {
        
        //ensure the root path is good
        if (!std::filesystem::exists(this->root) && !std::filesystem::is_directory(this->root)) {
            throw new Exceptions::DirectoryNotFoundException(root);
        }
        
        //the aim for this is to pull out all of the files in a given directory and add them to the
        //list
        std::vector<std::string> filesFound;

        std::stack<std::string> directoriesToSearch;

        //push the root directory into the stack
        directoriesToSearch.push(this->root);

        //loop through the list of directories to search until the list is empty.
        //this is the point of the program that will take the longest.
        while (!directoriesToSearch.empty())
        {
            //load the next path in from the stack
            std::filesystem::path currentPath { directoriesToSearch.top() };
            
            //remove the path from the stack
            directoriesToSearch.pop();

            try {
                //loop through the items in the current directory.
                for (const auto& item : std::filesystem::directory_iterator(currentPath)) {
                    
                    //check what type the item is, and add it to the correct container.
                    if (item.is_directory()) {
                        //item is a directory. push to the stack.
                        directoriesToSearch.push(item.path().string());
                    } else {
                        //item is a file, push to the list of files found
                        filesFound.push_back(item.path().string());

                        //alert the user that a file was found
                        std::cout << "File Found at Path: " << item.path().string() << std::endl;
                    }
                }
            } catch (const std::filesystem::filesystem_error ex) {
                //display the error to the user
                std::cerr << "Error accessing " << currentPath << ": " << ex.what() << std::endl;
                throw ex;
            }
        }
        

        return filesFound;
    }

}

