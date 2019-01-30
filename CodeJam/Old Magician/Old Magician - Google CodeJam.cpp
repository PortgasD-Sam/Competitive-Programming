#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n{},w{},b{},c{};
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&w,&b);
        (b%2)?printf("Case #%lld: BLACK\n",++c):printf("Case #%lld: WHITE\n",++c);
    }
    return 0;
}