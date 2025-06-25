
#include <bits/stdc++.h>

using namespace std;

vector<int>nge(vector<int>&nums){
    
    int n = nums.size();
    stack<int>st;
    vector<int>ans;
    
    for(int i = n-1;i>=0;i--){
        
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        
        st.push(nums[i]);
        
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}

vector<int>nse(vector<int>&nums){
    
    int n = nums.size();
    stack<int>st;
    vector<int>ans;
    
    for(int i = n-1;i>=0;i--){
        
        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        
        st.push(nums[i]);
    }
    
    return ans;
}

vector<int>pge(vector<int>&nums){
    
    int n = nums.size();
    vector<int>ans;
    stack<int>st;
    
    for(int i = 0;i<n;i++){
        
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        
        st.push(nums[i]);
    }
    
    return ans;
}

vector<int>pse(vector<int>&nums){
    
    int n = nums.size();
    vector<int>ans;
    stack<int>st;
    
    for(int i = 0;i<n;i++){
        
        while(!st.empty() && st.top() >= nums[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        
        st.push(nums[i]);
    }
    
    return ans;
}

int main()
{
    
    vector<int>nums = {1,3,4,2};
    
    
    vector<int>ans = pse(nums);
    
    
    for(auto a : ans){
        cout << a << " ";
    }
    
    
    
    
    
    
    
    
    

    return 0;
}