#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n{},k{},temporary{},counter{};
    cin>>n>>k;
    vector<int> sequence;
    for(int i=1;i<=n;i++)
    {
        cin>>temporary;
        sequence.push_back(temporary);
    }
    for(int i=0;i<n;i++)
    {
        if(sequence.at(i)>=sequence.at(k-1) && sequence.at(i)!=0)
        counter++;
    }
    cout<<counter<<endl;
    return 0;
}