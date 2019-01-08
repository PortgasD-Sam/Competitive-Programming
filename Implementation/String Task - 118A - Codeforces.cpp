#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    for(int i=0;i<s1.length();i++)
    {
        char c{};
        c=s1.at(i);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y')
        continue;
        else
        {
            s2+=".";
            s2+=tolower(c);
        }
    }
    cout<<s2<<endl;
    return 0;
}