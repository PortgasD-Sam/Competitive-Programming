#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,z,a,b,c;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
	bool condition = true;
	if(a-x>=0) a-=x;
	else condition = false;
	if(a+b-y>=0)
	{
		if(a-y>=0) a-=y;
		else
		{
			b = a+b-y;
			a = 0;
		}
	}
	else condition = false;
	if(a+b+c-z>=0)
	{
		if(a-z>=0) a-=z;
		else if(a+b-z>=0)
		{
			b = a+b-z;
			a = 0;
		}
		else
		{
			c = a+b+c-z;
			a = b = 0;
		}
	}
	else condition = false;
	if(condition) printf("YES\n");
	else printf("NO\n");
	return 0;
}