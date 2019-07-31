#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int f[32] = {0};
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int x;
            scanf("%d",&x);
            FORI(32) if(x&(1<<i)) f[i]++;
        }
        int mx = INT_MIN, ans = 0;
        FORI(32)
        {
            if(f[i] > mx)
            {
                mx = f[i];
                ans = i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}