#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll t{},a{},b{},k{};
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        ll aa = (k+1)/2;
        ll bb = k/2;
        ll result = a*aa - b*bb;
        printf("%lld\n",result);
    }
    return 0;
}
