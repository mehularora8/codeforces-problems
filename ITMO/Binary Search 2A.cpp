#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

long long w, h, n;

bool checkDimension(long long x){
	return (x / w) * (x / h) >= n;
}

int main() {
	
	cin >> w >> h >> n;
	
	long long l = 0; // 0 does not work for this problem. 
	long long r = 100; // r works. 
	
	while(r > l + 1){
		long long mid = (l + r) / 2;
		
		if(checkDimension(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	 cout << r;
	return 0;
}
