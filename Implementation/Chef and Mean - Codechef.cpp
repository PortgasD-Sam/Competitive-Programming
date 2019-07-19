#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll a[n];
		double sum = 0,avg = 0;
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		avg = sum / n;
		bool f = false;
		if(avg==(ll)avg)
		{
			for(ll i=0;i<n && f==false;i++)
			{
				if(a[i]==(ll)avg)
				{
					printf("%lld\n",i+1);
					f = true;
				}
			}
		}
		if(!f) printf("Impossible\n");
	}
	return 0;
}
