#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[10][2][100],x,y;
string target;

string to_s(int x)
{
  stringstream ss;
  ss << x;
  return ss.str();
}

int f(int pos,int tight,int sum)
{
    if(pos==target.size()) return sum;
    if(dp[pos][tight][sum]!=-1) return dp[pos][tight][sum];

    int ans = 0;
    int ul = tight ? target[pos] - '0' : 9;
    FOR(i,0,ul + 1) ans+=f(pos + 1,tight & (i==ul),sum + i);
    return dp[pos][tight][sum] = ans;
}

int solve(int x)
{
    memset(dp,-1,sizeof(dp));
    target = to_s(x);
    return f(0,1,0);
}

int32_t main()
{
    IOS;
    while(1)
    {
        cin>>x>>y;
        if(x==-1 && y==-1) break;
        else cout<<solve(y) - solve(x-1)<<"\n";
    }
    return 0;
}