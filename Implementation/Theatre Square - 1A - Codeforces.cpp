#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n{},m{},a{};
    cin>>n>>m>>a;
    long long minimum_squares =ceil((double)n/a)*ceil((double)m/a);
    cout<<minimum_squares<<endl;
    return 0;
}