#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FORI(n) for(ll i=0;i<n;i++)

struct node
{
	ll val,pos,sum;
};

ll n;

void solve(vector<node>& a)
{
	stack<node> s;
	FORI(n)
	{
		if(s.empty()) s.push(a[i]);
		else
		{
			node next = a[i];
			while(true)
			{
			    if(s.empty()) break;
			    node top = s.top();
			    if(next.val <= top.val) break;
			    a[top.pos-1].sum+=next.pos;
			    s.pop();
			}
			s.push(next);
		}
	}
	while(!s.empty())
	{
		node top = s.top();
		a[top.pos-1].sum+=-1;
		s.pop();
	}
}

int main()
{
	scanf("%lld",&n);
	vector<node> a(n),b(n);
	FORI(n)
	{
		scanf("%lld",&a[i].val);
		a[i].pos = i+1;
		a[i].sum = 0;
		b[i] = a[i];
	}
	solve(a);
	reverse(b.begin(),b.end());
	solve(b);
	FORI(n) printf("%lld ",a[i].sum + b[i].sum);
	return 0;
}