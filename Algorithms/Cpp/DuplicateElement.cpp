#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// given a array in which one element is more than one times and others are only once. Find that duplicate element.

int findDuplicate(vector<int>& a) {
    unordered_map<int ,int > m;
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    int x;
    // Hashing Using 
    unordered_map<int ,int >:: iterator it;
    for(it = m.begin();it!=m.end();it++){
        if(it->second != 1){
        x = it->first;
        }
    }
    return x;
}

// Main Function 
int main()
{
    int n,k; 
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<findDuplicate(v)<<endl;

    return 0;   
}




