#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

// Find largest index such that a(i) >= target
int binarySearchRight(vector<int> arr, int l, int r, int target) 
{ 
    if (r > l + 1) { 
        int mid = (r + l) / 2; 
  
        if (arr[mid] <= target)  return binarySearchRight(arr, mid, r, target); 
        
        else return binarySearchRight(arr, l, mid, target); 
    }
    
    return r;
} 

int binarySearchLeft(vector<int> arr, int l, int r, int target) 
{ 
    if (r > l + 1) { 
        int mid = (r + l) / 2; 
  
        if (arr[mid] < target)  return binarySearchLeft(arr, mid, r, target); 
        
        else return binarySearchLeft(arr, l, mid, target); 
    }
    
    return l;
} 

int main() {
	int n, k;
	
	cin >> n;
	
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	
	cin >> k;
	
	while(k--){
		int t1, t2;
		cin >> t1 >> t2;
		
		int l = -1;
		int r = n;
		
		int first = binarySearchLeft(arr, l, r, t1) + 1;
		int second = binarySearchRight(arr, l, r, t2) + 1;
		
		cout << first << " " << second << endl;
		cout << second - first - 1 << endl;
	}
	return 0;
}
