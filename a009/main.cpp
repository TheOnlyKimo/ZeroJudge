#include <iostream>

using namespace std;

int main()
{
    char c;

    while (cin >> c) {
        cout << char(c - 7);
    }
    return 0;
}
