#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n;
	scanf("%d",&n);
	vi a(n);
	int o = 0,z = 0,l = 0,r = 0, k = 0;
	FORI(n)
	{
		scanf("%d",&a[i]);
		(!a[i])?z++:o++;
	}
	FORI(n)
	{
		(!a[i])?l++:r++;
		k++;
		if(l==z || r==o)
		break;
	}
	return !printf("%d\n",k);
}