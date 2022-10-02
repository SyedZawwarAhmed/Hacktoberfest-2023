#include <iostream>

using namespace std;

int main(){
    int number;
    cout << "Type a number:- ";
    cin >> number;
    int remainder =  number % 3;
    if (remainder == 0){
        cout << "fizz";
    } 
    remainder = number % 5;
    if (remainder == 0){
        cout << "buzz";
    } 
    cout << endl;
return 0;
}