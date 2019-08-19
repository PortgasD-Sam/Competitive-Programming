#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXSIZE 100024

int dp[MAXSIZE][2];

int32_t main()
{
    IOS;
    int n,q;
    cin>>n>>q;
    int a[n],b[n];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n) cin>>b[i];
    bool f1 = true,f2 = true;
    FOR(i,1,n+1)
    {
        if(f1) dp[i][0] = dp[i-1][0] + a[i-1];
        else dp[i][0] = dp[i-1][0] + b[i-1];
        if(f2) dp[i][1] = dp[i-1][1] + b[i-1];
        else dp[i][1] = dp[i-1][1] + a[i-1];
        f1 = !f1,f2 = !f2;
    }
    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1)
        {
            if(l%2==1) cout<<dp[r][0] - dp[l-1][0]<<"\n";
            else cout<<dp[r][1] - dp[l-1][1]<<"\n";
        }
        else
        {
            if(l%2==1) cout<<dp[r][1] - dp[l-1][1]<<"\n";
            else cout<<dp[r][0] - dp[l-1][0]<<"\n";
        }
    }
    return 0;
}