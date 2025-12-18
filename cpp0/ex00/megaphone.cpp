#include <iostream>
#include <cctype>

int main (int argc, char *argv[])
{
    int i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            std::string s = argv[i];
            for (size_t j = 0; j < s.length(); j++)
                std::cout << (char)toupper(argv[i][j]);
            i++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return 0;
}