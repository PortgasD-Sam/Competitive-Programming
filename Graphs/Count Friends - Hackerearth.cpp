#include <bits/stdc++.h>
using namespace std;

#define MAX 100025
#define FORI(n) for(int i=0;i<n;i++)

int a[MAX],size[MAX],n,m;

void initialize()
{
	FORI(MAX)
	{
		a[i] = i;
		size[i] = 1;
	}
}

int root(int r)
{
	while(r!=a[r]) r = a[a[r]];
	return r;
}

void weightedUnion(int u,int v)
{
	int ru = root(u);
	int rv = root(v);
	if(ru!=rv)
	{
    	if(size[ru]<size[rv])
    	{
    		a[ru] = a[rv];
    		size[rv]+=size[ru];
    	}
    	else
    	{
    		a[rv] = a[ru];
    		size[ru]+=size[rv];
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
		weightedUnion(u,v);
	}
	FORI(n)
	{
	    int ri = root(i+1);
	    printf("%d ",size[ri]-1);
	}
	return 0;
}