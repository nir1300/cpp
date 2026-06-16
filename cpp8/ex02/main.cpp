#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "----- test subject main -----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack); // tests implicit conversion from MutantStack to std::stack
    }
    {
        std::cout << "----- compare test subject main with list -----" << std::endl;
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        //[...]
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        // std::stack<int> s(mlist);
    }

    {
        std::cout << "----- test normal iterator -----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        std::cout << "top: " << mstack.top() << std::endl;
        std::cout << "pop top" << std::endl;
        mstack.pop();
        std::cout << "size:" << mstack.size() << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "----- test const -----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        std::cout << "top: " << mstack.top() << std::endl;
        std::cout << "pop top" << std::endl;
        mstack.pop();
        std::cout << "size:" << mstack.size() << std::endl;
        MutantStack<int>::const_iterator it = mstack.begin();
        MutantStack<int>::const_iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "----- test reverse -----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        std::cout << "top: " << mstack.top() << std::endl;
        std::cout << "pop top" << std::endl;
        mstack.pop();
        std::cout << "size:" << mstack.size() << std::endl;
        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "----- test const reverse-----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);
        std::cout << "top: " << mstack.top() << std::endl;
        std::cout << "pop top" << std::endl;
        mstack.pop();
        std::cout << "size:" << mstack.size() << std::endl;
        MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator ite = mstack.rend();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
}