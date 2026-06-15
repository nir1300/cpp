#include "Span.hpp"

int main()
{
    {
        std::cout << " <<<< main from subject >>>>" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << " <<<< 5 numbers >>>>" << std::endl;
        Span sp = Span(5);
        try {
            sp.addNumber(-6);
            sp.addNumber(-5);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << " <<<< 15.000 numbers >>>>" << std::endl;
        Span sp = Span(15000);
        try {
            sp.addNumbers(15000);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << " <<<< 1 number >>>>" << std::endl;
        Span sp = Span(1);
        try {
            sp.addNumbers(1);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << " <<<< 2 numbers >>>>" << std::endl;
        Span sp = Span(2);
        try {
            sp.addNumbers(2);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
            sp.addNumber(1);
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << " <<<< 0 numbers >>>>" << std::endl;
        Span sp = Span(0);
        try {
            sp.addNumbers(1);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}