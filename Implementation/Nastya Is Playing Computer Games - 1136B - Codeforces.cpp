#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	return !printf("%d\n",2*(n-1)+3+min(2*abs(k-1) + abs(k-n),abs(k-1) + 2*abs(k-n)));
}