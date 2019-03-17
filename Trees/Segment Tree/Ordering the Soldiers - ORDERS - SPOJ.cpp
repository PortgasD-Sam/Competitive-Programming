#include <bits/stdc++.h>
using namespace std;
#define FORI(s,n) for(int i=s;i<n;i++)
#define REVI(n) for(int i=n;i>0;i--)

int tree[4000005],data[2000005],n;

void build(int c,int l,int r)
{
	tree[c] = r-l+1;
	if(l==r) return;
	int m = (l+r)>>1;
	build(c<<1,l,m);
	build((c<<1)|1,m+1,r);
}

int query(int c,int l,int r,int k)
{
	tree[c]--;
	if(l==r) return l;
	int m = (l+r)>>1,lc = c<<1;
	if(tree[lc]>=k)return query(lc,l,m,k);
	else return query(lc|1,m+1,r,k-tree[lc]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		build(1,1,n);
		FORI(1,n+1) scanf("%d",&data[i]);
		REVI(n) data[i] = query(1,1,n,i-data[i]);
		FORI(1,n+1) printf("%d ",data[i]);
		printf("\n");
	}
	return 0;
}