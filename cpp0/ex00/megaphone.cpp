#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[])
{
    int i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            string s = argv[i];
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            cout << s;
            i++;
        }
    }
    else
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    cout << endl;
    return 0;
}