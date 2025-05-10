#include<bits/stdc++.h>
using namespace std;

class Node{
  public: 
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      next=NULL;
    }
};
int getCount(Node* head){
  Node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  return count;
}
//BRUTE
Node* solve(Node* head){
  Node* temp=head;
  int len=getCount(temp);
  temp=head;
  int length=len/2;
  Node* prev=NULL;
  while(length--){
    prev=temp;
    temp=temp->next;
  }
  prev->next=temp->next;
  delete(temp);
  return head;
}

//Optimal
Node* optimal(Node* head){
  if(head==NULL)return head;
  Node* slow=head;
  Node* fast=head;
  Node* prev=NULL;
  while(fast!=NULL && fast->next!=NULL){
    prev=slow;
    slow=slow->next;
    fast=fast->next->next;
  }
  prev->next=slow->next;
  delete(slow);
  return head;
}

// array to LL
Node* arrayToLL(vector<int> &nums){
  Node* head=new Node(nums[0]);
  Node* temp=head;
  for(int i=1;i<nums.size();i=i+1){
    Node* newNode=new Node(nums[i]);
    temp->next=newNode;
    temp=newNode;
  }
  return head;
}

//print LL.
void print(Node* head){
  if(head==NULL)return;
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  return;
}


int main(){
  vector<int> v={1,2,3,4,5,6,7};
  Node* head = arrayToLL(v);
  head=optimal(head);
  print(head);
  return 0;
}