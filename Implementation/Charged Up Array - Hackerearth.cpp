#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007
#define FORI(n) for(ll i=0;i<n;i++)

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        ll a[n];
        FORI(n) scanf("%lld",&a[i]);
        int ans = 0;
        FORI(n)
        {
            if(a[i]>=pow(2,n-1))
            {
                ans+=a[i]%MOD;
                ans%=MOD;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}