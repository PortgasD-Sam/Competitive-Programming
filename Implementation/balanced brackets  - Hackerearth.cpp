#include <bits/stdc++.h>
using namespace std;

#define FORI(n) for(int i=0;i<n;i++)

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
    	string w;
    	cin>>w;
    	stack<char> s;
    	bool f = true;
    	FORI(w.size())
    	{
    		if(w[i]=='(' || w[i]=='[' || w[i]=='{') s.push(w[i]);
    		else if(s.empty() &&(w[i]==')' || w[i]==']' || w[i]=='}'))
    		{
    			cout<<"NO\n";
    			f = false;
    			break;
    		}
    		else
    		{
    			if((s.top()=='(' && w[i]==')') || (s.top()=='[' && w[i]==']') || (s.top()=='{' && w[i]=='}')) s.pop();
    			else
    			{
    				cout<<"NO\n";
    				f = false;
    				break;
    			}
    		}
    	}
    	if(f)
    	{
        	if(s.empty()) cout<<"YES\n";
        	else cout<<"NO\n";
    	}
	}
	return 0;
}