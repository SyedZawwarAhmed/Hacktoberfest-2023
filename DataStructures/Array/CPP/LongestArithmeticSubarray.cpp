#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=1;
    int prevSum[n]={-1};
    int d;
    for(int i=1;i<n;++i){
        d=abs(arr[i]-arr[i-1]);
        if(prevSum[i-1]==d){
            l++;
        }
        else{
            l=1;
        }
        d=abs(arr[i]-arr[i-1]);
        prevSum[i]=d;
    }
    cout<<l<<endl;
}