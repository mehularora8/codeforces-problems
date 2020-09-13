#include <iostream>
#include <algorithm>

using namespace std;

// Find largest index such that a(i) <= target
int binarySearch(int arr[], int l, int r, int target) 
{ 
    if (r > l + 1) { 
        int mid = (r + l) / 2; 
  
        if (arr[mid] < target)  return binarySearch(arr, mid, r, target); 
        
        else return binarySearch(arr, l, mid, target); 
    }
    
    return r;
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
		
		int l = -1;
		int r = n;
		
		cout << binarySearch(arr, l, r, target) + 1 << endl;
	}
	return 0;
}
