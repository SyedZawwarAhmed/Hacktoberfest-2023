#include <iostream>

using namespace std;

int main()
{

    int number;
    cout << "Type a number to find days:- ";
    cin >> number;
    if (number == 1)
    {
        cout << "MONDAY\n";
    }
    else if (number == 2)
    {
        cout << "TUESDAY\n";
    }
    else if (number == 3)
    {
        cout << "WEDNESDAY\n";
    }
    else if (number == 4)
    {
        cout << "THURSDAY\n";
    }
    else if (number == 5)
    {
        cout << "FRIDAY\n";
    }
    else if (number == 6)
    {
        cout << "SATURDAY\n";
    }
    else if (number == 7)
    {
        cout << "SUNDAY\n";
    }
    else
    {
        cout << "Invalid day\n";
    }
    return 0;
}
