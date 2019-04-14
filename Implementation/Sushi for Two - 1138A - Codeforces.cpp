#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int n;
	scanf("%d",&n);
	vi a(n+1);
	int left = 0,right = 0,mx = INT_MIN,mn = INT_MAX,current = 1;
	FORI(n) scanf("%d",&a[i]);
	a[n] = 3;
	FORI(n)
	{
		if(a[i]==a[i+1]) current++;
		else
		{
			if(!left) left = current;
			else if(!right) right = current;
			else
			{
				left = right;
				right = current;
				mn = min(left,right);
				mx = max(mx,mn);
			}
			current = 1;
		}
		mn = min(left,right);
		mx = max(mx,mn);
	}
	return !printf("%d\n",2*mx);
}