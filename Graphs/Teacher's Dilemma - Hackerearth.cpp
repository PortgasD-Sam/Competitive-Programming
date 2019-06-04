#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

#define MAXSIZE 100025
#define MOD 1000000007
#define FORI(n) for(int i=0;i<n;i++)

int a[MAXSIZE],size[MAXSIZE],n,m;
ll ans = 1;

void initialize()
{
	FORI(MAXSIZE)
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
			size[ru] = 1;
		}
		else
		{
			a[rv] = a[ru];
			size[ru]+=size[rv];
			size[rv] = 1;
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
	FORI(n) ans = (size[i+1]*1LL*ans)%MOD;
	return !printf("%lld\n",ans);
}