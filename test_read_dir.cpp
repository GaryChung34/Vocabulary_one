#include <string>
#include <iostream>
#include <filesystem>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main()
{
    std::string path = "/path/to/directory";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}