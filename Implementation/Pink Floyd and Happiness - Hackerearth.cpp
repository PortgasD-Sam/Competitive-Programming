#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    FORI(n) scanf("%d",&a[i]);
    stack<int> s;
    int k = 1,c = 0,i = 0;
    while(true)
    {
        if(i==n) break;
        if(a[i]==k)
        {
            k++;
            i++;
        }
        else if(!s.empty() && s.top()==k)
        {
            while(!s.empty() && s.top()==k)
            {
                s.pop();
                k++;
            }
        }
        else
        {
            s.push(a[i]);
            i++;
        }
    }
    while(!s.empty())
    {
        if(s.top()==k)
        {
            s.pop();
            k++;
        }
        else break;
    }
    if(s.empty()) printf("Happy\n");
    else printf("Sad\n");
    return 0;
}