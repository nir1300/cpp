#include "sed.hpp"


std::string replace(std::string line, std::string s1, std::string s2)
{
    size_t pos = 0;
    if (s1.empty())
        return (line);
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    return (line);
}


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Invalid argument number (must be filename and 2 strings)" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cout << "s1 cannot be empty string" << std::endl; //otherwise endless loop when calling .find()
        return 1;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cout << "Input file could not be opened or doesn't exist" << std::endl;
        return 1;
    }
    // check if empty
    inputFile.seekg(0, inputFile.end);
    if (inputFile.tellg() == 0)
    {
        std::cout << "Input file is empty" << std::endl;
        return 1;
    }
    inputFile.seekg(0, inputFile.beg);
    std::string newFile = std::string(argv[1]) + ".replace";
    std::ofstream replaceFile(newFile.c_str());
    if (!replaceFile)
    {
        std::cout << "Replace file could not be opened" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        replaceFile << replace(line, s1, s2);
        if (!inputFile.eof())
            replaceFile << std::endl;
    }
    return 0;
}