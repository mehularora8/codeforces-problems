#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    int t;
    
    cin >> t;
    while(t){
        
        int a, b, diff;
        
        cin >> a >> b;
        
        diff = abs(a - b);
        
        if (diff % 10 != 0){
        	diff += 10;
        }
        
        
        cout << (diff / 10) << endl;
        
        t--;
    }
    return 0;
}
