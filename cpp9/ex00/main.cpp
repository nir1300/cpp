#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::map<std::string, float> data;
    create_map(data);
    // print map
    // std::map<std::string, float>::iterator it;
    // for (it = data.begin(); it != data.end(); it++)
    // {
    //     std::cout << it->first << ": " << it->second << std::endl;
    // }
    find_exchange_rate(argv, data);
}