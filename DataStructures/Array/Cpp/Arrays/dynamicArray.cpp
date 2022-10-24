#include <iostream>
using namespace std;

int main()
{
    int n;
    int *ptr;
    int *arr = new int(n);

    cout << "Enter the size of array :";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the "<<(i+1)<<" element in array :";
        cin >> arr[i];
    }

    //printing the address of the elements in the array.
    for (int i = 0; i < n; i++)
    {
        ptr = &arr[i];
        cout << ptr<<"\n";
    }
};
