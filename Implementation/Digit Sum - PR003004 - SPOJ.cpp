#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[16][160][2],a,b;
string target;

string to_s(int x)
{
  stringstream ss;
  ss << x;
  return ss.str();
}

int f(int pos,int sum,int tight)
{
    if(pos==target.size()) return sum;
    if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];

    int ans = 0;
    int ul = tight ? target[pos] - '0' : 9;
    FOR(i,0,ul + 1) ans+= f(pos + 1,sum + i,tight & (i==ul));
    return dp[pos][sum][tight] = ans;
}

int solve(int x)
{
    memset(dp,-1,sizeof(dp));
    target = to_s(x);
    return f(0,0,1);
}

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<solve(b) - solve(a-1)<<"\n";
    }
    return 0;
}
