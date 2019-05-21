#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)
#define REVI(n) for(int i=n;i>=0;i--)

int n,m;

struct wrd
{
	string s;
	int p;
};

bool cmp(wrd a,wrd b)
{
	string ax = a.s;
	string bx = b.s;
	return (lexicographical_compare(ax.begin(),ax.begin()+m,bx.begin(),bx.begin()+m));
}


int main()
{
	cin>>n>>m;
	wrd a[n];
	FORI(n)
	{
		cin>>a[i].s;
		a[i].p = i + 1;
	}
	sort(a,a+n,cmp);
	string w;
	int p = INT_MAX;
	w = a[n-1].s;
	REVI(n-1)
	{
		if(a[i].s!=w) break;
		p = min(a[i].p,p);
	}
	cout<<p<<"\n";
	return 0;
}