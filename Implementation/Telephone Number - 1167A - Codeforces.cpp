#include <bits/stdc++.h>
using namespace std;

#define FORI(k,n) for(int i=k;i<n;i++)

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		reverse(s.begin(),s.end());
		bool f = false;
		FORI(10,n)
		{
			if(s[i]=='8')
			{
				f = true;
				break;
			}
		}
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}