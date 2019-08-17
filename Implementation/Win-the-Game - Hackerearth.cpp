#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

double dp[1005][1005];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        memset(dp,0,sizeof(dp));
        cin>>a>>b;
        FOR(r,0,a + 1)
        {
            FOR(g,0,b + 1)
            {
                if(r==0) dp[r][g] = 1;
                else if(g==0) dp[r][g] = 1;
                else dp[r][g] = r*1.0/(r + g) + ((g*1.0/(r + g)) * ((g - 1)*1.0/(r + g - 1)) * dp[r][g-2]);
            }
        }
        cout<<fixed<<setprecision(6)<<dp[a][b]<<"\n";
    }
    return 0;
}