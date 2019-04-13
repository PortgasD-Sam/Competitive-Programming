#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	FORI(s.size()) if((s[i] - '0')%2==0) ans+=i+1;
	cout<<ans<<"\n";
	return 0;
}