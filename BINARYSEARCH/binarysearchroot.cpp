
#include <iostream>
#include <math.h>

using namespace std;

long long fastpower(long long a, long long b){
    
    long long result = 1;
    
    while(b > 0){
        
        if(b % 2 == 1){
            result *= a;
        }
        
        a *= a;
        b = b/2;
    }
    
    
    return result;
}

int main()
{
    
    long long n;
    
    cin >> n;
    
    long long k;
    
    cin >> k;
    
    
    int left = 1;
    int right = n;
    
    while(left+1 < right){
        
        int mid = (left + right)/2;
        
        if(fastpower(mid,k) <= n){
            left = mid;
        }
        
        else if(fastpower(mid,k) > n){
            right = mid;
        }
    }
    
    cout << left;
    
    // cout << fastpower(2,6);

    return 0;
}