#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    string s;
    int n{},x{};
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(s=="++X")
        ++x;
        else if(s=="X++")
        x++;
        else if(s=="--X")
        --x;
        else
        x--;
    }
    cout<<x<<endl;
    return 0;
}