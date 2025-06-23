
// #include <bits/stdc++.h>
#include <iostream>
#include <climits>

using namespace std;

int koko(vector<int>piles,int k){
    
    int n = piles.size();
    int t = 0;
    
    for(int i = 0;i<n;i++){
        
        t += ceil((double)piles[i] / k);
        
    }
    
    return t;
}

int main()
{
    
    vector<int> A = {3,6,7,11};
    
    int n = A.size();
    
    int maxi = INT_MIN;
    
    for(int i = 0;i<n;i++){
        
        maxi = max(maxi,A[i]);
        
    }
    
    int h = 8;
    
    int l = 1;
    int r = maxi;
    
    while(l <= r){
        
        
        int m = (l+r)/2;
        
        
        
       if(koko(A,m) <= h){
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    
    
    cout << l;

    return 0;
}