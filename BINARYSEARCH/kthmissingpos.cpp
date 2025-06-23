#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        //BRUTE FORCE



        // int count = 0;

        // int i = 1;

        // while(count != k){

        //     if(find(arr.begin(),arr.end(),i) == arr.end()){
        //         count++;
        //     }

            

        //     i++;

        // }

        // return i-1;


        int t = arr.size();
    
    
    
    
    
    
    int l = 0;
    int r = t;
    
    while(l < r){
        
        int m = (l+r)/2;
        int missing = arr[m] - (m+1);
        
        if(missing < k){
            l = m+1;
        }
        else{
            r = m;
        }
    }
    
    return l+k;
        
    }
};