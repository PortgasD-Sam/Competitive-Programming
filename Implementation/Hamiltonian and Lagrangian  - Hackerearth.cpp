#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    FORI(n) scanf("%d",&a[i]);
    reverse(a,a+n);
    stack<int> s;
    FORI(n)
    {
        if(s.empty()) s.push(a[i]);
        else
        {
            if(a[i]>=s.top()) s.push(a[i]);
        }
    }
    while(!s.empty())
    {
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}