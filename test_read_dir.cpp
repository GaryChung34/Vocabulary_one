#include <string>
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
    std::string path = "/book/";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}