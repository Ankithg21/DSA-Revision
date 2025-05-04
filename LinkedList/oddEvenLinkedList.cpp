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

// BRUTE_FORCE
Node* oddEven(Node* head){
  vector<int> v;
  Node* temp=head;
  while(temp!=NULL && temp->next!=NULL){
    v.push_back(temp->data);
    temp=temp->next->next;
  }
  if(temp)v.push_back(temp->data);
  temp=head->next;
  while(temp!=NULL && temp->next!=NULL){
    v.push_back(temp->data);
    temp=temp->next->next;
  }
  if(temp)v.push_back(temp->data);
  temp=head;
  for(auto it: v){
    temp->data=it;
    temp=temp->next;
  }
  return head;
}

// OPTIMAL
Node* optimal(Node* head){
  if(head==NULL || head->next==NULL)return head;
  Node* odd=head;
  Node* even2=head->next;
  Node* even=head->next;
  while(even!=NULL && even->next!=NULL){
    odd->next=odd->next->next;
    even->next=even->next->next;
    odd=odd->next;
    even=even->next->next;
  }
  odd->next=even2;
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
  
  vector<int> v={1,2,3,4,5,6};
  Node* head = arrayToLL(v);
  head=optimal(head);
  print(head);
  
  return 0;
}