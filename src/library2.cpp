#include "library2.hpp"
#include <iostream>

using namespace std;

void print_value3( int x )
{
    cout << "function 3::" << x*3 << "\n";
}

void print_value4( int x ) 
{
     cout << "function 4::" << x*4 << "\n";
     cout << "function 7::" << x*7 << "\n";
     cout << "=======" << endl;
}