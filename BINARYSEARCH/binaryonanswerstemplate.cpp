#include<iostream>
#include<math.h>

using namespace std;


int main(){

  int n ;

  cin >>  n;

  int l = 1;
  int r = n;

  while(l+1 < r){

    int m = (l+r)/2;

    if(m*m <= n){
      l = m;
    }
    else{
      r = m;
    }
  }

  cout << l;
}