#include <bits/stdc++.h>

using namespace std;

int puke(string a)
{
    if (a == "10")
        return 1;
    if (a == "J")
        return 2;
    if (a == "Q")
        return 3;
    if (a == "K")
        return 4;
    if (a == "A")
        return 5;
    if (a == "2")
        return 6;
    if (a == "Joker")
        return 7;
    return 0;
}

int main()
{
    string a, b;
    cin >> a >> b;
    if (puke(a) > puke(b))
    {
        cout << "First";
    }
    else if (a == b)
    {
        cout << "Equal";
    }
    else
    {
        cout << "Second";
    }
    return 0;
}