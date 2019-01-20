#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FORI(n) for(int i=0;i<n;i++)

int main()
{
    int n{},c{};
    scanf("%d",&n);
    vi a(n),count(5);
    FORI(n) {scanf("%d",&a[i]);count[a[i]]++;}
    c = count[4] + count[3] + count[2]/2;
    count[1]-=count[3];
    if(count[2]%2 == 1) {count[1]-=2;c++;}
    if(count[1]>0)
    c+=(count[1]+3)/4;
    return !printf("%d\n",c);
}