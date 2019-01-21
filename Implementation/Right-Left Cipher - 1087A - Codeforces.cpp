#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    IOS;
    string s,w;
    cin>>s;
    int m{},n{(int)s.length()-1};
    if(s.length()%2)
    {
        FORI(s.length())
        {
            if(i%2==0)
            {
                w = s[m] + w;
                m++;
            }
            else
            {
                w = s[n] + w;
                n--;
            }
        }
    }
    else
    {
        FORI(s.length())
        {
            if(i%2==1)
            {
                w = s[m] + w;
                m++;
            }
            else
            {
                w = s[n] + w;
                n--;
            }
        }
    }
    cout<<w<<endl;
    return 0;
}