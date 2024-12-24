
#include <iostream>
#include <windows.h>
#include <filesystem>
#include <string>
#include <sstream>
#include <tuple>
#include <chrono>
#include <iomanip>
#include "../../include/PathBuilders/VideoBuilder.hpp"
#include "../../include/Enums.hpp"
#include "../../include/utilities/Helper.hpp"

namespace FileSorterProgram::PathBuilders {
    VideoBuilder::VideoBuilder(std::string sortedDir) {
        this->sortedDir = sortedDir;
    }

    VideoBuilder::~VideoBuilder() {  }

    std::string VideoBuilder::buildPath(std::string file, SortType sortType) {
        //build the file path by getting the last modified time.
        auto creationTime { getCreationDate(file) };

        //pull out the year and month
        int year { std::get<0>(creationTime) };
        int month { std::get<1>(creationTime) };

        //if the parse was invalid, then return from the function, and move onto the next file
        if (year + month == -2) {
            std::cerr << "An error occured while trying to open the file " << file << " "
                << GetLastError() << std::endl;
            return;
        }

        //build the directory that this file will be sorted into
        
        //build the year. it will always be there.
        std::string dirPath = (std::filesystem::path(this->sortedDir) /
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


        //return the build path.
        return dirPath;
    }

    std::tuple<int, int> VideoBuilder::getCreationDate(std::string file) {
        
        //check if the file exists
        if (!std::filesystem::exists(file)) {
            return std::make_tuple(-1, -1);
        }

        //get the last write time of the file
        std::filesystem::file_time_type lastWriteTimeFTime = std::filesystem::last_write_time(file);

        auto systemTime = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            lastWriteTimeFTime - std::filesystem::file_time_type::clock::now() +
            std::chrono::system_clock::now());

        auto lastWriteTime = std::chrono::system_clock::to_time_t(systemTime);
        auto localLastWriteTime = *std::localtime(&lastWriteTime);

        //get the year. the tm_year is apparently the years since 1900
        int year = localLastWriteTime.tm_year + 1900;

        //get the month + 1. The months should not be zero based.
        int month = localLastWriteTime.tm_mon + 1;

        return std::make_tuple(year, month);
        
    }
}
