#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int result = -1;
	if (m % n == 0) 
	{
	    result = 0;
	    int d = m / n;
	    while (d % 2 == 0)
	        d /= 2, result++;
	    while (d % 3 == 0)
	        d /= 3, result++;
	    if (d != 1)
	        result = -1;
	}
	cout << result << endl;
}