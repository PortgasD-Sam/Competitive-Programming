#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=1;i<=n;i++)
#define FORJ(n) for(int j=1;j<=n;j++)

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans = 0;
        scanf("%d",&n);
        FORI(n)
        {
            FORJ(n)
            {
                if(i==j) continue;
                if((i^j)<=n) ans++;
            }
        }
        ans/=2;
        printf("%d\n",ans);
    }
    return 0;
}