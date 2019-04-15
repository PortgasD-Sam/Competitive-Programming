#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,q = 1;
	scanf("%d",&t);
	while(t--)
	{
		int d,m,y,qy,c = 0;
		scanf("%d%d%d%d",&d,&m,&y,&qy);
		if(d == 29 && m == 2)
		{
			int k = y + 4;
			while(k<=qy)
			{
				if((k%4==0 && k%100!=0)||(k%400==0))
				c++;
				k+=4;
			}
		}
		else c = qy - y;
		printf("Case %d: %d\n",q++,c);
	}
	return 0;
}
