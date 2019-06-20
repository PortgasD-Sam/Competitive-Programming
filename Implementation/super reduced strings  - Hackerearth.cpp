#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	stack<char> s;
	string w;
	cin>>w;
	FORI(w.length())
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
		string res;
		int t = s.size();
		FORI(t)
		{
			res+=s.top();
			s.pop();
		}
		reverse(res.begin(),res.end());
		cout<<res<<"\n";
	}
	else cout<<"Empty String\n";
	return 0;
}