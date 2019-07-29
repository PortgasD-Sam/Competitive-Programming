#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007
#define FORI(n) for(ll i=0;i<n;i++)
#define FORJ(n) for(ll j=0;j<n;j++)

ll fast_exp(ll base,ll exp)
{
    ll res=1;
    while(exp>0)
    {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
    }
    return res;
}

int main()
{
    ll t,k = 1;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll a[n];
        FORI(n) scanf("%lld",&a[i]);
        ll p = 1 << n, b, c, d,ans = INT_MIN;
        FORI(p)
        {
            b = 1;
            c = 0;
            ll ctr = 0;
            FORJ(n)
            {
                if(i&(1<<j))
                {
                    ctr++;
                    b = (b * a[j]) % MOD;
                    c = (c + a[j]) % MOD;
                }
            }
            if(ctr>=2)
            {
                d = fast_exp(c,MOD - 2);
                ans = max((b * d) % MOD,ans);
            }
        }
        printf("Case #%lld: %lld\n",k++,ans);
    }
    return 0;
}