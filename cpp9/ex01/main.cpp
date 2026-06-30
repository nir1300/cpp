#include "RPN.hpp"




int main(int argc, char **argv)
{
    // error handling
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::string arg = argv[1];
    for (size_t i = 0; i < arg.size(); i++)
    {
        if ((arg[i] != '/' && arg[i] != '*' && arg[i] != '+' && arg[i] != '-' && arg[i] != ' ' && !std::isdigit(arg[i])) || (std::isdigit(arg[i]) && arg[i+1] && arg[i+1] != ' '))
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    
    // create stack: contains 2 nums max
    // -> when operand is found, do operation with those 2 nums
    std::stack<int> st;
    for (size_t i = 0; i < arg.length(); i++)
    {
        if (std::isdigit(arg[i]))
            st.push(arg[i]- '0');
        else if (arg[i] == ' ')
            continue;
        else if (isOperator(arg[i]))
        {
            if (st.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            if (doOperation(arg[i], st))
            {
                std::cerr << "Error (zero division error)" << std::endl;
                return 1;
            }
        }
    }
    // print solution
    if (st.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }  
    std::cout << st.top() << std::endl;
}
