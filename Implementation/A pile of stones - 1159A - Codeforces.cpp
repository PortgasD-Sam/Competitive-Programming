#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int n,ans;

int main()
{
	cin>>n;
	string s;
	cin>>s;
	FORI(n)
	{
		if(s[i]=='-')
		{
			ans--;
			ans = max(0,ans);
		}
		else ans++;
	}
	cout<<ans<<"\n";
	return 0;
}