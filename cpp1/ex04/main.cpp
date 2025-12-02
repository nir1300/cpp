#include "sed.h"

// to-do; create tests

int main(int argc, char **argv)
{
    if (argc != 4 ) // check filename and strings?
    {
        std::cout << "Invalid argument number (must be filename and 2 strings)" << std::endl;
        return 1;
    }
    std::string newFile = std::string(argv[1]) + ".replace";
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cout << "Input file could not be opened" << std::endl;
        return 1;
    }
    std::ofstream replaceFile(newFile.c_str());
    if (!replaceFile)
    {
        std::cout << "Input file could not be opened" << std::endl;
        return 1;
    }
    std::string line;
    
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(argv[2], pos)) != std::string::npos)
        {
            line.erase(pos, strlen(argv[2]));
            line.insert(pos, argv[3]);
            pos += strlen(argv[3]);
        }
        replaceFile << line << std::endl;
    }
    return 0;
}