#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> a[n];
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        while(k--)
        {
            int t;
            scanf("%d",&t);
            a[i].push_back(t);
        }
    }
    while(q--)
    {
        int idx1,idx2;
        scanf("%d%d",&idx1,&idx2);
        printf("%d\n",a[idx1][idx2]);
    }
    return 0;
}