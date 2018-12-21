#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define endl "\n"

int main()
{
    int n{},t{},cap{};
    cin>>n;
    vi sequence;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        sequence.push_back(t);
        cap = max(cap,(int)count(sequence.begin(),sequence.end(),t));
    }
    cout<<cap<<endl;
    return 0;
}