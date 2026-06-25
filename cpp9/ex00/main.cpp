#include "BitcoinExchange.hpp"
#include <string>
#include <iomanip>
#include <time.h>

void create_map(std::map<std::string, float>& data)
{
    std::ifstream dataFile("data.csv");
    if (!dataFile)
    {
        std::cerr << "Error: could not open exchange rate data file." << std::endl;
        exit(1);
    }
    std::string line;
    std::string sub1;
    std::string sub2;
    std::getline(dataFile, line); // skip first line
    // std::cout << std::fixed << std::setprecision(4);
    while (std::getline(dataFile, line, '\n'))
    {
        int pos = line.find(",");
        sub1 = line.substr(0,pos);
        sub2 = line.substr(pos+1);
        data.insert(std::make_pair(sub1, std::strtof(sub2.c_str(), NULL)));
    }

}

bool validDate(std::string date)
{
    if (date < "2009-01-02" || date[4] != '-' || date[7] != '-' || date.length() != 10)
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(date[i]))
            return false;
    }
    int year = atoi(date.substr(0,4).c_str());
    int month = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8).c_str());
    if (month > 12 || day <= 0 || month <= 0 || 
        (month == 2 && year % 4 != 0 && day > 28))
        return false;
    int daysPerMonth[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    return (day <= daysPerMonth[month - 1]);
}

bool validValue(float value)
{
    if (value > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return false;
    }
    else if (value < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }
    return true;
}

int find_exchange_rate(char **argv, std::map<std::string, float>& data)
{
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return(1);
    }
    std::string line;
    std::string date;
    float value;
    // std::cout << std::fixed << std::setprecision(4);
    std::getline(inputFile, line); // skip first line
    if (line != "date | value")
    {
        std::cerr << "Error: first line must be 'date | value'" << std::endl;
        return(1);
    }
    // std::cout << std::fixed << std::setprecision(4);
    while (std::getline(inputFile, line, '\n'))
    {
        int pos = line.find(" | ");
        if (pos < 0)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = line.substr(0,pos);
        value = std::strtof(line.substr(pos+3).c_str(), NULL);
        if (!validValue(value))
            continue;
        else if (!validDate(date))
        {
            std::cout << "Error: invalid date" << std::endl;
            continue;
        }
        else
        {
            std::map<std::string,float>::iterator it = data.lower_bound(date);
            if (it == data.end() || it->first != date)
                it--;
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        }
    }
    return 0;
}

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