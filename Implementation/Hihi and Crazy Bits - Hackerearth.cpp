#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FORI(n) for(ll i=0;i<n;i++)

int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,ans = 0,i = 0;
        scanf("%lld",&n);
        while(true)
        {
            if(n&(1<<i)) i++;
            else
            {
                ans = n | (1<<i);
                break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}