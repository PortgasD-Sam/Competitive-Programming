#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)
int a[4];

int main()
{
	FORI(4) scanf("%d",&a[i]);
	sort(a,a+4);
	return !printf("%d %d %d\n",a[3]-a[0],a[3]-a[1],a[3]-a[2]);
}