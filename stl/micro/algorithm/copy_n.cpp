// copy_n.cpp - copy_n

// Date   : 2020/12/11
#include <algorithm>
#include <iostream>
#include <string>

int main(void)
{
    using namespace std;

    string s1{"dandelion"};
    string s2{"badger"};

    cout << s1 << " + " << s2 << " = ";

    copy_n(s1.begin(), 3, s2.begin());


    cout << s2 << endl;
    return 0;
}
