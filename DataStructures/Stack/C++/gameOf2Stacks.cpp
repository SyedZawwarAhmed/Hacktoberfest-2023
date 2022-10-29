#include <cstdio>

using namespace std;
int g,i,j,k,n,m,x,s1,Max,nr,y,s[100004];
int main()
{
    scanf ("%d", &g);
    for (i=1;i<=g;i++)
    {
        scanf ("%d %d %d", &n, &m, &x);
        s[0]=0;
        Max=n;
        nr=n;
        for (j=1;j<=n;j++)
        {
            scanf ("%d", &y);
            if (s[j-1]<=x)
                s[j]=s[j-1]+y;
            else if (Max==n)
            {
                nr=j-2;
                Max=j-2;
            }
        }
        if (s[n]>x && Max==n)
        {
            Max=n-1;
            nr=n-1;
        }
        scanf ("%d", &y);
        if (y<=x && Max==0)
            Max=1;
        for (j=nr;j>=1;j--)
        {
            if ((s[j]+y)<=x)
            {
                if ((j+1)>Max)
                    Max=j+1;
                break;
            }
            nr--;
        }
        s1=y;
        for (j=1;j<=(m-1);j++)
        {
            scanf ("%d", &y);
            if (s1<=x)
            {
                s1+=y;
                if (((j+1)>Max) && (s1<=x))
                    Max=j+1;
                for (k=nr;k>=1;k--)
                {
                    if ((s[k]+s1)<=x)
                    {
                        if ((j+k+1)>Max)
                            Max=j+k+1;
                        break;
                    }
                    nr--;
                }
            }
        }
        printf ("%d\n", Max);
    }
    return 0;
}
