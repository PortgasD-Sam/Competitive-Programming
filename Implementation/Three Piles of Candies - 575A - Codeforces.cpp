#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main()
{
    ll q;
    scanf("%lld",&q);
    while(q--)
    {
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",(a+b+c)/2);
    }
    return 0;
}