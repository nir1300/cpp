#pragma once

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <string>

class ScalarConverter {
    private:
        // static class (only static functions) -> basically utility functions only
        // constructors etc private to prevent instatntiation
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
     
    public:
        // helpers
        static bool isPseudoLiteral(std::string str);
        static void toChar(std::string str);
        static bool isInt(std::string str);
        static void toInt(std::string str, long num);
        static bool isFloat(std::string str);
        static void toFloat(std::string str, float num);
        static bool isDouble(std::string str);
        static void toDouble(std::string str, double num);
        // member function
        static void convert(std::string const & str);
};
#endif