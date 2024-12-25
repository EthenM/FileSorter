
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <string>
#include <sstream>
#include <tuple>
#include "../../include/PathBuilders/JPGBuilder.hpp"
#include "../../include/Enums.hpp"
#include "../../include/utilities/Helper.hpp"
#include "../../external/exif/include/exif.h"

namespace FileSorterProgram::PathBuilders {
    JPGBuilder::JPGBuilder(std::string sortedDir) {
        this->sortedDir = sortedDir;
    }

    JPGBuilder::~JPGBuilder() {  }

    std::string JPGBuilder::buildPath(std::string file, SortType sortType) {
        //build the file path, by extracting out the metadata and finding the original date tag.

        auto creationTime { getCreationDate(file) };

        //pull out the year and month
        int year { std::get<0>(creationTime) };
        int month { std::get<1>(creationTime) };

        //if the parse was invalid, then return from the function, and move onto the next file
        if (year + month == -2) {
            std::cerr << "An error occured while trying to open the file " << file << " "
                << GetLastError() << std::endl;
            return "";
        }


        //build the directory that this file will be sorted into
        std::string dirPath = "";
        
        if (year + month == -4) {
            //no date stored, store this in an unsortable path.
            dirPath = (std::filesystem::path(this->sortedDir) /
                std::filesystem::path(utilities::Helper::UNSORTABLE_DIR))
                .string();

            //finally create the unsortable if it doesn't exist
            utilities::Helper::createDirectoryIfNotExists(dirPath);
        } else {
            //build the year. it will always be there.
            dirPath = (std::filesystem::path(this->sortedDir) /
                std::filesystem::path(std::to_string(year))).string();

            //create the year directory if it doesn't already exist
            utilities::Helper::createDirectoryIfNotExists(dirPath);

            //if the month is needed, add the month
            if (sortType == SortType::Month) {
                dirPath = (std::filesystem::path(dirPath) / std::filesystem::path(
                    utilities::Helper::getMonthString(static_cast<Months>(month)))).string();

                //create the month directory if it doesn't already exist
                utilities::Helper::createDirectoryIfNotExists(dirPath);
            }
        }

        


        //return the build path.
        return dirPath;
    }

    std::tuple<int, int> JPGBuilder::getCreationDate(std::string file) {
        //pull out the creation date. this will be the spot to pull out the exif data.

        FILE *jpgImg = fopen(file.c_str(), "rb");

        //if the image failed to load, report to the user, and skip this file
        if (!jpgImg) {
            std::cerr << "An error occured while opening " << file << " " << GetLastError()
                << std::endl;
            
            return std::make_tuple(-1, -1);
        }

        //navigate to the end of the file, to get the length of data to read from
        fseek(jpgImg, 0, SEEK_END);

        //get the size of the file, and rewind the file to the beginning.
        unsigned long fileSize = ftell(jpgImg);
        rewind(jpgImg);

        //build a character array the same size as the file. return from the method if the
        //read amount of bytes does not equal the fileSize.
        unsigned char *buf = new unsigned char[fileSize];
        if (fread(buf, 1, fileSize, jpgImg) != fileSize) {
            std::cout << "Can't read file." << std::endl;
            delete[] buf;
            return std::make_tuple(-1, -1);
        }

        //close the file
        fclose(jpgImg);

        // Parse EXIF
        easyexif::EXIFInfo result;

        //parse the buffer for the data given
        int code = result.parseFrom(buf, fileSize);
        
        //remove the buffer. it's no longer needed.
        delete[] buf;

        //if there was an error, return from the method.
        if (code) {
            std::cout << "Error parsing EXIF data: code " << code << std::endl;
            return std::make_tuple(-1, -1);
        }

        //lastly, return the year and month the photo was taken.
        std::stringstream dateString(result.DateTimeOriginal);
        int year, month;
        char colon;
        
        if (result.DateTimeOriginal.length() == 0) {
            //there is no date stored
            return std::make_tuple(-2, -2);
        }

        //parse the date string to the variables declared above
        dateString >> year >> colon >> month;

        //if the parse worked, return the year and month. if not, return -1.
        if (dateString && colon == ':') {
            return std::make_tuple(year, month);
        } else {
            std::cerr << "ERROR: could not extract year and month from file " << file << std::endl;
            return std::make_tuple(-1, -1);
        }
    }
}
