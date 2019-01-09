#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FORI(s,n) for(int i=s;i<n;i++)
#define FORJ(s,n) for(int j=s;j<n;j++)

int main()
{
    int n{},sum{},res{},mx{INT_MIN};
    scanf("%d",&n);
    vi a(n);
    FORI(0,n) {scanf("%d",&a[i]),sum+=a[i];mx = max(mx,a[i]);}
    FORI(mx,1e5+5)
    {
        FORJ(0,n) res+= i - a[j];
        if(res>sum) return !printf("%d\n",i);
        else
        res = 0;
    }
    return 0;
}
