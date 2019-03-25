#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n;
	scanf("%d",&n);
	vi a(n);
	FORI(n) {scanf("%d",&a[i]); a[i]--;}
	int ctr{},pos{};
	while(pos<n)
	{
		ctr++;
		int mx = pos;
		while(pos<n && pos<=mx)
		{
			mx = max(mx,a[pos]);
			pos++;
		}
	}
	return !printf("%d\n",ctr);
}