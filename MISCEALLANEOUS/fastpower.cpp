#include<iostream>
#include<math.h>

using namespace std;

long long fastpower(long long a, long long b){

  long long result = 1;

  while(b>0){
    
    if(b%2 == 1){
      result *= a;
    }
    

  a *= a;
  b = b/2;
  }


  return result;

  
  
}


int main(){

  long long a,b;

  cin >> a >> b;


  cout << fastpower(a,b);
}
