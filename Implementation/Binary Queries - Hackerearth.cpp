#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n,l,r,x,q,tmp;
	scanf("%d%d",&n,&q);
	int a[n];
	FORI(n) scanf("%d",&a[i]);
	while(q--)
	{
		scanf("%d",&tmp);
		if(tmp)
		{
			scanf("%d",&x);
			x--;
			a[x] = !a[x];
		}
		else
		{
			scanf("%d%d",&l,&r);
			l--;
			r--;
			if((a[r]&1)) printf("ODD\n");
			else printf("EVEN\n");
		}
	}
	return 0;
}