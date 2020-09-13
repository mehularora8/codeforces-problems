#include <iostream>
#include <algorithm>

using namespace std;

bool binarySearch(int arr[], int l, int r, int target) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        
        if (arr[mid] == target) return true; 
  
        if (arr[mid] > target)  return binarySearch(arr, l, mid - 1, target); 
        
        return binarySearch(arr, mid + 1, r, target); 
    } 
    
    return false; 
} 

int main() {
	int n, k;
	
	cin >> n >> k;
	
	int arr[n];
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	while(k--){
		int target;
		cin >> target;
		if (binarySearch(arr, 0, n - 1, target)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
