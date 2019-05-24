#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)
#define REVI(n) for(int i=n;i>=0;i--)

int main()
{
	stack<char> s;
	int n;
	cin>>n;
	string w;
	cin>>w;
	FORI(n)
	{
		if(s.empty())
		{
			s.push(w[i]);
			continue;
		}
		else
		{
			if(w[i]==s.top()) s.pop();
			else s.push(w[i]);
		}
	}
	if(s.size())
	{
		int ans = s.size();
		string res;
		FORI(ans)
		{
			res+=s.top();
			s.pop();
		}
		reverse(res.begin(),res.end());
		cout<<ans<<"\n"<<res<<"\n";
	}
	else cout<<0<<"\n";
	return 0;
}