#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n,k,c = INT_MIN;
	scanf("%d",&n);
	vpi a(n+1);
	FORI(n) scanf("%d%d",&a[i+1].first,&a[i+1].second);
	scanf("%d",&k);
	FORI(n+1)
	{
		if(k-1>=a[i].first && k-1<=a[i].second)
			c = i;
	}
	if(a[c].first == a[c].second) printf("%d\n",n - c);
	else if(a[c].second == k-1) printf("%d\n",n - c);
	else printf("%d\n",n-c+1);
	return 0;
}