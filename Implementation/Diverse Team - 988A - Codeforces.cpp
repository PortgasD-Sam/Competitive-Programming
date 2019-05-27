#include <bits/stdc++.h>

using namespace std;

int n, k, a[101];
set<int> st;
vector<int> sol;

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
  	cin >> a[i], st.insert(a[i]);

  if(st.size() < k)
  	cout << "NO" << endl;
  else {
  	for(set<int>::iterator it = st.begin(); it != st.end(); ++it)
  		for(int i = 0; i < n; ++i)
  			if(a[i] == *it) {
  				sol.push_back(i + 1);
  				break;
  			}
  	cout << "YES" << endl;
  	for(int i = 0; i < k; ++i)
  		cout << sol[i] << ' ';
  	cout << endl;
  }

  return 0;
}