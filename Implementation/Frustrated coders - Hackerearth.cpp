#include <bits/stdc++.h>
using namespace std;

#define FORI(k,n) for(int i=k;i<n;i++)

int n;

int main()
{
	cin>>n;
	int a[n],sum = 0;
	FORI(0,n) cin>>a[i];
	sort(a,a+n);
	FORI(1,n)
	{
	    if(a[i]-a[i-1]>0) a[i-1] = 0;
	    else
	    {
    		int j = i-1;
    		while(j>=0)
    		{
    			if(a[i]>a[j] && a[j]!=0)
    			{
    				a[j] = 0;
    				break;
    			}
    			j--;
    		}
	    }
	}
	FORI(0,n) sum+=a[i];
	cout<<sum<<"\n";
	return 0;
}