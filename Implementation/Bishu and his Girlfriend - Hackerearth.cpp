#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define MAXSIZE 1024
#define FORI(n) for(int i=0;i<n;i++)

vi graph[MAXSIZE];
int n;

int main()
{
    scanf("%d",&n);
    int q,ans = INT_MAX;
    FORI(n-1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    scanf("%d",&q);
    while(q--)
    {
        int tmp;
        scanf("%d",&tmp);
        ans = min(tmp,ans);
    }
    return !printf("%d\n",ans);
}