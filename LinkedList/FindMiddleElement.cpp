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

// BRUTE
// get length => n;
// go traverse (n/2)+1 and return ans;


//Optimal
Node* solve(Node* head){
  Node* slow=head;
  Node* fast=head->next;
  while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
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
  head=solve(head);
  cout<<head->data<<endl;
  return 0;
}