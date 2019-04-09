#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,ax,ay,bx,by,cx,cy;
	cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
	if(ax>=0)
	{
		bx-=ax;
		cx-=ax;
		ax-=ax;
	}
	else
	{
		bx+=abs(ax);
		cx+=abs(ax);
		ax+=abs(ax);
	}
	if(ay>=0)
	{
		by-=ay;
		cy-=ay;
		ay-=ay;
	}
	else
	{
		by+=abs(ay);
		cy+=abs(ay);
		ay+=abs(ay);
	}
	if((bx>0 && cx>0 && by>0 && cy>0) || (bx>0 && cx>0 && by<0 && cy<0) || (bx<0 && cx<0 && by<0 && cy<0) || (bx<0 && cx<0 && by>0 && cy>0))
	cout<<"YES\n";
	else
	cout<<"NO\n";
	return 0;
}