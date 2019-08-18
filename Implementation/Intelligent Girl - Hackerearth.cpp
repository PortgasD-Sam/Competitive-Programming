#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[10005];

int32_t main()
{
    IOS;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    if((s[0] - '0')%2==0) dp[0] = 1;
    FOR(i,1,s.size())
    {
        if((s[i] - '0')%2==0) dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
    }
    FOR(i,0,s.size()) cout<<dp[s.size() - i - 1]<<" ";
    return 0;
}