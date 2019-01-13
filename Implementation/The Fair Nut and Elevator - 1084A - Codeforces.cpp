#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int n{};
    scanf("%d",&n);
    vi a(n);
    FORI(n) scanf("%d",&a[i]);
    int res{};
    FORI(n) res+= a[i]*4*((i+1)-1);
    return !printf("%d\n",res);
}