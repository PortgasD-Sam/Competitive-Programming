#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],ans = 0;
    FORI(n) scanf("%d",&a[i]);
    FORI(n) ans|=a[i];
    return !printf("%d\n",ans);
}