#include "RPN.hpp"

bool isOperator(char c)
{
    return (c == '/' || c == '*' || c == '+' || c== '-');
}

int doOperation(char c, std::stack<int>& st)
{
    int tmp = st.top();
    st.pop();
    if (c == '+')
        st.top() += tmp;
    else if (c == '-')
        st.top() -= tmp;
    else if (c == '*')
        st.top() *= tmp;
    else if (c == '/')
    {
        if (tmp == 0)
            return(1);
        st.top() /= tmp;
    }
    return(0);
}

bool errorHandling(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error (only 1 argument allowed)" << std::endl;
        return false;
    }
    std::string arg = argv[1];
    for (size_t i = 0; i < arg.size(); i++)
    {
        if ((arg[i] != '/' && arg[i] != '*' && arg[i] != '+' && arg[i] != '-' && arg[i] != ' ' && !std::isdigit(arg[i])) || (std::isdigit(arg[i]) && arg[i+1] && arg[i+1] != ' '))
        {
            std::cerr << "Error (invalid equation)" << std::endl;
            return false;
        }
    }
    return true;
}

int executeRPN(std::string arg, std::stack<int> st)
{
    // create stack
    // -> when operand is found, do operation with those 2 nums
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
                std::cerr << "Error (invalid equation)" << std::endl;
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
        std::cerr << "Error (invalid equation)" << std::endl;
        return 1;
    }  
    std::cout << st.top() << std::endl;
    return 0;
}