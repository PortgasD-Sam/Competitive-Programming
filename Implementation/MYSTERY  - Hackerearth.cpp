    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
     
    #define FORI(n) for(ll i=0;i<n;i++)
     
    int main()
    {
        ll n;
        while(scanf("%lld",&n)!=EOF)
        {
            ll ans = 0;
            while(n)
            {
                if(n%2==1) ans++;
                n/=2;
            }
            printf("%lld\n",ans);
        }
        return 0;
    }