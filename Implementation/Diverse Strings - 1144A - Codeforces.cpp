#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	IOS;
	int n;
	string s,w;
	cin>>n;
	FORI(n)
	{
		cin>>s;
		sort(s.begin(),s.end());
		w = s;
		w.erase(unique(w.begin(),w.end()),w.end());
		bool f = true;
		if(s.size()!=w.size()) f = false;
		FORI((int)s.size()-1) if((s[i]-'a'+1)!=(s[i+1]-'a')) f = false;
		if(!f) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}