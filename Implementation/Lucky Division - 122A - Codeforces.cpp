#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define FORI(n) for(int i=0;i<n;i++)

bool luck(int n)
{
    string s = to_string(n);
    FORI(s.length()) if(s[i]!='4' && s[i]!='7') return false;
    return true;
}

int main()
{
    vi a;
    FORI(1001) if(luck(i)) a.push_back(i);
    int n{};
    scanf("%d",&n);
    FORI(a.size()) if(n%a[i]==0) return !printf("YES\n");
    return !printf("NO\n");
}