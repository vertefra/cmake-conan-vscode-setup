#include<iostream>
#include "../include/Fake.hpp"

using namespace std;

Fake::Fake()
{
    cout << "Fake constructor" << endl;
}

void Fake::doSomething()
{
    cout << "Fake doSomething" << endl;
}