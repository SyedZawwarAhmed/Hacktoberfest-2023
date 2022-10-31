#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int>a(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> left(n,0);
    vector<int> right(n,0);
    vector<int> water(n,0);
    left[0] = a[0];
    right[n-1] = a[n-1];
    for(int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1],a[i]);
    }
    
    for(int i = n-2; i >=0; i--)
    {
        right[i] = max(right[i+1],a[i]);
    }
    
    int ans = 0;
    
    for( int i = 0; i < n; i++)
    {
        water[i] = min(right[i],left[i])-a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
          ans += water[i];
    }
    cout<<ans<<endl;
    
    
    return 0; 
}
