#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

map<char,int> m;

int main()
{
	int n,ans = 0;
	scanf("%d",&n);
	FORI(n)
	{
		string s;
		cin>>s;
		m[s[0]]++;
	}
	for(char i='a';i<='z';i++)
	{
		if(m[i]==0 || m[i]==1) continue;
		int a = 0, b = 0;
		a = m[i]/2;
		b = m[i] - a;
		ans+=(a*(a-1)/2) + (b*(b-1)/2);
	}
	printf("%d\n",ans);
	return 0;
}