#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100005
#define FORI(n) for(int i=0;i<n;i++)

int a[MAXSIZE],size[MAXSIZE],str[MAXSIZE],n,m,q;

void initialize()
{
    FORI(MAXSIZE)
    {
        a[i] = i;
        size[i] = 1;
        str[i] = i;
    }
}

int root(int x)
{
    while(a[x]!=x) x = a[a[x]];
    return x;
}

void join(int u,int v)
{
    int ru = root(u);
    int rv = root(v);
    if(ru!=rv)
    {
        if(size[ru]>size[rv])
        {
            a[rv] = a[ru];
            size[ru]+=size[rv];
            str[ru] = max(u,max(v,max(str[ru],str[rv])));
        }
        else
        {
            a[ru] = a[rv];
            size[rv]+=size[ru];
            str[rv] = max(u,max(v,max(str[ru],str[rv])));
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    initialize();
    FORI(m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        join(u,v);
    }
    scanf("%d",&q);
    FORI(q)
    {
        int u,v,ru,rv;
        scanf("%d%d",&u,&v);
        ru = root(u);
        rv = root(v);
        if(ru!=rv)
        {
            if(str[ru]>str[rv]) printf("%d\n",u);
            else printf("%d\n",v);
        }
        else printf("TIE\n");
    }
    return 0;
}