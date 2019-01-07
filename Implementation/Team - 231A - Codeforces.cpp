#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n{},counter{},a{},b{},c{};
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        if((a+b+c)>=2)
        counter++;
    }
    cout<<counter<<endl;
    return 0;
}