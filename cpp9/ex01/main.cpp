#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (!errorHandling(argc, argv))
        return 1;
    std::string arg = argv[1];
    std::stack<int> st;
    return(executeRPN(arg, st));

}
