#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
const long long mod = 1e9 + 7;
long long sequence[N],p[N],f[N];

int main()
{
    long long n{},q{};
    scanf("%lld%lld",&n,&q);
    scanf("%lld%lld",f,f+1);
    long long a{},b{};
    scanf("%lld%lld",&a,&b);
    for(long long i=0;i<n;i++)
    scanf("%lld",sequence+i);
    for(long long i=2;i<n;i++)
    f[i] = (a*f[i-2] + b*f[i-1]) % mod;
    while(q--)
    {
        long long l{},r{};
        scanf("%lld%lld",&l,&r);
        --l;
        --r;
        if(l<r)
        {
            p[l] = (p[l]+f[0])%mod;
            p[l+1] = (p[l+1]+f[1])%mod;
            p[l+1] = (p[l+1]+mod - (b*f[0])%mod)%mod;
            p[r+1] = (p[r+1]+mod - f[r-l+1])%mod;
            p[r+2] = (p[r+2]+mod - (a*f[r-l])%mod)%mod;
        }
        else
        {
            p[l] = (p[l]+f[0])%mod;
            p[r+1] = (p[r+1]+mod - (b*f[0])%mod)%mod;
            p[r+2] = (p[r+2]+mod - (a*f[0])%mod)%mod;
        }
    }
    for(long long i=0;i<n;i++)
    {
        if(i>1)
        p[i] = (p[i] + a*p[i-2])%mod;
        if(i)
        p[i] = (p[i] + b*p[i-1])%mod;
        sequence[i] =(sequence[i] + p[i])%mod;
        printf("%lld ",sequence[i]);
    }
    return 0;
}