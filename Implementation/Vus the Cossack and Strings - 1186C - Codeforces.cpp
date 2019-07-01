#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 1000005

char a[MAXSIZE],b[MAXSIZE];
int sa[MAXSIZE],sb[MAXSIZE],ans;

int main()
{
	scanf("%s%s",a+1,b+1);
	int n = strlen(a+1);
	int m = strlen(b+1);
	for(int i=1;i<=n;i++) sa[i] = (a[i] - '0') + sa[i-1];
	for(int i=1;i<=m;i++) sb[i] = (b[i] - '0') + sb[i-1];
	for(int i=m;i<=n;i++) if((sb[m] + sa[i] - sa[i-m])%2==0) ans++;
	printf("%d\n",ans);
	return 0;
}