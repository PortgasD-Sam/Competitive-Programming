#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll k{},n{},w{},total{};
    scanf("%lld%lld%lld",&k,&n,&w);
    total = max(total,((k*w*(w+1))/2)-n);
    return !printf("%lld\n",total);
}