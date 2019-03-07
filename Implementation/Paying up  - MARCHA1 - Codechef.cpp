#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define S(x) scanf("%d",&x);
#define FORI(x,y) for(int i=x;i<=y;i++)
#define FORJ(x,y) for(int j=x;j<=y;j++)

int arr[25];
int main()
{
    int t;
    S(t);
    while(t--)
    {
        int n,m;
        S(n);S(m);
        int dp[n+1][m+1];
        FORI(1,n)
        S(arr[i]);
        memset(dp,0,sizeof(dp));
        FORI(0,n)
        dp[i][0]=1;
        FORI(1,n)
        {
            FORJ(1,m)
            {
                if(arr[i]<=j)
                {
                    if(dp[i-1][j-arr[i]]==1)
                    dp[i][j]=1;
                    if(dp[i-1][j]==1)
                    dp[i][j]=1;
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][m]==1)
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}