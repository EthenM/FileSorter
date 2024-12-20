#include <iostream>
#include <stdexcept>

namespace FileSorterProgram::Exceptions {

    class DirectoryNotFoundException : public std::runtime_error {
    public:
        DirectoryNotFoundException(const std::string& path)
            : std::runtime_error("Directory not Found: " + path) {}
    };

}
