#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int n;

int main()
{
	cin>>n;
	int a[n],ans = INT_MAX;
	FORI(n) cin>>a[i];
	FORI(n)
	{
		a[i] = a[i]/max(i,n-i-1);
		ans = min(a[i],ans);
	}
	cout<<ans<<"\n";
	return 0;
}