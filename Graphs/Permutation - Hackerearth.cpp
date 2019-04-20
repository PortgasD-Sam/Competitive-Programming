#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int n;
map<string,int> vis;

int main()
{
	scanf("%d",&n);
	string s;
	FORI(n)
	{
		int t;
		scanf("%d",&t);
		s+=to_string(t);
	}
	string r = s;
	sort(r.begin(),r.end());
	queue<string> q;
	q.push(s);
	vis[s] = 0;
	while(!q.empty())
	{
		string front = q.front();
		if(front == r) break;
		q.pop();
		FORI(n)
		{
			string w = front;
			reverse(w.begin(),w.begin()+i+1);
			if(!vis[w])
			{
				vis[w] = vis[front] + 1;
				q.push(w);
			}
		}
	}
	if(vis[r]==0) return !printf("%d\n",vis[r]);
	return !printf("%d\n",vis[r]-1);
}