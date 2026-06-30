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