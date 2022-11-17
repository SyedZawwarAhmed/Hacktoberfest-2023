#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int arr1[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr1[i][j];
        }
    }
    int p;
    cin>>m>>p;
    int arr2[m][p];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cin>>arr2[i][j];
        }
    }
    int a[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            a[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<m;k++){
                a[i][j]+=arr1[i][k]*arr2[k][j];
            }
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}