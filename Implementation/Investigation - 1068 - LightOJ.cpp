#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll
#define FOR(i,n,k) for(int i=n;i<k;i++)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dp[10][100][100][2],a,b,k;
string target;

string to_s(int x)
{
  stringstream ss;
  ss << x;
  return ss.str();
}

int f(int pos,int mod_sum,int mod_product,int tight)
{
    if(pos==target.size()) return (mod_sum==0 && mod_product==0);
    if(dp[pos][mod_sum][mod_product][tight] != -1) return dp[pos][mod_sum][mod_product][tight];

    int ans = 0;
    int ul = tight ? target[pos] - '0' : 9;
    FOR(i,0,ul + 1) ans+=f(pos + 1,(mod_sum + i) % k,(((mod_product * 10) % k) + i) % k,tight & (i==ul));
    return dp[pos][mod_sum][mod_product][tight] = ans;
}

int solve(int x)
{
    memset(dp,-1,sizeof(dp));
    target = to_s(x);
    return f(0,0,0,1);
}

int32_t main()
{
    IOS;
    int t,c = 1;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        if(k > 90) cout<<"Case "<<c++<<": "<<"0\n";
        else cout<<"Case "<<c++<<": "<<solve(b) - solve(a-1)<<"\n";
    }
    return 0;
}