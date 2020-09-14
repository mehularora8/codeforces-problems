#include <bits/stdc++.h>

using namespace std;

int k, n;
vector<vector<int>> a;

bool good(long long m, bool print){
	int s = 0;
	
	for(int i = 0; i < n; i++){
		vector<int> values = a[i];
		int ans;
		
		if (m <= values[0] * values[1]){
			ans = m / values[0];
			s += ans;
		} else if ((values[0] * values[1]) < m && m <= ((values[0] * values[1]) + values[2])){
			ans = values[1];
			s += ans;
		} else {
			ans = (m / ((values[0] * values[1]) + values[2])) * values[1] + ((m % ((values[0] * values[1]) + values[2])) / values[0]);
			s += ans;
		}
		
		if(print) cout << ans << " ";
	}
	
	return s >= k;
}

int main() {
	
	cin >> k >> n;
	
	a.resize(n);
	
	for(int i = 0 ; i < n; i ++){
		vector<int> b;
		b.resize(3);
		
		cin >> b[0] >> b[1] >> b[2];
		
		a[i] = b;
	}
	
	long long l = 0; // l is bad because you cannot make any copies in 0 seconds.
	long long r = k * a[0][0] + (k * a[0][2] / a[0][1]); // Exceeds maximum constraint for this problem. Works.
	
	while(r > l + 1){
		long long m = (l + r) / 2;
		
		if (good(m, false)){
			r = m;
		} else {
			l = m;
		}
	}
	
	cout << r << endl;
	good(r, true);
	
	return 0;
}
