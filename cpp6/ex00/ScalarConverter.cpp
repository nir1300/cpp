#include "ScalarConverter.hpp"
// #include <ctype.h>
// #include <cctype>
#include <cstdlib>
#include <iomanip> // for decimal printing
#include <limits>
#include <climits>


void ScalarConverter::toChar(std::string str)
{
    char c = str[0];
    std::cout << "char: " << c << std::endl; 
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1); // for fixed/poinnt notation and decimal precision
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

bool ScalarConverter::isInt(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (i == 0 && (str[0] == '+' || str[0] == '-'))
            continue;
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}


void ScalarConverter::toInt(std::string str, long num) 
{
    // check: only digits, optional + -
    if (num < INT_MIN || num > INT_MAX)
        std::cout << "char: impossible\nint: overflow or underflow\nfloat: impossible\ndouble: impossible" << std::endl;
    else
    {
        int c = atoi(str.c_str());
        if (isPseudoLiteral(str))
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(c))
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << c << std::endl; 
        std::cout << std::fixed << std::setprecision(1); // for fixed/poinnt notation and decimal precision
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
}

bool ScalarConverter::isFloat(std::string str)
{
    // check: digits, one dot, f at end
    if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
        return true;
    bool dot = false;
    for (size_t i = 0; i < str.length() - 1; i++)
    {
        if (!std::isdigit(str[i]))
        {
            if (i == 0 && (str[0] == '+' || str[0] == '-'))
                continue;
            if (str[i] == '.' && dot == false)
                dot = true;
            else
                return false;
        } 
    }
    if (str[str.length() - 1] != 'f' || !dot)
        return false;
    return true;
}

bool ScalarConverter::isPseudoLiteral(std::string str)
{
    return (str == "-inf" || str == "+inf" || str == "inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "inff" || str == "nanf");
}

// doesnt print overflow for int? just impossible
void ScalarConverter::toFloat(std::string str, double num)
{
    // didnt use min() -> returns smallest positive number
    if (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
        std::cout << "char: impossible\nint: impossible\nfloat: overflow or underflow\ndouble: impossible" << std::endl;
    else
    {
        int digitAfterDecimal = -1;
        bool dotSeen = false;
        for (size_t i = 0; i < str.length() - 1; i++)
        {
            if (str[i] == '.')
                dotSeen = true;
            if (dotSeen)
                digitAfterDecimal++;
        }
        if (digitAfterDecimal == 0)
            digitAfterDecimal++;
        float c = std::atof(str.c_str()); // converts to float
        if (isPseudoLiteral(str) || c < 0 || c > 127) // isprint might segfault for extremely large num -> 0/127 check before 
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(c))
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (num < INT_MIN || num > INT_MAX || isPseudoLiteral(str))
            std::cout << "!!int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(c) << std::endl; 
        std::cout << std::fixed << std::setprecision(digitAfterDecimal); // for fixed/poinnt notation and decimal precision
        std::cout << "float: " << c << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
}

bool ScalarConverter::isDouble(std::string str)
{
    // check: digits, one dot
    if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
        return true;
    bool dot = false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
        {
            if (i == 0 && (str[0] == '+' || str[0] == '-'))
                continue;
            if (str[i] == '.' && dot == false)
                dot = true;
            else
                return false;
        } 
    }
    return true;
}

void ScalarConverter::toDouble(std::string str, double num)
{
    if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: overflow or underflow" << std::endl;
    else
    {
        int digitAfterDecimal = 0;
        bool dotSeen = false;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (dotSeen)
                digitAfterDecimal++;
            if (str[i] == '.')
                dotSeen = true;
        }
        if (digitAfterDecimal == 0)
            digitAfterDecimal++;
        double c = std::atof(str.c_str());
        if (isPseudoLiteral(str) || c < 0 || c > 127) // isprint might segfault for extremely large num -> 0/127 check before 
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(static_cast<int>(c)))
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (num < INT_MIN || num > INT_MAX || isPseudoLiteral(str))
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(c) << std::endl; 
        std::cout << std::fixed << std::setprecision(digitAfterDecimal); // for fixed/poinnt notation and decimal precision
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << c << std::endl;
    }
}

void ScalarConverter::convert(std::string const & str)
{
    if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0]))
        return(toChar(str));
    else if (isInt(str))
        return(toInt(str, strtol(str.c_str(), NULL, 10))); // pass strol (long) to do overflow checks etc
    else if (isFloat(str))
        return(toFloat(str, strtof(str.c_str(), NULL)));
    else if (isDouble(str))
        return(toDouble(str, strtod(str.c_str(), NULL)));
    else
        std::cout << "Represents no known type: No conversion possible" << std::endl;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}