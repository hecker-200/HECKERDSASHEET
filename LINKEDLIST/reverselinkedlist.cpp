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
};

int main(){

  // lets say leetcode wala linkedlist is defined that is ListNode

  //lets say we have a linked list 1,2,3,4,5;

  ListNode*head = nullptr;

  //answer code 

  if(head == nullptr || head->next == nullptr){
    return head;
  }

  ListNode*p = head;
  ListNode*q = head->next;
  ListNode*t = nullptr;

  p->next = nullptr ; //v3ery important taki yeh head ab tail banpayega without issue

  while(q != nullptr){


    q->next = t;
    q->next = p;
    p = q;
    q = t;

  }

  return p;


}