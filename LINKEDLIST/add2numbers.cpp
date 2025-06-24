#include<iostream>
#include<math.h>
#include<vector>


using namespace std;

class ListNode{
  int val;
  ListNode*next;

  ListNode(int value){
    val = value;
    next = nullptr;
  }

  int addtwonums(ListNode*p,ListNode*q){

    int carry = 0;
    int sum = 0;

    ListNode*dummy = new ListNode(0);
    ListNode*temp = dummy;

    while(p != nullptr || q != nullptr || carry){

      sum = carry;

      if(p != nullptr){
        sum += p->val;
        p = p->next;
      }

      if(q != nullptr){
        sum += q->val;
        q = q->next;
      }

      int rem = sum % 10;
      carry = sum / 10;

      temp->next = new ListNode(rem);
      temp = temp->next;
    }
  }
};


int main(){
  return 0;
}
