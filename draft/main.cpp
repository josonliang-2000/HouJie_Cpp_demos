#include <iostream>
#include "Complex.h"
#include "String.h"
using namespace std;

int main()
{
    Complex c1;
    Complex c2;
    cout << (c1 == c2) << endl;
    cout << (c1 == 0) << endl;
    cout << (5 == c1) << endl;
}

