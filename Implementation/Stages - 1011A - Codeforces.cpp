#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	IOS;
	int n{},k{},w{},l{};
	cin>>n>>k;
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	char x = 'a'-2;
	FORI(n)
	{
		if(s[i]>=x+2)
		{
			w+=s[i]-'a'+1;
			x = s[i];
			l++;
		}
		if(l==k) break;
	}
	if(l==k) cout<<w<<endl;
	else cout<<"-1\n";
	return 0;
}