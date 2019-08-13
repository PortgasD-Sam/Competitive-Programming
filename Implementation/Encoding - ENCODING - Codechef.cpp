#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;

#define FOR(i,n,k) for(int i=n;i<k;i++)
#define MOD 1000000007
#define int ll

int num[1<<17][10][2],dp[1<<17][10][2];
int p[1<<17];

void init()
{
    p[0] = 1;
    FOR(i,1,100005) p[i] = (p[i-1] * 10) % MOD;
}

inline int add(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + MOD : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }

pi f(vi vec)
{
    memset(num,0,sizeof(num));
    memset(dp,0,sizeof(dp));
    num[0][0][1] = 1;
    FOR(i,0,vec.size())
    {
        FOR(d,0,10)
        {
            FOR(e,0,2)
            {
                int in = i + 1;
                FOR(dn,0,10)
                {
                    if(e && (dn > vec[i])) break;
                    int en = (e & (dn==vec[i]));
                    inc(num[in][dn][en],num[i][d][e]);
                    inc(dp[in][dn][en],dp[i][d][e]);
                    if(dn!=d) inc(dp[in][dn][en],(((num[i][d][e] * p[vec.size() - i - 1]) % MOD)* dn)% MOD);
                }
            }
        }
    }
    pi ans = {0,0};
    FOR(d,0,10) ans = {add(ans.first,dp[vec.size()][d][0]),add(add(ans.second,dp[vec.size()][d][0]),dp[vec.size()][d][1])};
    return ans;
}

int32_t main()
{
    int t;
    cin>>t;
    init();
    while(t--)
    {
        int ln,rn;
        string l,r;
        cin>>ln>>l;
        cin>>rn>>r;
        vi vecl,vecr;
        FOR(i,0,ln) vecl.push_back(l[i] - '0');
        FOR(i,0,rn) vecr.push_back(r[i] - '0');
        int ans = sub(f(vecr).second,f(vecl).first);
        cout<<ans<<"\n";
    }
    return 0;
}