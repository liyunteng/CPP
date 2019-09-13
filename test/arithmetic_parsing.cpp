// arithmetic_parsing.cpp - arithmetic_parsing

#include <cmath>
#include <iostream>
#include <cstdlib>
#include "arithmetic_parsing.hpp"
using namespace std;


int parser::find_sub(const string input)
{
    string::size_type idx = 0, len = input.length();
    int level = 0;
    if (len <= 0) {
        return 0;
    }

    for (; idx < len; idx++) {
        switch (input[idx]) {
        case prefix:
            level++;
            break;
        case suffix:
            level--;
            break;
        }
    }
}

float parser::eval(const string input)
{

}

int main(void)
{
    string input = "1 + 2";
    cout << eval(input) << endl;
    return 0;
}
