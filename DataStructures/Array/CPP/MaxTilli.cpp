#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
        cout<<mx<<endl;
    }
}