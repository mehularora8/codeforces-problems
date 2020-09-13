#include <bits/stdc++.h>

using namespace std;

int n, x, y;

bool good(long long m){
	if (m < min(x, y)) return false;
	
	m -= min(x, y);
	return (floor(m / x) + floor(m / y)) >= (n - 1);
}

int main() {
	
	cin >> n >> x >> y;
	
	long long l = 0; // l is bad because you cannot make any copies in l seconds. 
	long long r = max(x, y) * n;
	
	while(r > l + 1){
		
		long long m = (l + r) / 2;
		
		if (good(m)){
			r = m;
		} else {
			l = m;
		}
	}
	
	cout << r;
	
	return 0;
}
