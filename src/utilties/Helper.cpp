
#include <filesystem>
#include "../../include/utilities/Helper.hpp"
#include "../../include/Enums.hpp"

namespace FileSorterProgram::utilities {

    Helper::Helper() {  }
    Helper::~Helper() {  }

    std::string Helper::getMonthString(Months month) {
        //return the month corresponding to the value of the enum provided
        switch (month) {
        case Months::January:
            return "January";
        case Months::February:
            return "February";
        case Months::March:
            return "March";
        case Months::April:
            return "April";
        case Months::May:
            return "May";
        case Months::June:
            return "June";
        case Months::July:
            return "July";
        case Months::August:
            return "August";
        case Months::September:
            return "September";
        case Months::October:
            return "October";
        case Months::November:
            return "November";
        case Months::December:
            return "December";
        default:
            return "Unknown";
        }
    }

    void Helper::createDirectoryIfNotExists(std::string directory) {
        //create the directory if it can't be found
        if (!std::filesystem::exists(directory) && !std::filesystem::is_directory(directory)) {
            std::filesystem::create_directory(directory);
        }
    }

}
