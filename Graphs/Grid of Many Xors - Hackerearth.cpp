#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int,int>;

#define FORI(n) for(int i=0;i<n;i++)
#define FORJ(n) for(int j=0;j<n;j++)
#define MAXSIZE 100024

int a[MAXSIZE],size[MAXSIZE],n,m,t;
void initialize()
{
	FORI(MAXSIZE)
	{
		a[i] = i;
		size[i] = 1;
	}
}

int root(int x)
{
	while(x!=a[x]) x = a[a[x]];
	return x;
}

bool join(int u,int v)
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
		return 1;
	}
	return 0;
}

struct edge
{
	int u,v,val;
};

bool cmp(edge a,edge b)
{
	return a.val<b.val;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		initialize();
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		vvi graph(n,vi(m));
		vector<edge> E;
		int cnt = 0;
		map<pi,int> C;
		FORI(n)
		{
			FORJ(m)
			{
				C[{i,j}] = cnt++;
				int tmp;
				scanf("%d",&tmp);
				graph[i][j] = tmp;
				if(i-1>=0) E.push_back({C[{i-1,j}],C[{i,j}],graph[i-1][j]^graph[i][j]});
				if(j-1>=0) E.push_back({C[{i,j-1}],C[{i,j}],graph[i][j-1]^graph[i][j]});
			}
		}
		sort(E.begin(),E.end(),cmp);
		int ans = 0;
		FORI(E.size())
		{
			int u = E[i].u;
			int v = E[i].v;
			if(join(u,v)) ans+= E[i].val;
		}
		printf("%d\n",ans);
	}
	return 0;
}