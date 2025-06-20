//SELECTION SORT

/*Its called so because this kinda sorting basically we keep selecting the minimum element and then putting them in the starting index of the array and then we move this starting index to smth else*/

/* TIME COMPLEXITY = O(N^2)
   SPACE COMPLEXTIY = O(1)*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

void selection_sort(vector<int>&arr,int n){

  for(int i = 0;i<n;i++){

    int mini = i ;


    for(int j = i;j<n;j++){

      if(arr[mini] > arr[j]){

        mini = j;
      }

    }

      swap(arr[mini],arr[i]);

  }

  for (int j = 0; j < n; j++)
  {
    cout << arr[j] << " ";
  }
  


    

    
}


int main(){

  int n ;
  cin >> n;

  vector<int>q;



  for(int i = n;i>=1;i--){

      q.push_back(i);
  }

  selection_sort(q,n);

  

}