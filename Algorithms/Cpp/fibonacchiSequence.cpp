#include <iostream>
using namespace std;

void fib(int l)
{
    // Initial first 3 sequence
    cout << "0 1 1 ";

    // minus 3 because already printed first 3 value
    l-=3;

    // initialize first two value for summation
    int a = 1;
    int b = 1;
    int sum = 0;

    //then continue fibonacchi sequence
    while(l--)
    {
        sum = a+b;
        cout << sum << " ";
        a = b;
        b = sum;
    }

}


int main()
{
    // Take input for length of Fibonacchi Sequence
    int length; cin >> length;
    fib(length);
    return 0;
}