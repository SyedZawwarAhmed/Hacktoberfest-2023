#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int k; cin>>k;
    int r=0, c=m-1;
    bool flag=0;
    while((r<n) && (c>=0)){
            if(k==arr[r][c]){
                // cout<<r<<" "<<c<<endl;
                flag=1;
                break;
            }
            if(k>arr[r][c]){
                r++;
            }
            if(k<arr[r][c]){
                c--;
            }
    }
    if(flag==1){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}